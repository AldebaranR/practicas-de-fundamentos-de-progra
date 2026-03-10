#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE 256

// Imprime long
void print_long(const char *name, long v) {
    printf("%s = %ld\n", name, v);
}

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));

    // =============================
    // Declaracion de variables
    // =============================
    long x, y;
    long t;
    long a;
    long mayor;

    long long tmp;   // tipo mas ancho para comparar

    // Relacionales/logicos
    long xi, yi;

    // Bits
    unsigned long ux, uy;

    // Casting
    char c;
    short s;
    int i;
    long long ll;
    float f;
    double d;
    long double ld;

    // =============================
    // Datos de entrada
    // =============================
    x = (long)(rand() % LIMITE);   // 0..255
    y = (long)(rand() % LIMITE);   // 0..255
    if (y == 0) y = 1;

    printf("===== TIPO: long =====\n");
    print_long("x", x);
    print_long("y", y);
    printf("\n");

    xi = x;
    yi = y;

    // =========================
    // A) Operadores aritmeticos
    // =========================
    printf("== Aritmeticos (long) ==\n");

    tmp = (long long)x + (long long)y;
    printf("x + y  = %lld  -> long: %ld\n", tmp, (long)tmp);

    tmp = (long long)x - (long long)y;
    printf("x - y  = %lld  -> long: %ld\n", tmp, (long)tmp);

    tmp = (long long)x * (long long)y;
    printf("x * y  = %lld  -> long: %ld\n", tmp, (long)tmp);

    tmp = (long long)x / (long long)y;
    printf("x / y  = %lld  -> long: %ld (division entera)\n",
           tmp, (long)tmp);

    tmp = (long long)(x % y);
    printf("x %% y  = %lld  -> long: %ld\n",
           tmp, (long)tmp);

    printf("+x     = %ld\n", +x);
    printf("-x     = %ld\n", -x);
    printf("\n");

    // ============================
    // B) Incremento/Decremento
    // ============================
    printf("== Incremento/Decremento ==\n");
    t = x;
    printf("t inicial = %ld\n", t);
    printf("t++  imprime %ld, luego t=%ld\n", t++, t);
    printf("++t  ahora t=%ld\n", ++t);
    printf("t--  imprime %ld, luego t=%ld\n", t--, t);
    printf("--t  ahora t=%ld\n", --t);
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
    ux = (unsigned long)x;
    uy = (unsigned long)y;

    printf("== Bits ==\n");
    printf("~x       = %lu\n", (unsigned long)(~ux));
    printf("x & y    = %lu\n", (unsigned long)(ux & uy));
    printf("x | y    = %lu\n", (unsigned long)(ux | uy));
    printf("x ^ y    = %lu\n", (unsigned long)(ux ^ uy));
    printf("x << 1   = %lu\n", (unsigned long)(ux << 1));
    printf("x >> 1   = %lu\n", (unsigned long)(ux >> 1));
    printf("\n");

    // ============================
    // E) Asignacion y compuestas
    // ============================
    printf("== Asignacion ==\n");
    a = x;
    print_long("a = x", a);

    a += y; print_long("a += y", a);
    a -= y; print_long("a -= y", a);
    a *= y; print_long("a *= y", a);

    a /= y; print_long("a /= y", a);
    a %= y; print_long("a %= y", a);

    a <<= 1; print_long("a <<= 1", a);
    a >>= 1; print_long("a >>= 1", a);

    a &= y;  print_long("a &= y", a);
    a ^= y;  print_long("a ^= y", a);
    a |= y;  print_long("a |= y", a);
    printf("\n");

    // ============================
    // F) Ternario y sizeof
    // ============================
    printf("== Ternario y sizeof ==\n");
    mayor = (x > y) ? x : y;
    print_long("mayor (x>y?x:y)", mayor);

    printf("sizeof(long) = %zu bytes\n", sizeof(long));
    printf("sizeof(x)    = %zu bytes\n", sizeof(x));
    printf("\n");

    // ============================
    // G) Casting (mutacion)
    // ============================
    printf("== Casting desde x ==\n");

    c  = (char)x;
    s  = (short)x;
    i  = (int)x;
    ll = (long long)x;
    f  = (float)x;
    d  = (double)x;
    ld = (long double)x;

    printf("char        = %d\n", (int)c);
    printf("short       = %d\n", (int)s);
    printf("int         = %d\n", i);
    printf("long        = %ld\n", x);
    printf("long long   = %lld\n", ll);
    printf("float       = %f\n", f);
    printf("double      = %lf\n", d);
    printf("long double = %Lf\n", ld);

    return 0;
}