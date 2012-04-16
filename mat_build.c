#include "matrix.h"

s_matrix* mat_build(size_t l, size_t c)
{
    s_matrix* new_mat = NULL;
    size_t size = 0;


    new_mat = malloc(sizeof (s_matrix));
    if (new_mat)
    {
        size = l * c;
        new_mat->l = l;
        new_mat->c = c;
        new_mat->size_arr = size;
        new_mat->arr = malloc(sizeof (double) * size);
    }
    return (new_mat);
}

s_matrix* mat_build_id(size_t l, size_t c)
{
    s_matrix* new_mat = NULL;
    double* it = NULL;
    size_t it_c = 0;
    size_t size = 0;
    size_t next_1 = 0;

    if (!(new_mat = mat_build(l, c)))
        return (NULL);

    it = new_mat->arr;
    size = new_mat->size_arr;

    for (; it_c < size; ++it_c, ++it)
    {
        if (it_c == next_1)
        {
            *it = 1.;
            next_1 += new_mat->c + 1;
        }
        else
            *it = 0.;
    }
    return (new_mat);
}

s_matrix* mat_build_0(size_t l, size_t c)
{
    s_matrix* new_mat = NULL;
    double* it = NULL;
    size_t it_c = 0;
    size_t size = 0;

    if (!(new_mat = mat_build(l, c)))
        return (NULL);

    it = new_mat->arr;
    size = new_mat->size_arr;

    for (; it_c < size; ++it_c, ++it)
        *it = 0.;

    return (new_mat);
}

int mat_free(s_matrix* m)
{
    if (m)
    {
        if (m->arr)
            free(m->arr);
        free(m);
        return 1;
    }
    return 0;
}

void mat_print(s_matrix* m, int verbose)
{
    double *it = NULL;

    if (verbose)
        printf("Matrix\ndim: %d x %d\n", m->l, m->c);

    it = m->arr;
    for (size_t i = 0; i < m->l; i++)
    {
        for (size_t j = 0; j < m->c; j++, it++)
            printf(" %f", *it);
        printf("\n");
    }
}


