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
vector<houseOrder> hList;


//prototipos

bool loginUser();
void printMenu(void);
void addOrder(vector<delivery> dlist);
void addOrder(vector <houseOrder> hList);

int main(void)
{
    //Declaracion de variables y arreglos a usar
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
        addOrder(dList);
            break;
        case 2:
            addOrder(hList);
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

void addOrder(vector<delivery> dlist)
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
        
        dList.push_back(auxArray);}
        else
        {
         choice = 2;
         cout << "\tRegresando al menu principal ...\n";
        }
        
        
    }while(choice != 2);
    
}

void addOrder(vector <houseOrder> hList)
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

        if (aux == 1)
            array.houseInfo.pStarter = garlicBread;
        else if (aux == 2)
            array.houseInfo.pStarter = pizzaRolls;
        else
            array.houseInfo.pStarter = cheeseSticks;

        cout << "1 - Pizza" << endl;
        cout << "2 - Pasta" << endl;
        cout << "3 - Lasagna" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            array.houseInfo.pDish = pizza;
        else if (aux == 2)
            array.houseInfo.pDish = pasta;
        else
            array.houseInfo.pDish = lasagna;

        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opción:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 1)
            array.houseInfo.pDrink = beer;
        else if (aux == 2)
            array.houseInfo.pDrink = soda;
        else
            array.houseInfo.pDrink = tea;

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

        cout << "Monto: ";
        cin >> array.houseInfo.total;
        cin.ignore();

        hList.push_back(array);
        
        }
        else
        {
            choice = 2;
            cout << "Saliendo....\n"; 
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
