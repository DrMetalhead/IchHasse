/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricschmi <ricschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:59:22 by ricschmi          #+#    #+#             */
/*   Updated: 2023/07/30 23:29:21 by ricschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

char	*ft_get_index(long long fd)
{
    char c;
    long long i = 0;
    long long bufferSize = INITIAL_BUFFER_SIZE;
    char *buffer = malloc(bufferSize * sizeof(char));
    if (!buffer)
        exit(1);
    while (read(fd, &c, 1) > 0 && c != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            buffer[i++] = c;
            if (i == bufferSize)
            {
                bufferSize *= 2;
                buffer = ft_realloc(buffer, bufferSize * sizeof(char));
                if (!buffer)
                    exit(1);
            }
        }
        else
            break;
    }
    buffer[i] = '\0'; // Add null terminator at the end of the string
    return buffer;
}

char	*ft_get_str(long long fd, char *c)
{
    long long i;
    long long bufferSize;
    char *buffer;

	i = 0;
	bufferSize = INITIAL_BUFFER_SIZE;
	buffer = malloc(bufferSize * sizeof(char));
    if (!buffer)
        exit(1);
    while (c[0] != '\n')
    {
        buffer[i++] = c[0];
        read(fd, c, 1);
        if (i == bufferSize)
        {
            bufferSize *= 2;
            buffer = ft_realloc(buffer, bufferSize * sizeof(char));
            if (!buffer)
                exit(1);
        }
    }
    buffer[i] = '\0'; // Add null terminator at the end of the string
    return buffer;
}

void	ft_norminette_happy(t_list *row, long long fd, char *c, long long i)
{
	row[i].index = ft_atoi_free(ft_get_index(fd));
	read(fd, c, 1);
	while (c[0] == ' ')
		read(fd, c, 1);
	if (c[0] == ':')
		read(fd, c, 1);
	while (c[0] == ' ')
		read(fd, c, 1);
}

t_list	*ft_read_dict(char *file)
{
	long long	i;
	long long	fd;
	char		c[1];
	t_list		*row;
	char		*tmp;

	row = malloc(sizeof(t_list) * 33);
	if (!row)
		exit(1);
	fd = open(file, O_RDONLY);
	if ((fd == -1) || !(row))
		exit(1);
	i = 0;
	while (i < 32)
	{
		ft_norminette_happy(row, fd, c, i);
		tmp = ft_get_str(fd, c);
		row[i].str = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	close(fd);
	return (row);
}
