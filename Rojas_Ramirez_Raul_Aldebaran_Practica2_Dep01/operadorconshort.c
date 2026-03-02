#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE 256

// Imprime short como decimal
void print_short(const char *name, short v) {
    printf("%s = %d\n", name, (int)v);
}

int main(void) {
    srand((unsigned)time(NULL));

    // === Datos de entrada (NO se modifican) ===
    short x = (short)(rand() % LIMITE);   // 0..255
    short y = (short)(rand() % LIMITE);   // 0..255

    // Para evitar division/mod 0:
    if (y == 0) y = 1;

    printf("===== TIPO: short =====\n");
    print_short("x", x);
    print_short("y", y);
    printf("\n");

    // Para relacionales/logicos, promover a int
    int xi = (int)x;
    int yi = (int)y;

    // =========================
    // A) Operadores aritmeticos
    // =========================
    printf("== Aritmeticos ==\n");

    // Para VER overflow: calculo en long y luego asigno a short
    long tmp;

    tmp = (long)x + (long)y;
    short suma = (short)tmp;
    printf("x + y  = %ld  -> short: %d\n", tmp, (int)suma);

    tmp = (long)x - (long)y;
    short resta = (short)tmp;
    printf("x - y  = %ld  -> short: %d\n", tmp, (int)resta);

    tmp = (long)x * (long)y;
    short mult = (short)tmp;
    printf("x * y  = %ld  -> short: %d\n", tmp, (int)mult);

    // division entera (sin overflow típico aquí, pero mantengo el formato)
    tmp = (long)x / (long)y;
    short divi = (short)tmp;
    printf("x / y  = %ld  -> short: %d  (division entera)\n", tmp, (int)divi);

    tmp = (long)(x % y);
    short mod = (short)tmp;
    printf("x %% y  = %ld  -> short: %d\n", tmp, (int)mod);

    printf("+x     = %d\n", +xi);
    printf("-x     = %d\n", -xi);
    printf("\n");

    // ============================
    // B) Inc/Dec (con una copia)
    // ============================
    printf("== Incremento/Decremento ==\n");
    short t = x;
    printf("t inicial = %d\n", (int)t);
    printf("t++  imprime %d, luego t=%d\n", (int)t++, (int)t);
    printf("++t  ahora t=%d\n", (int)++t);
    printf("t--  imprime %d, luego t=%d\n", (int)t--, (int)t);
    printf("--t  ahora t=%d\n", (int)--t);
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
    // Para bits: usar unsigned (evitas líos con signo)
    unsigned short ux = (unsigned short)x;
    unsigned short uy = (unsigned short)y;

    printf("== Bits ==\n");
    printf("~x       = %u\n", (unsigned)(unsigned short)(~ux));
    printf("x & y    = %u\n", (unsigned)(ux & uy));
    printf("x | y    = %u\n", (unsigned)(ux | uy));
    printf("x ^ y    = %u\n", (unsigned)(ux ^ uy));
    printf("x << 1   = %u\n", (unsigned)(unsigned short)(ux << 1));
    printf("x >> 1   = %u\n", (unsigned)(ux >> 1));
    printf("\n");

    // ============================
    // E) Asignacion y compuestas
    // ============================
    printf("== Asignacion ==\n");
    short a = x;          // =
    print_short("a = x", a);

    a += y; print_short("a += y", a);
    a -= y; print_short("a -= y", a);
    a *= y; print_short("a *= y", a);

    a /= y; print_short("a /= y", a);
    a %= y; print_short("a %= y", a);

    // shifts con cuidado: en C se promueven a int, luego vuelven a short
    a = (short)(a << 1);  print_short("a <<= 1", a);
    a = (short)(a >> 1);  print_short("a >>= 1", a);

    a = (short)(a & y);   print_short("a &= y", a);
    a = (short)(a ^ y);   print_short("a ^= y", a);
    a = (short)(a | y);   print_short("a |= y", a);
    printf("\n");

    // ============================
    // F) Ternario y sizeof
    // ============================
    printf("== Ternario y sizeof ==\n");
    short mayor = (x > y) ? x : y;
    print_short("mayor (x>y?x:y)", mayor);

    printf("sizeof(short) = %zu bytes\n", sizeof(short));
    printf("sizeof(x)     = %zu bytes\n", sizeof(x));
    printf("\n");

    // ============================
    // G) Casting (mutacion)
    // ============================
    printf("== Casting desde x ==\n");
    char c = (char)x;
    short s = (short)x;
    int i = (int)x;
    long l = (long)x;
    long long ll = (long long)x;
    float f = (float)x;
    double d = (double)x;
    long double ld = (long double)x;

    printf("char        = %d\n", (int)c);
    printf("short       = %d\n", (int)s);
    printf("int         = %d\n", i);
    printf("long        = %ld\n", l);
    printf("long long   = %lld\n", ll);
    printf("float       = %f\n", f);
    printf("double      = %lf\n", d);
    printf("long double = %Lf\n", ld);

    return 0;
}