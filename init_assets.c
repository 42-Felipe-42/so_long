/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:44:06 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:23:20 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"
#include "so_long.h"

//init tout la struct a 0 avec b_zero
void	init_struct(t_data *game)
{
	ft_bzero(game, sizeof(t_data));
	game->img_size = PIXEL_SIZE;
}

//init des assets du joueur
void	init_img_player(t_map *mlx, t_data *game)
{
	mlx->floor_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/floor.xpm",
			&game->img_size, &game->img_size);
	if (!mlx->floor_img)
		error_xpm(game);
	mlx->perso_s_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets/sachaFRONT.xpm", &game->img_size, &game->img_size);
	if (!mlx->perso_s_img)
		error_xpm(game);
	mlx->perso_w_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets/sachaTOP.xpm", &game->img_size, &game->img_size);
	if (!mlx->perso_w_img)
		error_xpm(game);
	mlx->perso_d_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets/sachaRIGHT.xpm", &game->img_size, &game->img_size);
	if (!mlx->perso_d_img)
		error_xpm(game);
	mlx->perso_a_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets/sachaLEFT.xpm", &game->img_size, &game->img_size);
	if (!mlx->perso_a_img)
		error_xpm(game);
}

//init des assets de la map
void	init_img_map(t_map *mlx, t_data *game)
{
	mlx->exit_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/exit.xpm",
			&game->img_size, &game->img_size);
	if (!mlx->exit_img)
		error_xpm(game);
	mlx->collect_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets/pokeball.xpm", &game->img_size, &game->img_size);
	if (!mlx->collect_img)
		error_xpm(game);
	mlx->wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/tree.xpm",
			&game->img_size, &game->img_size);
	if (!mlx->wall_img)
		error_xpm(game);
}

//Libere l'espace alloue des img
void	free_img(t_data *game)
{
	if (game->map.exit_img)
		mlx_destroy_image(game->map.mlx_ptr, game->map.exit_img);
	if (game->map.collect_img)
		mlx_destroy_image(game->map.mlx_ptr, game->map.collect_img);
	if (game->map.wall_img)
		mlx_destroy_image(game->map.mlx_ptr, game->map.wall_img);
	if (game->map.floor_img)
		mlx_destroy_image(game->map.mlx_ptr, game->map.floor_img);
	if (game->map.perso_a_img)
		mlx_destroy_image(game->map.mlx_ptr, game->map.perso_a_img);
	if (game->map.perso_d_img)
		mlx_destroy_image(game->map.mlx_ptr, game->map.perso_d_img);
	if (game->map.perso_s_img)
		mlx_destroy_image(game->map.mlx_ptr, game->map.perso_s_img);
	if (game->map.perso_w_img)
		mlx_destroy_image(game->map.mlx_ptr, game->map.perso_w_img);
}

//Permet d'afficher une image selon le text donne
void	put_img(char *name_assets, t_data *game)
{
	if (strcmp(name_assets, "playerW") == 0)
		mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr,
			game->map.perso_w_img, (game->start_x) * game->img_size,
			(game->start_y) * game->img_size);
	if (strcmp(name_assets, "floor") == 0)
		mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr,
			game->map.floor_img, (game->start_x) * game->img_size,
			(game->start_y) * game->img_size);
	if (strcmp(name_assets, "playerS") == 0)
		mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr,
			game->map.perso_s_img, (game->start_x) * game->img_size,
			(game->start_y) * game->img_size);
	if (strcmp(name_assets, "playerD") == 0)
		mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr,
			game->map.perso_d_img, (game->start_x) * game->img_size,
			(game->start_y) * game->img_size);
	if (strcmp(name_assets, "playerA") == 0)
		mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr,
			game->map.perso_a_img, (game->start_x) * game->img_size,
			(game->start_y) * game->img_size);
	if (strcmp(name_assets, "exit") == 0)
		mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr,
			game->map.exit_img, (game->exit_x) * game->img_size, (game->exit_y)
			* game->img_size);
}
