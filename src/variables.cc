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

#include "variables.h"

Variable::Variable(vector<string>& every_line) {
  const regex expression ("^\\s*(int|double)\\s+(\\w+)\\s*(=\\s*(.+))?;" );
  const regex expression_int ("int");
  const regex expression_double ("double");
  const regex expression2 (";");
  const regex expression_value ("=\\s*");
  smatch matches;
  string aux;

  for (unsigned i = 0; i < every_line.size(); i++) {
    if (regex_search (every_line.at(i), expression)) {
      regex_search (every_line.at(i), matches, expression);
      ivariables_.push_back(i);
      aux = regex_replace((string)matches[0], expression2, "");
      if (regex_search(aux, expression_int)) {
        svariables_.push_back(regex_replace(aux, expression_int, "INT: "));
      } else {
        svariables_.push_back(regex_replace(aux, expression_double, "DOUBLE: "));
      }
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Variable& variable) {
  out << endl << "VARIABLES:" << endl;
  for (int i = 0; i < variable.ivariables_.size(); ++i) {
    out << "[Line " << variable.ivariables_.at(i) + 1 << "] ";
    out << variable.svariables_.at(i) << endl;
  }
  return out;
}

