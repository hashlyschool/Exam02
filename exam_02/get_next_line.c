#include <stdio.h>	// for: printf
#include <stdlib.h>	// for: malloc, free
#include <unistd.h>	// for: read

int	get_next_line(char **line)
{
	int rd = 0;
	int i = 0;
	char ch;
	char *buffer = malloc(100000);

	while ((rd = read(0, &ch, 1)) > 0 && ch != '\n')
	buffer[i++] = ch;
	buffer[i] = '\0';
	*line = buffer;
	return (rd);
}

/* delete befor upload */

int	main()
{
	char	*line;
	int		read_char;

	read_char = get_next_line(&line);
	while (read_char > 0)
	{
		printf("%s\n", line);
		free(line);
		read_char = get_next_line(&line);
	}
	free(line);
	return (0);
}
