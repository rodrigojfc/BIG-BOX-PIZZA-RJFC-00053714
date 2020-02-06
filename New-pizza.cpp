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
};

struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
};

//variables globales
bool isAdmin = false;
int idOrder = 1;
vector<delivery> dList;

//prototipos

bool loginUser();
void printMenu(void);
void addOrder(delivery *array, vector<delivery> mylist);
//void addOrder(houseOrder *array);

int main(void)
{
    //Declaracion de variables y arreglos a usar
    vector<houseOrder> *hList;
    delivery *dArray;
    houseOrder* hArray;
    int size = 0;
    int option = 0;
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
        addOrder(dArray, dList);
            break;
        case 2:
            //addOrder(hArray);
            break;
        case 3:
            break;
        case 4:
            break;

        case 0:
            break;

        default:
            break;
        }

    } while (option != 0);

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
    cout << "0. Salir"<< endl;
    cout << "Su opción:\t";
}

void addOrder(delivery *array, vector<delivery> mylist)
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

        if (aux == 1)
            auxArray.deliveryInfo.pStarter = garlicBread;
        else if (aux == 2)
            auxArray.deliveryInfo.pStarter = pizzaRolls;
        else
            auxArray.deliveryInfo.pStarter = cheeseSticks;

        cout << "1 - Pizza" << endl;
        cout << "2 - Pasta" << endl;
        cout << "3 - Lasagna" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            auxArray.deliveryInfo.pDish = pizza;
        else if (aux == 2)
            auxArray.deliveryInfo.pDish = pasta;
        else
            auxArray.deliveryInfo.pDish = lasagna;

        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            auxArray.deliveryInfo.pDrink = beer;
        else if (aux == 2)
            auxArray.deliveryInfo.pDrink = soda;
        else
            auxArray.deliveryInfo.pDrink = tea;

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

        cout << "Monto: ";
        cin >> auxArray.deliveryInfo.total;
        cin.ignore();
        cout << "Telefono: ";
        cin >> auxArray.cellphone;
        cin.ignore();
        
        mylist.push_back(auxArray);}
        else 
            choice = 2;
    }while(choice != 2);
    
}

void addOrder(houseOrder* array)
{
    int size = 0;
    int aux = 0;
    cout << "Cantidad de pedidos a ingresar: ";
    cin >> size;
    cin.ignore();

    array = new houseOrder[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Nombre:\t";
        getline(cin, array[i].houseInfo.name);
        cout << "Ingrese personas por mesa: ";
        cin >> array[i].pTable;
        cin.ignore();

        cout << "1 - Pan con ajo" << endl;
        cout << "2 - Pizza rolls" << endl;
        cout << "3 - Palitos de queso" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            array[i].houseInfo.pStarter = garlicBread;
        else if (aux == 2)
            array[i].houseInfo.pStarter = pizzaRolls;
        else
            array[i].houseInfo.pStarter = cheeseSticks;

        cout << "1 - Pizza" << endl;
        cout << "2 - Pasta" << endl;
        cout << "3 - Lasagna" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            array[i].houseInfo.pDish = pizza;
        else if (aux == 2)
            array[i].houseInfo.pDish = pasta;
        else
            array[i].houseInfo.pDish = lasagna;

        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            array[i].houseInfo.pDrink = beer;
        else if (aux == 2)
            array[i].houseInfo.pDrink = soda;
        else
            array[i].houseInfo.pDrink = tea;

        array[i].houseInfo.idOrder = idOrder++;

        cout << "Tipo de pago" << endl;
        cout << "1 - Tarjeta" << endl;
        cout << "2 - Efectivo" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            array[i].houseInfo.pay = card;
        else
            array[i].houseInfo.pay = cash;

        cout << "Monto: ";
        cin >> array[i].houseInfo.total;
        cin.ignore();
    }
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
