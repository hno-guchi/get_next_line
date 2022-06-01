#!/bin/zsh

if [ $2 ]
then
	# cc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 main.c ../get_next_line.c ../get_next_line_utils.c
	# ./a.out $2
	# diff $2 gnl.txt
	gcc -g -fsanitize=address -D BUFFER_SIZE=$1 main.c ../get_next_line.c ../get_next_line_utils.c
	./a.out $2 > gnl.txt
	diff $2 gnl.txt
elif [ $1 ]
then
	# cc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 main.c ../get_next_line.c ../get_next_line_utils.c
	gcc -g -fsanitize=address -D BUFFER_SIZE=$1 main.c ../get_next_line.c ../get_next_line_utils.c
else
	# cc -Wall -Wextra -Werror main.c ../get_next_line.c ../get_next_line_utils.c
	gcc -g -fsanitize=address main.c ../get_next_line.c ../get_next_line_utils.c
fi
