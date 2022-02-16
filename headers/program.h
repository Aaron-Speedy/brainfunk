#include "function.h"
class Program {
	public: 
	std::string input; 
	std::vector<Function> functions; std::string caller; 
	int function_pointer = 0;
	std::vector<char> array = {0}; 
	bool pre_def_input = 0; int input_index = 0; std::string input_string = ""; bool empty_done = 1;
	#include "tokenize.h" 
	#include "interpret.h"
};
