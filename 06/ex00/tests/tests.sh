#!/bin/sh

EXEC=./scalarConverter

while read line; do
    echo "===== INPUT: \"$line\" ====="
    $EXEC "$line"
    echo ""
done < tests.txt
