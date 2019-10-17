#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>

using namespace std;

class Alumno{
private:

	int id; 
	string nombre;
	string apellidoPaterno;
	string apellidoMaterno;
	string carrera;
public:
	Alumno();
	//Alumno(int id, string nombre, string pat, string mat, string carrera): id(id), nombre(nombre), apellidoPaterno(pat), apellidoMaterno(mat), carrera(carrera) {}
	void setNombre(string &value);
	void setApellidoPaterno(string &value);
	void setApellidoMaterno(string &value);
	void setCarrera(string &value);
	void setId(int value);

	int getId();
	string getNombre();
	string getApellidoPaterno();
	string getApellidoMaterno();
	string getCarrera();
	string getString();
};

#endif // ALUMNO_H
