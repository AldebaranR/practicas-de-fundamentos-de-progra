#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LIMITE 256

// Imprime long double
void print_ld(const char *name, long double v) {
    printf("%s = %.15Lf\n", name, v);
}

int main(void) {
    srand((unsigned)time(NULL));

    // =============================
    // Declaracion de variables
    // =============================
    long double x, y;
    long double t;
    long double a;
    long double mayor;

    long double tmp;

    // Para relacionales/logicos
    long double xl, yl;

    // Para modulo
    long double modv;

    // Casting
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;

    // =============================
    // Datos de entrada
    // =============================
    x = (long double)(rand() % LIMITE);
    y = (long double)(rand() % LIMITE);
    if (y == 0.0L) y = 1.0L;

    printf("===== TIPO: long double =====\n");
    print_ld("x", x);
    print_ld("y", y);
    printf("\n");

    xl = x;
    yl = y;

    // =========================
    // A) Operadores aritmeticos
    // =========================
    printf("== Aritmeticos (long double) ==\n");

    tmp = x + y;
    printf("x + y  = %.20Lf\n", tmp);

    tmp = x - y;
    printf("x - y  = %.20Lf\n", tmp);

    tmp = x * y;
    printf("x * y  = %.20Lf\n", tmp);

    tmp = x / y;
    printf("x / y  = %.20Lf\n", tmp);

    modv = fmodl(x, y);
    printf("fmodl(x, y) = %.20Lf\n", modv);

    printf("+x     = %.20Lf\n", +x);
    printf("-x     = %.20Lf\n", -x);
    printf("\n");

    // ============================
    // B) Incremento/Decremento
    // ============================
    printf("== Incremento/Decremento ==\n");
    t = x;
    printf("t inicial = %.15Lf\n", t);
    printf("t++  imprime %.15Lf, luego t=%.15Lf\n", t++, t);
    printf("++t  ahora t=%.15Lf\n", ++t);
    printf("t--  imprime %.15Lf, luego t=%.15Lf\n", t--, t);
    printf("--t  ahora t=%.15Lf\n", --t);
    printf("\n");

    // =========================
    // C) Relacionales y logicos
    // =========================
    printf("== Relacionales ==\n");
    printf("x <  y  -> %d\n", xl <  yl);
    printf("x <= y  -> %d\n", xl <= yl);
    printf("x >  y  -> %d\n", xl >  yl);
    printf("x >= y  -> %d\n", xl >= yl);
    printf("x == y  -> %d\n", xl == yl);
    printf("x != y  -> %d\n", xl != yl);
    printf("\n");

    printf("== Logicos ==\n");
    printf("!x        -> %d\n", !xl);
    printf("(x && y)  -> %d\n", (xl && yl));
    printf("(x || y)  -> %d\n", (xl || yl));
    printf("\n");

    // =================
    // D) Bits
    // =================
    printf("== Bits ==\n");
    printf("NO APLICA para long double (solo enteros)\n\n");

    // ============================
    // E) Asignacion y compuestas
    // ============================
    printf("== Asignacion ==\n");
    a = x;
    print_ld("a = x", a);

    a += y; print_ld("a += y", a);
    a -= y; print_ld("a -= y", a);
    a *= y; print_ld("a *= y", a);

    a /= y; print_ld("a /= y", a);

    printf("NO APLICA: %%, <<=, >>=, &=, ^=, |= para long double\n");
    printf("\n");

    // ============================
    // F) Ternario y sizeof
    // ============================
    printf("== Ternario y sizeof ==\n");
    mayor = (x > y) ? x : y;
    print_ld("mayor (x>y?x:y)", mayor);

    printf("sizeof(long double) = %zu bytes\n", sizeof(long double));
    printf("sizeof(x)           = %zu bytes\n", sizeof(x));
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
    d  = (double)x;

    printf("char        = %d\n", (int)c);
    printf("short       = %d\n", (int)s);
    printf("int         = %d\n", i);
    printf("long        = %ld\n", l);
    printf("long long   = %lld\n", ll);
    printf("float       = %f\n", f);
    printf("double      = %lf\n", d);
    printf("long double = %.15Lf\n", x);

    return 0;
}