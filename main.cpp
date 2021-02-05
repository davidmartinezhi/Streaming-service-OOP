//David Gerardo Martínez Hidrogo - a01235692
//Fernando Jiménez Pereyra - a01734609

#include <iostream>

#include "./Biblioteca.h"
using namespace std;

void menu();

int main(){
    Biblioteca biblio;
    biblio.cargaDatos("./repositorio.txt");
    cout <<"Datos cargados\n";

    bool bandera = true;
    int opcion =  0;
    bool opcionValida = false;
    string titulo;
    char tipo;
    double calificando;

    while (bandera){
      menu();

      while (opcionValida == 0) {
        try{
          cin >> opcion;
          std::cout  << '\n';
          cin.ignore(1);

          if (opcion < 1 || opcion >5) {
            throw opcion;
          }
          opcionValida = true;
        }
        catch(int &x){
          std::cout << x << " es una opcion invalida, selecione una opcion valida del menu." << "\n\n";
          menu();
        }
      }
      opcionValida = false;

      switch (opcion){
          case 1:

              std::cout << "C para buscar por calificacion o G para buscar por genero." << "\n\n";

              try{
                //cin >> tipo;
                getline(cin, titulo);
                std::cout << '\n';
                if (titulo != "C" && titulo != "G") {
                  throw titulo;
                }
              }
              catch(string){
                std::cout << "Opcion invalida." << "\n\n";
                break;
              }

              if (titulo == "C"){

                  try{
                    std::cout << "Calificacion: ";
                    getline(cin, titulo);
                    std::cout << '\n';
                    calificando = stoi(titulo);

                    try{
                      if (calificando < 1 || calificando > 5) {
                        throw calificando;
                      }
                      biblio.consultaCalificacion(calificando, 'T');
                    }
                    catch(double){
                      std::cout << "Valor fuera de rango 1-5." << "\n\n";
                    }
                  }
                catch(...){
                  std::cout << "Entrada no valida" << "\n\n";
                }
              }
              else {

                try{

                  cin >> titulo;
                  std::cout  << '\n';
                  if (titulo != "Drama" && titulo != "Acción" && titulo != "Misterio") {
                    throw titulo;
                  }
                  biblio.consultaGenero(titulo);
                }
                catch(string){
                  std::cout << "Genero no disponible." << "\n\n";
                }
              }

            break;

          case 2:
            try{
              std::cout << "Calificacion: ";
              getline(cin, titulo);
              std::cout << '\n';
              calificando = stoi(titulo);

              try{
                if (calificando < 1 || calificando > 5) {
                  throw calificando;
                }
                biblio.consultaCalificacion(calificando, 'S');
              }
              catch(double){
                std::cout << "Valor fuera de rango 1-5." << "\n\n";
              }
            }
          catch(...){
            std::cout << "Entrada no valida" << "\n\n";
          }
            break;

          case 3:
            try{
              std::cout << "Calificacion: ";
              getline(cin, titulo);
              std::cout << '\n';
              calificando = stoi(titulo);

              try{
                if (calificando < 1 || calificando > 5) {
                  throw calificando;
                }
                biblio.consultaCalificacion(calificando, 'P');
              }
              catch(double){
                std::cout << "Valor fuera de rango 1-5." << "\n\n";
              }
            }
          catch(...){
            std::cout << "Entrada no valida" << "\n\n";
          }
              break;

          case 4:

            std::cout << "Titulo: ";
            getline(cin, titulo);
            std::cout << '\n';

            try{

              std::cout << "Calificacion: ";
              std::string tempInt;
              getline(cin, tempInt);
              std::cout << '\n';
              calificando = stoi(tempInt);

              try{

                if (calificando < 1 || calificando > 5) {
                  throw calificando;
                }
                std::cout << titulo << '\n';
                std::cout << calificando << '\n';
                biblio.calificarTitulo(titulo, calificando);
              }
              catch(double){
                std::cout << "Valor fuera de rango 1-5." << "\n\n";
              }
            }
            catch(...){
              std::cout << "Entrada no valida" << "\n\n";
            }
            break;

          case 5:
              bandera = false;
              break;

      }
    }
    return 0;
}

void menu(){
  std::cout << "Menu:" << '\n';
  std::cout << "1.- Consultar todos lo videos por calificacion o genero." << '\n';
  std::cout << "2.- Consultar series por calificacion." << '\n';
  std::cout << "3.- Consultar peliculas por calificacion." << '\n';
  std::cout << "4.- Calificar una serie o pelicula." << '\n';
  std::cout << "5.- Salir." << "\n\n";
}
