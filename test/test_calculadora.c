#include <unity.h>
#include "calculadora.h"

// Debe crear una calculadora abstracta
void test_crear_calculadora(void) {
    TEST_ASSERT_TRUE(CrearCalculadora() != NULL);
}

int Suma(int a, int b) {
    return (a + b);
}

int Resta(int a, int b) {
    return (a - b);
}

int Producto(int a, int b) {
    return (a * b);
}

int Cociente(int a, int b) {
    return (a / b);
}

// Agragar operacion
void test_agregar_operacion(void) {
    calculadora_t calculadora = CrearCalculadora();

    TEST_ASSERT_TRUE(AgregarOperacion(calculadora, '+', Suma));
    TEST_ASSERT_FALSE(AgregarOperacion(calculadora, '+', Resta));
    TEST_ASSERT_TRUE(AgregarOperacion(calculadora, '*', Producto));
}

// Hacer suma
void test_hacer_suma(void) {
    calculadora_t calculadora = CrearCalculadora();

    AgregarOperacion(calculadora, '+', Suma);
    TEST_ASSERT_EQUAL(19, Calcular(calculadora, "14+5"));
    TEST_ASSERT_EQUAL(30, Calcular(calculadora, "20+10"));
}

// Hacer resta
void test_hacer_resta(void) {
    calculadora_t calculadora = CrearCalculadora();

    AgregarOperacion(calculadora, '-', Resta);
    TEST_ASSERT_EQUAL(2, Calcular(calculadora, "4-2"));
    TEST_ASSERT_EQUAL(-1, Calcular(calculadora, "3-4"));
}

// Hacer producto
void test_hacer_producto(void) {
    calculadora_t calculadora = CrearCalculadora();

    AgregarOperacion(calculadora, '*', Producto);
    TEST_ASSERT_EQUAL(100, Calcular(calculadora, "4*25"));
    TEST_ASSERT_EQUAL(120, Calcular(calculadora, "30*4"));
}

// Hacer cociente
void test_hacer_cociente(void) {
    calculadora_t calculadora = CrearCalculadora();

    AgregarOperacion(calculadora, '/', Cociente);
    TEST_ASSERT_EQUAL(20, Calcular(calculadora, "40/2"));
    TEST_ASSERT_EQUAL(96, Calcular(calculadora, "385/4"));
}
