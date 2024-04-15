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

#include "main.h"


Main::Main(vector<string>& every_line) {
  const regex expression ("int\\s+main\\s*\\(.*\\)\\s*\\{" );
  smatch matches;
  for (unsigned i = 0; i < every_line.size(); i++) {
    if (regex_search (every_line.at(i), expression)) {
      regex_search (every_line.at(i), matches, expression);
      main_ = regex_search (every_line.at(i), matches, expression);
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Main& main) {
  out << endl << "MAIN:" << endl;
  if (main.main_ == true) {
    out << "True" << endl;
  } else {
    out << "False" << endl;
  }
  return out;
}