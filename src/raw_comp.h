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


# define COEF_MUL(s, operation) \
    do\
    {\
       (*it_r) *= s;\
       operation\
    }\
    while(0);\

 /**
 ** RESET mat_c before and after use
 */

# define ADD(mat_c, operation)\
    do\
    {\
        *it_r += *(mat_c->it++);\
        operation\
    }\
    while(0);

 /**
 ** RESET mat_c before and after use
 */

# define SUB(mat_c, operation)\
    do\
    {\
        *it_r -= *(mat_c->it++);\
        operation\
    }\
    while(0);

# define HAD(mat_c, operation)\
   do\
   {\
       *it_r *= *(mat_c->it++);\
        operation\
   }\
   while(0);

 /**
 ** Identity operation, leaves it_r unchanged
 */

# define ZERO(mat_c, operation)\
   do\
   {\
       *it_r = 0;\
        operation\
   }\
   while(0);

# define ID



# define RAW_MAP(res, a, fun)\
  do\
  {\
    double *it_a = NULL;\
    double *it_r = NULL;\
    it_a =  a->arr;\
    it_r = r->arr;\
    for (size_t i = 0; i < a->size_arr; ++i, ++it_a, ++it_r)\
      it_r = fun(*it_a);\
  }\
  while (0);

/*
inline s_matrix* raw_mult_sum(s_matrix* res,
                              const double** mat_arrs,
                              const s_matrix* a,
                              const s_matrix* b,
                              size_t nb_matrices);
                              */
# include "raw_mult.hxx"

#endif /* !RAW_COMP_H_ */
