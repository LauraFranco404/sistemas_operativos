#pragma once
#ifndef interpreter
#define interpreter
#include <iostream>
#include <string> 
#include <cstring>
#include <vector>
#include <map>

using namespace std;

//el extern le dice al compilador que esto son variables globales que debe ir a buscar su definicion en otro sitio (interpreter.cpp)
extern int pc, mar;
extern string icr, mdr;
extern map<int, string> memory;

void fetch();  void decode(); void execute(); void next_instruction(); 

void printmemo(); 
//deja lo leido de la memoria en mdr
void readMemo(int dir);

#endif
