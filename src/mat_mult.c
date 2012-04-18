#include "matrix.h"
#include "raw_comp.h"

s_matrix* mat_mult(s_matrix* res, const s_matrix* a, const s_matrix* b)
{
    assert(a != NULL && b != NULL && res != NULL);

    if (a->c != b->l || a->c != res->c || b->l != res->l)
    {
        fprintf(stderr, "Matrix multiplication: dimensions don't match");
        return (NULL);
    }
    RAW_MULT(res, a, b);
}

void mat_scale(s_matrix* a, double s)
{
    double *it_a = NULL;

    assert(a != NULL);

    it_a = a->arr;
    for (size_t i = 0; i < a->size_arr; ++i, ++it_a)
        (*it_a) *= s;
}
