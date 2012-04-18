#ifndef MAT_MULT_HXX
# define MAT_MULT_HXX

# include "mat_mult.h"


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

inline void mat_scale(s_matrix* a, double s)
{
    double *it_a = NULL;

    assert(a != NULL);

    it_a = a->arr;
    for (size_t i = 0; i < a->size_arr; ++i, ++it_a)
        (*it_a) *= s;
}

#endif /* !MAT_MULT_HXX */
