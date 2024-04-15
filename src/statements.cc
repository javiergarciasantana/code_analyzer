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

#include "statements.h"

Statement::Statement(vector<string>& every_line) {
  regex expression ("for[^A-Za-z]\\s*|while\\s*" );
  smatch matches;
  for (unsigned i = 0; i < every_line.size(); i++) {
    if (regex_search (every_line.at(i), expression)) {
      regex_search (every_line.at(i), matches, expression);
      istatements_.push_back(i);
      sstatements_.push_back(matches[0]);
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Statement& statement) {

  out << endl << "STATEMENTS:" << endl;
  for (unsigned i = 0; i < statement.istatements_.size(); ++i) {
    
    out << "[Line " << statement.istatements_.at(i) + 1 << "] ";
    out << "LOOP: " << statement.sstatements_.at(i) << endl;
    
  }
  
  return out;
}