#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define PASSWORD "fstream" // DECLARACION DEFINE
using namespace std;

//enum y sobrecarga de funciones

//define = valor constante

/*Enum se usa cuando se usa un unico tipo de variable*/

//DECLARACIONES DE ESTRUCTURAS
enum mainDish
{
    pizza,
    pasta,
    lasagna
};
enum drink
{
    beer,
    soda,
    tea
};
enum starter
{
    garlicBread,
    pizzaRolls,
    cheeseSticks
};
enum paymentType
{
    cash,
    card
};

struct address
{
    string settlement, municipality, department;
    int houseNumber;
};

struct mainInfo
{
    string name;
    mainDish pDish;
    starter pStarter;
    drink pDrink;
    paymentType pay;
    int idOrder;
    float total;
};

struct delivery
{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
    float toWait;
};

struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
    float toWait;
};

//variables globales
bool isAdmin = false;
int idOrder = 1;


//prototipos
bool loginUser();
void printMenu(void);
void addOrder(vector<delivery> &dlist);
void addOrder(vector <houseOrder> &hList);
void checkOrders(vector<delivery> dList);
void checkOrders(vector<houseOrder> hList);
void dispatchOrders(vector<delivery> &moyList, vector<delivery> &dispatchedlist);
void dispatchOrders(vector<houseOrder> &meuList, vector<houseOrder> &servedlist);
void waitingtime(vector<delivery> myList, float myTime);
void waitingtime(vector<houseOrder> myList, float myTime);
void totalSale(vector<delivery> myList1, vector<houseOrder> myList2, float total);
void deleteOrder(vector<delivery> &dList, int option, int aux);
void deleteMenu(vector<delivery> &dList, vector<houseOrder> &hList);
void deleteOrder(vector<houseOrder> &hList, int option, int aux);



int main(void)
{
    //Declaracion de variables y listas a usar
    int size = 0;
    int option = 0;
    vector<delivery> dList;
    vector<houseOrder> hList;
    vector<delivery>  dispatchedList;
    vector<houseOrder> servedList;
    float totalTime = 0;


    //Verificacion para iniciar sesion
    if (!loginUser())
        return 0;

    //Logica para ejecucion del programa (menu)
    do
    {
        printMenu();
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
            //Agregar ordenes a domicilio
            addOrder(dList);
            break;
        case 2:
            //Agregar ordenes en restaurante
            addOrder(hList);
            break;
        case 3:
            //Revisar ordenes a domicilio
             checkOrders(dList);
            break;
        case 4:
            //Revisar ordenes en restaurante
            checkOrders(hList);
            break;
        case 5:
            //despachar ordenes a domicilio
            dispatchOrders(dList, dispatchedList);
        break;

        case 6:
            //despachar ordenes en restaurante
            dispatchOrders(hList, servedList);
        break;

        case 7:
            //revisar tiempo de espera a domicilio
            waitingtime(dList, totalTime);
        break;

        case 8:
            //revisar tiempo de espera en restaurante
             waitingtime(hList,  totalTime);
        break;

        case 9:
            //muestra el menu para borrar ordenes
            deleteMenu(dList, hList);
        break;

        case 10:
            //Calcular total de ventas
            totalSale(dispatchedList, servedList, totalTime);

        break;

        case 11:
            loginUser();
        break;

        case 12:
            break;

        default:
            break;
        }

    } while (option != 12);

    return 0;
}

bool loginUser()
{
    string enterPasword = "";
    char option;
    cout << "INICIO DE SESION" << endl;
    cout << "A - Administrador " << endl;
    cout << "E - Empĺeado" << endl;
    cout << "Su opción:\t";
    cin >> option;

    switch (option)
    {
    case 'a':
    case 'A':
        cout << "Digite contraseña: ";
        cin >> enterPasword;
        if (enterPasword.compare(PASSWORD) == 0)
        {
            isAdmin = true;
            return true;
        }
        else
        {
            cout << "Contraseña incorrecta" << endl;
        }
        break;
    case 'e':
    case 'E':
        isAdmin = false;
        return true;
        break;
    }
    return false;
}

void printMenu(void)
{
    cout << "\n\nSISTEMA DE DESPACHO PIZZERIA BIG BOX PIZZA" << endl;
    cout << "1. Agregar ordenes a domicilio" << endl;
    cout << "2. Agregar ordenes a restaurante" << endl;
    cout << "3. Ver ordenes a domicilio" << endl;
    cout << "4. Ver ordenes en restaurante" << endl;
    cout << "5. Despachar ordenes a domicilio"<< endl;
    cout << "6. Despachar ordenes en restaurante" << endl;
    cout << "7. Ver tiempo promedio de espera a domicilio" << endl;
    cout << "8. Ver tiempo promedio de espera en restaurante" << endl;
    cout << "9. Cancelar orden (Administrador)" << endl;
    cout << "10. Calcular total de ventas"<< endl;
    cout << "11. Cambiar de usuario" << endl;
    cout << "12. Salir"<< endl;
    cout << "Su opción:\t";
}


