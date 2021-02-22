#include <sycontainer.h>
#include <stdio.h>

int
main(
    // int argc,
    // char **argv
) {
    char chin = 'a';
    int inin = 234;
    float ftin = 23.53;
    double dbin = 23e5;
    char chout;
    int inout;
    float ftout;
    double dbout;
    // double k;
    // char
    sycontainer *cont = syc_create(SY_CHAR, &chin, sizeof(char));
    if (syc_ischar(cont)) {
        syc_getchar(cont, &chout);
        printf("the character is %c\n", chout);
    }
    syc_destroy(cont);
    // int
    cont = syc_create(SY_INT, &inin, sizeof(int));
    if (syc_isint(cont)) {
        syc_getint(cont, &inout);
        printf("the integer is %d\n", inout);
    }
    syc_destroy(cont);
    // float
    cont = syc_create(SY_FLOAT, &ftin, sizeof(float));
    if (syc_isfloat(cont)) {
        syc_getfloat(cont, &ftout);
        printf("the float is %f\n", ftout);
    }
    syc_destroy(cont);
    // double
    cont = syc_create(SY_DOUBLE, &dbin, sizeof(double));
    if (syc_isdouble(cont)) {
        syc_getdouble(cont, &dbout);
        printf("the double is %f\n", dbout);
    }
    return EXIT_SUCCESS;
}
