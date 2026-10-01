#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
//Lista inventario
struct nodo{
    char nombre[20];
    int clave;
    float precio;
    int cantidad;
	struct nodo *siguiente;
    int cantidad2;
    //arboles
    struct nodo *izq, *der,*padre;
}*primero, *ultimo;
//Cola Clientes
struct Nodo{
    char cliente[15];
	char orden[30];
	char nombre[20];
	int numero;
	int cantidad2;
	int cantidad;
	int clave;
	float total;
	Nodo *siguiente;
}*frente,*fin;

void menu();
int RegistrarProducto();
void imprimeInventario();
void MenuInventario();
void MenuPedido();
void MenuCliente();
void registarCliente();
void mostrarPedido();
void eliminar();
void eliminarProducto();
void ordenarProducto();
nodo* buscarProducto();
void mostrarProducto(nodo*producto);
void buscarCliente();
void ordenarClientes();
void mostrarOrden(int [100], int);
void QuickSort(int [100],int, int);
nodo *crearNodo(int,nodo *);
void insertarNodo(nodo *&,int,nodo *);
void mostrarArbol(nodo *,int);
void OrdenarClientesPorCompra(Nodo*& inicio);
void mostrarClientesConMayorCompra();
void ordenarClientesPorInsercion(Nodo*& inicio);
nodo *arbol = NULL;
int main(){
 system("color f4");
    int opcion,opcion1,opcion2,opcion3,contador=0;
    char rpt;
    do {
        menu();
        cin >> opcion;
        switch (opcion){
        case 1:system("cls");
           do{system("cls");
            MenuInventario();
            cin>>opcion1;
            switch (opcion1){
            case 1: system("cls");
			cout <<"\n\tREGISTRAR PRODUCTOS\n";
                RegistrarProducto();
                system("pause");
                break;
            case 2:system("cls");
                ordenarProducto();
                imprimeInventario();
                cout<<"\n\n\tCantidades de STOCK de mayor a menor\n";
                mostrarArbol(arbol,contador);
                system("pause");
                break;
            case 3:{system("cls");
	    			nodo*resultadoBusqueda = buscarProducto();
	    			mostrarProducto(resultadoBusqueda);
	    			system("pause");
				    break; }   
            case 4:system("cls");
                break;
                default:
                cout<<"Opcion no valida..."<<endl;
                }}while(opcion1!=4);
                break;
        case 2:system("cls");
				do{system("cls");
                MenuPedido();
				cin>>opcion2;
				switch(opcion2){
            case 1:system("cls");
                registarCliente();
                system("pause");
                break;
            case 2:system("cls");
                mostrarPedido();
                system("pause");
                break;
            case 3:system("cls");
					cout<<"\n\tPEDIDO ELIMINADO\n";
		            eliminar();
		            system("pause");
                break;
            case 4: system("cls");
                break;
                default:
                cout<<"Opcion no valida!"<<endl;
                }}while(opcion2!=4);
                break;
        case 3:system("cls");
        do {system("cls");
        	MenuCliente();
        	cin>>opcion3;
			switch(opcion3){
        	case 1: system("cls");
                    buscarCliente();
                    system("pause");
                    break;
            case 2: system("cls");
                    ordenarClientes();
                    system("pause");
                    break;
             case 3: system("cls");
	                mostrarClientesConMayorCompra();
	                system("pause");
                    break;                                       
            case 4: system("cls");
                break;
                default:
                cout<<"Opcion no valida..."<<endl;
                }}while(opcion3!=4);
                break;     
        case 4:cout << "\n\n\tFIN DEL PROGRAMA" << endl;
                break;                
            default:
                cout << "\n\nOPCION NO VALIDA" << endl;
                break;
        }}while (opcion !=4);
    return 0;   
}
void menu(){
    cout<<" \t|----------------------------------------- |\n";
    cout<<" \t|           TAQUERIA 'TACOS PACOS'         |\n";
    cout<<" \t|------------------------------------------|\n";
    cout<<" \t|\t     Menu principal                |\n";
    cout<<" \t|  1. Inventario                           |\n";
    cout<<" \t|  2. Pedidos                              |\n";
    cout<<" \t|  3. Clientes                             |\n";
    cout<<" \t|  4. Salir	                           |\n";
    cout<<" \t|------------------------------------------|\n";
    cout<<"\t Ingrese opcion: ";
}
void MenuInventario(){
        cout<<"\n MENU INVENTARIO";
        cout<<"\n 1. Registrar productos. "<<endl;
        cout<<"\n 2. Ver lista de productos. "<<endl;
        cout<<"\n 3. Buscar en la lista de productos. "<<endl;
        cout<<"\n 4. Volver al menu principal. "<<endl;
        cout<<"\n Ingrese opcion: ";
}
void MenuPedido(){
	cout<<"\n MENU PEDIDOS";
    cout<<"\n 1. Registar pedido \n";
    cout<<"\n 2. Ver pedidos \n";
    cout<<"\n 3. Borrar primer pedido \n";
    cout<<"\n 4. Volver al menu principal \n";
    cout<<"\n Ingrese opcion: ";
}
void MenuCliente(){
	cout<<"\n MENU CLIENTES";
    cout<<"\n 1. Buscar Cliente \n";
    cout<<"\n 2. Ordenar Clientes en mesas\n";
    cout<<"\n 3. Ver Clientes con Mayor Compra\n";
    cout<<"\n 4. Volver al menu principal \n";
    cout<<"\n Ingrese opcion: ";
}
int RegistrarProducto(){
    //Listas
nodo* nuevo= new nodo(); 
    cin.ignore();
	cout<<"\nNombre del producto: ";cin.getline(nuevo->nombre,30);
	cout <<"\nClave del producto:";cin >> nuevo->clave;
    cout << "\nPrecio: "; cin >> nuevo->precio;
    cout << "\nCantidad: "; cin >> nuevo->cantidad;
    insertarNodo(arbol,nuevo->cantidad,NULL);

	if(primero==NULL){
		primero=nuevo;
		primero->siguiente=NULL;
		ultimo=nuevo;
	}else{
		ultimo->siguiente=nuevo;
		nuevo->	siguiente=NULL;
		ultimo=nuevo;
	}
	cout<<"\n\tPRODUCTO GUARDADO!\n\n";
	return 0;
}

