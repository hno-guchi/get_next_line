#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	// size_t	siz = sysconf(OPEN_MAX - _SC_OPEN_MAX);
	// printf("OPEN_MAX     = [%ld]\n", sysconf(OPEN_MAX));
	printf("_SC_OPEN_MAX = [%ld]\n", sysconf(_SC_OPEN_MAX));
	printf("FOPEN_MAX    = [%ld]\n", sysconf(FOPEN_MAX));
	return (0);
}
