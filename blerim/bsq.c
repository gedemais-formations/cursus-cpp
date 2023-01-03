#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int	usage(char *filename)
{
    printf("Usage: %s <mapfile>\n", filename);
    return (1);
}


int	check_square(int size, char **map, int width, int height, int x, int y)
{
    int	i;
    int	j;
    i = 0;
    while (i < size && i + x < width)
    {
        j = 0;
        while (j < size && j + y < height)
        {
            if (map[j + y][i + x] != '.')
                return (0);
            j++;
        }
        i++;
    }
    if (i == size && j == size)
        return (1);
    else
        return (0);
}


void	try_square(char **map, int width, int height, int cy, int ci, int *x, int *y, int *maxsquare)
{
    // increment the size of the square
    // check if it fits in line and column
    int	size;
    size = 1;
    while (check_square(size, map, width, height, ci, cy))
        size++;
    size--;
    if (size > *maxsquare)
    {
        *maxsquare = size;
        *y = ci;
        *x = cy;
    }
}


void	process_file(char *filename)
{
    int	fd;
    char	c;
    int	width;
    int	height;
    char	**map;
    if ((fd = open(filename, O_RDONLY)) < 0)
    {
        printf("Failed to open the file\n");
        exit(1);
    }
    c = '\0';
    width = 0;
    height = -1;
    while (read(fd, &c, 1))
    {
        if (height == -1 && c != '\n')
            width++;
        if (c == '\n')
            height++;
    }
    height++;
    close(fd);
    fd = open(filename, O_RDONLY);
    map = (char **)malloc(sizeof(char *) * height);
    int	i = 0;
    while (i < height)
    {
        map[i] = (char *)malloc(sizeof(char) * (width + 1));
        read(fd, map[i], width + 1);
        map[i][width] = '\0';
        i++;
    }
    close(fd);
    int	x;
    int	y;
    int	maxsquare;
    x = 0;
    y = 0;
    maxsquare = 0;
    i = 0;
    while (i + maxsquare < height)
    {
        int j = 0;
        while (j + maxsquare < width)
        {
            try_square(map, width, height, i, j, &x, &y, &maxsquare);
            j++;
        }
        i++;
    }
    i = 0;
    while (i < maxsquare)
    {
        int j = 0;
        while (j < maxsquare)
        {
            map[i + x][j + y] = 'x';
            j++;
        }
        i++;
    }
    i = 0;
    while (i < height)
    {
        int j = 0;
        while (j < width)
        {
            printf("%c ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    i = 0;
    while (i < height)
    {
        free(map[i]);
        i++;
    }
    free(map);
}


int	main(int ac, char **av)
{
    if (ac != 2)
        return (usage(av[0]));
    process_file(av[1]);
    return (0);
}
