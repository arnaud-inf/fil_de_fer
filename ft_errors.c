/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 06:40:29 by aelison           #+#    #+#             */
/*   Updated: 2024/06/11 08:14:49 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_elem_exist(char *str, char elem)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == elem)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_isformat(char *str)
{
	int		i;

	i = ft_elem_exist(str, '.');
	if (i != -1)
		return (ft_strncmp(str + i, ".fdf", 4));
	return (1);
}

void	ft_errors(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error : wrong arg number\n", 2);
		exit(1);
	}
	if ((ft_strlen(argv) < 5) || (ft_isformat(argv) != 0))
	{
		ft_putstr_fd("Error : wrong name\n", 2);
		exit(1);
	}
	if (open(argv, O_RDONLY) == -1)
	{
		ft_putstr_fd("Error : file does not exist\n", 2);
		exit(1);
	}
}
