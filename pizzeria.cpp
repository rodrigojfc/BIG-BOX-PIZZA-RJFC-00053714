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
    string cust_name, main_dish, side_dish, beverage, payment_meth;
    int num_people, total_am;
};

int menu_selection(int A);
int menu_admin(void);


int main(void){
    int seleccion, admin;
    int size = 0;
    deliver_data *myArrayD;
    rest_data *myArrayR;
    
    seleccion = menu_admin();
    admin =  menu_selection(seleccion);
    if (seleccion == 1){
        cout << "";
    }
    else if(seleccion == 2){
        cout << "Ingrese la cantidad de pedidos: "; cin >> size;
    }
    myArrayD = new deliver_data[size];
    myArrayR = new rest_data[size];
    


  return 0;
}

// funcion para contrasenia

int menu_selection(int A){

    if (A == 3){
         return 0;
    }

    int test = 0;
    string pass;
    
    if (A == 1){
    cout<<"Ingrese la contraseña: "; 
    cin >> pass;
   

   while(test < 3){
        if (pass == "fstream"){
            cout<< "Bienvenido";
            return 1;
        }
        else{
            cout <<"La contraseña es incorrecta!"<< endl;
            cout << "Ingrese la contraseña: ";
            cin >> pass;
            test++;
        }
        }
    }
    else{
        return 2;
    }

return 0;
}

//funcion para cambiar a administrador
int menu_admin(void){
    int seleccion;
    cout<<"\t1-Ingresar como administrador"<<endl;
    cout<<"\t2-Ingresar como empleado"<< endl;
    cout<<"\t3-Salir"<<endl;
    cin>>seleccion;
    while (seleccion != 1 && seleccion != 2 && seleccion !=3){
        cout<<"\tIngrese numero 1, 2 o 3."<<endl;
        cin>>seleccion;
    }  
    return 0;
}

//funcion menu e ingreso de pedidos

void take_menu(deliver_data A_rray,rest_data B_rray, int size){
    int option;
    cout << "\tSeleccione '1' para pedidos en restaurante."<< endl;
    cout << "\tSeleccione '2' para pedidos a domicilio"<< endl;
    cin >> option;
    while (option != 1 && option != 2){
        cout<<"\tSeleccione un numero 1 o 2"<< endl;
        cout << "\tSeleccione '1' para pedidos en restaurante."<< endl;
        cout << "\tSeleccione '2' para pedidos a domicilio"<< endl;
        cin>>option;
    }
    if (option == 1){
        for (int i = 0; i < size; i++){
            cout << "\tIngrese nombre del cliente: "; 
            cin.ignore();
            getline (cin, B_rray.cust_name);
            cout <<"\tIngrese numero de personas: ";
            cin >> B_rray.num_people;
            cout << "\tIngrese plato principal pizza, ensalada o pasta: ";
            cin >> B_rray.main_dish;
            cout <<"\tIngrese bebida: gaseosa o té: "; 
            cin >> B_rray.beverage;
            cout << "\tIngrese entrada nachos o alitas:  ";
            cin >> B_rray.side_dish;
            cout <<"\tIngrese monto o total: ";
            cin >> B_rray.total_am;
            cout << "Ingrese tipo de pago, tarjeta o efectivo: ";
            cin >> B_rray.payment_meth;
        }
        }

}