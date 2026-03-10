#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LIMITE 256

// Imprime double
void print_double(const char *name, double v) {
    printf("%s = %.10f\n", name, v);
}

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));

    // =============================
    // Declaracion de variables
    // =============================
    double x, y;
    double t;
    double a;
    double mayor;

    long double tmp;   // mas ancho para comparar (double -> long double)

    // Para relacionales/logicos
    double xd, yd;

    // Para "mod" en double
    double modv;

    // Casting
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    long double ld;

    // =============================
    // Datos de entrada
    // =============================
    x = (double)(rand() % LIMITE);   // 0..255 como double
    y = (double)(rand() % LIMITE);   // 0..255 como double
    if (y == 0.0) y = 1.0;           // evitar division/mod 0

    printf("===== TIPO: double =====\n");
    print_double("x", x);
    print_double("y", y);
    printf("\n");

    xd = x;
    yd = y;

    // =========================
    // A) Operadores aritmeticos
    // =========================
    printf("== Aritmeticos (double) ==\n");

    tmp = (long double)x + (long double)y;
    printf("x + y  = %.20Lf  -> double: %.10f\n", tmp, (double)tmp);

    tmp = (long double)x - (long double)y;
    printf("x - y  = %.20Lf  -> double: %.10f\n", tmp, (double)tmp);

    tmp = (long double)x * (long double)y;
    printf("x * y  = %.20Lf  -> double: %.10f\n", tmp, (double)tmp);

    tmp = (long double)x / (long double)y;
    printf("x / y  = %.20Lf  -> double: %.10f\n", tmp, (double)tmp);

    // "mod" en double: fmod
    modv = fmod(x, y);
    printf("fmod(x, y) = %.10f\n", modv);

    printf("+x     = %.10f\n", +x);
    printf("-x     = %.10f\n", -x);
    printf("\n");

    // ============================
    // B) Incremento/Decremento
    // ============================
    printf("== Incremento/Decremento ==\n");
    t = x;
    printf("t inicial = %.10f\n", t);
    printf("t++  imprime %.10f, luego t=%.10f\n", t++, t);
    printf("++t  ahora t=%.10f\n", ++t);
    printf("t--  imprime %.10f, luego t=%.10f\n", t--, t);
    printf("--t  ahora t=%.10f\n", --t);
    printf("\n");

    // =========================
    // C) Relacionales y logicos
    // =========================
    printf("== Relacionales ==\n");
    printf("x <  y  -> %d\n", xd <  yd);
    printf("x <= y  -> %d\n", xd <= yd);
    printf("x >  y  -> %d\n", xd >  yd);
    printf("x >= y  -> %d\n", xd >= yd);
    printf("x == y  -> %d\n", xd == yd);
    printf("x != y  -> %d\n", xd != yd);
    printf("\n");

    printf("== Logicos ==\n");
    printf("!x        -> %d\n", !xd);
    printf("(x && y)  -> %d\n", (xd && yd));
    printf("(x || y)  -> %d\n", (xd || yd));
    printf("\n");

    // =================
    // D) Bits
    // =================
    printf("== Bits ==\n");
    printf("NO APLICA para double (solo enteros)\n\n");

    // ============================
    // E) Asignacion y compuestas
    // ============================
    printf("== Asignacion ==\n");
    a = x;
    print_double("a = x", a);

    a += y; print_double("a += y", a);
    a -= y; print_double("a -= y", a);
    a *= y; print_double("a *= y", a);

    a /= y; print_double("a /= y", a);

    printf("NO APLICA: %%, %%, <<=, >>=, &=, ^=, |= para double\n");
    printf("\n");

    // ============================
    // F) Ternario y sizeof
    // ============================
    printf("== Ternario y sizeof ==\n");
    mayor = (x > y) ? x : y;
    print_double("mayor (x>y?x:y)", mayor);

    printf("sizeof(double) = %zu bytes\n", sizeof(double));
    printf("sizeof(x)      = %zu bytes\n", sizeof(x));
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
    f  = (float)x;
    ld = (long double)x;

    printf("char        = %d\n", (int)c);
    printf("short       = %d\n", (int)s);
    printf("int         = %d\n", i);
    printf("long        = %ld\n", l);
    printf("long long   = %lld\n", ll);
    printf("float       = %f\n", f);
    printf("double      = %.10f\n", x);
    printf("long double = %Lf\n", ld);

    return 0;
}