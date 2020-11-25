/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:07:06 by aabounak          #+#    #+#             */
/*   Updated: 2020/11/20 23:00:09 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

float	distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return (sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
    return (angle);
}

int		wall_collision(float x, float y)
{
	unsigned int		mapGridIndexX = floor(x / TILE_SIZE);
	unsigned int		mapGridIndexY = floor(y / TILE_SIZE);

	// if (mapGridIndexY < 0 || mapGridIndexX < 0)
	// 	return (0);
	if (g_mapread[mapGridIndexY][mapGridIndexX] == '0' ||
		g_mapread[mapGridIndexY][mapGridIndexX] == 'N' ||
		g_mapread[mapGridIndexY][mapGridIndexX] == 'S' ||
		g_mapread[mapGridIndexY][mapGridIndexX] == 'E' || 
		g_mapread[mapGridIndexY][mapGridIndexX] == 'S')
		return (0);
	else if (g_mapread[mapGridIndexY][mapGridIndexX] == '1' ||
			g_mapread[mapGridIndexY][mapGridIndexX] == ' ')
		return (1);
	else if (g_mapread[mapGridIndexY][mapGridIndexX] == '2')
		return (2);
	else if (x < 0 && x >= WIN_WIDTH && y < 0 && y >= WIN_HEIGHT)	// OUTSIDE THE BOUNDARIES
		return (1);
	return (0);
}

void		draw_square(int y, int x, int size, int color)
{
	int		x_end = x + size;
	int		y_end = y + size;
	int		original_x = x;

	g_vars.y = y;
	while (y < y_end)
	{
		x = original_x;
		while (x < x_end)
		{
			if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
				g_mlx.data[x + y * WIN_WIDTH] = color;
			x++;
		}
		y++;
	}
}