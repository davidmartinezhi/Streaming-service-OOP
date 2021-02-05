#ifndef SERIE_H
#define SERIE_H

#include "./Video.h"
#include "./Episodio.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Serie : public Video {
  private:
      std::vector<std::vector<Episodio>> listaEpisodios;
      int temporadas;
      int episodios;
  public:
    Serie();
    Serie(string, string, string, string, double, int, int, int, ifstream&);
    string imprime();
};

Serie::Serie(){
  listaEpisodios = std::vector<std::vector<Episodio>> (0);
  temporadas = 0;
  episodios = 0;
}

Serie::Serie(string iden, string nom, string gen, string desc, double cali,
              int numCali, int temps, int eps, ifstream &entrada)
              : Video(iden, nom, gen, desc, cali, numCali){

  listaEpisodios = vector<vector<Episodio>> (temps, vector<Episodio>(0));
  temporadas = temps;
  episodios = eps;

  string tempTitulo, tempS;
  int tempDuracion, tempNumero, tempTemporada;
  for (int i = 0; i < episodios; i++) {
    getline(entrada,  tempTitulo);
    getline(entrada, tempS);
    tempDuracion = stoi(tempS);
    getline(entrada, tempS);
    tempNumero = stoi(tempS);
    getline(entrada, tempS);
    tempTemporada = stoi(tempS);
    listaEpisodios[tempTemporada-1].push_back(Episodio(tempTitulo, tempDuracion,
                                                      tempNumero, tempTemporada));
  }
}

std::string Serie::imprime(){
  string salida = "";
  string cali = to_string(getCalificacion());
  salida += getNombre() + " | " + cali + "\n";

  salida += getGenero() + "\n";
  salida += to_string(temporadas) + " Temporadas - " + to_string(episodios)
          + " Episodios\n";
  salida += getDescripcion() + "\n\n";

  for (int i = 0; i < temporadas; i++) {
    for (int j = 0; j < listaEpisodios[i].size(); j++) {
      salida += listaEpisodios[i][j].imprime();
      salida += "\n";
    }
  }
  return salida;
}
/*
Nombre | calificacion
genero
Duracion
descripcion
eps
*/
#endif
