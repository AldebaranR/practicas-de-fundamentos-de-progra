#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LIMITE 256

// Imprime float
void print_float(const char *name, float v) {
    printf("%s = %f\n", name, v);
}

int main(void) {
    srand((unsigned)time(NULL));

    // =============================
    // Declaracion de variables
    // =============================
    float x, y;
    float t;
    float a;
    float mayor;

    double tmp; // mas ancho para comparar (float -> double)

    // Para relacionales/logicos
    float xf, yf;

    // Para modulo con float
    float modf;

    // Casting
    char c;
    short s;
    int i;
    long l;
    long long ll;
    double d;
    long double ld;

    // =============================
    // Datos de entrada
    // =============================
    x = (float)(rand() % LIMITE);   // 0..255 como float
    y = (float)(rand() % LIMITE);   // 0..255 como float
    if (y == 0.0f) y = 1.0f;        // evitar division/mod 0

    printf("===== TIPO: float =====\n");
    print_float("x", x);
    print_float("y", y);
    printf("\n");

    xf = x;
    yf = y;

    // =========================
    // A) Operadores aritmeticos
    // =========================
    printf("== Aritmeticos (float) ==\n");

    tmp = (double)x + (double)y;
    printf("x + y  = %.10f  -> float: %f\n", tmp, (float)tmp);

    tmp = (double)x - (double)y;
    printf("x - y  = %.10f  -> float: %f\n", tmp, (float)tmp);

    tmp = (double)x * (double)y;
    printf("x * y  = %.10f  -> float: %f\n", tmp, (float)tmp);

    tmp = (double)x / (double)y;
    printf("x / y  = %.10f  -> float: %f\n", tmp, (float)tmp);

    // "mod" en float: fmodf
    modf = fmodf(x, y);
    printf("fmodf(x, y) = %f\n", modf);

    printf("+x     = %f\n", +x);
    printf("-x     = %f\n", -x);
    printf("\n");

    // ============================
    // B) Incremento/Decremento
    // ============================
    printf("== Incremento/Decremento ==\n");
    t = x;
    printf("t inicial = %f\n", t);
    printf("t++  imprime %f, luego t=%f\n", t++, t);
    printf("++t  ahora t=%f\n", ++t);
    printf("t--  imprime %f, luego t=%f\n", t--, t);
    printf("--t  ahora t=%f\n", --t);
    printf("\n");

    // =========================
    // C) Relacionales y logicos
    // =========================
    printf("== Relacionales ==\n");
    printf("x <  y  -> %d\n", xf <  yf);
    printf("x <= y  -> %d\n", xf <= yf);
    printf("x >  y  -> %d\n", xf >  yf);
    printf("x >= y  -> %d\n", xf >= yf);
    printf("x == y  -> %d\n", xf == yf);
    printf("x != y  -> %d\n", xf != yf);
    printf("\n");

    printf("== Logicos ==\n");
    // En C, cualquier valor distinto de 0.0 es "true"
    printf("!x        -> %d\n", !xf);
    printf("(x && y)  -> %d\n", (xf && yf));
    printf("(x || y)  -> %d\n", (xf || yf));
    printf("\n");

    // =================
    // D) Bits
    // =================
    printf("== Bits ==\n");
    printf("NO APLICA para float (solo enteros)\n\n");

    // ============================
    // E) Asignacion y compuestas
    // ============================
    printf("== Asignacion ==\n");
    a = x;
    print_float("a = x", a);

    a += y; print_float("a += y", a);
    a -= y; print_float("a -= y", a);
    a *= y; print_float("a *= y", a);

    a /= y; print_float("a /= y", a);

    // En float no existe %=, <<=, >>=, &=, ^=, |=
    printf("NO APLICA: %%, %%, <<=, >>=, &=, ^=, |= para float\n");
    printf("\n");

    // ============================
    // F) Ternario y sizeof
    // ============================
    printf("== Ternario y sizeof ==\n");
    mayor = (x > y) ? x : y;
    print_float("mayor (x>y?x:y)", mayor);

    printf("sizeof(float) = %zu bytes\n", sizeof(float));
    printf("sizeof(x)     = %zu bytes\n", sizeof(x));
    printf("\n");

    // ============================
    // G) Casting (mutacion)
    // ============================
    printf("== Casting desde x ==\n");

    c  = (char)x;
    s  = (short)x;
    i  = (int)x;
    l  = (long)x;
    ll = (long long)x;
    d  = (double)x;
    ld = (long double)x;

    printf("char        = %d\n", (int)c);
    printf("short       = %d\n", (int)s);
    printf("int         = %d\n", i);
    printf("long        = %ld\n", l);
    printf("long long   = %lld\n", ll);
    printf("float       = %f\n", x);
    printf("double      = %lf\n", d);
    printf("long double = %Lf\n", ld);

    return 0;
}