#ifndef RAW_MULT_HXX
# define RAW_MULT_HXX

# include "raw_comp.h"

inline s_matrix* raw_mult(s_matrix* res,
                          const s_matrix* a,
                          const s_matrix* b)
{
    double *it_a = NULL;
    double *it_b = NULL;
    double *it_r = NULL;
    double *it_tmp_a = NULL;
    double *it_tmp_b = NULL;

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
# ifdef OPERATION
                OPERATION;
# else
                (*it_r) += (*it_a) * (*it_b);
# endif
            it_a = it_tmp_a;
            it_b = it_tmp_b;
        }
    }
    return (res);
}


inline s_matrix* raw_mult_sum(s_matrix* res,
                              const double** mat_arrs;
                              const s_matrix* a,
                              const s_matrix* b,
                              size_t nb_matrices)
{
    double *it_a = NULL;
    double *it_b = NULL;
    double *it_r = NULL;
    double *it_tmp_a = NULL;
    double *it_tmp_b = NULL;
    double **m_it = NULL;

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

            for (size_t m = 0, m_it = mats_arrs; m < nb_matrices; ++m, ++m_it)
            {
                *it_r += **m_it;
                ++(*m_it);
            }

            for (size_t k = 0; k < a->c; ++k, ++it_a, it_b += b->c)
                (*it_r) += (*it_a) * (*it_b);

            it_a = it_tmp_a;
            it_b = it_tmp_b;
        }
    }
}
#endif /* !RAW_MULT_HXX */
