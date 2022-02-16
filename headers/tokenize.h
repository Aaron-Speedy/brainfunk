void tokenize() {
    std::string tokens; 
    bool first = 1; 
    bool comment = 0; 
    for(int i = 0; i < input.size(); i++) {
        if(first) {
            if(input[i] == ';') {
                for(int i = 0; i < tokens.size(); i++) { // For some reason caller = tokens didn't work
                    caller.push_back(tokens[i]); 
                }
                tokens = {}; 
                first = 0; 
            }
            else {
                tokens.push_back(input[i]); 
            }
        }
        else {
            if(input[i] == ';') {
                Function function;
                function.tokens = tokens;
                functions.push_back(function); 
                tokens = {}; 
            }
            else {
                tokens.push_back(input[i]); 
            }
        } 
    }
}