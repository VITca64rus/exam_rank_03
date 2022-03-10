#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
	int		count, width, height, i, j;
	char	background, type, c;
	float	x, y, ex, ey;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return(1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
		return(ft_exit(file, map));
	count = fscanf(file, "%i %i %c\n", &width, &height, &background);
	if (count != 3 || width <= 0 || width > 300 || height > 300 || height <= 0)
		return(ft_exit(file, map));
	map = calloc(width, height);
	if (!map)
		return(42);
	memset(map, background, width * height);
	while(1)
	{
		count = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &ex, &ey, &c);
		if (count == -1)
			break ;
		if (count != 6 || ex <= 0.0f || ey <= 0.0f || (type != 'r' && type != 'R'))
			return (ft_exit(file, map));
        ex += x;
        ey += y;
		i = 0;
		while (i < height)
		{
			j = 0;
			while (j < width)
			{
				if (j >= x && j <= ex && i >= y && i <= ey)
					if (type == 'R' || j < x + 1 || j > ex - 1 || i < y + 1 || i > ey - 1)
						map[i * width + j] = c;
				j++;
			}
			i++;
		}
	}
	ft_print_map(map, width, height);
	free(map);
	fclose(file);
	return(0);
}