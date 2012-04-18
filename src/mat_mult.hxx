#ifndef MAT_MULT_HXX
# define MAT_MULT_HXX

# include "matrix.h"

# define MAT_MULT(res, a, b, op)\
    do\
    {\
    assert(a != NULL && b != NULL && res != NULL);\
    if (a->c != b->l || a->c != res->c || b->l != res->l)\
    {\
        fprintf(stderr, "Matrix multiplication: dimensions don't match");\
        res = NULL;\
    }\
    RAW_MULT(res, a, b, op)\
    }\
while (0);

#endif /* !MAT_MULT_HXX */
