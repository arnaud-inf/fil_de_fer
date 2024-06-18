/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:09:17 by aelison           #+#    #+#             */
/*   Updated: 2024/05/30 08:47:19 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *result, int indice)
{
	char	*res;

	if (indice != -1)
	{
		res = ft_substr_gnl(result, 0, (size_t)indice + 1);
		return (res);
	}
	return (NULL);
}

static char	*get_stock(char *join, size_t start)
{
	char	*result;
	size_t	len;

	len = ft_strlen_gnl((const char *)join) - start;
	result = ft_substr_gnl(join, start, len);
	return (result);
}

static char	*read_file(int fd, char *join, char *buffer, char **stock)
{
	int		read_val;
	char	*result;

	if (BUFFER_SIZE <= 0)
		return (0);
	read_val = 1;
	while (read_val != 0)
	{
		read_val = read(fd, buffer, BUFFER_SIZE);
		if (read_val == -1 || read_val == 0)
			break ;
		buffer[read_val] = '\0';
		join = ft_strjoin_gnl(join, buffer);
		result = get_line(join, ft_strchr_gnl(join, '\n'));
		if (result != NULL)
		{
			*stock = get_stock (join, (size_t)ft_strchr_gnl(join, '\n') + 1);
			return (free(buffer), free(join), result);
		}
	}
	if (join[0] == 0 || read_val == -1)
		return (free(buffer), free(join), NULL);
	return (free(buffer), join);
}

char	*get_next_line(int fd)
{
	char		*join;
	char		*result;
	char		*buffer;
	static char	*stock;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	join = ft_strdup_gnl("\0");
	if (stock != NULL)
	{
		join = ft_strjoin_gnl(join, stock);
		free(stock);
		stock = NULL;
	}
	result = get_line(join, ft_strchr_gnl(join, '\n'));
	if (result != NULL)
	{
		stock = get_stock(join, (size_t)ft_strchr_gnl(join, '\n') + 1);
		return (free(buffer), free(join), result);
	}
	result = read_file(fd, join, buffer, &stock);
	return (result);
}
