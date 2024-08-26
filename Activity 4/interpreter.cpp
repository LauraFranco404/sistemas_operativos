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
    if (strcmp("END", inst) != 0)
    {
        char * p1 =strtok(NULL, " "); // tomar el primer parametro
        char * p2 =strtok(NULL, " "); // tomar hasta el primer espacio
        char * p3 =strtok(NULL, " "); // tomar hasta el primer espacio   
        char * p4 =strtok(NULL, " "); // tomar hasta el primer espacio
        //cout<<"Execute "<<inst<< " With p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
        execute(inst, p1, p2, p3, p4);
    }
}
void execute(char * inst, char * p1, char * p2, char * p3, char * p4)
{
    if (strcmp("SET", inst) == 0){
        Set(p1, p2, p3, p4);
    }
    else if (strcmp("LDR", inst) == 0)
    {
        Ldr(p1, p2, p3, p4);
    }
    else if (strcmp("ADD", inst) == 0)
    {
        Add(p1, p2, p3, p4);
    }
    else if (strcmp("INC", inst) == 0)
    {
        Inc(p1, p2, p3, p4);
    }
    else if (strcmp("DEC", inst) == 0)
    {
        Dec(p1, p2, p3, p4);
    }
    else if (strcmp("STR", inst) == 0)
    {
        Str(p1, p2, p3, p4);
    }
    else if (strcmp("SHW", inst) == 0)
    {
        Shw(p1, p2, p3, p4);
    }
    else if (strcmp("PAUSE", inst) == 0)
    {
        Pause(p1, p2, p3, p4);
    }
    else{
        cout<<"Error "<<inst<< "DOESNT EXIST"<<endl;
    }
    next_instruction();
}
void next_instruction()
{
    fetch();
}

void printMemo()
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

void writeMemo(int dir, string data)
{
    mar = dir;
    mdr = data;
    memory[dir] = data;
}

void Set(char * p1, char * p2, char * p3, char * p4){
    p1 = p1+sizeof(char); //quitar la D

    cout<<"Set with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
    int d1 = atoi(p1);
    cout<<"d1: "<<d1<<endl;
    string str(p2);
    writeMemo(d1, str);

}
void Ldr(char * p1, char * p2, char * p3, char * p4){
    cout<<"Ldr with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
}
void Add(char * p1, char * p2, char * p3, char * p4){
    cout<<"Add with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
}
void Inc(char * p1, char * p2, char * p3, char * p4){
    cout<<"Inc with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
}
void Dec(char * p1, char * p2, char * p3, char * p4){
    cout<<"Dec with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
}
void Str(char * p1, char * p2, char * p3, char * p4){
    cout<<"Str with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
}  
void Shw(char * p1, char * p2, char * p3, char * p4){
    cout<<"Shw with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
}
void Pause(char * p1, char * p2, char * p3, char * p4){
    cout<<"Pause with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
}