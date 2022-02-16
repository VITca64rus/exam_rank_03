#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_exit(FILE *file, char *map)
{
	if (file)
		fclose(file);
	if (map)
		free(map);
	write(1, "Error: Operation file corrupted\n", 32);
	return(1);
}

void ft_print_map(char *map, int width, int height)
{
	int i = 0;
	int j = 0;

	while (i < height)
	{
		write(1, &map[i * width], width);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	FILE	*file = NULL;
	char	*map = NULL;
	int		count, width, height;
	char	background;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return(1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
		return(ft_exit(file, map));
	count = fscanf(file, "%i %i %c", &width, &height, &background);
	if (count != 3 || width <= 0 || width > 300 || height > 300 || height <= 0)
		return(ft_exit(file, map));
	map = calloc(width, height);
	if (!map)
		return(42);
	memset(map, background, width * height);



	ft_print_map(map, width, height);
	free(map);
	fclose(file);
	return(0);
}