//funcion para agregar ordenes a domicilio a la lista
void addOrder(vector<delivery> &dlist)
{
    delivery auxArray;
    int aux = 0, choice = 0;
    
    do{
        cout << "\n1- Ingresar nuevo pedido\n";
        cout << "2- salir\n";
        cout << "Su opcion:\t"; cin >> choice; cin.ignore();
        cout << endl << endl;
        
        if(choice == 1){
        
        cout << "Nombre:\t";
        getline(cin, auxArray.deliveryInfo.name);
        cout << "Dirección\n" << endl;
        cout << "Colonia:\t";
        getline(cin, auxArray.deliveryAddress.settlement);
        cout << "Municipio:\t";
        getline(cin, auxArray.deliveryAddress.municipality);
        cout << "Departamento:\t";
        getline(cin, auxArray.deliveryAddress.department);
        cout << "No. casa:\t";
        cin >> auxArray.deliveryAddress.houseNumber;
        cin.ignore();

        cout << "1 - Pan con ajo" << endl;
        cout << "2 - Pizza rolls" << endl;
        cout << "3 - Palitos de queso" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

    switch(aux){
        case 1:
            auxArray.deliveryInfo.pStarter = garlicBread;
            auxArray.deliveryInfo.total = 3.99;
        break;

        case 2:
            auxArray.deliveryInfo.pStarter = pizzaRolls;
            auxArray.deliveryInfo.total = 4.99;
        break;

        case 3:
            auxArray.deliveryInfo.pStarter = cheeseSticks;
            auxArray.deliveryInfo.total = 3.75;
        break;

        default:
            cout<<"Opcion no valida!\n";
        break;

    }

        cout << "1 - Pizza" << endl;
        cout << "2 - Pasta" << endl;
        cout << "3 - Lasagna" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

            switch(aux)
            {
        case 1:
            auxArray.deliveryInfo.pDish = pizza;
            auxArray.deliveryInfo.total += 13.99;
        break;

        case 2:
            auxArray.deliveryInfo.pDish = pasta;
            auxArray.deliveryInfo.total += 5.55;
        break;

        case 3:
            auxArray.deliveryInfo.pDish = lasagna;
            auxArray.deliveryInfo.total += 6.25;
        break;

        default:
            cout <<"Opcion no valida!\n";
        break;

    }

        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

         switch(aux){
        case 1:
            auxArray.deliveryInfo.pDrink = beer;
            auxArray.deliveryInfo.total += 1.99;
        break;

        case 2:
            auxArray.deliveryInfo.pDrink = soda;
            auxArray.deliveryInfo.total += 0.95;
        break;

        case 3:
            auxArray.deliveryInfo.pDrink = tea;
            auxArray.deliveryInfo.total += 1.15;
        break;

        default:
            cout <<"Opcion no valida!\n";
        break;

    }

        auxArray.deliveryInfo.idOrder = idOrder++;

        if(dlist.empty())
            auxArray.toWait = (1 * 1.35 + 1 * 1.10 + 1 * 1.5) + 15;
        else
            auxArray.toWait = (dlist.size() + 1) * ((1 * 1.35 + 1 * 1.10 + 1 * 1.5) + 15);
        

        cout << "Tipo de pago" << endl;
        cout << "1 - Tarjeta" << endl;
        cout << "2 - Efectivo" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            auxArray.deliveryInfo.pay = card;
        else
            auxArray.deliveryInfo.pay = cash;

        cout << "Telefono: ";
        cin >> auxArray.cellphone;
        cin.ignore();

        dlist.push_back(auxArray);
        
        }
        else
        {
         choice = 2;
         cout << "\tRegresando al menu principal ...\n";
        }
        
        
    }while(choice != 2);
    
}