void ordenarProducto(){
	//Ordenamiento Burbuja
	nodo *actual, *siguiente;
    int tempClave;
    float tempPrecio;
    char tempNombre[20];
    int tempCantidad;

    actual = primero;

    while (actual->siguiente != NULL) {
        siguiente = actual->siguiente;

        while (siguiente != NULL) {
            if (actual->clave > siguiente->clave) {
                tempClave = actual->clave;
                actual->clave = siguiente->clave;
                siguiente->clave = tempClave;

                tempPrecio = actual->precio;
                actual->precio = siguiente->precio;
                siguiente->precio = tempPrecio;

 				tempCantidad = actual->cantidad;
                actual->cantidad = siguiente->cantidad;
                siguiente->cantidad = tempCantidad;
                
                strcpy(tempNombre, actual->nombre);
                strcpy(actual->nombre, siguiente->nombre);
                strcpy(siguiente->nombre, tempNombre);
            }

            siguiente = siguiente->siguiente;
        }

        actual = actual->siguiente;
    }
	
}

nodo* buscarProducto() {
	//Busqueda Binaria
    cout << "\n\tBUSCAR PRODUCTO POR CLAVE\n";
    int claveBusqueda;
    cout << "\nIngrese la clave del producto a buscar: ";
    cin >> claveBusqueda;
    nodo* inicio = primero;
    nodo* fin = NULL;

    while (inicio != fin) {
        nodo* medio = inicio;
        int steps = 0;

        while (medio->siguiente != fin && steps < 2) {
            medio = medio->siguiente;
            steps++;
        }

        if (medio->clave == claveBusqueda) {
            return medio;
        }

        if (medio->clave < claveBusqueda) {
            inicio = medio->siguiente;
        } else {
            fin = medio;
        }
    }
    return NULL; 
}
void mostrarProducto(nodo* producto) {
    if (producto != NULL) {
        cout<< "\n\tPRODUCTO ENCONTRADO\n";
        cout<<"--------------------------------------\n";
        cout<< "Nombre: " << producto->nombre << "\n";
        cout<< "Clave: " << producto->clave << "\n";
        cout<< "Precio: " << producto->precio << "\n";
        cout<< "Cantidad: " << producto->cantidad << "\n";
        cout<<"--------------------------------------\n";
    } else {
        cout<< "\n\tPRODUCTO NO ENCONTRADO!!\n\n";
    }
}

//Funcion para crear el nodo
nodo *crearNodo(int n,nodo *padre){
	nodo *nuevo_nodo = new nodo();

	nuevo_nodo->cantidad = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;

	return nuevo_nodo;
}

//Funcion para insertar el nodo
void insertarNodo(nodo *&arbol, int n, nodo *padre){
	if(arbol == NULL){
		nodo *nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->cantidad;
		if(n<valorRaiz){
			insertarNodo(arbol->izq,n,arbol);
		}
		else{
			insertarNodo(arbol->der,n,arbol);
		}
	}
}

