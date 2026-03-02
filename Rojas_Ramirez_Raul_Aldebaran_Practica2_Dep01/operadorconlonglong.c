#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE 256

// Imprime long long
void print_ll(const char *name, long long v) {
    printf("%s = %lld\n", name, v);
}

int main(void) {
    srand((unsigned)time(NULL));

    // =============================
    // Declaracion de variables
    // =============================
    long long x, y;
    long long t;
    long long a;
    long long mayor;

    long long tmp;   // mismo ancho (no necesitamos mas grande)

    // Relacionales/logicos
    long long xi, yi;

    // Bits
    unsigned long long ux, uy;

    // Casting
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    long double ld;

    // =============================
    // Datos de entrada
    // =============================
    x = (long long)(rand() % LIMITE);   // 0..255
    y = (long long)(rand() % LIMITE);   // 0..255
    if (y == 0) y = 1;

    printf("===== TIPO: long long =====\n");
    print_ll("x", x);
    print_ll("y", y);
    printf("\n");

    xi = x;
    yi = y;

    // =========================
    // A) Operadores aritmeticos
    // =========================
    printf("== Aritmeticos (long long) ==\n");

    tmp = x + y;
    printf("x + y  = %lld\n", tmp);

    tmp = x - y;
    printf("x - y  = %lld\n", tmp);

    tmp = x * y;
    printf("x * y  = %lld\n", tmp);

    tmp = x / y;
    printf("x / y  = %lld (division entera)\n", tmp);

    tmp = x % y;
    printf("x %% y  = %lld\n", tmp);

    printf("+x     = %lld\n", +x);
    printf("-x     = %lld\n", -x);
    printf("\n");

    // ============================
    // B) Incremento/Decremento
    // ============================
    printf("== Incremento/Decremento ==\n");
    t = x;
    printf("t inicial = %lld\n", t);
    printf("t++  imprime %lld, luego t=%lld\n", t++, t);
    printf("++t  ahora t=%lld\n", ++t);
    printf("t--  imprime %lld, luego t=%lld\n", t--, t);
    printf("--t  ahora t=%lld\n", --t);
    printf("\n");

    // =========================
    // C) Relacionales y logicos
    // =========================
    printf("== Relacionales ==\n");
    printf("x <  y  -> %d\n", xi <  yi);
    printf("x <= y  -> %d\n", xi <= yi);
    printf("x >  y  -> %d\n", xi >  yi);
    printf("x >= y  -> %d\n", xi >= yi);
    printf("x == y  -> %d\n", xi == yi);
    printf("x != y  -> %d\n", xi != yi);
    printf("\n");

    printf("== Logicos ==\n");
    printf("!x        -> %d\n", !xi);
    printf("(x && y)  -> %d\n", (xi && yi));
    printf("(x || y)  -> %d\n", (xi || yi));
    printf("\n");

    // =================
    // D) Bits
    // =================
    ux = (unsigned long long)x;
    uy = (unsigned long long)y;

    printf("== Bits ==\n");
    printf("~x       = %llu\n", (unsigned long long)(~ux));
    printf("x & y    = %llu\n", (unsigned long long)(ux & uy));
    printf("x | y    = %llu\n", (unsigned long long)(ux | uy));
    printf("x ^ y    = %llu\n", (unsigned long long)(ux ^ uy));
    printf("x << 1   = %llu\n", (unsigned long long)(ux << 1));
    printf("x >> 1   = %llu\n", (unsigned long long)(ux >> 1));
    printf("\n");

    // ============================
    // E) Asignacion y compuestas
    // ============================
    printf("== Asignacion ==\n");
    a = x;
    print_ll("a = x", a);

    a += y; print_ll("a += y", a);
    a -= y; print_ll("a -= y", a);
    a *= y; print_ll("a *= y", a);

    a /= y; print_ll("a /= y", a);
    a %= y; print_ll("a %= y", a);

    a <<= 1; print_ll("a <<= 1", a);
    a >>= 1; print_ll("a >>= 1", a);

    a &= y;  print_ll("a &= y", a);
    a ^= y;  print_ll("a ^= y", a);
    a |= y;  print_ll("a |= y", a);
    printf("\n");

    // ============================
    // F) Ternario y sizeof
    // ============================
    printf("== Ternario y sizeof ==\n");
    mayor = (x > y) ? x : y;
    print_ll("mayor (x>y?x:y)", mayor);

    printf("sizeof(long long) = %zu bytes\n", sizeof(long long));
    printf("sizeof(x)         = %zu bytes\n", sizeof(x));
    printf("\n");

    // ============================
    // G) Casting (mutacion)
    // ============================
    printf("== Casting desde x ==\n");

    c  = (char)x;
    s  = (short)x;
    i  = (int)x;
    l  = (long)x;
    f  = (float)x;
    d  = (double)x;
    ld = (long double)x;

    printf("char        = %d\n", (int)c);
    printf("short       = %d\n", (int)s);
    printf("int         = %d\n", i);
    printf("long        = %ld\n", l);
    printf("long long   = %lld\n", x);
    printf("float       = %f\n", f);
    printf("double      = %lf\n", d);
    printf("long double = %Lf\n", ld);

    return 0;
}