#include <iostream>
using namespace std;

int contrasenya(int choice){
    char arr1 [] = "fstream";
    char arr2 [] = "";
    int correct;
    if (choice == 1){
        cout<<"\tIngresar la contrasenya: "<<endl;
        cin>>arr2;
    }
    for (int i = 0; i < 7; i++){
      cout << arr2[i];
      if (arr2[i] == arr1[i]){
        correct = 1;
        i++;
      }
      else if (arr2[i] != arr1[i]){
        correct = 0;
        cout << "\tLa contrasenya es invalida" << endl;
        break;
      }

    }
   return 0;
}

int main(void){
    int seleccion;
    int pass;
    cout<<"\t1-Ingresar al menu principal"<<endl;
    cout<<"\t2-Salir"<<endl;
    cin>>seleccion;
    while (seleccion != 1 && seleccion != 2){
        cout<<"\tIngrese numero 1 o 2"<<endl;
        cin>>seleccion;
    }
    contrasenya(seleccion);
    
  
}