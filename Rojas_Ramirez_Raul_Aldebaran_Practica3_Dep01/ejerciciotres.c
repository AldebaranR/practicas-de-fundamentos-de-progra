#include <stdio.h>

int main(int argc, char *argv[]) {

    int cuartos, decimos, quintos;
    int valorMonetario;

    printf("Ingrese la cantidad de cuartos: ");
    scanf("%d", &cuartos);

    printf("Ingrese la cantidad de monedas de diez centavos: ");
    scanf("%d", &decimos);

    printf("Ingrese la cantidad de monedas de cinco centavos: ");
    scanf("%d", &quintos);

    valorMonetario = (25 * cuartos) + (10 * decimos) + (5 * quintos);

    printf("Las monedas valen %d centavos.\n", valorMonetario);

    return 0;
}