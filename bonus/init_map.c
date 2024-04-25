/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:29:13 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:28:00 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_struct(t_data *game)
{
	ft_bzero(game, sizeof(t_data));
	game->grid = 0;
	game->collectible = 0;
	game->exit = 0;
	game->height = 0;
	game->start = 0;
	game->steps = 0;
	game->width = 0;
	game->start_x = 0;
	game->start_y = 0;
	game->walls = 0;
	game->collected_collectible = 0;
	game->found_exit = 0;
	game->npc.nb_npc_see = 0;
	game->npc.nb_npc = 0;
	game->loop_npc = 0;
	game->dead_player = 0;
	game->img_size = 0;
	game->dead = 0;
	game->npc.pos_x = 0;
	game->npc.pos_y = 0;
	game->npc.nb_npc = 0;
	game->npc.nb_npc_see = 0;
	game->npc.direction = 0;
	game->started = 0;
}

//Init des assets et retourne un message d'erreur 
//en cas de probleme avec le fichier xpm
void	init_assets_player(t_map *mlx, t_data *game)
{
	game->img.player_s = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/persF3.xpm", &game->img_size, &game->img_size);
	if (!game->img.player_s)
		ft_error_xpm(game);
	game->img.player_d = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/persR3.xpm", &game->img_size, &game->img_size);
	if (!game->img.player_d)
		ft_error_xpm(game);
	game->img.player_a = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/persL3.xpm", &game->img_size, &game->img_size);
	if (!game->img.player_a)
		ft_error_xpm(game);
	game->img.player_w = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/persT2.xpm", &game->img_size, &game->img_size);
	if (!game->img.player_w)
		ft_error_xpm(game);
	game->img.player_s1 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/persF1.xpm", &game->img_size, &game->img_size);
	if (!game->img.player_s1)
		ft_error_xpm(game);
	game->img.die_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/die.xpm", &game->img_size, &game->img_size);
	if (!game->img.die_img)
		ft_error_xpm(game);
}

//Init des assets et retourne un message d'erreur 
//en cas de probleme avec le fichier xpm
void	init_dance_player(t_map *mlx, t_data *game)
{
	game->img.dance_f1 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/danceFrontUp.xpm", &game->img_size, &game->img_size);
	if (!game->img.dance_f1)
		ft_error_xpm(game);
	game->img.dance_f2 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/dancefront1.xpm", &game->img_size, &game->img_size);
	if (!game->img.dance_f2)
		ft_error_xpm(game);
	game->img.dance_f3 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/dancefront2.xpm", &game->img_size, &game->img_size);
	if (!game->img.dance_f3)
		ft_error_xpm(game);
	game->img.dance_b1 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/dancebackUP.xpm", &game->img_size, &game->img_size);
	if (!game->img.dance_b1)
		ft_error_xpm(game);
	game->img.dance_b2 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/danceBack1.xpm", &game->img_size, &game->img_size);
	if (!game->img.dance_b2)
		ft_error_xpm(game);
	game->img.dance_b3 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/danceBack2.xpm", &game->img_size, &game->img_size);
	if (!game->img.dance_b3)
		ft_error_xpm(game);
}

//Init des assets et retourne un message d'erreur 
//en cas de probleme avec le fichier xpm
void	init_assets_npc(t_map *mlx, t_data *game)
{
	game->img.npc_s = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/npcF1.xpm", &game->img_size, &game->img_size);
	if (!game->img.npc_s)
		ft_error_xpm(game);
	game->img.npc_d = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/npcR2.xpm", &game->img_size, &game->img_size);
	if (!game->img.npc_d)
		ft_error_xpm(game);
	game->img.npc_a = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/npcL2.xpm", &game->img_size, &game->img_size);
	if (!game->img.npc_a)
		ft_error_xpm(game);
	game->img.npc_w = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/npcT2.xpm", &game->img_size, &game->img_size);
	if (!game->img.npc_w)
		ft_error_xpm(game);
	game->img.black_case = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets_bonus/black_case.xpm", &game->img_size, &game->img_size);
	if (!game->img.black_case)
		ft_error_xpm(game);
}

//Assigne les position de chaque npc en prenant compte leurs nombres dans la map
void	init_nb_npc(t_data *game)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	game->npc_number = ft_calloc(game->npc.nb_npc, sizeof(t_npc));
	if (!game->npc_number)
		return ;
	while (y < game->height && i < game->npc.nb_npc)
	{
		x = 0;
		while (x < game->width && i < game->npc.nb_npc)
		{
			if (game->grid[y][x] == 'M')
			{
				game->npc_number[i].pos_y = y;
				game->npc_number[i].pos_x = x;
				i++;
			}
			x++;
		}
		y++;
	}
}
