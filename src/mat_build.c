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

s_matrix* mat_build_from_file(const char* file)
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
