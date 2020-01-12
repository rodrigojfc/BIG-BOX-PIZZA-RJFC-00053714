#include <iostream>
using namespace std;

void contrasenya(){
    int seleccion;
    cout<<"\t1-Ingresar al menu principal"<<endl;
    cout<<"\t2-Salir"<<endl;
    cin>>seleccion;
    while (seleccion != 1 && seleccion != 2){
        cout<<"\tIngrese numero 1 o 2"<<endl;
        cin>>seleccion;
    }
}

int main(void){
    contrasenya();
}