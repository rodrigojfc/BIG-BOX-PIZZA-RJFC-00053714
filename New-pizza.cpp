#include <iostream>
#include <string>
#include <vector>
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


int main(void)
{
    //Declaracion de variables y listas a usar
    int size = 0;
    int option = 0;
    vector<delivery> dList;
    vector<houseOrder> hList;
    vector<delivery>  dispatchedList;
    vector<houseOrder> servedList;


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
            addOrder(hList);
            break;
        case 3:
             checkOrders(dList);
            break;
        case 4:
            checkOrders(hList);
            break;
        case 5:
            dispatchOrders(dList, dispatchedList);
        break;

        case 6:
            dispatchOrders(hList, servedList);
        break;

        case 7:
        break;

        case 8:
        break;

        case 9:
        break;

        case 10:
        break;

        case 11:
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

void searchByName(delivery *array, int size)
{
    string aux = "";
    bool userExists = false;
    cout << "Nombre a buscar: ";
    getline(cin, aux);

    for (int i = 0; i < size; i++)
    {
        if (aux.compare(array[i].deliveryInfo.name) == 0)
        {
            //Imprimir datos del pedido
            userExists = true;
        }
    }
    (!userExists) ? cout << "No existe el usuario" : cout << "";
}

void searchByName(houseOrder *array, int size)
{
    string aux = "";
    bool userExists = false;
    cout << "Nombre a buscar: ";
    getline(cin, aux);

    for (int i = 0; i < size; i++)
    {
        if (aux.compare(array[i].houseInfo.name) == 0)
        {
            //Imprimir datos del pedido

            userExists = true;
        }
    }
    (!userExists) ? cout << "No existe el usuario" : cout << "";
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

void 