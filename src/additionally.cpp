
#include "additionally.h"

std::vector<std::string> split_string(const std::string &input, const char &sep) {
    // length of result vec
    size_t count_sep = 0;
    for(const char& i : input){
        if(i == sep)count_sep++;
    }

    // set and init split vector
    std::vector<std::string> split_strings(count_sep + 1);
    size_t second_ind = 0;
    size_t ind = 0;
    for(size_t i = 0; i < input.size();i++){
        if(input[i] == sep){
            split_strings[ind] =input.substr(second_ind,i - second_ind);
            second_ind = i + 1;
            ind++;
        }
    }
    split_strings[ind] = input.substr(second_ind,input.size() - second_ind);

    return split_strings;
}

std::vector<std::vector<std::string>> read_csv(const std::string &file_name) {
    std::ifstream file(file_name);
    std::vector<std::vector<std::string>> csv_table( get_n_lines_file(file_name) + 1);

    // read file and init csv_table
    size_t ind = 0;
    std::vector<std::string> res;
    std::string out;
    while(getline(file,out)){
        erase_end_character(out,'\r');
        res = split_string(out,',');
        csv_table[ind] = res;
        ind++;
    }
    return csv_table;
}

double string_to_double(const std::string &s) {
    std::istringstream i(s);
    double x;
    if (!(i >> x))
        return 0;
    return x;
}

void erase_end_character(std::string &input, char ch) {
    if(input[input.size() - 1] == ch) {
        input.pop_back();
    }
}

size_t get_n_lines_file(const std::string &filename) {
    std::ifstream file(filename);
    return std::count(std::istreambuf_iterator<char>(file),
                      std::istreambuf_iterator<char>(),'\n');
}
