/************************************************************************************************
Copyright (c) 2023, Jesus Gerardo Daniel Avila jesus.avila.05@gmail.com
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions: The above copyright notice and this
permission notice shall be included in all copies or substantial portions of the
Software. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO
EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. SPDX-License-Identifier: MIT
*************************************************************************************************/
/**
 * \cond
 * El archivo no será expuesto en la página generada por doxygen
 */

/** \brief Implementacion de la libraria calculadora.h
 **
 ** \addtogroup Calculadora
 ** \brief Calculadora Dinámica
 ** @{ */

/* === Headers files inclusions
 * =============================================================== */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* === Macros definitions
 * ====================================================================== */

/* === Private data type declarations
 * ========================================================== */

/// @brief Descriptor a estructura operacion_s
typedef struct operacion_s *operacion_t;

/// @brief Contiene un puntero al primer elemento de la lista enlazada
struct calculadora_s {
  operacion_t operaciones;
};

/// @brief Definición de los atruibutos de operacion_s
struct operacion_s {
  char operador;
  funcion_t funcion;
  operacion_t siguiente;
};

/* === Private variable declarations
 * =========================================================== */

/* === Private function declarations
 * =========================================================== */

/**
 * @brief Busca la operacion en la lista enlazada
 *
 * @param calculadora Descriptor de calculadora
 * @param operador Indicador de la operacion a buscar
 * @return operacion_t: Descriptor de la operacion encontrada. Si no existe
 * devuelve NULL
 */
operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/* === Public variable definitions
 * ============================================================= */

/* === Private variable definitions
 * ============================================================ */

/* === Private function implementation
 * ========================================================= */

calculadora_t CrearCalculadora(void) {
  calculadora_t calculadora = malloc(sizeof(struct calculadora_s));
  if (calculadora) {
    memset(calculadora, 0, sizeof(struct calculadora_s));
  }
  return calculadora;
}

bool AgregarOperacion(calculadora_t calculadora, char operador,
                      funcion_t funcion) {
  operacion_t operacion = NULL;

  if (!BuscarOperacion(calculadora, operador)) {
    operacion = malloc(sizeof(struct operacion_s));
  }
  if (operacion) {
    operacion->operador = operador;
    operacion->funcion = funcion;
    operacion->siguiente = calculadora->operaciones;
    calculadora->operaciones = operacion;
  }
  return operacion;
  //  return  (operacion != NULL);
}

static operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {
  operacion_t result = NULL;
  operacion_t actual = calculadora->operaciones;

  if (actual != NULL) {
    for (actual; actual != NULL; actual = actual->siguiente) {
      if (actual->operador == operador) {
        result = actual;

        break;
      }
    }
  }

  return result;
}

int Calcular(calculadora_t calculadora, char *cadena) {
  int a, b;
  char operador;
  int resultado = 0;
  operacion_t operacion = NULL;

  for (int index = 0; index < strlen(cadena); index++) {
    if (cadena[index] < '0') {
      operador = cadena[index];
      a = atoi(cadena);
      b = atoi(cadena + index + 1);
      break;
    }
  }

  operacion = BuscarOperacion(calculadora, operador);
  if (operacion) {
    resultado = operacion->funcion(a, b);
  }

  return resultado;
}

/* === Public function implementation
 * ========================================================== */

/**
 * \endcond
 */

/* === End of documentation
 * ==================================================================== */

/** @} End of module definition for doxygen */