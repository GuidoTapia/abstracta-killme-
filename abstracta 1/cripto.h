#ifndef CRIPTO_H_INCLUDED
#define CRIPTO_H_INCLUDED

#include <iostream>
using namespace std;

class cripto{
string alfabeto;
int clave;
public:
    cripto(int);
    int mod(int,int );
    string cifrado(string,int );
    string descifrado(string ,int );
};

#endif // JUEGO_H_INCLUDED
