#!/bin/env bash
set -x
clang++ *.cpp -o build/out -lraylib -lm && chmod +x build/out && ./build/out