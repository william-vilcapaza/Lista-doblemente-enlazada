#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
int dato;
Nodo *siguiente;
Nodo *anterior;

} *primero, *ultimo, *current, *aux;

void menu();
void insertarlista(Nodo*,int);
void mostrarlista(Nodo *&, Nodo *&);
void mostrarlistaalreves(Nodo *&, Nodo *&);
void buscarlista(Nodo *, int);
void eliminarnodo(Nodo *&, int);
void insertarlistadoble(Nodo *&, Nodo *&, int);
void suprimirlistadoble(Nodo *&, Nodo *&, int &);
void pausa();

Nodo*lista=NULL;

int main(){
 menu();
 getchar ();
    return 0;
 int dato;
    char resp;
 menu();

    getchar ();
    return 0;
}

void menu () {

 int opcion,dato;

     do{
  cout<<"MENU\n";
  cout<<"|1. Insertar elementos a la lista                        |\n";
  cout<<"|2. Mostrar el contenido en el orden de la entrada       |\n";
  cout<<"|3. Mostrar el contenido en orden inverso a la entrada   |\n";
     cout<<"|4. Buscar un elemento en lista                          |\n";
  cout<<"|5. Eliminar un nodo de la lista                         |\n";
  cout<<"|6. Salir                                                |\n";
  cout<<""<<endl;
  cout<<"opcion: ";
  cin>>opcion;

  switch(opcion){
  case 1: cout<<"\t Usted ha elegido la opccion numero 1. \n";
  cout<<"Digite un numero: ";
          cin>>dato;
          insertarlistadoble(primero, ultimo,dato);
          cout<<"\n";
          system("pause");
          break;
  case 2: cout<<"\t Usted ha elegido la opccion numero 2. \n";
  mostrarlista(primero,ultimo);
          cout<<"\n";
          system("pause");
          break;
  case 3: cout<<"\t Usted ha elegido la opccion numero 3. \n";
  mostrarlistaalreves(primero,ultimo);
          cout<<"\n";
          system("pause");
          break;


  case 4: cout<<"\t Usted ha elegido la opccion numero 4. \n";
  cout<<"\nDigite un numero a buscar: ";
           cin>>dato;
     buscarlista(lista, dato);
     cout<<"\n";
                 system("pause");
                 break;

  case 5:cout<<"\t Usted ha elegido la opccion numero 5. \n";
   cout<<"\nDigite el numero que desea eliminar: ";
        cin>>dato;
          suprimirlistadoble(primero, ultimo, dato);
          cout<<"\n";
          system("pause");
              break;
  case 6: break;

 }
 system("cls");

    }while(opcion !=6);
}

void insertarlistadoble(Nodo *&primero, Nodo *&ultimo, int n){
 Nodo *nuevo_nodo=new Nodo();
 nuevo_nodo->dato=n;
 nuevo_nodo->siguiente=NULL;
 if (primero==NULL){
 primero=nuevo_nodo;
 primero->siguiente=NULL;
 primero->anterior=NULL;
 ultimo=primero;
}
else {
 ultimo->siguiente=nuevo_nodo;
 nuevo_nodo->anterior=ultimo;
 nuevo_nodo->siguiente=NULL;
 ultimo=nuevo_nodo;
}
}

 void suprimirlistadoble(Nodo *&primero, Nodo *&ultimo, int &n)

{
 bool encontrado;
 if (primero==NULL)
cout<<"\nLa lista esta vacia, no hay nada que borrar \n";
else if (primero->dato==n){
current=primero;
primero=primero->siguiente;
if (primero != NULL)
primero->anterior=NULL;
 else
 ultimo=NULL;
 delete current;
 }
 else
 {
encontrado=false;
current=primero;
while (current !=NULL && !encontrado)
 if (current->dato==n)
 encontrado=true;
 else
 current=current->siguiente;

if (current==NULL)
 cout<<"\nEl numero no se encuentra en la lista\n";
else
 if (current->dato==n){
aux=current->anterior;
aux->siguiente=current->siguiente;
if (current->siguiente!=NULL)
 current->siguiente->anterior=aux;
if (current==ultimo)
 ultimo=aux;
delete current;
}
 else
 cout<<"\nEl numero no se encuentra en la lista doble \n";
 }
 cout<<"\nQuedan estos numeros:\n";
 current=primero;
 while(current != NULL){
cout<<current->dato<<", ";
current=current->siguiente;
 }
 cout<<"No hay mas datos\n ";
}

void mostrarlista(Nodo*&,Nodo*&){
cout<<"\nListando los elementos de la lista doblemente ligada en el orden en que entraron : ";
 current=primero;
 while(current != NULL){
cout<<current->dato<<", ";
current=current->siguiente;
}

getch();
 }

 void mostrarlistaalreves(Nodo*&,Nodo*&){
cout<<"\nListando los elementos de la lista en orden: ";
 current=ultimo;
 while(current != NULL){
cout<<current->dato<<", ";
current=current->anterior;
}

getch();
 }

void buscarlista(Nodo *lista, int n){
 bool band = false;

 Nodo *actual = new Nodo();
 actual = lista;

 while((actual != NULL) && (actual->dato <= n)){ //recorre la lista
     if(actual->dato == n){
      band = true;

  }
  actual = actual->siguiente; //si no encuentra el elemento que siga recorriendo por los demas elementos
 }
 if(band == true){
  cout<<"Elemento "<<n<<" Si a sido encontrado en lista\n";
 }
 else{
  cout<<"Elemento "<<n<<" No a sido encontrado en lista\n";
 }
 getch();
}

void eliminarnodo(Nodo *& lista, int n){
 //preguntar si la lista no esta vacia
 if(lista != NULL){
  Nodo *aux_borrar;
  Nodo *anterior = NULL;

  aux_borrar = lista;

  //Recorrer la lista
  while((aux_borrar != NULL) && (aux_borrar->dato != n)){
   anterior = aux_borrar;
   aux_borrar = aux_borrar->siguiente;
  }

  //El elemento no ha sido encontrado
  if(aux_borrar == NULL){
   cout<<"El elemento no ha sido encontrado";
  }

  //El primer elemento es el que vamos a eliminar
  else if(anterior == NULL){
      lista = lista->siguiente;
   delete aux_borrar;
  }

  //El elemento esta en la lista pero, no es el primer nodo
  else{
    anterior->siguiente = aux_borrar->siguiente;
    delete aux_borrar;
  }
 }
}
