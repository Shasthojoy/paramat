/*
** file: raw_comp.h
** author: benjamin
** created on 16/04/12 at 18:59
*/

/**
** @brief The purpose of these functions are primarly for
**        parallel computation. They are 'raw' meaning that
**        they are not for direct use
*/

#ifndef RAW_COMP_H_
# define RAW_COMP_H_
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <assert.h>


# define SIMP_MUL \
    do\
    {\
        for (size_t k = 0; k < a_col; ++k, ++it_a, it_b += b_col)\
            (*it_r) += (*it_a) * (*it_b);\
    }\
    while(0);\


# define COEF_MUL(s) \
    do\
    {\
       for (size_t k = 0; k < a_col; ++k, ++it_a, it_b += b_col)\
          (*it_r) += (*it_a) * (*it_b);\
       (*it_r) *= s;\
    }\
    while(0);\


/*
inline s_matrix* raw_mult_sum(s_matrix* res,
                              const double** mat_arrs,
                              const s_matrix* a,
                              const s_matrix* b,
                              size_t nb_matrices);
                              */
# include "raw_mult.hxx"

#endif /* !RAW_COMP_H_ */
