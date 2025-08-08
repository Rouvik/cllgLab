#!/bin/bash

if [ -n "$1" ]; then
    echo "Setting build scripts in ${1}..."
    cp $(find $(dirname "$0") -mindepth 1 -not -name '*.sh' -not -name '.') $1
    echo "Setup complete!"
else
    echo "Error missing path to setup into"
fi