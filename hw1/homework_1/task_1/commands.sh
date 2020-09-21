#!/usr/bin/env bash

echo "The number of lines:"
cat data.dat | wc -l

echo "The number of lines that contain dolor or dalor:"
grep -E "dolor|dalor" data.dat | wc -l

echo "The number of words: "
cat data.dat | wc -w

echo "The number of words start with mol"
grep -o "\bmol\w*" data.dat | wc -w 