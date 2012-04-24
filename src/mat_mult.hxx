#ifndef MAT_MULT_HXX
# define MAT_MULT_HXX

# include "mat_mult.h"


/**
** @param res a pointer to where the result matrix should be stored
** @param a the first multiplication component
** @param b the second multiplication component
** @param t either T1 (a transposed), T2 (b transposed),
**          T12 (a and b transposed), TT (no transposing)
** @param operation the core operation to perform on res. Can be:
**                  COEF_MUL, ADD or SUB (cf. raw_comp.h)
*/

# define MAT_MULT(res, a, b, t, op)\
    do\
    {\
    assert(a != NULL && b != NULL && res != NULL);\
    if (t ## _COL_A(a) != t ## _LINE_B(b) \
            || t ## _COL_A(a) != res->c \
            || t ## _LINE_B(b) != res->l)\
    {\
        fprintf(stderr, "Matrix multiplication: dimensions don't match");\
        res = NULL;\
    }\
    RAW_MULT(res, a, b, t, op)\
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
