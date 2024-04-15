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
#include <vector>
#include <regex>
#include <string>

#ifndef VARIABLES_H
#define VARIABLES_H

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::regex;
using std::regex_match;
using std::smatch;

class Variable {
 public:
  Variable(vector<string>& every_line);//constructor por parametro

  friend std::ostream& operator<<(std::ostream& out, const Variable& variable);//sobrecarga del operador de extraccion

 private: 
  vector<string> svariables_;
  vector<int> ivariables_;
};

#endif