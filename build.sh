#!/bin/bash

gcc -Wall -Wextra -Werror -fsanitize=address -o ./build/brutis brutis.c 