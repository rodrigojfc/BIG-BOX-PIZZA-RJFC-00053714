#include <iostream>
using namespace std;


struct cust_data{
    int house_num;
    string  colonia, city, state;
};

struct deliver_data{
    string cust_name, payment_meth;
    cust_data customer;
    int phone_num, total_am, meal, beverage, side_dish;

};

struct rest_data{
    string cust_name;
    int num_people, main_dish, side_dish, total_am;
};


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
  
}