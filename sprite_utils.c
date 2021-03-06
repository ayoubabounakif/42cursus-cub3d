/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:22:04 by aabounak          #+#    #+#             */
/*   Updated: 2020/12/18 18:26:42 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	g_j;
static int	g_i;
static int	g_spt_id;

void		ft_sprite_sort(void)
{
	int			i;
	int			j;
	t_sprite	*tmp;

	i = 0;
	while (i < g_sprite_count)
	{
		j = 0;
		while (j < g_sprite_count - i - 1)
		{
			if (g_sprite[j]->distance <= g_sprite[j + 1]->distance)
			{
				tmp = g_sprite[j];
				g_sprite[j] = g_sprite[j + 1];
				g_sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void		update_sprite(void)
{
	g_spt_id = 0;
	g_j = -1;
	while (++g_j < ROWS)
	{
		g_i = -1;
		while (++g_i < COLS)
		{
			if (g_map[g_j][g_i] == '2')
			{
				g_sprite[g_spt_id]->y = (g_j * TILE_SIZE) + TILE_SIZE / 2;
				g_sprite[g_spt_id]->x = (g_i * TILE_SIZE) + TILE_SIZE / 2;
				g_sprite[g_spt_id]->distance = distance_bpts(
					g_sprite[g_spt_id]->y, g_sprite[g_spt_id]->x,
					g_player.y, g_player.x);
				g_spt_id++;
			}
		}
	}
	ft_sprite_sort();
}
