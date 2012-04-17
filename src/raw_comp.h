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


# define SIMP_MUL ((*it_r) += (*it_a) * (*it_b))
# define COEF_MUL(s) ((*it_r) += s * (*it_a) * (*it_b))


inline s_matrix* raw_mult(s_matrix* res,
                          const s_matrix* a,
                          const s_matrix* b);

# include "raw_mult.hh"

#endif /* !RAW_COMP_H_ */
