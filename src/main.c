#include "matrix.h"

int main(int argc, char** argv)
{
  argc = argc; argv = argv;
  s_matrix *mat1 = mat_build(830, 9272);
  s_matrix *mat2 = mat_build(9272, 8679);
  s_matrix *res = mat_build(830, 8679);
