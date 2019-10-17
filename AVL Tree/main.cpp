#include <iostream>
#include "avl.h"
#include "alumno.h"

using namespace std;


enum options{
	INSERT = 1,
	ERASE,
	FIND,
	PREORDER,
	INORDER,
	POSORDER,
	EXIT
};
void showMenu();
void setAlumno(Alumno *al);

int main(){

	AVLTree avlTree;

	int opt, tempId;
	Alumno aux;
	Alumno* auxptr;

	do{
		showMenu();
		cin >> opt;
		switch(opt){
			case INSERT:
				setAlumno(&aux);
				auxptr = avlTree.find(aux.getId());
				if(auxptr != nullptr){
					cout << endl << "Se encontró un alumno con ese, el elemento no se ha agregado al arbol." << endl;
				}else{
					avlTree.insert(aux);
					cout << endl << "El elemento se ha agregado correctamente al árbol." << endl;
					cout << aux.getString() <<  endl;
				}
				break;
			case ERASE:
				cout << endl << "Ingrese el ID del alumno que desea eliminar: ";
				cin >> tempId;
				if(avlTree.erase(tempId)){
					cout << endl << "El elemento " << tempId << " se ha eliminado correctamente." << endl;
				}else{
					cout << "No se encontro el elemento " << tempId << "." << endl;
				}
				break;
			case FIND:
				cout << "Ingrese el ID del alumno que desea eliminar: ";
				cin >> tempId;
				auxptr = avlTree.find(tempId);
				if(auxptr != nullptr){
					cout << endl << "El elemento encontrado es el siguiente: " << endl
				 		<< auxptr->getString() << endl << endl;
				}else{
					cout << "No se ha encontrado un elemento con ese ID." << endl;
				}
				break;
			case PREORDER:
				cout << "Realizando recorrido pre-orden: " << endl;
				avlTree.preOrder();
				cout << endl;
				break;
			case INORDER:
				cout << "Realizando recorrido en-orden: " << endl;
				avlTree.inOrder();
				cout << endl;
				break;
			case POSORDER:
				cout << "Realizando recorrido pos-orden: " << endl;
				avlTree.posOrder();
				cout << endl;
				break;
			case EXIT:
				cout << "Saliendo del programa . . . "<< endl;
				break;
			default:
				cout << "Ingrese una opcion correcta !" << endl;
				break;
		}
	}while(opt != EXIT);

	return 0;
}

void showMenu(){
	cout << "\n\n\tArbol de busqueda binaria" << endl
		<< INSERT << ") Ingresar un elemento al arbol." << endl
		<< ERASE << ") Eliminar un elemento del arbol." << endl
		<< FIND << ") Buscar elemento por llave primaria." << endl
		<< PREORDER << ") Hacer recorrido pre-orden." << endl
		<< INORDER << ") Hacer recorrido en-orden." << endl
		<< POSORDER << ") Hacer recorrido pos-orden." << endl
		<< EXIT << ") Salir del programa. " << endl << endl
		<< "Escoja una opcion: ";
}

void setAlumno(Alumno *al){
	int id;
	string nom, pat, mat, car;
	cout << "Ingrese el ID: ";
	cin >> id;
	cin.ignore();
	cout << "Ingrese el nombre: ";
	getline(cin, nom);
	cout << "Ingrese el apellido paterno: ";
	getline(cin, pat);
	cout << "Ingrese el apellido materno: ";
	getline(cin, mat);
	cout << "Ingrese la carrera: ";
	getline(cin, car);

	al->setNombre(nom);
	al->setId(id);
	al->setApellidoPaterno(pat);
	al->setApellidoMaterno(mat);
	al->setCarrera(car);
}
