#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../src/matrix.h"

#define MAX_DIM 200
#define MIN_DIM 100

void generate_mult(size_t end_c, size_t end_l, std::ofstream os, std::string& op_id)
{
    std::string* res = new std::string();
    size_t mid_dim = rand() % (MAX_DIM - MIN_DIM) + MIN_DIM;

    s_matrix* matA = mat_build_rand(end_c, mid_dim);
    s_matrix* matB = mat_build_rand(mid_dim, end_l);

}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./test_gen file size" << std::endl;
        return 1;
    }

    char* file = argv[1];
    size_t s = atoi(argv[2]);
    std::ofstream os;
    int fd_mat = 0;

    os.open("test1.m");

    os << "Matlab script" << std::endl;

    os.close();

    return 0;
}
