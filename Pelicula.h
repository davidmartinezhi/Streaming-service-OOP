#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
#include <vector>

using namespace std;

class Pelicula : public Video {
  private:
    int duracion;
    vector <string> premios;
    string serieFilmica;
  public:
    Pelicula();
    Pelicula(string, string, string, string, double, int, int, vector <string>&,
              string);

    string imprime();
};

Pelicula::Pelicula() : Video(){
  duracion = 0;
  premios = std::vector<string> (0);
  serieFilmica = "N/A";
}

Pelicula::Pelicula(string iden, string nom, string gen, string desc, double cali,
                    int numCali, int dura, vector<string> &pre, string serieF) :
                    Video(iden, nom, gen, desc, cali, numCali){

  duracion = dura;
  premios = pre;
  serieFilmica = serieF;
}

string Pelicula::imprime(){
  string cali = to_string(getCalificacion());
  string salida = "";
  string tempNombre = getNombre();
  salida += tempNombre + " | " + cali + "\n";
  salida += serieFilmica + "\n";

  for (int i = 0; i < premios.size(); i++) {
    salida += premios[i];
    if (i < premios.size()-1) {
      salida += ", ";
    }
    else{
      salida = salida + "." + "\n";
    }
  }

  salida += getDescripcion() + "\n";
  salida += to_string(duracion) + " min\n";
  salida += getGenero() + "\n";
  return salida;
}
/*
Nombre | calificacion
serie filmica
premios
descripcion
Duracion
genero
*/
#endif
