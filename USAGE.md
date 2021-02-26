# Sycontainer Usage Instructions

The container is a single structure which holds native C type variables.

Do understand that it can't hold format-modified variables like `long int`, `short int`, `long double`, `long long int` et cetera.

## Structure Definitions

1.  `sycontainer_type`: This is an enumerator which holds the type of variable that is held by the `sycontainer` object (which we'll get into later).

    A `sycontainer_type` enumerator has the following constants, which one uses to inform the creating function or the user what variable it contains / should contain.

    ```c
    enum sycontainer_type {
        SY_EMPTY,   // THIS HOLDS 'NULL' OR NO DATA
        SY_CHAR,    // THIS HOLDS ONE CHARACTER
        SY_INT,     // THIS HOLDS ONE VANILLA INTEGER
        SY_FLOAT,   // THIS HOLDS ONE VANILLA FLOAT
        SY_DOUBLE,  // THIS HOLDS ONE VANILLA DOUBLE
        SY_STRING,  // THIS HOLDS A STRING WITH GIVEN CAPACITY
        SY_GENERIC  // THIS CAN HOLD ANY KIND OF DATA
        // SY_GENERIC can be used to hold all the other kinds of data,
        // like size_t, [u]intX, all kind of user-defined structures,
        // as we would see later.
    };
    ```

2.  `sycontainer`: This *container* structure holds the data and also all the information relevant to the container structure we have here.

    ```c
    struct sycontainer {
        enum sycontainer_type ctype;
        // THIS HOLDS THE DATA TYPE HELD BY THE CONTAINER
        size_t datasize;
        // THIS IS AN UNSIGNED INTEGER WITH A VERY LONG BITSIZE
        // USUALLY RESERVED TO STORE SIZE OF DATA, USED HERE
        union {
            char ch;
            int in;
            float ft;
            double db;
            char* str;
            void* genc;
        } contents;
        // THIS HOLDS ALL DATA CONTENTS IN A UNION STRUCTURE, WHOSE
        // TYPE OF CONTENT IT NEEDS TO ACCESS DEPENDS ON 'ctype' MEMBER
    };
    ```

## Usage of `sycontainer` - Functions declared

1. `syc_create`: This function creates an object based on the parameters given.
    
    It has the following declaration:
    ```c
    sycontainer *syc_create(sycontainer_type ctype, void* data, size_t datasize);
    ```
    
    In the above, the following parameters are to be passed for the 
    container.

    1.  `ctype`: This takes in a variable of type `sycontainer_type` to provide information of the type of data the container is going to store.
    2.  `data`: This takes in a pointer to the data. Usually the address to the variable is passed into this as pointer, where the pointer is not accessible.
    3.  `datasize`: This takes in the size of the data. This is important especially for string and generic type containers, as the container performs a **deep-copy** of the object, and would need the size of the data in question.
    
        It is good practice to pass in `sizeof(<data_type>)` when you have a non-string or generic data type in question here.

    NOTE: Since initialization of variables use dynamic allocation techniques, **one is not encouraged to use it on real-time systems**, as it can cause unintended performance hit. **ALLOCATE AND ASSIGN ALL VARIABLES BEFORE STARING REAL-TIME PROCESSING IN THAT CASE.**

2.  `syc_destroy`: This function destroys the container object passed in as parameter.

    It has the following declaration:
    ```c
    void syc_destroy(sycontainer *container);
    ```

    This is a very straight-forward function, as one just needs to pass the pointer to the container to free it from the memory.

    NOTE: Since destruction of variables use dynamic-allocation techniques, **one is not encouraged to use it on real-time systems**, as it can cause unintended performance hit. **REFRAIN FROM DESTROYING VARIABLES IN REAL-TIME PARTS OF CODE THAT CASE.**

3. `syc_is<type>`: This returns a boolean on whether or not a container is of a particular given type.

    **NOTE**: For cases with multiple data type cases, stick with using `switch` statments with `container->ctype` as paramaeter, rather than use mutliple if-else statements for finding the type.

    Functions:
    1.  `syc_isempty(sycontainer *container)`: This checks whether the container is empty (or null, or is a null-pointer (`NULL` or `0x00`)) or not.
    2.  `syc_ischar(sycontainer *container)`: This checks whether the container holds a `char` or not.
    3.  `syc_isint(sycontainer *container)`: This checks whether the container contains an `int` or not.
    4.  `syc_isfloat(sycontainer *container)`: This checks whether the container contains a `float` (single precision floating-point number) or not.
    5.  `syc_isdouble(sycontainer *container)`: This checks whether the container contains a `double` (double precision floating-point number) or not.
    6.  `syc_isstr(sycontainer *container)`: This checks whether the container contains a string (`char` array) or not.