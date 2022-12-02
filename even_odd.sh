#!/bin/bash

echo "enter a number"
read x

if [ $(( $x % 2 )) -eq 0 ]; then
    echo "Even"
else
    echo "odd"
fi