//Funcion para mostrar arbol
void mostrarArbol(nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->cantidad<<endl;
		mostrarArbol(arbol->izq, cont+1);
	}
}
void imprimeInventario(){
    cout << "\n             I N V E N T A R I O         " ;
    cout << "\n---------------------------------------";
    nodo* actual = new nodo();
	actual=primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout<<"\nProducto:"<<actual->nombre;
			cout<<"\nClave:"<<actual->clave;
			cout<<"\nPrecio:"<<actual->precio;
			cout<<"\nCantidad:"<<actual->cantidad<<endl;
			cout<<"--------------------------------------";
			actual=actual->siguiente;
		}
	}else{
		cout<<"\n\tNo hay productos en stock!!";
	}
}
void MenuRestaurante(){
    		cout << "\n\t M E N U \n" ;
    		cout<<"\n----------------------------------------\n";
    nodo* actual = new nodo();
	actual=primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout<<"\nProducto:"<<actual->nombre;
			cout<<"\t - Clave :"<<actual->clave;
			cout<<"\t - Precio:"<<actual->precio;
			cout<<"\n-----------------------------------------\n";		
			actual=actual->siguiente;
		}
	}else{
		cout<<"\n\tNO HAY PRODUCTOS PARA MOSTRAR\n";
	}
}

void registarCliente(){
    int total;
    Nodo *Nuevo = new Nodo();
	cin.ignore();
	cout<<"\n\tAGREGANDO UN NUEVO CLIENTE\n"<<endl;
	cout<<"\nNombre del cliente: "; cin.getline(Nuevo->cliente,15);
	cout<<"\nNumero de cliente:";cin>>Nuevo->numero;
	cout<<"\n\tNUESTRO MENU ES:"<<endl;
	MenuRestaurante();
    cin.ignore();
    cout<<"\nProducto que desea comprar: ";cin.getline(Nuevo->orden,30);
    cout<<"\nCantidad: ";cin>>Nuevo->cantidad2;
    nodo* actual=new nodo();
	actual=primero;
	bool encontrado=false;
	int clave=0;

    cout<<"\nClave del producto:";cin>>clave;
	if(primero!=NULL){
		while(actual!=NULL && encontrado!=true){
			if(actual->clave==clave){
				if (actual->cantidad < Nuevo -> cantidad2){
					cout<<"\n\n\tNo hay suficiente cantidad en el inventario para completar el pedido \n ";
					cout << "\n\n\tPEDIDO NO EXITOSO\n";
					return;
				}
	actual->cantidad -= Nuevo->cantidad2;
    float total= actual->precio * Nuevo->cantidad2;
     Nuevo -> total = total;
    cout<<"\n\t\t\tPEDIDO EXITOSO";
    cout<<"\n\t\t\t**********************";
    cout<<"\n\t\t\tEl total de su compra es de:$"<<total;
    cout<< "\n\t\t\tGRACIAS POR SU COMPRA!" << endl;
    //Colas
	Nuevo->siguiente = NULL;
	if(frente == NULL){
		frente = Nuevo;
	}
	else{
		fin->siguiente = Nuevo;
	}
	fin = Nuevo;
	encontrado=true;
    }
			actual=actual->siguiente;
		}
				if(!encontrado){
			cout<<"\n\tNO HAY PRODUCTO";
		}
	}else{
		cout<<"\n\tEl menu aun no esta disponible";
		cout<<"\n\tPedido NO exitoso";
	}
}
void mostrarPedido(){
	if (frente == NULL){
		cout<<"\n\tNO HAY PEDIDOS POR AHORA\n";
		return;
	}
	Nodo *aux = new Nodo();
	aux=frente;
	float total = 0.0;
     while(aux!=NULL){
    cout<<"\nDETALLES DEL PEDIDO"; 	
    cout<<"\n---------------------------------"; 	
    cout<<"\nNombre del cliente:"<<aux->cliente;
    cout<<"\nNumero de cliente:"<<aux->numero;
    cout<<"\nProducto Ordenado: "<<aux->orden;
	cout<<"\nCantidad: "<<aux->cantidad2;
	cout<<"\nTotal a Pagar: $ "<<aux->total<<endl;
	cout<<"----------------------------------\n";
        aux=aux->siguiente;
     }
    ordenarClientesPorInsercion(frente);
}
void eliminar(){
char n;
Nodo *aux = new Nodo();
    aux=frente;

	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}
