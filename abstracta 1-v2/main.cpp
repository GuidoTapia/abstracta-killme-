#include <iostream>
#include "cripto.h"
#include <fstream>
using namespace std;


int main() {
	string mensaje;
	int clave;
	//cout<<"Ingresa mensaje";
	//getline(cin,mensaje);
	mensaje="Recibir dos strings por entrada estandar. Imprimir el numero de veces que aparece el segundo string en el primer string. Las cadenas no contienen espacios en blanco.";
	cout<<"Ingresa clave";
	cin>>clave;
	cripto algo(clave);
	//string cipher=algo.cifrado(mensaje,7);//="wV5.1N5N11NN...Nh5NUN.96,WZ6TN_VW.W,nBV.5N5NZO9iax7VWWUU91NW5X955U3Y5399Z.5N8G9.bgx1Z1ZWVWW55NNYN3VNNW.V.N5VV_N_Tigx86.Y95nY_,SV95TN5_N1N571YZ9nZ7kfx1N3N6NN,NT55W7.Z.5VW76ZU91.ZNVikxWV9E.756NU9.77Mjx";//"F..N5ZN55ZNNP6zk95N9NZ.YVN6V7UNWV6NZV95NZ.WN_jgPN_U4PZ_N_1ZZ.5N9Z_65W.9N9ZV9iaNV9NTNNZ75Z1,9_97UZ1N9N,.vN5Skh35N95VV3Z6NJZN__9NNW5O5_ZNKW5igZYS6W55N,N6NN1ZNN5V4,Z_9N595Ncg_1UmZ5VV6TYNV7ix";//"2796.91NVxZNZNXN59U7.WV17N9x_V,mTZ_79N7UU,1Z_x9ZZ.10NN.91N5N4.5XN3N9l99_6.Z5OXWNNN915U68WZZT.69Y9Z91,V58NNN6V";
//"vNIZN5.V5hTN19T1V5m ,VlV6YNZZNWWiNW5ZU85WN,.NZVZuZNV1NWPV,6W9g5Y865N.8gN69,UVzVl5.V1NN959NhVN9ZW9N9N91Y95W N47ZZ,VWWN77kUVNU,WPN3W9W8NTKv51n.1Z51_NZNZ5GN19NZTW_Z7I_m,U9.NG..5n";//"F..N5ZN55ZNNP6zk95N9NZ.YVN6V7UNWV6NZV95NZ.WN_jgPN_U4PZ_N_1ZZ.5N9Z_65W.9N9ZV9iaNV9NTNNZ75Z1,9_97UZ1N9N,.vN5Skh35N95VV3Z6NJZN__9NNW5O5_ZNKW5igZYS6W55N,N6NN1ZNN5V4,Z_9N595Ncg_1UmZ5VV6TYNV7ix";//"2796.91NVxZNZNXN59U7.WV17N9x_V,mTZ_79N7UU,1Z_x9ZZ.10NN.91N5N4.5XN3N9l99_6.Z5OXWNNN915U68WZZT.69Y9Z91,V58NNN6V";//algo.cifrado(mensaje,clave);
	string cipher=algo.cifrado(mensaje,7);
	cout<<cipher;
	ofstream myfile;
    myfile.open ("example.txt");
    myfile << cipher;
    myfile.close();
	//cout<<algo.descifrado(cipher,clave)<<endl;
	return 0;
}
