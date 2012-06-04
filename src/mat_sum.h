/*
** file: mat_sum.h
** author: benjamin
** created on 18/04/12 at 19:00
*/

#ifndef MAT_SUM_H_
# define MAT_SUM_H_
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <assert.h>

# include "mat_struct.h"


s_matrix *mat_sum(s_matrix *res, s_matrix *a, s_matrix *b);
s_matrix *mat_diff(s_matrix *res, s_matrix *a, s_matrix *b);

# include "mat_sum.hxx"

#endif /* !MAT_SUM_H_ */
