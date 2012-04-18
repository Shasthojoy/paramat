#ifndef RAW_MULT_HXX
# define RAW_MULT_HXX

# define MAT_MULT(res, a, b)\
    do\
    {\
    assert(a != NULL && b != NULL && res != NULL);\
    if (a->c != b->l || a->c != res->c || b->l != res->l)\
    {\
        fprintf(stderr, "Matrix multiplication: dimensions don't match");\
        return (NULL);\
    }\
    RAW_MULT(res, a, b);\
    }\
while (0)

#endif /* !RAW_MULT_HXX */
