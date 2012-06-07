#include "matrix.h"

int main(int argc, char** argv)
{
  if (argc < 2)
  {
      printf("Usage : %s [file mat 1] [file mat 2]\n", argv[0]);
      return 1;
  }

  s_matrix *mat1 = mat_build_from_file(argv[1]);
  s_matrix *mat2 = mat_build_from_file(argv[2]);
  s_matrix *res = mat_build_id(mat1->l, mat2->c);
  MAT_MULT(res, mat1, mat2, TT, ZERO(res, ID), ID);
  if (res)
  {
    mat_print(res, 1);
    mat_free(mat1);
    mat_free(mat2);
    mat_free(res);
  }
  return 0;
}
