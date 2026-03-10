/*
Desarrollar un simulador de juego de fútbol. Su simulador debería funcionar de 
la siguiente manera:
    • Un generador de números aleatorios debe generar un número y este será el 
      número de eventos en un juego. 
    Este valor debe estar entre 12 y 25.
    • Su programa debería entonces generar este número de eventos. Para cada 
      evento, debe generar un número aleatorio entre 1 y 6.
        ◦ Si el número generado ahora es 1, entonces el primer equipo ha 
          marcado un gol.
        ◦ Si se es 2, entonces el segundo equipo ha marcado un gol.
        ◦ Si el número es 3, el primer equipo ha cometido un fuera de juego.
        ◦ Si es un 4 entonces el segundo equipo ha cometido un fuera de juego.
        ◦ Si el número es 5, el primer equipo comete penalti.
        ◦ Si es 6, el segundo equipo recibe un penalti.
Para decidir el resultado de la sanción (penalti), su programa debe 
generar otro número aleatorio entre 1 y 4.
        ◦ Si este número es 1 o 3, el equipo anota de penalti,
        ◦ Si es 2 o 4, falla el penalti,
    • Para decidir el resultado de la sanción (penalti), su programa debe 
      generar otro número aleatorio entre 1 y 4.
        ◦ Un 2 o 3 significa que reciben una tarjeta amarilla.
        ◦ Un 1 o 4 significa una tarjeta roja para el equipo.
Para cada evento generado, su programa debe generar una declaración dando un 
comentario sobre ese evento, como "El equipo 1 anotó un gol". Al final del 
programa, debe imprimir la puntuación final del juego. En el inicio de su 
función principal inicialice el generador de números aleatorios con el la hora 
actual usando la función rand()
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define EVENTOS 26
#define MOMENTOS 10
#define EQUIPOS 2
#define NOMBRE 80
#define PENA_MAXIMA 4
#define MAX_STATS 13

int main(int argc, char *argv[]) {
    int accion, contador = 0, penal, sancion, x, y, longitud, esquina;
    char equipos[EQUIPOS][NOMBRE];
    int estadisticas[EQUIPOS][MAX_STATS];
    
    srand(time(NULL));
    int numeroEventos = rand() % EVENTOS;
    
    if(numeroEventos<12) {
        numeroEventos = 12;
    }
    
    for(y=0; y<EQUIPOS; y++) {
        for(x=0; x<MAX_STATS; x++) {
            estadisticas[y][x] = 0;
        }
    }
    
    printf("Simulador de futbol.\n");
    printf("Nombre del primer equipo: ");
    fgets(equipos[0], NOMBRE, stdin);
    longitud = strlen(equipos[0]);
    equipos[0][longitud-1] = '\0';
    
    printf("Nombre del segundo equipo: ");
    fgets(equipos[1], NOMBRE, stdin);
    longitud = strlen(equipos[1]);
    equipos[1][longitud-1] = '\0';
    
    while(contador<numeroEventos) {
        accion = (rand() % MOMENTOS) + 1;
        switch(accion) {
            case 1:
                printf("GOOOOOOOOLLLLL de %s\n", equipos[0]);
                estadisticas[0][0]++;
                break;
            case 2:
                printf("GOOOOOOOOLLLLL de %s\n", equipos[1]);
                estadisticas[1][0]++;
                break;
            case 3:
                printf("Fuera de lugar de %s\n", equipos[0]);
                estadisticas[0][6]++;
                break;
            case 4:
                printf("Fuera de lugar de %s\n", equipos[1]);
                estadisticas[1][6]++;
                break;
            case 5:
                printf("PENALLLLLTYYYY cometido por %s\n", equipos[0]);
                estadisticas[0][3]++;
                sancion = (rand() % PENA_MAXIMA) + 1;
                switch(sancion) {
                    case 2:
                    case 3:
                        printf("Tarjeta amarilla para %s\n", equipos[0]);
                        estadisticas[0][1]++;
                        break;
                    case 1:
                    case 4:
                        printf("Tarjeta roja para %s\n", equipos[0]);
                        estadisticas[0][2]++;
                        break;
                }
                penal = (rand() % PENA_MAXIMA) + 1;
                switch(penal) {
                    case 1:
                    case 3:
                        printf("GOLAZOOOOOO de %s\n", equipos[1]);
                        estadisticas[1][4]++;
                        break; 
                    case 2:
                    case 4:
                        printf("VOLO LA PELOTA, HA FALLADO %s\n", equipos[1]);
                        estadisticas[1][5]++;
                        break;
                }
                break;
            case 6:
                printf("PENALLLLLTYYYY cometido por %s\n", equipos[1]);
                estadisticas[1][3]++;
                sancion = (rand() % PENA_MAXIMA) + 1;
                switch(sancion) {
                    case 2:
                    case 3:
                        printf("Tarjeta amarilla para %s\n", equipos[1]);
                        estadisticas[1][1]++;
                        break;
                    case 1:
                    case 4:
                        printf("Tarjeta roja para %s\n", equipos[1]);
                        estadisticas[1][2]++;
                        break;
                }
                penal = (rand() % PENA_MAXIMA) + 1;
                switch(penal) {
                    case 1:
                    case 3:
                        printf("GOLAZOOOOOO de %s\n", equipos[0]);
                        estadisticas[0][4]++;
                        break; 
                    case 2:
                    case 4:
                        printf("VOLO LA PELOTA, HA FALLADO %s\n", equipos[0]);
                        estadisticas[0][5]++;
                        break;
                }
                break;
            case 7:
                printf("Saque de banda para %s\n", equipos[0]);
                estadisticas[0][8]++;
                break;
            case 8:
                printf("Saque de banda para %s\n", equipos[1]);
                estadisticas[1][8]++;
                break;
            case 9:
                printf("Tiro de esquina para %s\n", equipos[0]);
                estadisticas[0][9]++;
                esquina = (rand() % 4) + 1;
                switch(esquina) {
                    case 1:
                        printf("%s cobra el tiro de esquina pero no genera peligro\n", equipos[0]);
                        break;
                    case 2:
                        printf("GOOOOOOOOLLLLL OLIMPICO de %s\n", equipos[0]);
                        estadisticas[0][10]++;
                        break;
                    case 3:
                        printf("GOOOOOOOOLLLLL de cabeza de %s\n", equipos[0]);
                        estadisticas[0][11]++;
                        break;
                    case 4:
                        printf("GOOOOOOOOLLLLL por tiro de esquina de %s\n", equipos[0]);
                        estadisticas[0][12]++;
                        break;
                }
                break;
            case 10:
                printf("Tiro de esquina para %s\n", equipos[1]);
                estadisticas[1][9]++;
                esquina = (rand() % 4) + 1;
                switch(esquina) {
                    case 1:
                        printf("%s cobra el tiro de esquina pero no genera peligro\n", equipos[1]);
                        break;
                    case 2:
                        printf("GOOOOOOOOLLLLL OLIMPICO de %s\n", equipos[1]);
                        estadisticas[1][10]++;
                        break;
                    case 3:
                        printf("GOOOOOOOOLLLLL de cabeza de %s\n", equipos[1]);
                        estadisticas[1][11]++;
                        break;
                    case 4:
                        printf("GOOOOOOOOLLLLL por tiro de esquina de %s\n", equipos[1]);
                        estadisticas[1][12]++;
                        break;
                }
                break;
        }
        contador++;
    }
    
    printf("\tResumen del partido\n");
    printf("%s\t\tVS\t\t%s\n", equipos[0], equipos[1]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][0], "goles anotados", estadisticas[1][0]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][1], "tarjeta amarilla", estadisticas[1][1]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][2], "tarjeta roja", estadisticas[1][2]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][3], "penal cometido", estadisticas[1][3]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][4], "penal anotado", estadisticas[1][4]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][5], "penal fallado", estadisticas[1][5]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][6], "fuera de lugar", estadisticas[1][6]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][8], "saques de banda", estadisticas[1][8]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][9], "tiros de esquina", estadisticas[1][9]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][10], "gol olimpico", estadisticas[1][10]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][11], "gol de cabeza", estadisticas[1][11]);
    printf("%3d\t%-20s\t%3d\n", estadisticas[0][12], "gol por esquina", estadisticas[1][12]);
    
    estadisticas[0][7] = estadisticas[0][0] + estadisticas[0][4] + estadisticas[0][10] + estadisticas[0][11] + estadisticas[0][12];
    estadisticas[1][7] = estadisticas[1][0] + estadisticas[1][4] + estadisticas[1][10] + estadisticas[1][11] + estadisticas[1][12];
    
    printf("  %d\t marcador final \t%d\n", estadisticas[0][7], estadisticas[1][7]);
    
    if(estadisticas[0][7]>estadisticas[1][7]) {
        printf("GANO el equipo %s\n", equipos[0]);       
    }
    else if(estadisticas[0][7]<estadisticas[1][7]) {
        printf("GANO el equipo %s\n", equipos[1]);       
    }
    else {
        printf("TRISTE empate\n");
    }
    
    return 0;
}