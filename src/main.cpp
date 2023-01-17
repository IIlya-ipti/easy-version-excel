#include "csv_class.h"
#include <iostream>


int main(int argc, char **argv) {
    if(argc > 1) {

        CSV_class csv(argv[1]);
        csv.write();
    }else{
        std::cout << "Enter the file name correctly!"<<std::endl;
    }
    return 0;
}
