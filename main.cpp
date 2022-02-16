#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "headers/program.h"

int main() {
    std::ifstream t("../main.bfunk");
    std::string input((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    Program program; 
    program.input = input;
    program.tokenize(); 
    program.interpretCaller(); 
    std::cout << std::endl; 
    return 0; 
}