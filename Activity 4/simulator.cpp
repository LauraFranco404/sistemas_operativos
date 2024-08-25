#include <iostream>
#include <fstream>
#include "interpreter.h"



int main(){
    pc = 1000;

    ifstream file("programa1.txt"); 
  
    // String to store each line of the file. 
    string line; 
  
    if (file.is_open()) { 
        int i = 0;
        while (getline(file, line)) { 
            if (line.empty()) { 
                break; 
            } 
            memory.insert({pc+i, line});
            i++;
        } 
        file.close(); 
    } 
    else { 
        cerr << "ERROR OPENING PROGRAM FILE" << endl; 
    } 
    printmemo();
    fetch();
        
    return 0;
}
