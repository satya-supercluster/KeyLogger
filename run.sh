#!/bin/bash
set -e

echo "Running Makefile..."
make

echo " Cleaning..."
make clean

echo "Running the program..."
./setup

echo "✅ Done!"
