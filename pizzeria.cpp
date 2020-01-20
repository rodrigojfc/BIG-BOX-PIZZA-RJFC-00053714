#include <iostream> //input  output
#include <string>//string variable
using namespace std;

//Estructura anidada
struct cust_data{
    int house_num;
    string  colonia, city, state;
};

// Estructura pedido a domicilio    
struct deliver_data{
    string cust_name, payment_meth;
    cust_data customer;
    int phone_num, total_am, meal, beverage, side_dish;

};

//Estructura pedido restaurante

struct rest_data{
    string cust_name;
    int num_people, main_dish, side_dish, total_am;
};

void menu_selection(int A);


int main(void){
    int seleccion;

    cout<<"\t1-Ingresar al menu principal"<<endl;
    cout<<"\t2-Salir"<<endl;
    cin>>seleccion;
    while (seleccion != 1 && seleccion != 2){
        cout<<"\tIngrese numero 1 o 2"<<endl;
        cin>>seleccion;
    }    
    menu_selection(seleccion);
    

  return 0;
}

// funcion para contrasenia

void menu_selection(int A){

    if (A == 2){
         return;
    }

    int test = 0;
    string pass;
    
    cout<<"Ingrese la contraseña: "; 
    cin >> pass;
   

   while(test < 3){
        if (pass == "fstream"){
            cout<< "Bienvenido";
            break;
        }
        else{
            cout <<"La contraseña es incorrecta!"<< endl;
            cout << "Ingrese la contraseña: ";
            cin >> pass;
            test++;
        }
        }
  

}