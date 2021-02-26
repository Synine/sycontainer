#include <sycontainer.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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
        if (chout != chin) {
            fprintf(stderr, "sycontainer.c: create->getchar: Values don't match\n");
            return (EXIT_FAILURE);
        }
    }
    syc_destroy(cont);
    // int
    cont = syc_create(SY_INT, &inin, sizeof(int));
    if (syc_isint(cont)) {
        syc_getint(cont, &inout);
        if (inout != inin) {
            fprintf(stderr, "sycontainer.c: create->getint: Values don't match\n");
            return (EXIT_FAILURE);
        }
    }
    syc_destroy(cont);
    // float
    cont = syc_create(SY_FLOAT, &ftin, sizeof(float));
    if (syc_isfloat(cont)) {
        syc_getfloat(cont, &ftout);
        if (ftout != ftin) {
            fprintf(stderr, "sycontainer.c: create->getfloat: Values don't match\n");
            return (EXIT_FAILURE);
        }
    }
    syc_destroy(cont);
    // double
    cont = syc_create(SY_DOUBLE, &dbin, sizeof(double));
    if (syc_isdouble(cont)) {
        syc_getdouble(cont, &dbout);
        if (dbout != dbin) {
            fprintf(stderr, "sycontainer.c: create->getdouble: Values don't match\n");
            return (EXIT_FAILURE);
        }
    }
    syc_destroy(cont);
    // string
    char *strin = "Yazimeenah Stanton";
    char *strout1, *strout2;
    strout1 = (char*)malloc(sizeof(char) * strlen(strin));
    strout2 = NULL;
    cont = syc_create(SY_STRING, strin, sizeof(char) * strlen(strin));
    if (syc_isstr(cont)) {
        strout1 = syc_getstr(cont, strout1);
        if (strcmp(strout1, strin)) {
            fprintf(stderr, "sycontainer.c: create->getstr - 1: Values don't match\n");
            return (EXIT_FAILURE);
        }
        free(strout1);
        strout2 = syc_getstr(cont, strout2);
        if (strcmp(strout2, strin)) {
            fprintf(stderr, "sycontainer.c: create->getstr - 1: Values don't match\n");
            return (EXIT_FAILURE);
        }
        free(strout2);
    }
    // structure -> normal
    struct point {
        int x;
        int y;
    } pin, pout1, *pout2, *pout3;
    pin.x = INT_MAX;
    pin.y = INT_MIN;
    pout1.x = 0;
    pout1.y = 0;
    pout2 = NULL;
    pout3 = (struct point*)malloc(sizeof(struct point));
    cont = syc_create(SY_GENERIC, &pin, sizeof(struct point));
    if (syc_isgeneric(cont)) {
        syc_getgeneric(cont, &pout1);
        if (pin.x != pout1.x || pin.y != pout1.y) {
            fprintf(stderr, "sycontainer.c: create->getgeneric - 1: Values don't match\n");
            return (EXIT_FAILURE);
        }
        pout2 = syc_getgeneric(cont, pout2);
        if (pin.x != pout2->x || pin.y != pout2->y) {
            fprintf(stderr, "sycontainer.c: create->getgeneric - 2: Values don't match\n");
            return (EXIT_FAILURE);
        }
        free(pout2);
        pout3 = syc_getgeneric(cont, pout3);
        if (pin.x != pout3->x) {
            fprintf(stderr, "sycontainer.c: create->getgeneric - 3: Values don't match\n");
            return (EXIT_FAILURE);
        }
        free(pout3);
    }
    return EXIT_SUCCESS;
}
