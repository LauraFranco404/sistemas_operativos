#include <iostream>
#include <fstream>
#include "interpreter.h"



int main(){
    pc = PCINIT;

    ifstream file("programa3.txt"); 
  
    // String to store each line of the file. 
    string line; 
  
    if (file.is_open()) { 
        int i = 0;
        while (getline(file, line)) { 
            if (line.empty()) { 
                break; 
            } 
            memory[pc+i]= line;
            i++;
        } 
        file.close(); 
    } 
    else { 
        cerr << "ERROR OPENING PROGRAM FILE" << endl; 
    } 
    //printMemo();
    fetch();
    //printMemo();
        
    return 0;
}
