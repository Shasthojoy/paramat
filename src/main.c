#include "matrix.h"


int main(int argc, char** argv)
{
    argc = argc;
    argv = argv;

    s_matrix *mat1 = mat_build_id(10, 10);
    s_matrix *mat2 = mat_build_id(10, 10);
    s_matrix *res = mat_build(10, 10);
#define OPERATION COEF_MUL(5.)
    res = mat_mult(res, mat1, mat2);
    mat_print(res, 1);
    mat_free(mat1);
    mat_free(mat2);
    mat_free(res);
    return (0);
}
