#include "affin.h"

gcd eucExt(int r1,int r2){
    int aux,s1=1,s2=0,t1=0,t2=1,q;
    while(r2){
        q=r1/r2;
        aux=r1-(q*r2);
        r1=r2;
        r2=aux;
        aux=s1-(q*s2);
        s1=s2;
        s2=aux;
        aux=t1-(q*t2);
        t1=t2;
        t2=aux;
    }
    return gcd(r1,s1,t1);
}
int modulo(int a, int n){
    a=a-(a/n)*n;
    if(a<0)
        return a+n;
    return a;
}
int mcd(int a, int b){
    int aux;
    while(a){
        aux=modulo(b,a);
        b=a;
        a=aux;
    }
    return b;
}
gcd::gcd(int a, int b, int c){
    x[0]=a;
    x[1]=b;
    x[2]=c;
}
int gcd::getnum(int i){
    if (i<3)
        return x[i];
}
affin::affin(int x,int y){
    T=alfabeto.length();
    a=x;
    b=y;
    ai=eucExt(a,T).getnum(1);
    if(ai<0)
        ai+=T;
}
affin::affin(){
    T=alfabeto.length();
    srand(time(NULL));
    do{
        a=rand();
    }while(mcd(a,T)!=1);
    b=rand();
}
gcd affin::getclave(){
    return gcd(a,b,0);
}
string affin::cifrado(string mens){
    for(int i=0;i<mens.length();i++)
        mens[i]=alfabeto[modulo((alfabeto.find(mens[i])*a)+b,T)];
    return mens;
}
string affin::descifrado(string mens){
    for(int i=0;i<mens.length();i++)
        mens[i]=alfabeto[modulo((alfabeto.find(mens[i])-b)*ai,T)];
    return mens;
}
