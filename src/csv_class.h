
#ifndef UNTITLED2_CSV_CLASS_H
#define UNTITLED2_CSV_CLASS_H

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <fstream>
#include "additionally.h"

class CSV_class{
private:
    std::unordered_map<std::string,unsigned long> ind_column_to_char;
    std::unordered_map<std::string,unsigned long>  ind_line_to_int;
    std::vector<std::vector<std::string>> csv_table;
    const std::unordered_set<char> operations = {
            '+','-','*','/'
    };
    const char main_sep = '=';

    static double op_first_second(double first, char op, double second);
    double get_cell(std::string value);
    double result_cell(const std::string &cell);
public:
    explicit CSV_class(const std::string & file_name);
    void write() const ;
};

#endif //UNTITLED2_CSV_CLASS_H
