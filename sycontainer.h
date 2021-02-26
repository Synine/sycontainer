#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_SYCONTAINER
    #define SYCONTAINER_PUBLIC __declspec(dllexport)
  #else
    #define SYCONTAINER_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_SYCONTAINER
      #define SYCONTAINER_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define SYCONTAINER_PUBLIC
  #endif
#endif

// LIBRARIES WE NEED
// - sys/types for size_t
#include <sys/types.h>
// - stdlib for dynamic allocation
#include <stdlib.h>
// - string for memcpy
#include <string.h>
// - stdbool for booleans
#include <stdbool.h>

typedef enum sycontainer_type {
  SY_EMPTY,
  SY_CHAR,
  SY_INT,
  SY_FLOAT,
  SY_DOUBLE,
  SY_STRING,
  SY_GENERIC
} sycontainer_type;

typedef struct sycontainer {
  enum sycontainer_type ctype;
  // only used when the data size is generic,
  // else is assigned with the size of the datatype
  size_t datasize;
  union {
    char ch;
    int in;
    float ft;
    double db;
    char* str;
    void* genc;
  } contents;
} sycontainer;

sycontainer SYCONTAINER_PUBLIC *syc_create(sycontainer_type ctype, void* data, size_t datasize);

void SYCONTAINER_PUBLIC syc_destroy(sycontainer *container);

bool SYCONTAINER_PUBLIC syc_isempty(sycontainer *container);

bool SYCONTAINER_PUBLIC syc_ischar(sycontainer *container);

// Remember to NOT pass in NULL pointer to 'ch'.
// If you do, remember to free the returned pointer after copying the value.
char SYCONTAINER_PUBLIC *syc_getchar(sycontainer *container, char* ch);

bool SYCONTAINER_PUBLIC syc_isint(sycontainer *container);

// Remember to NOT pass in NULL pointer to 'in'. 
// If you do, remember to free the returned pointer after copying the value.
int SYCONTAINER_PUBLIC *syc_getint(sycontainer *container, int* in);

bool SYCONTAINER_PUBLIC syc_isfloat(sycontainer *container);

float SYCONTAINER_PUBLIC *syc_getfloat(sycontainer *container, float *ft);

bool SYCONTAINER_PUBLIC syc_isdouble(sycontainer *container);

double SYCONTAINER_PUBLIC *syc_getdouble(sycontainer *container, double *db);

bool SYCONTAINER_PUBLIC syc_isstr(sycontainer *container);

char SYCONTAINER_PUBLIC *syc_getstr(sycontainer *container, char *str);

bool SYCONTAINER_PUBLIC syc_isgeneric(sycontainer *container);

void SYCONTAINER_PUBLIC *syc_getgeneric(sycontainer *container, void *genc);
