#! /bin/bash

echo 'Generating tests...'
./gen_mul.sh 'test' test1.oct $1
echo 'Tests generated'

echo 'Running program...'
time ./a.out test1.pm test2.pm > /dev/null

echo ' '
echo 'Program terminated'
echo ' '
echo 'Done'

