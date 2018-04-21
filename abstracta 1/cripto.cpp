
#include "cripto.h"
#include <iostream>

cripto::cripto(int c){
    alfabeto= "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";;
    clave=c;
}
int cripto::mod(int x,int y){
    int res=x-((x/y)*y);
    if(res<0)
        return res+y;
    return res;
}
string cripto::cifrado(string mensaje,int c=0){
    if(c)
        clave=c;
    string salida[clave];
    string mensaje2;
    int i=mod(mensaje.length()-clave,(clave*2)-2);
    if(i){
        for(;i<(clave*2)-2;i++){
            mensaje+='x';
        }
    }
    for(i=0;i<mensaje.length();i++){
        size_t found = alfabeto.length()-alfabeto.find(mensaje[i])-1;
        int aux=mod(i,(clave*2)-2);
        if (aux<clave){
            salida[aux]+=alfabeto[found];
        }else{
            salida[(clave*2)-2-(aux)]+=alfabeto[found];
        }
    }
    for(i=0;i<clave;i++){
        mensaje2+=salida[i];
    }
    return mensaje2;
}
string cripto::descifrado(string mensaje,int c=0){
    if(c)
        clave=c;
    string auxiliares[clave];
    int inicio=0;
    int aux=int((float(mensaje.length())/((clave-1)*2))+0.5);
    for(int i=0;i<clave-1;i++){
        auxiliares[i]=mensaje.substr (inicio,aux);
        inicio+=aux;
        aux=mensaje.length()/(clave-1);
    }
    auxiliares[clave-1]=mensaje.substr(inicio);
    string mensaje2;
    for(int i=0;i<mensaje.length();i++){
        int aux2=mod(i,(clave*2)-2);
        if (aux2<clave){
            mensaje2+=auxiliares[aux2][0];
            auxiliares[aux2].erase(0,1);
        }else{
            mensaje2+=auxiliares[(clave*2)-2-(aux2)][0];
            auxiliares[(clave*2)-2-(aux2)].erase(0,1);
        }
        mensaje2[i]=alfabeto[alfabeto.length()-alfabeto.find(mensaje2[i])-1];
    }
    return mensaje2;
}

