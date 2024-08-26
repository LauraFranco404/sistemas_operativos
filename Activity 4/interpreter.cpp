#include "interpreter.h"

int pc, mar, acum;
string icr, mdr, controlunit;
string memory[MEMSIZE];

void fetch(){
    if (pc < MEMSIZE && pc >= PCINIT && memory[pc] != "")
    {
        readMemo(pc);
        icr = mdr;
        pc+=1;
        controlunit = mdr;
        decode();
    }
}

void decode()
{
    string decodeaux = controlunit;
    char * inst;
    char * mdrval = &decodeaux[0]; // convertir de string a char*
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
        return;
    }
    else{
        cout<<"Error "<<inst<< "DOESNT EXIST"<<endl;
        return;
    }
    next_instruction();
}
void next_instruction()
{
    fetch();
}

void printMemo()
{
    cout << "Memoria: "<<endl;
    cout << "DIR\tVAL\n"; 
    for (int i = 0; i< MEMSIZE; i++) { 
        cout << i << '\t' << memory[i] << '\n'; 
    } 
    cout<<"fin memoria"<<endl;
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
    //cout<<"Set with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
    int d1 = atoi(p1);
    string str(p2);
    writeMemo(d1, str);
}
void Ldr(char * p1, char * p2, char * p3, char * p4){
    //cout<<"Ldr with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
    p1 = p1+sizeof(char); //quitar la D
    readMemo(atoi(p1));
    acum = stoi(mdr); //poner en acumulador
}
void Add(char * p1, char * p2, char * p3, char * p4){
    //cout<<"Add with p1: "<<p1<< " With p2: "<<p2<< " With p3: "<<p3<< " With p4: "<<p4<<endl;
    p1 = p1+sizeof(char); //quitar la D

    if (strcmp("NULL", p3) == 0)
    {
        if (strcmp("NULL", p2) == 0)
        { //Caso 1
            readMemo(atoi(p1));
            acum = acum + stoi(mdr);
        }else{ //caso 2, suma d1 y d2 dejando la suma en el acumulador
            p2 = p2+sizeof(char); //quitar la d
            readMemo(atoi(p1)); //carga d1 en el acumulador
            acum = stoi(mdr);
            readMemo(atoi(p2)); //carga d2 en la alu y suma
            acum = acum + stoi(mdr);
        }
    }else{ //caso 3
        p2 = p2+sizeof(char); //quitar la d
        p3 = p3+sizeof(char); //quitar la d
        readMemo(atoi(p1)); //carga d1 en el acumulador
        acum = stoi(mdr);
        readMemo(atoi(p2)); //carga d2 en la alu y suma
        acum = acum + stoi(mdr);
        writeMemo(atoi(p3), to_string(acum));
    }
}
void Inc(char * p1, char * p2, char * p3, char * p4){
    p1 = p1+sizeof(char); //quitar la D
    readMemo(atoi(p1));
    acum = stoi(mdr); //carga primero en el acumulador para operarlo
    acum += 1;
    writeMemo(atoi(p1), to_string(acum));
}
void Dec(char * p1, char * p2, char * p3, char * p4){
    p1 = p1+sizeof(char); //quitar la D
    readMemo(atoi(p1));
    acum = stoi(mdr); //carga primero en el acumulador para operarlo
    acum -= 1;
    writeMemo(atoi(p1), to_string(acum));
}
void Str(char * p1, char * p2, char * p3, char * p4){
    p1 = p1+sizeof(char); //quitar la D
    writeMemo(atoi(p1), to_string(acum));

    
}  
void Shw(char * p1, char * p2, char * p3, char * p4){
    if (strcmp("ACC", p1) == 0) { std::cout<<"Acumulador: "<<acum<<endl; }
    else if(strcmp("ICR", p1)== 0) { std::cout<<"ICR: "<<icr<<endl; }
    else if(strcmp("MAR", p1)== 0) { std::cout<<"MAR: "<<mar<<endl; }
    else if(strcmp("MDR", p1)== 0) { std::cout<<"MDR: "<<mdr<<endl; }
    else if(strcmp("UC", p1)== 0) { std::cout<<"Control unit: "<<controlunit<<endl; }
    else if(strcmp("PC", p1)== 0) { std::cout<<"PC: "<<pc<<endl; }
    else{
        p1 = p1+sizeof(char); //quitar la D
        cout<<memory[atoi(p1)]<<endl;
    }
}

void Pause(char * p1, char * p2, char * p3, char * p4){
    cout<<"-----------------Pause----------------------"<<endl;
    cout<<"Registers: "<<endl;
    cout<<"PC: "<<pc<<endl;
    cout<<"ICR: "<<icr<<endl;
    cout<<"MAR: "<<mar<<endl;
    cout<<"MDR: "<<mdr<<endl;
    cout<<"CONTROL UNIT: "<<controlunit<<endl;
    cout<<"ACUMULADOR: "<<acum<<endl;
    cout<<"--------MEMORY---------"<<endl;
    printMemo();
}