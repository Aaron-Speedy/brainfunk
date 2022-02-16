void interpretFunction(Function& function) {
    int index = 0; 
    for(int i = 0; i < function.tokens.size(); i++) {
        switch(function.tokens[i]) {
            case '+':
                array[function.pointer]++; 
                break; 
            case '-':
                array[function.pointer]--; 
                break; 
            case '<': 
                function.pointer--; 
                if(0 > function.pointer) {
                    function.pointer = array.size() - 1; 
                }
                break; 
            case '>': 
                function.pointer++; 
                if(array.size() <= function.pointer) {
                    array.push_back(0); 
                }
                break; 
            case '.':
                std::cout << array[function.pointer]; 
                break; 
            case ',':
                if(pre_def_input) {
                    if(input_index >= input_string.size()) {
                        if(empty_done) {
                            array[function.pointer] = 0; 
                        }
                        else {
                            std::cin >> array[function.pointer]; 
                        }
                    }
                    else {
                        array[function.pointer] = input_string[input_index]; 
                    }
                    input_index++; 
                } 
                else {
                    std::cin >> array[function.pointer]; 
                }
            case '[':
                {
                    int loop_num = 1; 
                    if(array[function.pointer] == 0) {
                        while(loop_num != 0) {
                            i++;
                            if(i >= function.tokens.size()) {
                                break; 
                            }
                            if(function.tokens[i] == '[') {
                                loop_num++; 
                            }
                            if(function.tokens[i] == ']') {
                                loop_num--; 
                            }
                            if(loop_num == 0) {
                                i--; 
                            }
                        }
                    }
                }
                break; 
            case ']':
                {
                    int loop_num = 1; 
                    if(array[function.pointer] != 0) {
                        while(loop_num != 0) {
                            i--; 
                            if(i < 0) {
                                break; 
                            }
                            if(function.tokens[i] == '[') {
                                loop_num--; 
                            }
                            if(function.tokens[i] == ']') {
                                loop_num++; 
                            }
                            if(loop_num == 0) {
                                i--; 
                            }
                        }
                    }
                }
                break; 
        }
    }
}
void interpretCaller() {
    for(int i = 0; i < caller.size(); i++) {
        switch(caller[i]) {
            case '^':
                function_pointer--; 
                if(function_pointer < 0) {
                    function_pointer = functions.size() - 1; 
                }
                break; 
            case 'v': 
                function_pointer++; 
                if(function_pointer == functions.size()) {
                    function_pointer = 0; 
                }
                break; 
            case ':':
                interpretFunction(functions[function_pointer]); 
                break; 
            case '!':
                functions[function_pointer].pointer = 0; 
                break; 
            case '[':
                {
                    int loop_num = 1; 
                    if(array[functions[function_pointer].pointer] == 0) {
                        while(loop_num != 0) {
                            i++;
                            if(i >= functions[function_pointer].tokens.size()) {
                                break; 
                            }
                            if(caller[i] == '[') {
                                loop_num++; 
                            }
                            if(caller[i] == ']') {
                                loop_num--; 
                            }
                            if(caller[i] == 0) {
                                i--; 
                            }
                        }
                    }
                }
                break; 
            case ']':
                {
                    int loop_num = 1; 
                    if(array[functions[function_pointer].pointer] != 0) {
                        while(loop_num != 0) {
                            i--; 
                            if(i < 0) {
                                break; 
                            }
                            if(caller[i] == '[') {
                                loop_num--; 
                            }
                            if(caller[i] == ']') {
                                loop_num++; 
                            }
                            if(loop_num == 0) {
                                i--; 
                            }
                        }
                    }
                }
                break; 
            case 'c':
                functions.push_back(functions[function_pointer]); 
                break; 
            case 'r':
                functions.erase(functions.begin() + function_pointer); 
                break; 
            case '{':
                {
                    int loop_num = 1; 
                    bool another = 0; 
                    for(int j = 0; j < functions.size(); j++) {
                        if(functions[j].pointer == functions[function_pointer].pointer) {
                            another = 1; 
                        }
                    }
                    if(!another) {
                        while(loop_num != 0) {
                            i++;
                            if(i >= functions[function_pointer].tokens.size()) {
                                break; 
                            }
                            if(caller[i] == '{') {
                                loop_num++; 
                            }
                            if(caller[i] == '}') {
                                loop_num--; 
                            }
                            if(caller[i] == 0) {
                                i--; 
                            }
                        }
                    }
                }
                break; 
            case '}':
                {
                    int loop_num = 1; 
                    bool another = 0; 
                    for(int j = 0; j < functions.size(); j++) {
                        if(functions[j].pointer == functions[function_pointer].pointer) {
                            another = 1; 
                        }
                    }
                    if(another) {
                        while(loop_num != 0) {
                            i--; 
                            if(i < 0) {
                                break; 
                            }
                            if(caller[i] == '{') {
                                loop_num--; 
                            }
                            if(caller[i] == '}') {
                                loop_num++; 
                            }
                            if(loop_num == 0) {
                                i--; 
                            }
                        }
                    }
                }
                break; 
        }
    }
}
