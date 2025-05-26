#!/bin/bash
toplevel_dir=$(dirname -- "$0")
if [ -d ${toplevel_dir}/build ]; then
    rm -rf build
fi
mkdir -p ${toplevel_dir}/build
cd ${toplevel_dir}/build
cmake ..
cmake --build .
