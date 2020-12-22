/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:03:15 by aabounak          #+#    #+#             */
/*   Updated: 2020/12/22 14:44:12 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_exit(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(-1);
}

int		all_n(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int		ft_isnum(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' && s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		ft_strlendoubleptr(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				ft_exit("Error\nLetters in Resolution!\n");
			j++;
		}
		i++;
	}
	return (i);
}

void	check_comma(char *buffer)
{
	int		comma;

	comma = 0;
	while (*buffer)
	{
		if (*buffer == ',')
		{
			comma++;
			if (comma > 2)
				ft_exit("Error\nYou can't use more than 2 commas!\n");
		}
		buffer++;
	}
}
