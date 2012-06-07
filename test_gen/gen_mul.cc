#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <stdlib.h>

#define MAX_VAL 10
#define MIN_VAL -10


static long next_rand(long min, long max)
{
    return ((rand() % (max - min + 1)) + min);
}

void gen_mat(std::ofstream& file, std::ofstream& fileoct, const char* name, long l, long c)
{
    long size = 0;
    file << l << " " << c;
    fileoct << name << " = [";
    size = l * c;
    for (long i = 0; i < size; ++i)
    {
        int val = next_rand (MAX_VAL, MIN_VAL);
        file << " " << val;
        fileoct << val;

        if (i == size - 1)
            fileoct << "];" << std::endl;
        else if ((i + 1) % c == 0)
            fileoct << ";";
        else
            fileoct << ",";
    }
}


int main (int argc, char** argv)
{
    if (argc < 5)
    {
        std::cout << "Usage : " << argv[0] << " [mat1file] [mat2file] [octfile] [min dim] [max dim]"
            << std::endl;
        return 1;
    }

    srand(time(NULL));
    std::ofstream filepm1;
    std::ofstream filepm2;
    std::ofstream fileoct;

    filepm1.open (argv[1], std::ios_base::out | std::ios_base::trunc);
    filepm2.open (argv[2], std::ios_base::out | std::ios_base::trunc);
    fileoct.open (argv[3], std::ios_base::out | std::ios_base::trunc);

    if (!filepm1.is_open () || !filepm2.is_open () || !fileoct.is_open ())
    {
        std::cerr << "Could not open files" << std::endl;
        return 1;
    }

    long min = atol (argv[4]);
    long max = atol (argv[5]);

    long lines = next_rand (min, max);
    long common = next_rand (min, max);
    long columns = next_rand (min, max);

    std::cout << lines << " x " << common << " * " << common << " x " << columns
              << " = " << lines << " x " << columns << std::endl;

    gen_mat (filepm1, fileoct, "mat1", lines, common);
    gen_mat (filepm2, fileoct, "mat2", common, columns);

    fileoct << "res = mat1 * mat2" << std::endl;

    filepm1.close ();
    filepm2.close ();
    fileoct.close ();
    return 0;
}
