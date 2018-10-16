#!/bin/bash


if [[ $# -ne 1 ]]; then
    echo "USAGE: test.sh <COMMAND> "
    exit 1
fi

COMMAND=$1
pip3 install ${COMMAND}
