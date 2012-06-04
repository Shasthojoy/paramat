#ifndef RAW_MULT_HXX
# define RAW_MULT_HXX

# include "raw_comp.h"

/**
** @param res a pointer to where the result matrix should be stored
** @param a the first multiplication component
** @param b the second multiplication component
** @param t either T1 (a transposed), T2 (b transposed),
**          T12 (a and b transposed), TT (no transposing)
** @param operation the core operation to perform on res. Can be:
**                  COEF_MUL, ADD or SUB (cf. raw_comp.h)
*/

# define RAW_MULT(res, a, b, t, pre_op, post_op)\
    do\
    {\
        double *it_a = NULL;\
        double *it_b = NULL;\
        double *it_r = NULL;\
        double *it_tmp_a = NULL;\
        double *it_tmp_b = NULL;\
        size_t a_col = a->c;\
        size_t b_col = b->c;\
        size_t a_line = a->l;\
        size_t b_line = b->l;\
        a_line = a_line;\
        b_line = b_line;\
        a_col = a_col;\
        b_col = b_col;\
        it_a = a->arr;\
        it_r = res->arr;\
        \
        \
        for (size_t i = 0; i < res->l; ++i, t ## _MAIN_ITA)\
        {\
            it_b = b->arr;\
            it_tmp_a = it_a;\
            for (size_t j = 0; j < res->c; ++j, ++it_r, t ## _MAIN_ITB)\
            {\
                pre_op\
                it_tmp_b = it_b;\
                for (size_t k = 0; k < t ## _COM_DIM; \
                        ++k, t ## _SUB_ITA, t ## _SUB_ITB)\
                    (*it_r) += (*it_a) * (*it_b);\
                post_op\
                it_a = it_tmp_a;\
                it_b = it_tmp_b;\
            }\
        }\
    }\
    while (0);

/**
 ** TODO
 ** There's probably a way I can get these defines less illegible
 */

# define T1_MAIN_ITA ++it_a
# define T1_MAIN_ITB ++it_b
# define T1_COM_DIM a_line
# define T1_SUB_ITA it_a += a_col
# define T1_SUB_ITB it_b += b_col
# define T1_COL_A(a) a->l
# define T1_COL_B b->c
# define T1_LINE_A(a) a->c
# define T1_LINE_B(b) b->l

# define T2_MAIN_ITA it_a += a_col
# define T2_MAIN_ITB it_b += b_col
# define T2_COM_DIM a_col
# define T2_SUB_ITA ++it_a
# define T2_SUB_ITB ++it_b
# define T2_COL_A(a) a->c
# define T2_COL_B(b) b->l
# define T2_LINE_A(a) a->l
# define T2_LINE_B(b) b->c

# define T12_MAIN_ITA ++it_a
# define T12_MAIN_ITB it_b += b_col
# define T12_COM_DIM a_line
# define T12_SUB_ITA it_a += a_col
# define T12_SUB_ITB ++it_b
# define T12_COL_A(a) a->l
# define T12_COL_B(b) b->l
# define T12_LINE_A(a) a->c
# define T12_LINE_B(b) b->c

# define TT_MAIN_ITA it_a += a_col
# define TT_MAIN_ITB ++it_b
# define TT_COM_DIM a_col
# define TT_SUB_ITA ++it_a
# define TT_SUB_ITB it_b += b_col
# define TT_COL_A(a) a->c
# define TT_COL_B(b) b->c
# define TT_LINE_A(a) a->l
# define TT_LINE_B(b) b->l



inline s_matrix* raw_mult_sum(s_matrix* res,
                              const double** mat_arrs,
                              const s_matrix* a,
                              const s_matrix* b,
                              size_t nb_matrices)
{
    double *it_a = NULL;
    double *it_b = NULL;
    double *it_r = NULL;
    double *it_tmp_a = NULL;
    double *it_tmp_b = NULL;
    const double **m_it = NULL;

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
            m_it = mat_arrs;

            for (size_t m = 0; m < nb_matrices; ++m, ++m_it)
            {
                (*it_r) += (**m_it);
                ++(*m_it);
            }

            for (size_t k = 0; k < a->c; ++k, ++it_a, it_b += b->c)
                (*it_r) += (*it_a) * (*it_b);

            it_a = it_tmp_a;
            it_b = it_tmp_b;
        }
    }
    return res;
}
#endif /* !RAW_MULT_HXX */
