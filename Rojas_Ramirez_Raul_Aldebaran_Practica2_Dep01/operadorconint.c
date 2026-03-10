// programa1_int.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE 256

// Imprime int
void print_int(const char *name, int v) {
    printf("%s = %d\n", name, v);
    if (v >= 32 && v <= 126) printf(" ('%c')", v);
    printf("\n");
}

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));

    // === Variables declaradas al inicio (como pide la practica) ===
    int x, y;
    int xi, yi;
    long long tmp;

    // Incremento/decremento
    int t;

    // Bits
    unsigned int ux, uy;

    // Asignacion
    int a;

    // Ternario
    int mayor;

    // Casting (mutacion)
    char c;
    short s;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;

    x = (int)(rand() % LIMITE);   // 0..255
    y = (int)(rand() % LIMITE);   // 0..255
    if (y == 0) y = 1;            // evitar div/mod 0

    printf("===== TIPO: int =====\n");
    print_int("x", x);
    print_int("y", y);
    printf("\n");

    xi = x;
    yi = y;

    // =========================
    // A) Operadores aritmeticos
    // =========================
    printf("== Aritmeticos (int) ==\n");

    tmp = (long long)x + (long long)y;
    printf("x + y  = %lld  -> int: %d\n", tmp, (int)tmp);

    tmp = (long long)x - (long long)y;
    printf("x - y  = %lld  -> int: %d\n", tmp, (int)tmp);

    tmp = (long long)x * (long long)y;
    printf("x * y  = %lld  -> int: %d\n", tmp, (int)tmp);

    tmp = (long long)x / (long long)y;
    printf("x / y  = %lld  -> int: %d (division entera)\n", tmp, (int)tmp);

    tmp = (long long)(x % y);
    printf("x %% y  = %lld  -> int: %d\n", tmp, (int)tmp);

    printf("+x     = %d\n", +x);
    printf("-x     = %d\n", -x);
    printf("\n");

    // ============================
    // B) Inc/Dec (con una copia)
    // ============================
    printf("== Incremento/Decremento ==\n");
    t = x;
    printf("t inicial = %d\n", t);
    printf("t++  imprime %d, luego t=%d\n", t++, t);
    printf("++t  ahora t=%d\n", ++t);
    printf("t--  imprime %d, luego t=%d\n", t--, t);
    printf("--t  ahora t=%d\n", --t);
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
    // D) Bits (enteros)
    // =================
    ux = (unsigned int)x;
    uy = (unsigned int)y;

    printf("== Bits ==\n");
    printf("~x       = %u\n", (unsigned)(~ux));
    printf("x & y    = %u\n", (unsigned)(ux & uy));
    printf("x | y    = %u\n", (unsigned)(ux | uy));
    printf("x ^ y    = %u\n", (unsigned)(ux ^ uy));
    printf("x << 1   = %u\n", (unsigned)(ux << 1));
    printf("x >> 1   = %u\n", (unsigned)(ux >> 1));
    printf("\n");

    // ============================
    // E) Asignacion y compuestas
    // ============================
    printf("== Asignacion ==\n");
    a = x;            // =
    print_int("a = x", a);

    a += y; print_int("a += y", a);
    a -= y; print_int("a -= y", a);
    a *= y; print_int("a *= y", a);

    a /= y; print_int("a /= y", a);
    a %= y; print_int("a %= y", a);

    a <<= 1; print_int("a <<= 1", a);
    a >>= 1; print_int("a >>= 1", a);

    a &= y;  print_int("a &= y", a);
    a ^= y;  print_int("a ^= y", a);
    a |= y;  print_int("a |= y", a);
    printf("\n");

    // ============================
    // F) Ternario y sizeof
    // ============================
    printf("== Ternario y sizeof ==\n");
    mayor = (x > y) ? x : y;
    print_int("mayor (x>y?x:y)", mayor);

    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    printf("sizeof(x)   = %zu bytes\n", sizeof(x));
    printf("\n");

    // ============================
    // G) Casting (mutacion)
    // ============================
    printf("== Casting desde x ==\n");
    c  = (char)x;
    s  = (short)x;
    l  = (long)x;
    ll = (long long)x;
    f  = (float)x;
    d  = (double)x;
    ld = (long double)x;

    printf("char        = %d\n", (int)c);
    printf("short       = %d\n", (int)s);
    printf("int         = %d\n", x);
    printf("long        = %ld\n", l);
    printf("long long   = %lld\n", ll);
    printf("float       = %f\n", f);
    printf("double      = %lf\n", d);
    printf("long double = %Lf\n", ld);

    return 0;
}