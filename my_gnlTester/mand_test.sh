#!/bin/zsh

if [ $2 ]
then
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 ./main/leaks.c ../get_next_line.c ../get_next_line_utils.c
	rm ./files/gnl.txt
	./a.out $2 > ./files/gnl.txt
	diff $2 ./files/gnl.txt
	cc -g -fsanitize=address -D BUFFER_SIZE=$1 ./main/fsanitize.c ../get_next_line.c ../get_next_line_utils.c
	rm ./files/gnl.txt
	./a.out $2 > ./files/gnl.txt
	diff $2 ./files/gnl.txt
elif [ $1 ]
then
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 ./main/leaks.c ../get_next_line.c ../get_next_line_utils.c
	./a.out
	# cc -g -fsanitize=address -D BUFFER_SIZE=$1 ./main/fsanitize.c ../get_next_line.c ../get_next_line_utils.c
	# ./a.out
else
	cc -Wall -Wextra -Werror ./main/leaks.c ../get_next_line.c ../get_next_line_utils.c
	./a.out
	# gcc -g -fsanitize=address ./main/fsanitize.c ../get_next_line.c ../get_next_line_utils.c
	# ./a.out
fi
