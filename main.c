/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:35:03 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/11 13:47:27 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"
#include "so_long.h"

void	init_mlx(t_data *game)
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
	mlx_get_screen_size(game->map.mlx_ptr, &(game->sizex), &(game->sizey));
	if (game->width * game->img_size > game->sizex || game->height
		* game->img_size > game->sizey)
	{
		ft_printf(ROUGE "Error\nMap too big for sreen!\n" RESETCOLOR);
		free_img(game);
		close_display(game);
	}
}

void	init_window(t_data *game)
{
	game->map.win_ptr = mlx_new_window(game->map.mlx_ptr, game->width
			* game->img_size, game->height * game->img_size,
			"POKEMON 42 EDITION");
	if (game->map.win_ptr == NULL)
	{
		free_img(game);
		exit(0);
	}
	draw_map(game, &game->map);
	draw_visu(game, &game->map);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (0);
	parse_map(&game, av[1]);
	init_mlx(&game);
	init_window(&game);
	mlx_hook(game.map.win_ptr, KeyPress, KeyPressMask, &user_keypress, &game);
	mlx_hook(game.map.win_ptr, DestroyNotify, StructureNotifyMask, &close_game,
		&game);
	mlx_loop(game.map.mlx_ptr);
	return (0);
}

// Verifier le format (.ber) ->
// initialser toute les struct a 0
// Open map -> read_map -> stocker la valeur de grid
// Verifier si c'est un rectangle, close
// Verifier si il y a assez de collectible/sortie/start
// Comparer les donnee avec celle de flood fill