void buscarCliente(){
	//Busqueda Secuencial
		cout<<"\n\tBUSCAR CLIENTE\n";
       int nuCliente;
        Nodo* aux=new Nodo();
        aux=frente;
        cout<<"\nNumero del cliente que desea buscar: ";
        cin>>nuCliente; 
		if(frente!=NULL){
		while(aux!=NULL ){
			if(aux->numero == nuCliente){
				cout<<"\n El cliente se encuentra en la lista su nombre es: "<<aux->cliente<<endl;
				return;
			}
				aux = aux -> siguiente;
		}
			cout<<"\n\tEl cliente NO se encuentra en la lista"<<endl;
		}
}
void ordenarClientes(){
	Nodo* aux = frente;
	if (frente == NULL){
		cout<<"\n\tNO HAY CLIENTES PARA ORDENAR EN LAS MESAS ";
		return;
	}
int i,numero, A[100], clientesor = 0;
	cout<<"\n\nPosibles clientes que se pueden ordenar en mesas:\n ";
	while (aux != NULL){
		cout<<"\nNombre del cliente: "<< aux->cliente;
		cout<<"\nNumero de cliente:"<< aux->numero<<endl;
		clientesor ++;
		aux = aux->siguiente;
	}
	cout<<"\n\nCuantos clientes desea ordenar en mesas: ";
	cin>>numero;
		if (numero>clientesor){
			cout<<"\n\n\tNO HAY SUFICIENTES CLIENTES EN LA LISTA PARA ORDENAR\n\n ";
			return;
	}
	for(i=0;i<numero;i++){
		cout<<"No.Cliente: ";
		cin>>A[i];
	}
	cout<<"\nClientes ingresados: "<<endl;
	for(i=0;i<numero;i++){
		cout<<A[i]<<", ";
	}

	QuickSort(A,0, numero-1);
	mostrarOrden(A, numero);
}

void QuickSort(int A[100], int primero, int ultimo){
	// ordenamiento QuickSort
	int central, i, j, pivote, temporal;
	central = (primero +ultimo)/2; 
	pivote = A[central];
	i= primero;
	j= ultimo;

	do{
		while(A[i]<pivote) i++; 
		while(A[j]>pivote) j--; 
		if(i<=j){
			temporal=A[i];
			A[i]=A[j];
			A[j]=temporal;
			i++;
			j--;
		}
	}while(i<=j);

	if(primero<j){
		QuickSort(A, primero,j);
	}

	if(i<ultimo){
		QuickSort(A,i,ultimo);
	}
}
void mostrarOrden(int A[100], int numero){
	int i,j,e=1;
    cout<<endl;
	cout<<"\n\tCLIENTES ORDENADOS EN LAS MESAS";
	for(i=0;i<numero;i++){
		cout<<"\n-------------------"; 
		cout<<"\nMesa "<<e++<<" - Cliente "<<A[i]<<" \n";
		cout<<"\n-------------------\n"; 
	}
}

void OrdenarClientesPorCompra(Nodo*& inicio) {
	//ordemaniento seleccion
    Nodo* actual = inicio;
    Nodo* siguiente = NULL;
    Nodo temp;

    while (actual != NULL) {
        Nodo* maximo = actual;
        siguiente = actual->siguiente;

        while (siguiente != NULL) {
            if (siguiente->total > maximo->total) {
                maximo = siguiente;
            }
            siguiente = siguiente->siguiente;
        }

        if (maximo != actual) {
            swap(actual->cliente, maximo->cliente);
            swap(actual->numero, maximo->numero);
            swap(actual->orden, maximo->orden);
            swap(actual->cantidad2, maximo->cantidad2);
            swap(actual->cantidad, maximo->cantidad);
            swap(actual->clave, maximo->clave);
            swap(actual->total, maximo->total);
        }

        actual = actual->siguiente;
    }
}



void mostrarClientesConMayorCompra() {
		if (frente == NULL){
		cout<< "\n\tNO HAY CLIENTES \n";
		return;
	}
	OrdenarClientesPorCompra(frente);
    cout << "\n\tCLIENTES CON MAYOR COMPRA:\n";
    Nodo *aux = frente;
     while(aux!=NULL){
    cout<<"------------------------------"; 	
    cout<<"\nNombre del cliente: "<<aux->cliente;
	cout<<"\nCantidad de compra: $ "<<aux->total<<endl;
	cout<<"-----------------------------\n";
        aux=aux->siguiente;
     }
}

void ordenarClientesPorInsercion(Nodo*& frente) {
	//Ordenamiento Insercion
    if (frente == NULL || frente->siguiente == NULL) {
        return;
    }
    Nodo* lista = NULL; 
    while (frente != NULL) {
        Nodo* nuevo = frente;
        frente = frente->siguiente;
        if (lista == NULL || nuevo->numero < lista->numero) {
            nuevo->siguiente = lista;
            lista = nuevo;
        } else {
            Nodo* temp = lista;
            while (temp->siguiente != NULL && temp->siguiente->numero < nuevo->numero) {
                temp = temp->siguiente;
            }
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }

    frente = lista; 
}