#include <stdio.h>

int main(int argc, char *argv[]) {

    int enteroUno, enteroDos;
    int suma, producto;

    printf("Ingrese el primer entero: ");
    scanf("%d", &enteroUno);

    printf("Ingrese el segundo entero: ");
    scanf("%d", &enteroDos);

    suma = enteroUno + enteroDos;
    producto = enteroUno * enteroDos;

    printf("\n%d + %d = %d\n", enteroUno, enteroDos, suma);
    printf("%d * %d = %d\n", enteroUno, enteroDos, producto);

    printf("Este es el final del programa.");

    return 0;
}