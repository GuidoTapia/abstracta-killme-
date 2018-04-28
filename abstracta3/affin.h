#ifndef AFFIN_H_INCLUDED
#define AFFIN_H_INCLUDED
using namespace std;
string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";
class gcd{
int x[3];
public:
    gcd(int,int,int);
    int getnum(int);
};
int modulo(int,int);
int mcd(int,int);
gcd eucExt(int,int);
class affin{
int a,b,T,ai;
public:
    affin();
    affin(int,int);
    gcd getclave();
    string cifrado(string);
    string descifrado(string);
};

#endif // AFFIN_H_INCLUDED
