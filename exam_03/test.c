// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <math.h>

// typedef struct s_zone
// {
// 	int		width;
// 	int		height;
// 	char	background;
// } t_zone;

// typedef struct s_list
// {
//     char type;
//     float x;
//     float y;
//     float radius;
//     char color;
// } t_list;

// int ft_strlen(char *str)
// {
//     int i = 0;
//     if (!str)
//         return (i);
//     while (str[i])
//         i++;
//     return (i);
// }

// int fail(char *str)
// {
//     write(1, str, ft_strlen(str));
//     return(1);
// }

// int free_all(FILE *file, char *str)
// {
//     fclose(file);
//     if (str)
//         free(str);
//     return (1);
// }

// char *get_zone(FILE *file, t_zone *zone)
// {
//     int i;
//     char *array;

//     if ((i = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
//         return (NULL);
//     if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
//         return (NULL);
//     if (!(array = (char *)malloc(sizeof(char) * (zone->width * zone->height))))
//         return (NULL);
//     i = 0;
//     while (i < (zone->width * zone->height))
//     {
//         array[i] = zone->background;
//         i++;
//     }
//     return (array);
// }

// int is_rad(float x, float y, t_list *tmp)
// {
//     float dist;

//     dist = sqrtf(((x - tmp->x) * (x - tmp->x)) + ((y - tmp->y) * (y - tmp->y)));

//     if (dist <= tmp->radius)
//     {
//         if ((tmp->radius - dist) < 1.00000000)
//             return (2);
//         return (1);
//     }
//     return (0);
// }

// void get_draw(t_list *tmp, t_zone *zone, char *draw)
// {
//     int x, y, rad;

//     y = 0;
//     while (y < zone->height)
//     {
//         x = 0;
//         while (x < zone->width)
//         {
//             rad = is_rad((float)x, (float)y, tmp);
//             if ((rad == 2 && tmp->type == 'c') || (rad && tmp->type == 'C'))
//                 draw[(y * zone->width) + x] = tmp->color;
//             x++;
//         }
//         y++;
//     }
// }

// int drawing(FILE *file, t_zone *zone, char *draw)
// {
//     t_list tmp;
//     int count;

//     while ((count = fscanf(file, "%c %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.radius, &tmp.color)) == 5)
//     {
//         if (tmp.radius <= 0.00000000 && (tmp.type != 'c' || tmp.type != 'C'))
//             return (0);
//         get_draw(&tmp, zone, draw);
//     }
//     if (count != (-1))
//         return (0);
//     return (1);
// }

// void print_draw(char *draw, t_zone *zone)
// {
//     int i = 0;

//     while (i < zone->height)
//     {
//         write(1, draw + (i * zone->width), zone->width);
//         write(1, "\n", 1);
//         i++;
//     }
// }

// int	main(int argc, char ** argv)
// {
// 	t_zone	zone;
// 	char	*draw;
// 	FILE	*file;

// 	if (argc != 2)
// 		return (fail("Error: argument\n"));
// 	if (!(file = fopen(argv[1], "r")))
// 		return (fail("Error: Operation file corrupted\n"));
// 	if (!(draw = get_zone(file, &zone)))
// 		return (free_all(file, NULL) && fail("Error: Operation file corrupted\n"));
// 	if (!(drawing(file, &zone, draw)))
// 		return (free_all(file, draw) && fail("Error: Operation file corrupted\n"));
// 	print_draw(draw, &zone);
// 	free_all(file, draw);
// }

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	back;
}	t_zone;

typedef struct s_circle
{
	char	c;
	float	x;
	float	y;
	float	rad;
	char	fill;
}	t_circle;

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while(str[len])
		len++;
	return (len);
}

int fail(char *str)
{
    write(1, str, ft_strlen(str));
    return(1);
}

int	ft_free(FILE *file, char *map)
{
	if (map)
		free(map);
	fclose(file);
	return (1);
}

char*	get_map(FILE *file, t_zone *zone)
{
	char	*map;
	int		i;
	if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->back) != 3)
		return (NULL);
	if ((zone->width <= 0 || zone->width > 300) ||
	(zone->height <= 0 || zone->height > 300))
		return (NULL);
	map = (char *)malloc(sizeof(char) * (zone->width * zone->height));
	if (!map)
		return (NULL);
	i = 0;
	while (i < (zone->width * zone->height))
		map[i++] = zone->back;
	return (map);
}

int	ft_find_rad(int x, int y, t_circle *circle)
{
	float	dist;

	dist = sqrtf(powf((float)x - circle->x, 2) + powf((float)y - circle->y, 2));
	if (dist <= circle->rad)
	{
		if (circle->rad - dist < 1.0)
			return (1);
		return (2);
	}
	return (0);
}

void	draw_circle(t_zone *zone, char *map, t_circle *circle)
{
	int	x;
	int	y;
	int	rad;

	y = 0;
	while (y < zone->width)
	{
		x = 0;
		while (x < zone->height)
		{
			rad = ft_find_rad(x, y, circle);
			if ((rad == 2 && circle->c == 'C') || rad == 1)
				map[(y * zone->width) + x] = circle->fill;
			x++;
		}
		y++;
	}
}

int	fill_map(FILE *file, t_zone *zone, char *map)
{
	t_circle	temp;
	int			count;

	while ((count = fscanf(file, "%c %f %f %f %c\n",
	&temp.c, &temp.x, &temp.y, &temp.rad, &temp.fill)) == 5)
	{
		if (temp.rad <= 0)
			return (1);
		if (temp.c == 'c' || temp.c == 'C')
			draw_circle(zone, map, &temp);
		else
			return (1);
	}
	if (count != -1)
		return (0);
	return (1);
}

void print_map(char *draw, t_zone *zone)
{
    int i = 0;

    while (i < zone->height)
    {
        write(1, draw + (i * zone->width), zone->width);
        write(1, "\n", 1);
        i++;
    }
}

int main(int argc, char **argv)
{
	t_zone	zone;
	char	*map;
	FILE	*file;

	if (argc != 2)
		return (fail("Error: argc\n"));
	file = fopen(argv[1], "r");
	if (!file)
		return (fail("Error: fopen\n"));
	map = get_map(file, &zone);
	if (!map)
		return (fail("Error: get_map\n") && ft_free(file, map));
	if (!fill_map(file, &zone, map))
		return (fail("Error: fill_map\n") && ft_free(file, map));
	print_map(map, &zone);
	ft_free(file, map);
	return (0);
}
