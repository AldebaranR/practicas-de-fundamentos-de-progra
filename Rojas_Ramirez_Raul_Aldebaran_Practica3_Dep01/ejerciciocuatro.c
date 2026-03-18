#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int opcionSeleccionada;
    double tiempoCaida, aceleracionGravedad = 32.0, distanciaCaida;
    double radioTierra = 6371.0; // Radio en kilómetros
    double porcentajeGravedad, fraccionGravedad, alturaKilometros, alturaMetros, alturaPies;

    printf("=== MENU DE OPCIONES ===\n");
    printf("1) Calcular distancia de caida libre\n");
    printf("2) Calcular altura donde la gravedad es un porcentaje especifico\n");
    printf("Seleccione una opcion (1 o 2): ");
    scanf("%d", &opcionSeleccionada);

    switch(opcionSeleccionada) {
        case 1:
            printf("Ingrese el tiempo de caida en segundos: ");
            scanf("%lf", &tiempoCaida);

            // Calcular distancia de caída
            distanciaCaida = (aceleracionGravedad * pow(tiempoCaida, 2)) / 2.0;

            // Convertir la distancia a metros y kilómetros
            double distanciaMetros = distanciaCaida * 0.3048; // 1 pie = 0.3048 metros
            double distanciaKilometros = distanciaMetros / 1000.0; // 1 km = 1000 metros

            printf("\nEl objeto ha caido:\n");
            printf("- %.2lf pies en %.2lf segundos.\n", distanciaCaida, tiempoCaida);
            printf("- %.2lf metros en %.2lf segundos.\n", distanciaMetros, tiempoCaida);
            printf("- %.4lf kilometros en %.2lf segundos.\n", distanciaKilometros, tiempoCaida); // Mostramos más decimales para kilómetros
            break;

        case 2:
            printf("Ingrese el porcentaje de gravedad deseado (por ejemplo: 10 para el 10%%): ");
            scanf("%lf", &porcentajeGravedad);

            fraccionGravedad = porcentajeGravedad / 100.0;

            if (fraccionGravedad <= 0 || fraccionGravedad >= 1) {
                printf("Error: El porcentaje debe ser mayor que 0 y menor que 100.\n");
                return 1;
            }

            // Calcular altura en kilómetros
            alturaKilometros = radioTierra * ((1.0 / sqrt(fraccionGravedad)) - 1.0);
            alturaMetros = alturaKilometros * 1000.0;
            alturaPies = alturaMetros * 3.28084;

            printf("\n--- ALTURAS SEGUN LA GRAVEDAD ---\n");
            printf("Gravedad al %.2lf%% respecto al valor en la superficie terrestre:\n", porcentajeGravedad);
            printf("Altura estimada:\n");
            printf("- %.2lf km\n", alturaKilometros);
            printf("- %.2lf m\n", alturaMetros);
            printf("- %.2lf ft\n", alturaPies);
            break;

        default:
            printf("Opción no valida. Por favor, seleccione 1 o 2.\n");
    }

    return 0;
}