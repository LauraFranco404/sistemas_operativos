#include "interpreter.h"

int pc, mar;
string icr, mdr;
map<int, string> memory;

void fetch(){
    if (memory.find(pc) != memory.end())
    {
        readMemo(pc);
        icr = mdr;
        pc+=1;
        //cout<<"executing: "<<icr<<std::endl;
        decode();
    }
}

void decode()
{
    char * inst;

    char * mdrval = &mdr[0]; // convertir de string a char*
    inst = strtok(mdrval, " "); // tomar hasta el primer espacio


    cout<<"executing: "<<inst<<std::endl;
    execute();
}
void execute()
{
    next_instruction();
}
void next_instruction()
{
    fetch();
}

void printmemo()
{
    cout << "DIR\tVAL\n"; 
    for (auto itr = memory.begin(); itr != memory.end(); ++itr) { 
        cout << itr->first << '\t' << itr->second << '\n'; 
    } 
}

void readMemo(int dir){
    mar = dir;
    mdr = memory[dir];
}
