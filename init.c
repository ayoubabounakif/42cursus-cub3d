/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 04:42:41 by aabounak          #+#    #+#             */
/*   Updated: 2020/11/25 08:41:01 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initiating my player position
// so that it spawns on the right x,y axis where 'P' is written
void		init_player()
{
	ft_bzero(&g_vars, sizeof(t_vars));
	ft_bzero(&g_player, sizeof(t_player));
	while (g_vars.rows < ROWS)
	{
		g_vars.cols = 0;
		while (g_vars.cols < COLS)
		{
			if (g_mapread[g_vars.rows][g_vars.cols] == 'N' ||
				g_mapread[g_vars.rows][g_vars.cols] == 'S' ||
				g_mapread[g_vars.rows][g_vars.cols] == 'W' ||
				g_mapread[g_vars.rows][g_vars.cols] == 'E')
			{
				set_rotation_angle(g_mapread[g_vars.rows][g_vars.cols]);
				g_player.y = g_vars.rows * TILE_SIZE + 32;
				g_player.x = g_vars.cols * TILE_SIZE + 32;
			}
			// else if (g_mapread[g_vars.rows][g_vars.cols] == '2')
			// {
			// 	g_sprite.SptOffSetY = (g_vars.rows + 0.5) * (float)TILE_SIZE;
			// 	g_sprite.SptOffSetX = (g_vars.cols + 0.5) * (float)TILE_SIZE;
			// 	g_sprite.distance = distanceBetweenPoints(g_sprite.SptOffSetX, g_sprite.SptOffSetY,
			// 			g_player.x, g_player.y);
			// 	g_sprite_count++;
			// }
			g_vars.cols++;
		}
		g_vars.rows++;
	}
}

// Initialising my tex vars because its C
void		init_tex()
{
	g_tex.texOffSetX = 0;
	g_tex.texOffSetY = 0;
	g_tex.distanceFromTop = 0;
	g_tex.texelColor = 0;

	g_tex.ptr = mlx_xpm_file_to_image(g_mlx.mlx_ptr, g_data.paths.no, &g_tex.img_width, &g_tex.img_height);
	g_textnorth = (int *)mlx_get_data_addr(g_tex.ptr, &g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);

	g_tex.ptr = mlx_xpm_file_to_image(g_mlx.mlx_ptr, g_data.paths.so, &g_tex.img_width, &g_tex.img_height);
	g_textsouth = (int *)mlx_get_data_addr(g_tex.ptr, &g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);

	g_tex.ptr = mlx_xpm_file_to_image(g_mlx.mlx_ptr, g_data.paths.we, &g_tex.img_width, &g_tex.img_height);
	g_textwest = (int *)mlx_get_data_addr(g_tex.ptr, &g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);

	g_tex.ptr = mlx_xpm_file_to_image(g_mlx.mlx_ptr, g_data.paths.ea, &g_tex.img_width, &g_tex.img_height);
	g_texteast = (int *)mlx_get_data_addr(g_tex.ptr, &g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);
}
