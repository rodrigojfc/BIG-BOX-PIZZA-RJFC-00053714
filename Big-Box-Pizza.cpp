#include <iostream> // input & output
#include <string> //String types
#include <vector> //listas
#include <cmath> //floor function
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
    int howMuch;
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
void dispatchOrders(vector<delivery> &moyList, vector<delivery> &dispatchedlist, int aux);
void dispatchOrders(vector<houseOrder> &meuList, vector<houseOrder> &servedlist, int aux);
void waitingtime(vector<delivery> myList, float myTime);
void waitingtime(vector<houseOrder> myList, float myTime);
float totalSale(vector<delivery> myList1, int total);
float totalSale(vector<houseOrder> myList1, int total);
void deleteOrder(vector<delivery> &dList, int option, int aux, string auxString);
void deleteMenu(vector<delivery> &dList, vector<houseOrder> &hList);
void deleteOrder(vector<houseOrder> &hList, int option, int aux, string auxString);
void dispatchMenu(vector<delivery> &myList, vector<delivery> &dmyList);
void dispatchMenu(vector<houseOrder> &myList, vector<houseOrder> &dmyList);



int main(void)
{
    //Declaracion de variables y listas a usar
    int size = 0;
    int option = 0;
    vector<delivery> dList;
    vector<houseOrder> hList;
    vector<delivery>  dispatchedList;
    vector<houseOrder> servedList;
    float totalTime = 0, totalSales = 0;


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
            dispatchMenu(dList, dispatchedList);
        break;

        case 6:
            //despachar ordenes en restaurante
            dispatchMenu(hList, servedList);
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
            totalSales = totalSale(dispatchedList, totalTime) + totalSale(servedList, totalTime);
            cout <<"\n\tTotal de ventas es:\t$" << totalSales << endl; 

        break;

        case 11:
            //Cambiar de usario
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


//funcion que cambia el usuario para poder borrar ordenes
bool loginUser()
{
    string enterPasword = "";
    char option;
    cout << "\n\t***INICIO DE SESION***\n" << endl;
    cout << "\tA - Administrador " << endl;
    cout << "\tE - Empĺeado" << endl;
    cout << "\tSu opción:\t";
    cin >> option;

    switch (option)
    {
    case 'a':
    case 'A':
        cout << "\n\tDigite contraseña: ";
        cin >> enterPasword;
        if (enterPasword.compare(PASSWORD) == 0)
        {
            isAdmin = true;
            return true;
        }
        else
        {
            cout << "\n\t***Contraseña incorrecta***\n" << endl;
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
    cout << "\n\n\t***SISTEMA DE DESPACHO PIZZERIA BIG BOX PIZZA***\n" << endl;
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
            auxArray.toWait = (dlist.size() + 2) * ((1 * 1.35 + 1 * 1.10 + 1 * 1.5) + 15);
        

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
    //Revisa si la orden esta vacia como condicion de salida    
    if (dList.empty()){
        cout<<"\n\t***No hay ordenes***\n";
        return;
    }
    else{
        delivery myArray = dList.back();
        cout <<"\nNombre del cliente:\t" << myArray.deliveryInfo.name << endl;
        cout << "\nId de orden:\t" <<myArray.deliveryInfo.idOrder << endl;
      
        switch(myArray.deliveryInfo.pStarter){
            case cheeseSticks:
                cout << "Entrada:\tPalitos de queso"<<endl;
            break;
            case garlicBread:
                cout << "Entrada:\tPan con ajo"<< endl;
            break;
            case pizzaRolls:
                cout << "Entrada:\tPizza rolls"<<endl;
            break;
        }

            switch(myArray.deliveryInfo.pDish){
            case pizza:
                cout << "Plato fuerte:\tPizza"<<endl;
            break;
            case lasagna:
                cout << "Plato fuerte:\tLasagna"<< endl;
            break;
            case pasta:
                cout << "Plato fuerte:\tPasta"<<endl;
            break;
        }

        switch(myArray.deliveryInfo.pDrink){
            case beer:
                cout << "Bebida:\tCerveza"<<endl;
            break;
            case soda:
                cout << "Bebida:\tSoda"<< endl;
            break;
            case tea:
                cout << "Bebida:\tTe helado"<<endl;
            break;
        }

        cout << "El total es:\t$"<< myArray.deliveryInfo.total << endl;
        cout << "Tiempo de espera:\t" <<floor (myArray.toWait) <<" minutos" << endl;

        
        dList.pop_back();
        checkOrders(dList);
    }
}


//Funcion recursiva para ver ordenes en restaurante
void checkOrders(vector<houseOrder> hList){
    //Revisa si la orden esta vacia como condicion de salida    
    if (hList.empty())
        cout <<"\n\t***No hay ordenes!***";
    else{
        houseOrder myArray = hList.back();
        cout <<"\nNombre del cliente:\t" << myArray.houseInfo.name << endl;
        cout << "\nId de orden:\t" <<myArray.houseInfo.idOrder << endl;
      
        switch(myArray.houseInfo.pStarter){
            case cheeseSticks:
                cout << "Entrada:\tPalitos de queso"<<endl;
            break;
            case garlicBread:
                cout << "Entrada:\tPan con ajo"<< endl;
            break;
            case pizzaRolls:
                cout << "Entrada:\tPizza rolls"<<endl;
            break;
        }

            switch(myArray.houseInfo.pDish){
            case pizza:
                cout << "Plato fuerte:\tPizza"<<endl;
            break;
            case lasagna:
                cout << "Plato fuerte:\tLasagna"<< endl;
            break;
            case pasta:
                cout << "Plato fuerte:\tPasta"<<endl;
            break;
        }

        switch(myArray.houseInfo.pDrink){
            case beer:
                cout << "Bebida:\tCerveza"<<endl;
            break;
            case soda:
                cout << "Bebida:\tSoda"<< endl;
            break;
            case tea:
                cout << "Bebida:\tTe helado"<<endl;
            break;
        }

        cout << "El total es:\t$"<< myArray.houseInfo.total << endl;
        cout << "Tiempo de espera:\t" <<floor (myArray.toWait) <<" minutos" << endl;

        
        hList.pop_back();
        checkOrders(hList);
    }

}

//Funcion para despachar ordenes a domicilio
void dispatchOrders(vector<delivery> &moyList, vector<delivery> &dispatchedlist, int aux){

    //Condicion de salida
    if (moyList.empty()){
        cout<<"\n\t***No hay ordenes***\n";
        return;
    }

    else{
        //Se despachan todas las ordenes recursivamente
        if(aux == 1){
        delivery myArray = moyList.back();
        dispatchedlist.push_back(myArray);
        moyList.pop_back();
        dispatchOrders(moyList, dispatchedlist, aux);
        }
        else
        {
            //se depacha la ultima orden
            delivery myArray = moyList.back();
            dispatchedlist.push_back(myArray);
            moyList.pop_back();
            cout<<"\n\t***Orden despachada***";
        }
    }

}

//Funcion para despachar ordenes a restaurante
void dispatchOrders(vector<houseOrder> &myList, vector<houseOrder> &servedlist, int aux){
        if (myList.empty()){
        cout<<"\n\t***No hay ordenes***\n";
        return;
        }
        else{
            if(aux == 1){
            //Se despachan todas las ordenes recursivamente
            houseOrder myArray = myList.back();
            servedlist.push_back(myArray);
            myList.pop_back();
            dispatchOrders(myList, servedlist, aux);
            }
            else{
                //se depacha la ultima orden
                houseOrder myArray = myList.back();
                servedlist.push_back(myArray);
                myList.pop_back();
                cout <<"\n\t***Orden despachada***\n";
            }
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
        cout <<"El tiempo total de espera es:\t" << floor (myTime) << " minutos"<< endl;
        cout <<"\nEl tiempo promedio es:\t"<< floor(myTime/(myList.size()+2))<< " minutos"<< endl;
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
        cout <<"El tiempo total de espera es:\t" << floor (myTime) << " minutos"<< endl;
        cout <<"\nEl tiempo promedio es:\t"<< floor(myTime/(myList.size()+2))<< " minutos" <<endl;
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

//calcular total de ventas en el dia en la lista de domicilio
float totalSale(vector<delivery> myList1, int total)
{

     if(myList1.empty()){
         if (total <= 0)
            return 0;
        else{ 
            return (total * 0.13) + total;
        }
     }
     else{
        // estructura para guardar informacion en la lista
         delivery array1 = myList1.back();

         total = total + array1.deliveryInfo.total;
         myList1.pop_back();
         totalSale(myList1, total);
        }
}
//calcular total de ventas en el dia en la lista de domicilio
float totalSale(vector<houseOrder> myList1, int total){
      if(myList1.empty()){
         if (total <= 0)
            return 0;
        else{ 
            return (total * 0.13) + total;
        }
     }
     else{
          // estructura para guardar informacion en la lista
         houseOrder array1 = myList1.back();

         total = total + array1.houseInfo.total;
         myList1.pop_back();
         totalSale(myList1, total);
        }
}

//funcion para borrar ordenes a domicilio
void deleteOrder(vector<delivery> &dList, int option, int aux, string auxString)
{
    if(dList.empty())
        cout <<"\n\t***No hay ordenes para borrar***\n";
    else{
        if(option == 1){
            dList.pop_back();
            cout <<"\n\t***Ultima orden Borrada***\n";
        }
        else if(option == 2){
            for (auto iter = dList.begin(); iter != dList.end(); iter++){
                if(aux == iter->deliveryInfo.idOrder){
                    dList.erase(iter);
                    cout <<"\n\t***Orden Borrada***\n";
                }
                else
                    iter++;
            }            
        }
        else{
            for (auto iter = dList.begin(); iter != dList.end(); iter++){
                if(iter->deliveryInfo.name.compare(auxString)){ 
                    dList.erase(iter);
                    cout <<"\n\t***Orden Borrada***\n";
                }
                else
                    iter++;       
            }
        }
        }

}

//funcion para borrar ordenes en restaurantes
void deleteOrder(vector<houseOrder> &hList, int option, int aux, string auxString)
{
    if(hList.empty())
        cout <<"\n\t***No hay ordenes para borrar***\n";
    else{
        if(option == 1)
            hList.pop_back();
        else if(option == 2){
            for (auto iter = hList.begin(); iter != hList.end(); iter++){
                if(aux == iter->houseInfo.idOrder){
                    hList.erase(iter);
                    cout <<"\n\t***Orden borrada***\n";
                }
                else
                    iter++;
            }            
        }
        else{
            for (auto iter = hList.begin(); iter != hList.end(); iter++){
                if(iter->houseInfo.name.compare(auxString)){
                    hList.erase(iter);
                    cout <<"***\n\tOrden borrada***\n";
                }
                else
                    iter++;
            }
        }
        }

} 


//funcion menu para borrar ordenes
void deleteMenu(vector<delivery> &dList, vector<houseOrder> &hList){
        //variables para guardar informacion del pedido a eliminar
       int Deletechoice = 0;
       int selection = 0;
       string nameDelete = "";
       
       //se revisa que el usuario que intenta borrar la orden sea administrador
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
                    cout <<"\n\n1. Borrar ultima orden\n";
                    cout <<"2. Borrar por ID de orden\n";
                    cout <<"3. Borrar por nombre\n";
                    cout <<"Opcion:\t"; cin >> selection; cin.ignore();
                    if(selection == 1)
                        deleteOrder(dList, 1, 0, " ");
                    else if(selection == 2){
                        cout <<"\nIngrese ID de orden a buscar:\t"; cin >> selection; cin.ignore(); 
                        deleteOrder(dList, 2, selection, " ");
                    }
                    else
                    {      
                        cout <<"\nIngrese nombre de cliente para borrar orden:\t"; getline(cin, nameDelete);
                        cin.ignore();
                        deleteOrder(dList, 3, 0, nameDelete);
                    }
                break;
                case 2:
                    cout <<"\n\n1. Borrar ultima orden\n";
                    cout <<"2. Borrar por ID de orden\n";
                    cout <<"3. Borrar por nombre\n";
                    cout <<"Opcion:\t"; cin >> selection; cin.ignore();
                    if(selection == 1)
                        deleteOrder(hList, 1, 0, " ");
                    else if(selection == 2){
                        cout <<"\nIngrese ID de orden a buscar:\t"; cin >> selection; cin.ignore(); 
                        deleteOrder(hList, 2, selection, " ");
                    }
                    else
                    {      
                        cout <<"\nIngrese nombre de cliente para borrar orden:\t"; getline(cin, nameDelete);
                        cin.ignore();
                        deleteOrder(hList, 3, 0, nameDelete);
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

void dispatchMenu(vector<delivery> &myList, vector<delivery> &dmyList){
    int decision = 0;
    
    cout <<"\n1. Despachar todas las ordenes\n";
    cout <<"2. Despachar ultima orden\n";
    cout <<"Su opcion:\t"; cin >> decision; cin.ignore();

    switch(decision){
        case 1:
            dispatchOrders(myList, dmyList, decision);
        break;

        case 2:
            dispatchOrders(myList, dmyList, decision);
        break;
        default:
            cout<<"\n\t***Opcion no valida***";
        break;

    }
}

void dispatchMenu(vector<houseOrder> &myList, vector<houseOrder> &dmyList){
    int decision = 0;
    
    cout <<"\n1. Despachar todas las ordenes\n";
    cout <<"2. Despachar ultima orden\n";
    cout <<"Su opcion:\t"; cin >> decision; cin.ignore();

    switch(decision){
        case 1:
            dispatchOrders(myList, dmyList, decision);
        break;

        case 2:
            dispatchOrders(myList, dmyList, decision);
        break;
        default:
            cout<<"\n\t***Opcion no valida***";
        break;

    }
}