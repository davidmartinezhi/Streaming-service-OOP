#ifndef VIDEO_H
#define VIDEO_H

//David Gerardo Martínez Hidrogo - A01235692
//Fernando Pereyra - a*******
#include <iostream>
#include <string>
using namespace std;

class Video {
    private:
        string ID;
        string nombre;
        string genero;
        string descripcion;
        double calificacion;
        int numeroCalificaciones;

    public:
    //Constructores
        Video();
        Video(string, string, string, string, double, int);
    //Setters

        void setID(string);
        void setNombre(string);
        void setGenero(string);
        void setDescripcion(string);
        void setCalificacion(double);
        void setNumeroCali(int);

    //Getters

        string getID() const;
        string getNombre() const;
        string getGenero() const;
        string getDescripcion() const;
        double getCalificacion() const;
        int getNumeroCali() const;

    //Ajuste de calificacion con nuevas entradas
        void calificar(double);

    //Imprime la información del video.
        virtual string imprime() = 0;

    // Sobrecarga del operador para definir la salida del tipo de dato
       friend ostream& operator << (ostream& salida, Video* vid);

};

Video::Video(){

    ID = "";
    nombre = "";
    genero = "";
    descripcion = "";
    calificacion = 0.0;
    numeroCalificaciones = 0;
}

Video::Video(string iden, string nom, string gen, string desc, double cali, int numCali){

    ID = iden;
    nombre = nom;
    genero = gen;
    descripcion = desc;
    calificacion = cali;
    numeroCalificaciones = numCali;
}

//Setters

void Video::setID(string nuevoID){
    ID = nuevoID;
}
void Video::setNombre(string nuevoNombre){
    nombre = nuevoNombre;
}
void Video::setGenero(string nuevoGener){
    genero = nuevoGener;
}
void Video::setDescripcion(string nuevaDesc){
    descripcion = nuevaDesc;
}
void Video::setCalificacion(double nuevaCali){
    calificacion = nuevaCali;
}
void Video::setNumeroCali(int nuevoNumero){
    numeroCalificaciones = nuevoNumero;
}

//Getters

string Video::getID() const{
    return ID;
}
string Video::getNombre() const{
    return nombre;
}
string Video::getGenero() const{
    return genero;
}
string Video::getDescripcion() const{
    return descripcion;
}
double Video::getCalificacion() const{
    return calificacion;
}
int Video::getNumeroCali() const{
    return numeroCalificaciones;
}

//Ajuste de calificacion con nuevas entradas
void Video::calificar(double nuevaCali){
    double numerador = (calificacion * numeroCalificaciones) + nuevaCali;
    numeroCalificaciones += 1;
    calificacion = numerador/numeroCalificaciones;
}

// Sobrecarga del operador para definir la salida del tipo de dato
ostream& operator << (ostream& salida, Video* vid){
    salida << vid->imprime();
    return salida;
}


#endif //VIDEO_H
