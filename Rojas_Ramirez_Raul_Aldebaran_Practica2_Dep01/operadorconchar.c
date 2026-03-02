#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE 256

// Imprime char como numero (0..255) y como caracter si es imprimible
void print_uchar(const char *name, unsigned char v) {
    printf("%s = %3u", name, (unsigned)v);
    if (v >= 32 && v <= 126) printf(" ('%c')", v);
    printf("\n");
}

int main(void) {
    srand((unsigned)time(NULL));

    // === Datos de entrada (NO se modifican) ===
    unsigned char x = (unsigned char)(rand() % LIMITE);   // 0..255
    unsigned char y = (unsigned char)(rand() % LIMITE);   // 0..255

    // Para evitar division/mod 0 en esta practica:
    if (y == 0) y = 1;

    printf("===== TIPO: unsigned char =====\n");
    print_uchar("x", x);
    print_uchar("y", y);
    printf("\n");

    // Nota: x e y se PROMOCIONAN a int al operar.
    int xi = (int)x;
    int yi = (int)y;

    // =========================
    // A) Operadores aritmeticos
    // =========================
    printf("== Aritmeticos (unsigned char) ==\n");

    long tmp;   // tipo ancho para ver el resultado real

    // SUMA
    tmp = (long)x + (long)y;
    unsigned char resultadoSuma = (unsigned char)tmp;
    printf("x + y  = %ld  -> unsigned char: %u\n",
        tmp, (unsigned)resultadoSuma);

    // RESTA
    tmp = (long)x - (long)y;
    unsigned char resultadoResta = (unsigned char)tmp;
    printf("x - y  = %ld  -> unsigned char: %u\n",
        tmp, (unsigned)resultadoResta);

    // MULTIPLICACION
    tmp = (long)x * (long)y;
    unsigned char resultadoMult = (unsigned char)tmp;
    printf("x * y  = %ld  -> unsigned char: %u\n",
        tmp, (unsigned)resultadoMult);

    // DIVISION
    tmp = (long)x / (long)y;
    unsigned char resultadoDiv = (unsigned char)tmp;
    printf("x / y  = %ld  -> unsigned char: %u (division entera)\n",
        tmp, (unsigned)resultadoDiv);

    // MODULO
    tmp = (long)(x % y);
    unsigned char resultadoMod = (unsigned char)tmp;
    printf("x %% y  = %ld  -> unsigned char: %u\n",
        tmp, (unsigned)resultadoMod);

    // UNARIOS
    tmp = +(long)x;
    printf("+x     = %ld  -> unsigned char: %u\n",
        tmp, (unsigned)((unsigned char)tmp));

    tmp = -(long)x;
    printf("-x     = %ld  -> unsigned char: %u\n",
        tmp, (unsigned)((unsigned char)tmp));

    printf("\n");
    // ============================
    // B) Inc/Dec (con una copia)
    // ============================
    printf("== Incremento/Decremento ==\n");
    unsigned char t = x;
    printf("t inicial = %u\n", (unsigned)t);
    printf("t++  imprime %u, luego t=%u\n", (unsigned)t++, (unsigned)t);
    printf("++t  ahora t=%u\n", (unsigned)++t);
    printf("t--  imprime %u, luego t=%u\n", (unsigned)t--, (unsigned)t);
    printf("--t  ahora t=%u\n", (unsigned)--t);
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
    // Para bits es mejor verlos como unsigned int
    unsigned int ux = (unsigned int)x;
    unsigned int uy = (unsigned int)y;

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
    unsigned char a = x;  // =
    print_uchar("a = x", a);

    a += y; print_uchar("a += y", a);
    a -= y; print_uchar("a -= y", a);
    a *= y; print_uchar("a *= y", a);

    // y ya es != 0
    a /= y; print_uchar("a /= y", a);
    a %= y; print_uchar("a %= y", a);

    a <<= 1; print_uchar("a <<= 1", a);
    a >>= 1; print_uchar("a >>= 1", a);

    a &= y; print_uchar("a &= y", a);
    a ^= y; print_uchar("a ^= y", a);
    a |= y; print_uchar("a |= y", a);
    printf("\n");

    // ============================
    // F) Ternario y sizeof
    // ============================
    printf("== Ternario y sizeof ==\n");
    unsigned char mayor = (x > y) ? x : y;
    print_uchar("mayor (x>y?x:y)", mayor);

    printf("sizeof(unsigned char) = %zu bytes\n", sizeof(unsigned char));
    printf("sizeof(x)             = %zu bytes\n", sizeof(x));
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