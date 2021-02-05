#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "./Pelicula.h"
#include "./Serie.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Biblioteca {
    private:
    vector<Video*> repositorio;

    public:
        Biblioteca();

        void cargaDatos(string);
        void consultaGenero(string);
        void consultaCalificacion(double, char);
        void calificarTitulo(string, double);

};

Biblioteca::Biblioteca(){
    repositorio = vector<Video*>(0);
}

void Biblioteca::cargaDatos(string txt){
    //Videos
    string id, nom, gene, desc;
    double cali;
    int numeroCalis;

    //Pelicula
    int dura;
    int cantidadPremios;
    string p;
    vector<string> premios;
    string saga;

    //Serie
    int temp;
    int ep;

    //Abre el archivo
    ifstream archivo;
    archivo.open(txt);
    string tempS;
    while (getline(archivo,id)){

        getline(archivo, nom);
        getline(archivo,gene);
        getline(archivo, desc);
        getline(archivo,tempS);
        cali = stod(tempS);
        getline(archivo,tempS);
        numeroCalis = stoi(tempS);

        if (id.at(0) == 'P'){

            getline(archivo, tempS);
            dura = stoi(tempS);
            getline(archivo, tempS);
            cantidadPremios = stoi(tempS);

            for (int i = 0; i < cantidadPremios; i++){
                getline(archivo,p);
                premios.push_back(p);
            }

            getline(archivo, saga);

            repositorio.push_back(new Pelicula(id, nom, gene, desc, cali, numeroCalis, dura, premios, saga));
        }
        else {
            getline(archivo, tempS);
            temp = stoi(tempS);
            getline(archivo, tempS);
            ep = stoi(tempS);
            repositorio.push_back(new Serie(id, nom, gene, desc, cali, numeroCalis, temp, ep, archivo));
        }
    }
    archivo.close();
}


void Biblioteca::consultaGenero(string gene){
    for(int i = 0; i < repositorio.size(); i++){

        if(repositorio[i]->getGenero() == gene){
            cout << "--------------------------------\n";
            cout << repositorio[i]->imprime();
        }
    }
    cout << "--------------------------------\n\n";
}

void Biblioteca::consultaCalificacion(double cali, char tipo){


    for(int i = 0; i < repositorio.size(); i++){
        if (tipo == 'T' || tipo == repositorio[i]->getID().at(0)){
            if (repositorio[i]->getCalificacion() == cali) {
              cout << "--------------------------------\n";
              cout << repositorio[i]->imprime();
            }
        }

    }
    cout << "--------------------------------\n\n";

}

void Biblioteca::calificarTitulo(string titulo, double cali){
    for(int i = 0; i < repositorio.size(); i++){
        if(repositorio[i]->getNombre() == titulo){
            repositorio[i]->calificar(cali);
            break;
        }
    }

}
#endif // BIBLIOTECA_H
