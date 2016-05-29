#!/bin/bash

sed 's/^[ \t]*//' "3.py" | sed 's/.*/\L&/' | grep "^#" | sort --unique --ignore-case | wc -l
