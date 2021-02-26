#include <sycontainer.h>


sycontainer *syc_create(
    enum sycontainer_type ctype,
    void* data,
    size_t datasize
) {
    if (data == NULL) return NULL;
    sycontainer* newcontainer = (sycontainer*)malloc(sizeof(struct sycontainer));
    newcontainer->ctype = ctype;
    if (ctype == SY_EMPTY) {
        newcontainer->datasize = 0;
        newcontainer->contents.genc = NULL;
    } else if (ctype == SY_CHAR) {
        newcontainer->datasize = sizeof(char);
        memcpy(&(newcontainer->contents.ch), data, newcontainer->datasize);
    } else if (ctype == SY_INT) {
        newcontainer->datasize = sizeof(int);
        memcpy(&(newcontainer->contents.in), data, newcontainer->datasize);
    } else if (ctype == SY_FLOAT) {
        newcontainer->datasize = sizeof(float);
        memcpy(&(newcontainer->contents.ft), data, newcontainer->datasize);
    } else if (ctype == SY_DOUBLE) {
        newcontainer->datasize = sizeof(double);
        memcpy(&(newcontainer->contents.db), data, newcontainer->datasize);
    } else if (ctype == SY_STRING) {
        newcontainer->datasize = sizeof(char) * datasize;
        memcpy(&(newcontainer->contents.str), data, newcontainer->datasize);
    } else if (ctype == SY_GENERIC) {
        newcontainer->datasize = datasize;
        memcpy(&(newcontainer->contents.genc), data, newcontainer->datasize);
    } else {
        newcontainer->datasize = 0;
        newcontainer->contents.genc = NULL;
    }
    return newcontainer;
}

// Destroy a contaianer
void syc_destroy(sycontainer *container) {
    if (container == NULL) return;
    if (container->ctype == SY_STRING) {
        if (container->contents.str != NULL) {
            free(container->contents.str);
        }
    } else if (container->ctype == SY_CHAR) {
        if (container->ctype == SY_GENERIC) {
            if (container->contents.genc != NULL) {
                free(container->contents.genc);
            }
        }
    }
    free(container);
    return;
}

bool syc_isempty(sycontainer *container) {
    if (container == NULL) return false;
    if (
        container->ctype == SY_EMPTY ||
        container->contents.genc == NULL
    ) return true;
    return false;
}

bool syc_ischar(sycontainer *container) {
    if (container == NULL) return false;
    if (container->ctype != SY_CHAR) {
        return false;
    }
    return true;
}

// if you use this, with NULL passed into 'ch',
// remember to free the memory before using it,
// as not doing that can cause memory leaks.
// THIS APPLIES FOR ALL syc_get<TYPE> functions
char *syc_getchar(sycontainer *container, char* ch) {
    if (!syc_ischar(container)) return NULL;
    char* retnval;
    if (ch == NULL) {
        retnval = (char*)malloc(sizeof(char));
    } else {
        retnval = ch;
    }
    *retnval = container->contents.ch;
    return retnval;
}

bool syc_isint(sycontainer *container) {
    if (container == NULL) return false;
    if (container->ctype != SY_INT) {
        return false;
    }
    return true;
}

int *syc_getint(sycontainer *container, int* in) {
    if (!syc_isint(container)) return NULL;
    int* retnval;
    if (in == NULL) {
        retnval = (int*)malloc(sizeof(int));
    } else {
        retnval = in;
    }
    *retnval = container->contents.in;
    return retnval;
}

bool syc_isfloat(sycontainer *container) {
    if (container == NULL) return false;
    if (container->ctype != SY_FLOAT) {
        return false;
    }
    return true;
}

float *syc_getfloat(sycontainer *container, float *ft) {
    if (!syc_isfloat(container)) return NULL;
    float *retnval;
    if (ft == NULL) {
        retnval = (float*)malloc(sizeof(float));
    } else {
        retnval = ft;
    }
    *retnval = container->contents.ft;
    return retnval;
}

bool syc_isdouble(sycontainer *container) {
    if (container == NULL) return false;
    if (container->ctype != SY_DOUBLE) {
        return false;
    }
    return true;
}

double *syc_getdouble(sycontainer *container, double *db) {
    if (!syc_isdouble(container)) return NULL;
    double* retnval;
    if (db == NULL) {
        retnval = (double*)malloc(sizeof(double));
    } else {
        retnval = db;
    }
    *retnval = container->contents.db;
    return retnval;
}

bool syc_isstr(sycontainer *container) {
    if (container == NULL) return false;
    if (container->ctype != SY_STRING) {
        return false;
    }
    return true;
}

// MAKE SURE TO FREE THE STRING AFTER USING IT
char *syc_getstr(sycontainer *container, char *str) {
    if (!syc_isstr(container)) return NULL;
    char* retnstr = NULL;
    if (str == NULL) {
        retnstr = (char*)malloc(sizeof(char) * container->datasize);
    } else {
        retnstr = str;
    }
    memcpy(retnstr, container->contents.str, sizeof(char) * container->datasize);
    return retnstr;
}

bool syc_isgeneric(sycontainer *container) {
    if (container == NULL) return false;
    if (container->ctype != SY_GENERIC) {
        return false;
    }
    return true;
}

void *syc_getgeneric(sycontainer *container, void *genc) {
    if (!syc_isgeneric(container)) return NULL;
    void* retnval = NULL;
    if (genc == NULL) {
        retnval = (void*)malloc(container->datasize);
    } else {
        retnval = genc;
    }
    memcpy(retnval, container->contents.genc, container->datasize);
    return retnval;
}