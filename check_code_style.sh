#!/bin/bash

find src test -name *.h -exec ./cpplint.py {} \;
find src test -name *.cc -exec ./cpplint.py {} \;
