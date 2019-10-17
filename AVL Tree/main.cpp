#include <iostream>
#include "bst.h"
#include "avl.h"
#include "alumno.h"

using namespace std;


enum options{
	INSERT = 1,
	ERASE,
	PREORDER,
	INORDER,
	POSORDER,
	EXIT
};
void showMenu();
void setAlumno(Alumno *al);

int main(){

	BinarySearchTree tree;
	AVLTree avlTree;

	int opt, tempId;
	Alumno aux;

	do{
		showMenu();
		cin >> opt;
		switch(opt){
			case INSERT:
				setAlumno(&aux);
				tree.insert(aux);
				cout << aux.getString() <<  endl;
				break;
			case ERASE:
				cout << "Ingrese el ID del alumno que desea eliminar: ";
				cin >> tempId;
				if(tree.erase(tempId)){
					cout << "El elemento " << tempId << " se ha eliminado correctamente." << endl;
				}else{
					cout << "No se encontro el elemento " << tempId << "." << endl;
				}
				break;
			case PREORDER:
				cout << "Realizando recorrido pre-orden: ";
				tree.preOrder();
				cout << endl;
				break;
			case INORDER:
				cout << "Realizando recorrido en-orden: ";
				tree.inOrder();
				cout << endl;
				break;
			case POSORDER:
				cout << "Realizando recorrido pos-orden: ";
				tree.posOrder();
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

/*

Tiene que ser un arbol autobalanceable

*/
