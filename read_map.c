/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:24:52 by aabounak          #+#    #+#             */
/*   Updated: 2020/12/16 12:08:47 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int		g_p;
static int		g_i;
static t_list	*g_temp;
static char		*g_str;

static void		free_list(void)
{
	while (g_file != NULL)
	{
		g_temp = g_file;
		g_file = g_file->next;
		free(g_temp->content);
		free(g_temp);
	}
}

static void		second_init(void)
{
	g_biglen += 2;
	g_sizeofmap += 2;
	if (!(g_map = (char **)malloc(sizeof(char *) * (g_sizeofmap + 1))))
		return ;
	g_map[0] = space_filler(g_biglen);
	g_temp = g_file;
	g_str = NULL;
	g_i = 1;
}

static void		first_init(void)
{
	g_p = 0;
	g_sizeofmap = 0;
	g_biglen = 0;
	g_temp = g_file;
	g_str = NULL;
}

int				map_error(void)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ROWS)
	{
		j = -1;
		while (++j < COLS)
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'S'
			|| g_map[i][j] == 'W' || g_map[i][j] == 'E')
				g_p++;
			if (g_map[i][j] == '0' || g_map[i][j] == 'N' || g_map[i][j] == 'S'
			|| g_map[i][j] == 'W' || g_map[i][j] == 'E' || g_map[i][j] == '2')
			{
				if (g_map[i - 1][j] == ' ' || g_map[i][j - 1] == ' ' ||
				g_map[i + 1][j] == ' ' || g_map[i][j + 1] == ' ')
					return (1);
			}
		}
	}
	return (0);
}

void			check_map(void)
{
	first_init();
	while (g_temp)
	{
		g_str = g_temp->content;
		if (get_fchar(g_str))
		{
			g_sizeofmap++;
			if (ft_strlen(g_str) > (size_t)g_biglen)
				g_biglen = ft_strlen(g_str);
		}
		g_temp = g_temp->next;
	}
	second_init();
	while (g_temp)
	{
		g_str = g_temp->content;
		if (get_fchar(g_str))
			g_map[g_i++] = spacer(g_str, g_biglen);
		g_temp = g_temp->next;
	}
	g_map[g_i++] = space_filler(g_biglen);
	g_map[g_i] = NULL;
	free_list();
	if (map_error() == 1 || g_p != 1)
		ft_exit("Error\nMultiple or no players or Invalid map!\n");
}
