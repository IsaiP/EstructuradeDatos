/*Hecho y Copilado por: Adilman Isai Portillo Ceron PC18035
Universidad de El Salvador*/

#include <iostream>
#include <conio.h>

using namespace std;



struct nodo{
	int nro;
	struct nodo *izq, *der;	
};

typedef struct nodo *ABB; 

class arbin{
	public:
    ABB crearNodo(int x){
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->nro = x;
	nuevoNodo->der = nuevoNodo->izq = NULL;
	return nuevoNodo;
}

void insertar(ABB &raiz, int x){
	if(!raiz){
		raiz = crearNodo(x);
	}
	else if(raiz->nro > x){
		insertar(raiz->izq,x);
	}
	else if(raiz->nro < x){
		insertar(raiz->der,x);
	}
}

void preOrden(ABB raiz){
    if(raiz != NULL){
        cout << raiz->nro << ", ";
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

void inOrden(ABB raiz){
    if(raiz != NULL){        
        inOrden(raiz->izq);
        cout << raiz->nro << ", ";
        inOrden(raiz->der);
    }
}

void postOrden(ABB raiz){
    if(raiz != NULL){
        cout << raiz->nro << ", ";
        postOrden(raiz->izq);
        postOrden(raiz->der);
    }
}

void verArbol(ABB raiz, int n){
	if(!raiz){
		return;
	}
	verArbol(raiz->der,n+1);
	for(int i = 0; i < n; i++){
		cout << " ";
	}
	cout << raiz->nro << endl;
	verArbol(raiz->izq, n+1);
}

void suma(ABB raiz,int &sum){
	if(raiz){
	suma(raiz->izq,sum);
	sum = sum + raiz->nro;
	suma(raiz->der,sum);
	}
}

int eshoja( struct nodo *hoja ){

	if( hoja->izq==NULL && hoja->der==NULL )
		return true;
	return false;
}
int alturafull( struct nodo *hoja, int *altura ){
	auxaltura( hoja, altura, 1 );
	return *altura;
}

void auxaltura( struct nodo *hoja, int *altura, int cont ){
	if( !hoja ) return;
	auxaltura( hoja->izq, altura, cont+1 );
	auxaltura( hoja->der, altura, cont+1 );
	if( (eshoja( hoja ) && cont)>*altura ) *altura= cont;
	if(cont > *altura) *altura = cont;
}

void printSubMenu(ABB raiz){
	int op;
	cout<<endl<<"1.Imprimir en pre-orden"<<endl;
    cout<<"2.Imprimir en in-orden"<<endl;
    cout<<"3.Imprimir en post-orden"<<endl;
    cout<<endl<<"\tOPCION: ";
	cin >> op;
	switch(op){
        case 1:
            preOrden(raiz);
        break;
        
        case 2:
            inOrden(raiz);
        break;
        
        case 3:
            postOrden(raiz);
        break;
	
        default:
	    cout<<"Error! opcion invalida"<<endl<<endl;
	     break;
    }
}
};

class System:public arbin{
	ABB arbol = NULL;
	int n, x , sum, altura;
	int op;
	public:
	System(){
	n = 0;
	sum = 0;
	while(true){
		cout << "[El numero actual de nodos es de: " << n << "]" << endl << endl;
		cout<<"\t\tMENU"<<endl;
        cout<<"1.Insertar"<<endl;
        cout<<"2.Mostrar"<<endl;
        cout<<"3.Altura de Arbol"<<endl;
        cout<<"4.Recorridos"<<endl;
        cout<<"5.Salir"<<endl;
        cout<<endl<<"\tOPCION: ";
		cin>> op; cout<<"\n";
	switch(op){
		case 1:
			cout << "Ingrese -1 para dejar de insertar nodos\n\n";
			while(x != (-1)){
				cout << "Ingrese el valor del nodo:";
				cin >> x;
				if(x != (-1)){	
					insertar(arbol,x);
					n++;	
				}
			}
			x = 0;
		break;
		case 2:
			cout << "El numero actual de nodos es de: " << n << endl;
			suma(arbol,sum);
			cout << "La suma de el valor de todos los nodos es de: " << sum << endl; sum = 0;
			verArbol(arbol,0);
			break;
		case 3:
			altura = 0;
			cout << "\n\nLa Altura del Arbol es: " << alturafull( arbol, &altura ) << endl;
			altura = 0; 
			break;
		case 4:
			printSubMenu(arbol);
			break;
		case 5:
            cout<<"Cerrando aplicacion...";
            cout << "\n\n";
			exit(0);

	}
	system("pause");
	system("cls");	
	}
	}
};

int main(){
	System *system = new System();
	cout << "\n\n";
	getch();
	return 0;
}
