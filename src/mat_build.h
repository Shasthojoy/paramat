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
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "mat_struct.h"


 /**
 ** @brief mat_build* will create a matrix of given dimensions
 ** @return the matrix newly created or a NULL value if
 **         something went wrong
 */
s_matrix* mat_build(size_t l, size_t c);
s_matrix* mat_build_id(size_t l, size_t c);
s_matrix* mat_build_0(size_t l, size_t c);
s_matrix* mat_build_from_file(const char* file);
 /**
 ** @brief mat_build* will create a matrix of given dimensions
 **        initialized with random values between 0 and 1
 ** @return the matrix newly created or a NULL value if
 **         something went wrong
 */
s_matrix* mat_build_rand(size_t l, size_t c);
void mat_print(const s_matrix* m, int verbose);
void mat_print_matlab(const s_matrix* m);
void mat_write_to_file(const s_matrix* mat, const char* file);

void mat_set(s_matrix* mat, ...);

void mat_reset(s_matrix* mat);


 /**
 ** @brief mat_free will free any given matrix
 ** @return 1 if memory freeing went well and 0 if
 **         something went wrong
 */
int mat_free(s_matrix* m);
#endif /* !MAT_BUILD_H_ */
