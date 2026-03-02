#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    float numeroFloatUno, numeroFloatDos;
    int numeroUno, numeroDos;
    int numeroTres, numeroCuatro;
    int limite = 100;

    // Crea la semilla de los números aleatorios
    srand(time(NULL));

    

    int i;
    for (i = 0; i < 10; i++){
            // Genera dos números aleatorios
        numeroUno = rand() % limite;
        numeroDos = rand() % limite;
        numeroTres = rand() % limite;
        numeroCuatro = rand() % limite;

        numeroFloatUno = (float)numeroUno + numeroTres / 100.0;
        numeroFloatDos = (float)numeroDos + numeroCuatro / 100.0;
        // Imprime los cuatro números enteros
        printf("numeroUno = %d\n", numeroUno);
        printf("numeroDos = %d\n", numeroDos);
        printf("numeroTres = %d\n", numeroTres);
        printf("numeroCuatro = %d\n", numeroCuatro);

        // Imprime los dos números flotantes aleatorios
        printf("numeroFloatUno = %f\n", numeroFloatUno);
        printf("numeroFloatDos = %f\n", numeroFloatDos);
        printf("\n");
    }
    

    return 0;
}
