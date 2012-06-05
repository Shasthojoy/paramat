#! /bin/bash

echo 'Generating tests...'
./gen_mul.sh ../src/main.c test1.oct $1
echo 'Tests generated'
echo 'Compiling program...'
cd ../src
make > /dev/null
cd ../test_gen

echo 'Program compiled'
echo 'Running program...'
time ../src/a.out > /dev/null

echo 'Program terminated'
echo ' '

echo 'cleaning up...'
cd ../src
make clean > /dev/null
cd ../test_gen
echo 'Done'

