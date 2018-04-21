
#include "cripto.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cripto algo(7);
    string mensaje="Me morire en Paris con aguacero,un dia del cual tengo ya el recuerdo Me morire en Paris -y no me corro-.Guido Luis Tapia Ore 171-10-39690";
	//getline (cin,mensaje);
	string cipher=algo.cifrado(mensaje,7);
	//string cipher="2796.91NVxZNZNXN59U7.WV17N9x_V,mTZ_79N7UU,1Z_x9ZZ.10NN.91N5N4.5XN3N9l99_6.Z5OXWNNN915U68WZZT.69Y9Z91,V58NNN6V";//algo.cifrado(mensaje,7);
	cout<<cipher<<endl;
	ofstream myfile;
    myfile.open ("example.txt");
    myfile << cipher;
    myfile.close();
	cout<<algo.descifrado(cipher,7)<<endl;
	return 0;
}
