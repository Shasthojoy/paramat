/*
** file: mat_build.h
** author: benjamin
** created on 18/04/12 at 19:11
*/

#ifndef MAT_BUILD_H_
# define MAT_BUILD_H_
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <assert.h>
# include <time.h>

# include "mat_struct.h"


s_matrix* mat_build(size_t l, size_t c);
s_matrix* mat_build_id(size_t l, size_t c);
s_matrix* mat_build_0(size_t l, size_t c);
inline void mat_reset(s_matrix* mat)
{
    mat->it = mat->arr;
}

#endif /* !MAT_BUILD_H_ */
