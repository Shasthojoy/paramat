#ifndef MAT_SUM_HXX
# define MAT_SUM_HXX

# include "matrix.h"


inline s_matrix *mat_sum(s_matrix *res, s_matrix *a, s_matrix *b)
{
    double *it_a = NULL;
    double *it_b = NULL;
    double *it_r = NULL;

    assert(a != NULL && b != NULL && res != NULL);

    if (a->c != b->c || b->l != a->l || res->l != a->l ||
        res->c != a->c)
    {
        fprintf(stderr, "Matrix addition: dimensions don't match");
        return NULL;
    }

    it_a = a->arr;
    it_b = b->arr;
    it_r = res->arr;

    for (size_t i = 0; i < res->size_arr; ++i, ++it_r, ++it_a, ++it_b)
        (*it_r) = (*it_a) + (*it_b);

    return (res);
}

#endif /* !MAT_SUM_HXX */
