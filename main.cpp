#include <iostream>

using namespace std;
class cripto{
int n,m;
public:
    cripto(int n, int m){
        this->n=n;
        this->m=m;
    }
    string encriptamiento(string mensaje){
        string mensajeSalida="";
        string aux="";
        int longitud[]={n*n,(n*2)+(n/2)-1,n*n,(n*3)-2};
        int cambios[]={1,0,-1,1};
        int longi,vi,i,j,cont,elem,k,pos,mod,posMensaje=0,puntoInicio=(n-1)/2;
        bool flag;
        int particiones[n];
        int suma=0;
        for(i=0;i<n;i++){
            particiones[i]=0;
        }
        for(i=0;i<m;i++){
            suma+=longitud[i%4];
        }
        for(i=mensaje.length();i<=suma;i++){
            mensaje+="x";
        }
        //cout<<"Mensaje\n"<<mensaje<<"\n";
        for(i=0;i<m;i++){
            longi=i%4;
            aux="";
            if(!longi){
                k=1;
                vi=0;
                elem=n;
                flag=true;
                cont=0;
                pos=-1;
                mod=cambios[vi];
                for(j=posMensaje;j<longitud[0]+posMensaje;j++){
                    pos+=mod;
                    aux.insert(pos,1,mensaje[j]);
                    cont++;
                    if(cont==elem&&j){
                        if(flag){
                            elem--;
                            flag=false;
                        }else{
                            flag=true;
                        }
                        if(vi==3){
                            vi=0;
                            k+=2;
                        }else{
                            vi++;
                        }
                        mod=cambios[vi];
                        if(vi==0||vi==2){
                            mod*=k;
                        }
                        cont=0;
                    }
                }
                for(int j=0;j<n;j++){
                    mensajeSalida.insert(particiones[j],aux.substr(j*n,n));
                    for(k=j;k<n;k++)
                        particiones[k]+=n;
                }
                posMensaje+=longitud[0];
                //cout<<"Mensaje\n"<<mensajeSalida<<"\n";
            }
            else if(longi==1){
                cont=-1;
                elem=posMensaje+n-puntoInicio;
                for(pos=posMensaje;pos<elem;pos++){
                    cont++;
                    aux.insert(cont,1,mensaje[pos]);
                    posMensaje++;
                }
                elem+=(n-puntoInicio-1);
                for(pos=posMensaje;pos<elem;pos++){
                    aux.insert(cont,1,mensaje[pos]);
                    cont--;
                    posMensaje++;
                }
                elem+=puntoInicio;
                for(pos=posMensaje;pos<elem;pos++){
                    aux.insert(cont,1,mensaje[pos]);
                    posMensaje++;
                }
                elem+=(puntoInicio-1);
                for(pos=posMensaje;pos<elem;pos++){
                    cont+=2;
                    aux.insert(cont,1,mensaje[pos]);
                    posMensaje++;
                }
                elem=posMensaje+n-puntoInicio-1;
                for(pos=posMensaje;pos<elem;pos++){
                    cont+=3;
                    aux.insert(cont,1,mensaje[pos]);
                    posMensaje++;
                }
                if(puntoInicio)
                    aux.append(1,mensaje[posMensaje]);
                posMensaje++;
                if(puntoInicio){
                    mensajeSalida.insert(particiones[0],aux.substr(0,1));
                    for(k=0;k<n;k++)
                        particiones[k]+=1;
                }else{
                    mensajeSalida.insert(particiones[0],aux.substr(0,n));
                    for(k=0;k<n;k++)
                        particiones[k]+=2;
                }
                for(j=1;j<puntoInicio;j++){
                    mensajeSalida.insert(particiones[j],aux.substr((2*j)-1,2));
                    for(k=j;k<n;k++)
                        particiones[k]+=2;
                }
                for(;j<n-1;j++){
                    mensajeSalida.insert(particiones[j],aux.substr(((3*(j-puntoInicio))+(2*puntoInicio)-1),3));
                    for(k=j;k<n;k++)
                        particiones[k]+=3;
                }
                mensajeSalida.insert(particiones[j],aux.substr(aux.length()-2,2));
                for(k=j;k<n;k++)
                    particiones[k]+=2;
                //cout<<"Mensaje\n"<<mensajeSalida<<"\n";
            }
            else if(longi==2){
                k=1;
                vi=0;
                elem=1;
                flag=false;
                cont=0;
                pos=0;
                mod=cambios[vi];
                for(j=posMensaje;j<longitud[2]+posMensaje;j++){
                    if(cont==elem){
                        if(flag){
                            flag=false;
                            elem++;
                        }else{
                            flag=true;
                        }
                        if(vi==0){
                            vi=3;
                        }else{
                            if(vi==2){
                                k+=2;
                            }
                            vi--;
                        }
                        mod=cambios[vi];
                        if(vi==0||vi==2){
                            mod*=k;
                        }
                        cont=0;
                    }
                    aux.insert(pos,1,mensaje[j]);
                    pos+=mod;
                    if(pos<0){
                        pos=0;
                    }else if(pos>aux.length()){
                        pos=aux.length();
                    }
                    cont++;
                }
                for(int j=0;j<n;j++){
                    mensajeSalida.insert(particiones[j],aux.substr(j*n,n));
                    for(k=j;k<n;k++)
                        particiones[k]+=n;
                }
                posMensaje+=longitud[0];
                //cout<<"Mensaje\n"<<mensajeSalida<<"\n";
            }
            else if(longi==3){
                pos=0;
                vi=0;
                cont=0;
                for(j=posMensaje;j<posMensaje+longitud[3];j++){
                    aux.insert(pos,1,mensaje[j]);
                    cont++;
                    if(cont==n){
                        vi=2;
                    }else if(cont==(n*2)-1){
                        vi=-1;
                    }else if(cont==(n*2)){
                        vi=-2;
                    }
                    pos+=vi;
                    if(pos>aux.length())
                        pos=aux.length();
                }
                mensajeSalida.insert(particiones[0],aux.substr(0,2));
                for(k=0;k<n;k++)
                    particiones[k]+=2;
                for(j=1;j<n-1;j++){
                    mensajeSalida.insert(particiones[j],aux.substr((j*3)-1,3));
                    for(k=j;k<n;k++)
                        particiones[k]+=3;
                }
                mensajeSalida.insert(particiones[n-1],aux.substr(aux.length()-2,2));
                particiones[n-1]+=2;
                posMensaje+=longitud[3];
                //cout<<"Mensaje\n"<<mensajeSalida<<"\n";
            }
        }
        return mensajeSalida;
    }
    string desencriptamiento(string mensaje){
        int particiones[n];
        particiones[0]=0;
        cout<<particiones[0]<<endl;
        int puntoInicio=(n-1)/2;
        for(int j=1;j<n;j++){
            particiones[j]=particiones[j-1];
            for(int i=0;i<m;i++){
                int aux=i%4;
                if(aux==0||aux==2){
                    particiones[j]+=n;
                }else if(aux==3){
                    if(n==1){
                        particiones[j]+=2;
                    }else{
                        if(j==1){
                            particiones[j]+=2;
                        }else{
                            particiones[j]+=3;
                        }
                    }
                }else if(aux==1){
                    if(j==1){
                        if(n==2){
                            particiones[j]+=2;
                        }else{
                            particiones[j]++;
                        }
                    }else{
                        if(j<puntoInicio+1){
                            particiones[j]+=2;
                        }else{
                            particiones[j]+=3;
                        }
                    }
                }
            }
        }
        string aux;
        string mensajeFinal;
        int longitud[]={n*n,(n*2)+(n/2)-1,n*n,(n*3)-2};
        int longi;
        int paso[]={n,-1,-n,1};

        for(int i=0;i<m;i++){
            longi=i%4;
            aux="";
            if(longi==0){
                int pos=-1;
                int vi=0;
                int mod=paso[vi];
                int cont=0;
                int elem=n;
                bool flag=true;
                for(int j=0;j<n;j++){
                    aux+=mensaje.substr(particiones[j],n);
                    particiones[j]+=n;
                }
                for(int j=0;j<longitud[0];j++){
                    pos+=mod;
                    mensajeFinal+=aux[pos];
                    cont++;
                    if(cont==elem){
                        if(flag){
                            elem--;
                            flag=false;
                        }else{
                            flag=true;
                        }
                        if(vi==3){
                            vi=0;
                        }else{
                            vi++;
                        }
                        mod=paso[vi];
                        cont=0;
                    }
                }
            }

            else if(longi==1){
                if(n==2){
                    aux+=mensaje.substr(particiones[0],2);
                    particiones[0]+=2;
                }else{
                    aux+=mensaje.substr(particiones[0],1);
                    particiones[0]++;
                }
                for(int j=1;j<n;j++){
                    if(j<puntoInicio||j==n-1){
                        aux+=mensaje.substr(particiones[j],2);
                        particiones[j]+=2;
                    }else{
                        aux+=mensaje.substr(particiones[j],3);
                        particiones[j]+=3;
                    }
                }
                int pos=(puntoInicio*2)-4;
                for(int j=0;j<n-puntoInicio;j++){
                    pos+=3;
                    mensajeFinal+=aux[pos];
                }
                for(int j=n-1;j>1;j--){
                    if(j<puntoInicio||j==n-1){
                        pos-=2;
                    }else{
                        pos-=3;
                    }
                    mensajeFinal+=aux[pos];
                }
                if(1<puntoInicio){
                    pos--;
                }else{
                    pos-=2;
                }
                mensajeFinal+=aux[pos];
                for(int j=0;j<n-1;j++){
                    if(j<puntoInicio-1||j==n-2){
                        pos+=2;
                    }else{
                        pos+=3;
                    }
                    mensajeFinal+=aux[pos];
                }
            }
            else if(longi==2){
                int pos=(n*puntoInicio)+puntoInicio;
                int vi=0;
                int mod=paso[vi];
                int cont=0;
                int elem=1;
                bool flag=false;
                for(int j=0;j<n;j++){
                    aux+=mensaje.substr(particiones[j],n);
                    particiones[j]+=n;
                }
                mensajeFinal+=aux[pos];
                for(int j=0;j<longitud[0]-1;j++){
                    pos+=mod;
                    mensajeFinal+=aux[pos];
                    cont++;
                    if(cont==elem){
                        if(flag){
                            elem++;
                            flag=false;
                        }else{
                            flag=true;
                        }
                        if(vi==0){
                            vi=3;
                        }else{
                            vi--;
                        }
                        mod=paso[vi];
                        cont=0;
                    }
                }

            }
            else{
                aux+=mensaje.substr(particiones[0],2);
                particiones[0]+=2;
                for(int j=1;j<n-1;j++){
                    aux+=mensaje.substr(particiones[j],3);
                    particiones[j]+=3;
                }
                aux+=mensaje.substr(particiones[n-1],2);
                particiones[n-1]+=2;
                int pos=aux.length()-2;
                mensajeFinal+=aux[pos];
                for(int j=0;j<n-2;j++){
                    pos-=3;
                    mensajeFinal+=aux[pos];
                }
                pos-=2;
                mensajeFinal+=aux[pos];
                for(int j=0;j<n-1;j++){
                    pos+=3;
                    mensajeFinal+=aux[pos];
                }
                pos-=2;
                mensajeFinal+=aux[pos];
                for(int j=0;j<n-2;j++){
                    pos-=3;
                    mensajeFinal+=aux[pos];
                }
            }
        }
        return mensajeFinal;
    }
};

int main(){
    int n,m;
    string mensaje="12345678";
    cout<<"Mensaje a encriptar:\n"<<mensaje<<"\nMensaje encriptado:\n";
    cripto algo(2,2);
    string cipher=algo.encriptamiento(mensaje);
    cout<<cipher;
    cout<<"\nMensaje desencriptado:\n";
    cout<<algo.desencriptamiento(cipher);
    return 0;
}
