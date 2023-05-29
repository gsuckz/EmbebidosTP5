#include "src/calculadora.h"
#include "C:/msys64/ucrt64/lib/ruby/gems/3.1.0/gems/ceedling-0.32.0/vendor/unity/src/unity.h"




void test_crear_calculadora(void) {

    do { if ((CrearCalculadora() != 

   ((void *)0)

   )) { } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(6))); } } while (0);

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





void test_agregar_operacion(void) {

    calculadora_t calculadora = CrearCalculadora();



    do { if ((AgregarOperacion(calculadora, '+', Suma))) { } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(29))); } } while (0);

    do { if (!(AgregarOperacion(calculadora, '+', Resta))) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(30))); } } while (0);

    do { if ((AgregarOperacion(calculadora, '*', Producto))) { } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(31))); } } while (0);

}





void test_hacer_suma(void) {

    calculadora_t calculadora = CrearCalculadora();



    AgregarOperacion(calculadora, '+', Suma);

    UnityAssertEqualNumber((UNITY_INT)((19)), (UNITY_INT)((Calcular(calculadora, "14+5"))), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((Calcular(calculadora, "20+10"))), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

}





void test_hacer_resta(void) {

    calculadora_t calculadora = CrearCalculadora();



    AgregarOperacion(calculadora, '-', Resta);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((Calcular(calculadora, "4-2"))), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((Calcular(calculadora, "3-4"))), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

}





void test_hacer_producto(void) {

    calculadora_t calculadora = CrearCalculadora();



    AgregarOperacion(calculadora, '*', Producto);

    UnityAssertEqualNumber((UNITY_INT)((100)), (UNITY_INT)((Calcular(calculadora, "4*25"))), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((120)), (UNITY_INT)((Calcular(calculadora, "30*4"))), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}





void test_hacer_cociente(void) {

    calculadora_t calculadora = CrearCalculadora();



    AgregarOperacion(calculadora, '/', Cociente);

    UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((Calcular(calculadora, "40/2"))), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((96)), (UNITY_INT)((Calcular(calculadora, "385/4"))), (

   ((void *)0)

   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

}
