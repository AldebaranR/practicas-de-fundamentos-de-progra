#include <stdio.h>

int main(int argc, char *argv[]) {

    int tiempo=-1;
    int aceleracion = 32;
    int producto;
    float distancia;

    while (tiempo<0)
    {
        printf("Ingrese el tiempo en segundos (no valores negativos): ");
        scanf("%d", &tiempo);
    }
    

    producto = aceleracion * tiempo * tiempo;

    distancia = producto / 2.0;

    printf("El objeto avanza una distancia de %.2f pies en caida libre.\n", distancia);

    return 0;
}