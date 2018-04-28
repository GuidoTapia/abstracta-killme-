#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "affin.h"
#include "affin.cpp"
using namespace std;

int main(){
    affin algo=affin();
    gcd clave=algo.getclave();
    string m=algo.cifrado("Renzo hay dos posibles secuelas para infinity war una es infinity guantlet en la cual se explora el vacio existencial en thanos despues de todo, y la otra es secret invasion en la cual una raza alienigena invade la tierra, adueyandose del cuerpo del cap");
    //m="4 o5Io5wUDb s3ywDowQSIydsyu3UD3Ud3D5Io7VDl9DuIDQI95I9IDK o539U3Dow9DIM IDqysIDSIyIDb sdIyU3D3uDU 395SVluDU 395wDK3D3UdIyDO 9dwDID3uuIV" ;
    cout<<endl<<m<<endl;
    affin algo2=affin(clave.getnum(0),clave.getnum(1));
    cout<<endl<<algo2.descifrado(m);
    return 0;
}
