// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia // Curso: 2o
// Practica 4: Code analyzer
// Autor: Javier Garcia Santana
// Correo: alu0101391663@ull.edu.es
// Fecha: 20/10/2022
//
// Archivo cya-P04-code-analyzer.cc: programa cliente.
// Contienelafunci ́onmaindelproyectoqueusalasclases
//         X e Y para ... (indicar brevemente el objetivo)
// Descripcion otras funcionalidades //
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 20/10/2022 - Creacion (primera version) del codigo

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>

#include "variables.h"
#include "statements.h"
#include "comments.h"
#include "main.h"
#include "precompiler.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::regex;
using std::regex_match;
using std::smatch;
using std::ios_base;

int main(int argc, char* argv[]) {
  if (argc != 3) {//He aqui el usage, al ser tan corto, no merece implementar una clase para el mismo
    cout << "Número erroneo de parámetros..." << endl
         << "El formato debe ser: ./p04_code_analyzer code.cc codescheme.txt " << endl;

    return 1;
  } else {
    vector<string> every_line;
    string file_in = argv[1];
    ifstream code;
    code.open(argv[1], ios_base::in);
    std::ofstream codescheme{argv[2]};

    if (code.is_open()) {//leemos es fichero de entrada...
      string linea;
      while (getline(code, linea)) {
        every_line.push_back(linea);
      }
      cout << "El fichero de entrada se ha abierto correctamente..." << endl;
    } else {
      cout << "Ha habido un error al abrir el archivo de entrada..." << endl;
    }
    //creamos los objetos con cada grupo de elementos del fichero
    Comment comment(every_line);
    Variable variable(every_line);
    Statement statement(every_line);
    Main main(every_line);
    Precompiler precompiler(every_line);
    //los metemos al archivo de salida
    codescheme << "PROGRAM: " << file_in << endl;

    codescheme << precompiler << comment << variable << statement << main << comment;
    cout << "El fichero de salida se ha generado correctamente" << endl;
  }
  return 0;
}