#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_exit(FILE *file, char *map)
{
	if (file)
		fclose(file);
	if (map)
		free(map);
	write(1, "Error: Operation file corrupted\n", 32);
	return(1);
}

int	main(int argc, char **argv)
{
	FILE	*file = NULL;
	char	*map = NULL;
	int		count, width, height;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return(1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
		return(ft_exit(file, map));
	return(0);
}