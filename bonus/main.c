/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:08:37 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/11 22:54:04 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_mlx(t_data *game)
{
	game->map.mlx_ptr = mlx_init();
	if (game->map.mlx_ptr == NULL)
	{
		free_grid(game);
		exit(0);
		return ;
	}
	init_img_player(&game->map, game);
	init_img_map(&game->map, game);
	init_assets_player(&game->map, game);
	init_assets_npc(&game->map, game);
	init_dance_player(&game->map, game);
	mlx_get_screen_size(game->map.mlx_ptr, &(game->sizex), &(game->sizey));
	if (game->width * game->img_size > game->sizex || game->height
		* game->img_size > game->sizey)
	{
		ft_printf(ROUGE "Error\nMap too big for sreen!\n" RESETCOLOR);
		free_img(game);
		free_assets_player(game);
		free_assets_npc(game);
		free_npc(game);
		close_display(game);
	}
}

void	ft_init_window(t_data *game)
{
	game->map.win_ptr = mlx_new_window(game->map.mlx_ptr, game->width
			* game->img_size, (game->height + 1) * game->img_size,
			"POKEMON 42 EDITION");
	if (game->map.win_ptr == NULL)
	{
		free_img(game);
		free_assets_player(game);
		free_assets_npc(game);
		free_npc(game);
		close_display(game);
	}
	draw_map(game, &game->map);
	draw_visu(game, &game->map);
	put_enemy(game);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (0);
	srand(time(NULL));
	ft_parse_map(&game, av[1]);
	ft_init_mlx(&game);
	ft_init_window(&game);
	mlx_hook(game.map.win_ptr, KeyPress, KeyPressMask, &ft_user_keypress,
		&game);
	mlx_hook(game.map.win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_close_game, &game);
	mlx_loop_hook(game.map.mlx_ptr, &random_move, &game);
	mlx_loop(game.map.mlx_ptr);
	return (0);
}
