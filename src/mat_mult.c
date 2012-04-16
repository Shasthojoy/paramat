#include "matrix.h"

s_matrix* mat_mult(s_matrix* res, const s_matrix* a, const s_matrix* b)
{
    double *it_a = NULL;
    double *it_b = NULL;
    double *it_r = NULL;
    double *it_tmp_a = NULL;
    double *it_tmp_b = NULL;

    assert(a != NULL && b != NULL && res != NULL);

    if (a->c != b->l || a->c != res->c || b->l != res->l)
    {
        fprintf(stderr, "Matrix multiplication: dimensions don't match");
        return (NULL);
    }

    it_a = a->arr;

    it_r = res->arr;

    for (size_t i = 0; i < res->l; ++i, it_a += a->c)
    {
        it_b = b->arr;
        it_tmp_a = it_a;
        for (size_t j = 0; j < res->c; ++j, ++it_r, ++it_b)
        {
            *it_r = 0.;
            it_tmp_b = it_b;
            for (size_t k = 0; k < a->c; ++k, ++it_a, it_b += b->c)
                (*it_r) += (*it_a) * (*it_b);
            it_a = it_tmp_a;
            it_b = it_tmp_b;
        }
    }
    return (res);
}

void mat_scale(s_matrix* a, double s)
{
    double *it_a = NULL;

    assert(a != NULL);

    it_a = a->arr;
    for (size_t i = 0; i < a->size_arr; ++i, ++it_a)
        (*it_a) *= s;
}
