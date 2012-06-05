#include "matrix.h"


int main(int argc, char** argv)
{
    argc = argc;
    argv = argv;

    s_matrix *mat1 = mat_build_id(4, 1);
    s_matrix *mat2 = mat_build_id(4, 1);
    s_matrix *mat3 = mat_build_id(4, 1);
    s_matrix *res = mat_build(4, 4);

    MAT_MULT(res, mat1, mat2, T2, ID, ID);

    if (res)
    {

        mat_reset(res);
        mat_print(mat1, 1);
        mat_print(mat2, 1);
        mat_print(res, 1);

        mat_free(mat1);
        mat_free(mat2);
        mat_free(res);
        mat_free(mat3);
    }




    return (0);
}