//funcion para agregar ordenes en restaurante
void addOrder(vector <houseOrder> &hList)
{
    houseOrder array;
    int aux = 0, choice = 0;

    do{ 
        cout << "\n1- Ingresar nuevo pedido\n";
        cout << "2- salir\n";
        cout << "Su opcion:\t"; cin >> choice; cin.ignore();
        cout << endl << endl;

        if(choice == 1){
        cout << "Nombre:\t";
        getline(cin, array.houseInfo.name);
        cout << "Ingrese personas por mesa: ";
        cin >> array.pTable;
        cin.ignore();

        cout << "1 - Pan con ajo" << endl;
        cout << "2 - Pizza rolls" << endl;
        cout << "3 - Palitos de queso" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        switch(aux){
        case 1:
            array.houseInfo.pStarter = garlicBread;
            array.houseInfo.total = 3.99;
        break;

        case 2:
            array.houseInfo.pStarter = pizzaRolls;
            array.houseInfo.total = 4.99;
        break;

        case 3:
            array.houseInfo.pStarter = cheeseSticks;
            array.houseInfo.total = 3.75;
        break;

        default:
            cout<<"Opcion no valida!\n";
        break;

        }

        cout << "1 - Pizza" << endl;
        cout << "2 - Pasta" << endl;
        cout << "3 - Lasagna" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();
        switch(aux)
            {
        case 1:
            array.houseInfo.pDish = pizza;
            array.houseInfo.total += 13.99;
        break;

        case 2:
            array.houseInfo.pDish = pasta;
            array.houseInfo.total += 5.55;
        break;

        case 3:
            array.houseInfo.pDish = lasagna;
            array.houseInfo.total += 6.25;
        break;

        default:
            cout <<"Opcion no valida!\n";
        break;

    }

        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

         switch(aux){
        case 1:
            array.houseInfo.pDrink = beer;
            array.houseInfo.total += 1.99;
        break;

        case 2:
            array.houseInfo.pDrink = soda;
            array.houseInfo.total += 0.95;
        break;

        case 3:
            array.houseInfo.pDrink = tea;
            array.houseInfo.total += 1.15;
        break;

        default:
            cout <<"Opcion no valida!\n";
        break;

    }

        array.houseInfo.idOrder = idOrder++;
        
         if(hList.empty())
            array.toWait = (1 * 1.35 + 1 * 1.10 + 1 * 1.5);
        else
            array.toWait = (hList.size() + 1) * (1 * 1.35 + 1 * 1.10 + 1 * 1.5);

        cout << "Tipo de pago" << endl;
        cout << "1 - Tarjeta" << endl;
        cout << "2 - Efectivo" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            array.houseInfo.pay = card;
        else
            array.houseInfo.pay = cash;

        hList.push_back(array);
        
        }
        else
        {
            choice = 2;
            cout << "Regresando al menu principal....\n"; 
        }
        
    }while(choice != 2);
}

//Funcion recursiva para ver ordenes a domicilio 
void checkOrders(vector<delivery> dList){

    vector<delivery> auxList;
    
    if (dList.empty())
        cout <<"\nNo hay ordenes!";
    else{
        delivery myArray = dList.front();
        cout << "\nId de orden:\t" <<myArray.deliveryInfo.idOrder << endl;
        cout << "Su total es:\t"<< myArray.deliveryInfo.total << endl;
        /*cout << "Entrada:\t" << myArray.deliveryInfo.pStarter << endl;
        cout <<"Plato fuerte:\t"<<myArray.deliveryInfo.pDish << endl;
        cout <<"Bebida:\t" << myArray.deliveryInfo.pDrink << endl;*/
        dList.pop_back();
        checkOrders(dList);
    }
}


//Funcion recursiva para ver ordenes en restaurante
void checkOrders(vector<houseOrder> hList){

      vector<houseOrder> auxList;
    
    if (hList.empty())
        cout <<"\nNo hay ordenes!";
    else{
        houseOrder myArray = hList.back();
        cout << "\nId de orden:\t" <<myArray.houseInfo.idOrder << endl;
        /*cout << "Entrada:\t" << myArray.houseInfo.pStarter << endl;
        cout <<"Plato fuerte:\t"<<myArray.houseInfo.pDish << endl;
        cout <<"Bebida:\t" << myArray.houseInfo.pDrink << endl;*/
        hList.pop_back();
        checkOrders(hList);
    }

}

//Funcion para despachar ordenes a domicilio
void dispatchOrders(vector<delivery> &moyList, vector<delivery> &dispatchedlist){
    delivery myArray;
    if (moyList.empty())
        cout <<"Ordenes despachadas";
    else{
        delivery myArray = moyList.back();
        dispatchedlist.push_back(myArray);
        moyList.pop_back();
        dispatchOrders(moyList, dispatchedlist);

    }

}

//Funcion para despachar ordenes a restaurante
void dispatchOrders(vector<houseOrder> &meuList, vector<houseOrder> &servedlist){
    houseOrder myArray;
        if (meuList.empty())
            cout <<"Ordenes despachadas!\n";
        else{
            houseOrder myArray = meuList.back();
            servedlist.push_back(myArray);
            meuList.pop_back();
            dispatchOrders(meuList, servedlist);
        }
}

