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

#include "comments.h"

Comment::Comment(vector<string>& every_line) {
  indicator_ = 0;
  //description
  const regex expression_1 ("\\/\\*");
  const regex expression_2 ("\\*\\/");
  bool open = false;
  bool close = false;
  for (unsigned i = 0; (i < every_line.size()) || close == false; i++) {
    if (regex_search (every_line.at(i), expression_1) && (open == false)) {
      regex_search (every_line.at(i), expression_1);
      open = true;
      idescription_.push_back(i);
      icomments_.push_back(i);
      sdescription_.push_back(every_line.at(i));
    
    } else if (open) { //Inside description
      if (regex_search (every_line.at(i), expression_2)) {
        open = false;
        close = true;
        idescription_.push_back(i);
        sdescription_.push_back(every_line.at(i));
      }
      sdescription_.push_back(every_line.at(i));
    }
  }
  //comments
  const regex expression ("^\\/\\/.*");
  smatch matches;
  for (unsigned i = 0; i < every_line.size(); i++) {
    if (regex_search (every_line.at(i), expression)) {
      regex_search (every_line.at(i), matches, expression);
     
        icomments_.push_back(i);
        scomments_.push_back(matches[0]);
    }
  }
}

std::ostream& operator<<(std::ostream& out, Comment& comment) {
  ++comment.indicator_;
  if (comment.indicator_ == 1) {
    out << endl << "DESCRIPTION:" << endl;
    for (unsigned j = 0; j < comment.sdescription_.size(); j++) {
    out << comment.sdescription_.at(j) << endl;
    }
  } else {
    out << endl << "COMMENTS:" << endl;
    out << "[Line " << comment.idescription_.at(0) + 1 << "-" << comment.idescription_.at(1) + 1 << "] DESCRIPTION" << endl;
    for (int i = 0; i < comment.scomments_.size(); ++i) {
      out << "[Line " << comment.icomments_.at((comment.icomments_.size() - 1) - i) + 1 << "] ";
      out << comment.scomments_.at(i) << endl;
    }
  }
  return out;
}
