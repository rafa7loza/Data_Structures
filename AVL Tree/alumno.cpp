#include <iostream>
#include "alumno.h"

Alumno::Alumno(){}

void Alumno::setId(int value){
	id = value;
}

void Alumno::setNombre(string &value){
	nombre = value;
}

void Alumno::setApellidoPaterno(string &value){
	apellidoPaterno = value;
}

void Alumno::setApellidoMaterno(string &value){
	apellidoMaterno = value;
}

void Alumno::setCarrera(string &value){
	carrera = value;
}

int Alumno::getId(){
	return id;
}

string Alumno::getNombre(){
	return nombre;
}

string Alumno::getApellidoPaterno(){
	return apellidoPaterno;
}

string Alumno::getApellidoMaterno(){
	return apellidoMaterno;
}

string Alumno::getCarrera(){
	return carrera;
}

string Alumno::getString(){
	int id = getId();
	string s = to_string(id) + ": " + getNombre() + " " + getApellidoPaterno() + " " + getApellidoMaterno();
	return s;
}
