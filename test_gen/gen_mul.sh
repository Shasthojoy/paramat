#! /bin/bash
function mat_gen()
{
    SIZE=$(($2 * $3))
    COUNT=0

    OCTAVE="$1 = ["
    STRING="mat_set($1"

    while test $COUNT -lt $SIZE; do
        VAL=$(($RANDOM % 10))
        COUNT=$(($COUNT + 1))
        STRING="$STRING"", $VAL."
        OCTAVE="$OCTAVE""$VAL"
        if test $(($COUNT % $3)) -eq 0; then
            if test $COUNT -eq $SIZE; then
                OCTAVE="$OCTAVE""];"
                STRING="$STRING"");"
            else
                OCTAVE="$OCTAVE""; "
            fi
        else
            OCTAVE="$OCTAVE"" "
        fi
    done

    echo "  $STRING" >> $PMFILE
    echo $OCTAVE >> $OCTFILE
}

if test $# -lt 3; then
    echo "Usage: $0 [mat_file] [octave_file] [MAX_DIM]"
    exit 1
fi

PMFILE=$1
OCTFILE=$2
MX=$3

LIN=$((($RANDOM % MX) + 2))
COLIN=$((($RANDOM % MX) + 2))
COL=$((($RANDOM % MX) + 2))

echo ' '
echo "$LIN x $COLIN * $COLIN x $COL = $LIN x $COL"
echo ' '

echo '#include "matrix.h"' > $1
echo '' >> $1
echo 'int main(int argc, char** argv)' >> $1
echo '{' >> $1
echo '  argc = argc; argv = argv;' >> $1
echo "  s_matrix *mat1 = mat_build($LIN, $COLIN);" >> $1
echo "  s_matrix *mat2 = mat_build($COLIN, $COL);" >> $1
echo "  s_matrix *res = mat_build($LIN, $COL);" >> $1

echo '' > $2

mat_gen mat1 $LIN $COLIN
mat_gen mat2 $COLIN $COL

OCT="res = mat1 * mat2"
PM="MAT_MULT(res, mat1, mat2, TT, ID, ID);"

echo "$OCT" >> $OCTFILE

echo "  $PM" >> $PMFILE
echo "  if (res)" >> $PMFILE
echo "  {" >> $PMFILE
echo "    mat_print(res, 1);" >> $PMFILE
echo "    mat_free(mat1);" >> $PMFILE
echo "    mat_free(mat2);" >> $PMFILE
echo "    mat_free(res);" >> $PMFILE
echo "  }" >> $PMFILE
echo "  return 0;" >> $PMFILE
echo "}" >> $PMFILE
