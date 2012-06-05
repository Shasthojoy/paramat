#! /bin/bash

if test $# -lt 2; then
    echo "Usage : $0 [lines] [columns]"
    exit 1
fi

SIZE=$(($1 * $2))
COUNT=0

OCTAVE="mat = ["
STRING="mat_set(mat"

while test $COUNT -lt $SIZE; do
    VAL=$(($RANDOM % 10))
    COUNT=$(($COUNT + 1))
    STRING="$STRING"", $VAL"
    OCTAVE="$OCTAVE""$VAL"
    if test $(($COUNT % $1)) -eq 0; then
        if test $COUNT -eq $SIZE; then
            OCTAVE="$OCTAVE""]"
            STRING="$STRING"");"
        else
            OCTAVE="$OCTAVE""; "
        fi
    else
        OCTAVE="$OCTAVE"", "
    fi
done

echo $STRING
echo $OCTAVE
