#include "matrix.h"


int main(int argc, char** argv)
{
    argc = argc;
    argv = argv;

    s_matrix *mat1 = mat_build_rand(10, 10);
    s_matrix *mat2 = mat_build_rand(10, 10);
    mat_scale(mat1, 3.);
    s_matrix *res = mat_mult(mat1, mat2);
    mat_print(res, 1);
    mat_free(mat1);
    mat_free(mat2);
    mat_free(res);
    return (0);
}
