#include "matrix.h"
#include "raw_comp.h"


void mat_scale(s_matrix* a, double s)
{
    double *it_a = NULL;

    assert(a != NULL);

    it_a = a->arr;
    for (size_t i = 0; i < a->size_arr; ++i, ++it_a)
        (*it_a) *= s;
}
