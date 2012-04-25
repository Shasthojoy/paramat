/*
** file: mat_struct.h
** author: benjamin
** created on 18/04/12 at 18:59
*/

#ifndef MAT_STRUCT_H_
# define MAT_STRUCT_H_
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <assert.h>


typedef struct
{
    unsigned int l;
    unsigned int c;
    size_t size_arr;
    double *arr;
    double *it;
} s_matrix;


#endif /* !MAT_STRUCT_H_ */
