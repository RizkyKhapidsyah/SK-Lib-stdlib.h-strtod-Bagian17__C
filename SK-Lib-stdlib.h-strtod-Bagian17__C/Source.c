#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    char* string, * stopstring;
    double x;
    long   l;
    int    base;
    unsigned long ul;

    string = "3.1415926This stopped it";
    x = strtod(string, &stopstring);

    printf("string = %s\n", string);
    printf("   strtod = %f\n", x);
    printf("   Stopped scan at: %s\n\n", stopstring);

    string = "-10110134932This stopped it";
    l = strtol(string, &stopstring, 10);
    
    printf("string = %s\n", string);
    printf("   strtol = %ld\n", l);
    printf("   Stopped scan at: %s\n\n", stopstring);

    string = "10110134932";
    printf("string = %s\n", string);

    // konversi string menggunakan basis 2, 4, and 8:
    for (base = 2; base <= 8; base *= 2) {
        // Convert the string:
        ul = strtoul(string, &stopstring, base);
        printf("   strtol = %ld (base %d)\n", ul, base);
        printf("   Stopped scan at: %s\n", stopstring);
    }

    // NaN
    x = strtod("+nan", &stopstring);
    printf("\n%f\n", x);

    // INF
    x = strtod("-INF", &stopstring);
    printf("\n%f\n", x);

    // e - exponent
    x = strtod("1.18973e+49", &stopstring);
    printf("\n%f\n", x);

    // doesn't handle Fortran style
    x = strtod("1.18973d+49", &stopstring);
    printf("\n%f\n", x);
    printf("No Fortran style support. Stopped parsing at %s\n", stopstring);

    _getch();
    return 0;
}