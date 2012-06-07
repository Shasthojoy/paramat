#include "mat_build.h"

s_matrix* mat_build(size_t l, size_t c)
{
    s_matrix* new_mat = NULL;
    size_t size = 0;


    new_mat = malloc(sizeof (s_matrix));
    if (new_mat)
    {
        size = l * c;
        new_mat->l = l;
        new_mat->c = c;
        new_mat->size_arr = size;
        new_mat->arr = malloc(sizeof (double) * size);
        new_mat->it = new_mat->arr;
    }
    return (new_mat);
}

s_matrix* mat_build_id(size_t l, size_t c)
{
    s_matrix* new_mat = NULL;
    double* it = NULL;
    size_t it_c = 0;
    size_t size = 0;
    size_t next_1 = 0;

    if (!(new_mat = mat_build(l, c)))
        return (NULL);

    it = new_mat->arr;
    size = new_mat->size_arr;

    for (; it_c < size; ++it_c, ++it)
    {
        if (it_c == next_1)
        {
            *it = 1.;
            next_1 += new_mat->c + 1;
        }
        else
            *it = 0.;
    }
    return (new_mat);
}

void mat_reset(s_matrix* mat)
{
    mat->it = mat->arr;
}

void mat_set(s_matrix* mat, ...)
{
    va_list ptr = NULL;
    double* it = NULL;
    size_t size = 0;
    size_t it_c = 0;

    va_start(ptr, mat);

    it = mat->arr;
    size = mat->size_arr;

    for (; it_c < size; ++it_c, ++it)
        *it = va_arg(ptr, double);
    va_end(ptr);

}

s_matrix* mat_build_0(size_t l, size_t c)
{
    s_matrix* new_mat = NULL;
    double* it = NULL;
    size_t it_c = 0;
    size_t size = 0;

    if (!(new_mat = mat_build(l, c)))
        return (NULL);

    it = new_mat->arr;
    size = new_mat->size_arr;

    for (; it_c < size; ++it_c, ++it)
        *it = 0.;

    return (new_mat);
}

s_matrix* mat_build_rand(size_t l, size_t c)
{
    s_matrix* new_mat = NULL;
    double* it = NULL;
    size_t it_c = 0;
    size_t size = 0;

    srand(time(NULL));

    if (!(new_mat = mat_build(l, c)))
        return (NULL);

    it = new_mat->arr;
    size = new_mat->size_arr;

    for (; it_c < size; ++it_c, ++it)
        *it = (double)rand() / (double)RAND_MAX;

    return (new_mat);
}

int mat_free(s_matrix* m)
{
    if (m)
    {
        if (m->arr)
            free(m->arr);
        free(m);
        return 1;
    }
    return 0;
}

void mat_print(const s_matrix* m, int verbose)
{
    double *it = NULL;

    if (verbose)
        printf("Matrix\ndim: %d x %d\n", m->l, m->c);

    it = m->arr;
    for (size_t i = 0; i < m->l; i++)
    {
        for (size_t j = 0; j < m->c; j++, it++)
            printf(" %f", *it);
        printf("\n");
    }
}

s_matrix* mat_build_from_bin_file(const char* file)
{
    int fd = 0;
    s_matrix* new_mat = NULL;
    size_t size = 0;

    new_mat = malloc(sizeof (s_matrix));
    if (new_mat)
    {
        fd = open(file, O_RDONLY);
        if (fd < 0)
        {
            perror("");
            return (NULL);
        }
        read(fd, &new_mat->l, sizeof (unsigned int));
        read(fd, &new_mat->c, sizeof (unsigned int));
        size = new_mat->l * new_mat->c;
        new_mat->size_arr = size;
        new_mat->arr = malloc(sizeof (double) * size);
        read(fd, new_mat->arr, size * sizeof (double));
        new_mat->it = new_mat->arr;
        close(fd);
    }
    return new_mat;
}

static double read_double(char** file_map, size_t* size)
{
    double val = 0;
    char*  str_val = NULL;

    str_val = *file_map;
    for (;(**file_map) != ' ' && *size > 0; --(*size), ++(*file_map));
    **file_map = '\0';

    val = atof(str_val);
    **file_map = ' ';
    return val;
}

static int is_sep(char c)
{
    return (c == ' ' || c == '\n');
}

s_matrix* mat_build_from_file(const char* file)
{
    int fd = 0;
    s_matrix* new_mat = NULL;
    size_t size = 0;
    size_t mat_size = 0;
    char*  file_map = NULL;
    char* start = NULL;
    struct stat st_f;
    double* it = 0;

    new_mat = malloc(sizeof (s_matrix));
    if (new_mat)
    {
        fd = open(file, O_RDWR);
        if (fd < 0 || fstat(fd, &st_f))
        {
            perror("");
            return (NULL);
        }
        size = st_f.st_size;
        file_map = mmap(NULL,
                        size,
                        PROT_READ | PROT_WRITE,
                        MAP_PRIVATE,
                        fd,
                        0);
        start = file_map;

        for (;is_sep(*file_map) && size > 0; --size, ++file_map);
        new_mat->l = read_double(&file_map, &size);
        for (;is_sep(*file_map) && size > 0; --size, ++file_map);
        new_mat->c = read_double(&file_map, &size);
        new_mat->size_arr = new_mat->l * new_mat->c;
        mat_size = new_mat->size_arr;
        new_mat->arr = malloc(sizeof (double) * new_mat->size_arr);
        it = new_mat->arr;
        new_mat->it = it;
        while (size > 0 && mat_size > 0)
        {
            for (;is_sep(*file_map) && size > 0; --size, ++file_map);
            *(it++) = read_double(&file_map, &size);
            --mat_size;
        }
        munmap(start, st_f.st_size);
        close(fd);
    }
    return new_mat;
}

void mat_print_matlab(const s_matrix* m)
{
    const double* it = m->arr;
    printf("[");
    for (size_t i = 0; i < m->l; i++)
    {
        for (size_t j = 0; j < m->c; j++, it++)
            printf(" %f", *it);
        if (i < m->l - 1)
            printf(" ; ");
    }
    printf("\n");
}

void mat_write_to_file(const s_matrix* mat, const char* file)
{
    int fd = 0;

    assert (mat != NULL);

    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC);
    if (fd < 0)
    {
        perror("");
        return;
    }
    write(fd, &mat->l, sizeof (unsigned int));
    write(fd, &mat->c, sizeof (unsigned int));
    write(fd, mat->arr, mat->size_arr * sizeof (double));

    close(fd);
}
