#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int numeroUno, numeroDos;
    int limite = 100;

    // Crea la semilla de los números aleatorios
    srand(time(NULL));
    int i;
    for ( i = 0; i < 10; i++){
        // Genera dos números aleatorios
        numeroUno = rand() % limite;
        numeroDos = rand() % limite;

        // Imprime los números aleatorios
        printf("numeroUno = %d\n", numeroUno);
        printf("numeroDos = %d\n", numeroDos);
        printf("\n");
    }
    

    return 0;
}
