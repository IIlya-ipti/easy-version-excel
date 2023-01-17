//
// Created by Ilya on 17.01.2023.
//

#ifndef ADDITIONALLY_H
#define ADDITIONALLY_H


/*
 * [INP] input - string to split
 * [INP] sep - separation separator
 * [OUT] split string
 * */
std::vector<std::string> split_string (const std::string & input, const char& sep);
std::vector<std::vector<std::string>> read_csv(const std::string& file_name);
double string_to_double( const std::string& s );

/*
 * if there is an element "ch" at the end, then it is removed
 * [INP] input string
 * [INP] input ch
 * [OUT] string with removed element
 * */
void erase_end_character(std::string& input, char ch );

/*
 * [INP] - file name
 * [OUT] - number of lines in file
 * */
size_t get_n_lines_file(const std::string& filename);
#endif //ADDITIONALLY_H
