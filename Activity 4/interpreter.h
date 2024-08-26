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
extern int acum;
extern string icr, mdr;
extern map<int, string> memory;

void fetch();  void decode(); void next_instruction(); 
void execute(char * inst, char * p1, char * p2, char * p3, char * p4); 

//instrucciones
void Set(char * p1, char * p2, char * p3, char * p4);
void Ldr(char * p1, char * p2, char * p3, char * p4);
void Add(char * p1, char * p2, char * p3, char * p4);
void Inc(char * p1, char * p2, char * p3, char * p4);
void Dec(char * p1, char * p2, char * p3, char * p4);
void Str(char * p1, char * p2, char * p3, char * p4);
void Shw(char * p1, char * p2, char * p3, char * p4);
void Pause(char * p1, char * p2, char * p3, char * p4);

//Memoria
void printMemo(); 
//deja lo leido de la memoria en mdr
void readMemo(int dir);

void writeMemo(int dir, string data);

#endif