//Funcion para ver tiempo total y promedio de espera a domicilio
void waitingtime(vector<delivery> myList, float myTime)
{
    //si la lista esta vacia regresa el valor de tiempo total de espera y el tiempo de espera.
    if (myList.empty()){
        if(myTime <= 0){
            cout<<"No hay tiempo de espera!\n";
            return;
        }
        else{
        cout <<"El tiempo total de espera es:\t" << floor (myTime) << endl;
        cout <<"\nEl tiempo promedio es:\t"<< floor(myTime/(myList.size()+1))<< endl;
        }
    }
        
    else{
        // estructura para guardar informacion en la lista
        delivery auxArray = myList.back();

        myTime = myTime + auxArray.toWait;
        myList.pop_back();
        waitingtime(myList, myTime);
    }
}

//Funcion para ver tiempo total y promedio de espera en restaurante
void waitingtime(vector<houseOrder> myList, float myTime)
{
    //si la lista esta vacia regresa el valor de tiempo total de espera y el tiempo de espera.
    if (myList.empty()){
        if(myTime <= 0){
            cout << "No hay tiempo de espera!\n";
            return;
        }
        else{
        cout <<"El tiempo total de espera es:\t" << floor (myTime) << endl;
        cout <<"\nEl tiempo promedio es:\t"<< floor(myTime/(myList.size()+1))<< endl;
        }
    }
        
    else{
        // estructura para guardar informacion en la lista
        houseOrder auxArray = myList.back();

        myTime = myTime + auxArray.toWait;
        myList.pop_back();
        waitingtime(myList, myTime);
    }
}


//calcular total de ventas en el dia
void totalSale(vector<delivery> myList1, vector<houseOrder> myList2, float total)
{

     if(myList1.empty() && myList2.empty()){
         if (total <= 0)
            cout <<"No hay ventas!\n";
        else{
            cout <<"El total de ventas es:\t" << (total * 0.13) + total << endl;
        }
     }
     else{
         delivery array1 = myList1.back();
         houseOrder array2 = myList2.back();

         total = total + array1.deliveryInfo.total + array2.houseInfo.total;
         myList2.pop_back();
         myList1.pop_back();
         totalSale(myList1, myList2, total);
        }
}

void deleteOrder(vector<delivery> &dList, int option, int aux)
{
    if(dList.empty())
        cout <<"No hay ordenes para borrar\n";
    else{
        if(option == 1)
            dList.pop_back();
        else{
            delivery array = dList.back();
            if(array.deliveryInfo.idOrder == aux){
                dList.pop_back();
            }
            else
                deleteOrder(dList, option, aux);
        }
        }

}

void deleteOrder(vector<houseOrder> &hList, int option, int aux)
{
    if(hList.empty())
        cout <<"No hay ordenes para borrar\n";
    else{
        if(option == 1)
            hList.pop_back();
        else{
            houseOrder array = hList.back();
            if(array.houseInfo.idOrder == aux){
                hList.pop_back();
            }
            else
                deleteOrder(hList, option, aux);
        }
        }

}



void deleteMenu(vector<delivery> &dList, vector<houseOrder> &hList){
       int Deletechoice = 0;
       int selection = 0;
     if(isAdmin == false){
        cout <<"\n***Se necesita ser administrador para borrar ordenes!***\n";
        cout <<"\n\tCambiando usuario...\n\n";
        loginUser();
     }
     else{
        do{
            cout <<"\n\t***Esta a punto de borrar una orden***\n\n";
            cout <<"1. Borrar orden a domicilio\n";
            cout <<"2. Borrar orden en restaurante\n";
            cout <<"0. Salir\n";
            cout <<"Su opcion:\t";
            cin >> Deletechoice; cin.ignore();

            switch(Deletechoice){
                case 1:
                    cout <<"1. Borrar ultima orden\n";
                    cout <<"2. Borrar por ID de orden\n";
                    cout <<"Opcion:\t"; cin >> selection; cin.ignore();
                    if(selection == 1)
                        deleteOrder(dList, 1, 0);
                    else
                    {      
                        cout <<"Ingrese ID de orden a borrar:\t"; cin >> selection;
                        cin.ignore();
                        deleteOrder(dList, 2, selection);
                    }
                break;
                case 2:
                    cout <<"1. Borrar ultima orden\n";
                    cout <<"2. Borrar por ID de orden\n";
                    cout <<"Opcion:\t"; cin >> selection; cin.ignore();
                    if(selection == 1)
                        deleteOrder(hList, 1, 0);
                    else
                    {      
                        cout <<"Ingrese ID de orden a borrar:\t"; cin >> selection;
                        cin.ignore();
                        deleteOrder(hList, 2, selection);
                    }
                break;
                case 0:
                Deletechoice = 0;
                break;
                default:
                    cout <<"\n\t***Seleccione una opcion valida***\n\n";
                break;
            }

     }while(Deletechoice != 0);
     }
}
