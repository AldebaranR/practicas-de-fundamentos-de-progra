#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    char letraMinusculaUno, letraMinusculaDos;
    char letraMayusculaUno, letraMayusculaDos;
    char caracterUno, caracterDos;

    // Inicializa la semilla para números aleatorios
    srand(time(NULL));

    // Genera letras minúsculas (ASCII 97 - 122)
    letraMinusculaUno = rand() % 26 + 97;
    letraMinusculaDos = rand() % 26 + 97;

    // Genera letras mayúsculas (ASCII 65 - 90)
    letraMayusculaUno = rand() % 26 + 65;
    letraMayusculaDos = rand() % 26 + 65;

    // Genera caracteres imprimibles (ASCII 33 - 126)
    caracterUno = rand() % 94 + 33;
    caracterDos = rand() % 94 + 33;

    // Imprime los resultados
    printf("Letras minusculas:\n");
    printf("letraMinusculaUno = %c\n", letraMinusculaUno);
    printf("letraMinusculaDos = %c\n\n", letraMinusculaDos);

    printf("Letras mayusculas:\n");
    printf("letraMayusculaUno = %c\n", letraMayusculaUno);
    printf("letraMayusculaDos = %c\n\n", letraMayusculaDos);

    printf("Caracteres ASCII imprimibles:\n");
    printf("caracterUno = %c\n", caracterUno);
    printf("caracterDos = %c\n", caracterDos);

    return 0;
}