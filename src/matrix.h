/*
** file: matrix.h
** author: benjamin
** created on 16/04/12 at 15:42
*/

#ifndef MATRIX_H_
# define MATRIX_H_
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <assert.h>
# include <time.h>
# include <limits.h>


typedef struct
{
    size_t l;
    size_t c;
    size_t size_arr;
    double *arr;
} s_matrix;

 /**
 ** @brief mat_build* will create a matrix of given dimensions
 ** @return the matrix newly created or a NULL value if
 **         something went wrong
 */

s_matrix* mat_build(size_t l, size_t c);
s_matrix* mat_build_id(size_t l, size_t c);
s_matrix* mat_build_0(size_t l, size_t c);

 /**
 ** @brief mat_build* will create a matrix of given dimensions
 **        initialized with random values between 0 and 1
 ** @return the matrix newly created or a NULL value if
 **         something went wrong
 */
s_matrix* mat_build_rand(size_t l, size_t c);

 /**
 ** @brief mat_build* will free any given matrix
 ** @return 1 if memory freeing went well and 0 if
 **         something went wrong
 */
int mat_free(s_matrix* m);

void mat_print(const s_matrix* m, int verbose);


inline s_matrix *mat_sum(s_matrix *res, s_matrix *a, s_matrix *b);

void mat_scale(s_matrix* a, double s);

# include "raw_comp.h"

 /**
 ** @brief mat_mult will multiply two matrices together
 **        if A is of dimensions n * m and B of dimensions
 **        m * p then R = A * B is of dim n * p
 ** @return the resulting matrix or a NULL value if
 **         something went wrong (dimensions don't match
 **         for instance)
 */

# include "mat_mult.hxx"

# include "mat_sum.hxx"


#endif /* !MATRIX_H_ */
