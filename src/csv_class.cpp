//
// Created by Ilya on 17.01.2023.
//

#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>
#include "csv_class.h"

double CSV_class::result_cell(const std::string &cell) {


    double result_value = 0;
    unsigned long first_ind = 1;


    char op = '%';
    double val;
    for(unsigned long i = 1; i < cell.size(); i++){
        if(operations.count(cell[i]) > 0){
            // get value
            val = get_cell(cell.substr(first_ind,i - first_ind));

            result_value = op_first_second(result_value, op, val);

            first_ind = i + 1;
            op = cell[i];
        }
    }
    val = get_cell(cell.substr(first_ind,cell.size() - 1));
    result_value = op_first_second(result_value, op, val);
    return result_value;
}

CSV_class::CSV_class(const std::string &file_name) {
    this->csv_table = read_csv(file_name);

    if(!csv_table.empty() && !csv_table[0].empty()) {
        // init columns
        for (unsigned long i = 0; i < csv_table[0].size(); i++) {
            ind_column_to_char[csv_table[0][i]] = i;
        }
        // init lines
        for (unsigned long i = 0; i < csv_table.size(); i++) {
            ind_line_to_int[csv_table[i][0]] = i;
        }
        for (unsigned long i = 1; i < csv_table.size(); i++) {
            if(csv_table[i].size() != csv_table[0].size()){
                std::cout << "data is not correct" <<std::endl;
                throw std::runtime_error("data is not correct");
            }
            for (unsigned long j = 1; j < csv_table[i].size(); j++) {
                if (csv_table[i][j][0] == main_sep) {
                    csv_table[i][j] = std::to_string(result_cell(csv_table[i][j]));
                }
            }
        }
    }else{
        std::cout << "file is empty or not load"<< std::endl;
    }
}

void CSV_class::write() const {
    for(auto & i : csv_table){
        for(unsigned long j= 0; j < i.size(); j++){
            std::cout << i[j];
            if(j != i.size() - 1){
                std::cout << ',';
            }
        }
        std::cout << '\n';
    }
}

double CSV_class::get_cell(std::string value) {
    std::string column;
    std::string line;

    int first_ind =0 ;
    bool is_number = true;
    while(!('0' <= value[first_ind] && value[first_ind] <= '9')){
        column += value[first_ind];
        first_ind++;
        is_number = false;
    }
    while(first_ind < value.size()){
        if(!('0' <= value[first_ind] && value[first_ind] <= '9'))is_number = false;
        line += value[first_ind];
        first_ind++;
    }
    if(is_number){
        try {
            return string_to_double(value);
        }catch(std::exception&e){
            std::cout << "data is not correct" <<std::endl;
            throw std::runtime_error("data is not correct");
        }
    }
    if(ind_column_to_char.count(column)== 0){
        std::cout << "data is not correct" <<std::endl;
        throw std::runtime_error("column out of range");
    }
    if(ind_line_to_int.count(line)== 0){
        std::cout << "data is not correct" <<std::endl;
        throw std::runtime_error("line out of range");
    }
    unsigned long column_ind = ind_column_to_char[column];
    unsigned long line_ind = ind_line_to_int[line];
    if(csv_table[line_ind][column_ind][0] == '=' || csv_table[line_ind][column_ind].empty()){
        std::cout << "data is not correct" <<std::endl;
        throw std::runtime_error("data is not correct");
    }
    return string_to_double(csv_table[line_ind][column_ind]);
}

double CSV_class::op_first_second(double first, char op, double second) {
    if(op == '/' && second == 0){
        std::cout << "division by zero" <<std::endl;
        throw std::runtime_error("division by zero");
    }
    switch (op) {
        case '+':
            return first+second;
        case '-':
            return first - second;
        case '*':
            return first*second;
        case '/':
            return first/second;
        default:
            return second;
    }

}
