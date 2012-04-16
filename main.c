#include "matrix.h"


int main(int argc, char** argv)
{
    argc = argc;
    argv = argv;

    s_matrix *mat = mat_build_id(10, 10);
    mat_print(mat, 1);
    mat_free(mat);
    return (0);
}
