#!/bin/zsh

if [ $2 ]
then
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 leaks.c ../get_next_line.c ../get_next_line_utils.c
	rm gnl.txt
	./a.out $2 > gnl.txt
	diff $2 gnl.txt
	cc -g -fsanitize=address -D BUFFER_SIZE=$1 fsanitize.c ../get_next_line.c ../get_next_line_utils.c
	rm gnl.txt
	./a.out $2 > gnl.txt
	diff $2 gnl.txt
elif [ $1 ]
then
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 leaks.c ../get_next_line.c ../get_next_line_utils.c
	./a.out
	# cc -g -fsanitize=address -D BUFFER_SIZE=$1 fsanitize.c ../get_next_line.c ../get_next_line_utils.c
	# ./a.out
else
	cc -Wall -Wextra -Werror leaks.c ../get_next_line.c ../get_next_line_utils.c
	./a.out
	# gcc -g -fsanitize=address fsanitize.c ../get_next_line.c ../get_next_line_utils.c
	# ./a.out
fi
