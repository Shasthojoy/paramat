#include "matrix.h"


int main(int argc, char** argv)
{
    argc = argc;
    argv = argv;

    s_matrix *mat1 = mat_build_id(10, 10);
    s_matrix *mat2 = mat_build_id(10, 10);
    s_matrix *mat3 = mat_build_id(10, 10);
    s_matrix *res = mat_build(10, 10);

    mat_scale(mat3, 2.);

    RAW_MULT(res, mat1, mat2, TT, ID, HAD(mat3, ID));

    mat_reset(res);
    mat_print(res, 1);

    mat_free(mat1);
    mat_free(mat2);
    mat_free(res);
    mat_free(mat3);




    return (0);
}
