#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
using namespace std;

class Episodio{
  private:
    string titulo;
    int duracion;
    int numeroEpisodio;
    int temporada;

  public:
    Episodio();
    Episodio(string, int, int, int);
    string imprime();
};

Episodio::Episodio(){
  titulo = "";
  duracion = 0;
  numeroEpisodio = 0;
  temporada = 0;
}

Episodio::Episodio(string titu, int dura, int ep, int temp){
  titulo = titu;
  duracion = dura;
  numeroEpisodio = ep;
  temporada = temp;
}

string Episodio::imprime(){
  string info = "";
  info += titulo + " | " + to_string(duracion) + " min\n";
  info += "Temporada: " + to_string(temporada) + " - Episodio: " + to_string(numeroEpisodio) + "\n";
  return info;
}
/*
titu | duracion
temp - ep
*/
#endif
