#! /bin/bash
function mat_gen()
{
    SIZE=$(($2 * $3))
    COUNT=0

    OCTAVE="$1 = ["
    STRING="$2 $3"

    while test $COUNT -lt $SIZE; do
        VAL=$(($RANDOM % 10))
        COUNT=$(($COUNT + 1))
        STRING="$STRING"" $VAL."
        OCTAVE="$OCTAVE""$VAL"
        if test $(($COUNT % $3)) -eq 0; then
            if test $COUNT -eq $SIZE; then
                OCTAVE="$OCTAVE""];"
                STRING=" $STRING"
            else
                OCTAVE="$OCTAVE""; "
            fi
        else
            OCTAVE="$OCTAVE"" "
        fi
    done

    echo "$STRING" >> $PMFILE
    echo $OCTAVE >> $OCTFILE
}

if test $# -lt 3; then
    echo "Usage: $0 [mat_file] [octave_file] [MAX_DIM]"
    exit 1
fi

PMFILE1=$1"1.pm"
PMFILE2=$1"2.pm"
OCTFILE=$2
MX=$3

LIN=$((($RANDOM % MX) + 2))
COLIN=$((($RANDOM % MX) + 2))
COL=$((($RANDOM % MX) + 2))

echo ' '
echo "$LIN x $COLIN * $COLIN x $COL = $LIN x $COL"
echo ' '

echo '' > $PMFILE1
echo '' > $PMFILE2
echo '' > $2

PMFILE=$PMFILE1
mat_gen mat1 $LIN $COLIN
PMFILE=$PMFILE2
mat_gen mat2 $COLIN $COL

OCT="res = mat1 * mat2"

echo "$OCT" >> $OCTFILE
