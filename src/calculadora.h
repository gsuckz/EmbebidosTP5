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

#ifndef CALCULADORA_H
#define CALCULADORA_H

/** \brief Calculadora Dinámica
 **
 ** Implementacion de una calculadora dinámica en la que podrá crear sus propias
 *operaciones
 ** siguiendo una estructura predefinida.
 **
 ** \addtogroup Calculadora
 ** @{ */

/* === Headers files inclusions
 * ================================================================ */

#include <stdbool.h>

/* === Cabecera C++
 * ============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions
 * =============================================================== */

/* === Public data type declarations
 * =========================================================== */

/// Declaración del descriptor para la clase calculadora
typedef struct calculadora_s *calculadora_t;

/// Se declara la estructura con la que se deben implementar las operaciones
typedef int (*funcion_t)(int, int);

/* === Public variable declarations
 * ============================================================ */

/* === Public function declarations
 * ============================================================ */

/**
 * @brief Metodo de creacion de una calculadora
 *
 * @return calculadora_t: descriptor de calculadora
 */
calculadora_t CrearCalculadora(void);

/**
 * @brief Metodo para agragar operaciones a la calculadora
 *
 * @param calculadora Puntero al objeto Calculadora que se agrega la operacion
 * (puntero)
 * @param operador Simbolo del operador (char)
 * @param funcion Puntero a la funcion que se asociarà con el Operador (puntero
 * a funcion)
 * @return true: La operacion se almaceno
 * @return false: La operacion no se almacena
 */
bool AgregarOperacion(calculadora_t calculadora, char operador,
                      funcion_t funcion);

/**
 * @brief Metodo para realizar los calculos
 *
 * @param calculadora Puntero a la calculadora que realiza la operacion
 * @param cadena Operacion a realizar por calculadora Ej: "2+4"
 * @return int Resultado del calculo
 */
int Calcular(calculadora_t calculadora, char *cadena);

void BorrarCalculadora(calculadora_t calculadora);
/* === End of documentation
 * ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* CALCULADORA_H */