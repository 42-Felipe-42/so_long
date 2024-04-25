/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:25:03 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 13:40:27 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Fonction principal qui recoit les touches presse par l'user
int	ft_user_keypress(int keycode, t_data *game)
{
	if ((keycode == XK_a || keycode == XK_s || keycode == XK_d
			|| keycode == XK_w) && game->dead == 0)
	{
		game->started = 1;
		put_black_case(game);
		ft_move_left(keycode, game);
		ft_move_right(keycode, game);
		ft_move_up(keycode, game);
		ft_move_down(keycode, game);
	}
	else if (keycode == XK_h && game->dead == 0)
	{
		make_dance(game);
		put_image_window(game, game->img.player_s1, game->start_x,
			game->start_y);
	}
	else if (keycode == XK_Escape)
	{
		ft_close_game(game);
	}
	return (0);
}

// Genere des move random au npc (diminuer la taille de la 
//loop_npc pour augmenter la difficulter)
int	random_move(t_data *game)
{
	int	i;
	int	random_direction;

	if (game->loop_npc++ > 19000 && game->started == 1)
	{
		i = -1;
		while (++i < game->npc.nb_npc)
		{
			random_direction = rand() % 4;
			if (random_direction == 0)
				npc_move_up(game, &(game->npc_number[i]), i);
			else if (random_direction == 1)
				npc_move_left(game, &(game->npc_number[i]), i);
			else if (random_direction == 2)
				npc_move_right(game, &(game->npc_number[i]), i);
			else if (random_direction == 3)
				npc_move_down(game, &(game->npc_number[i]), i);
			if (check_in_front_npc(game, &(game->npc_number[i]), i))
				return (put_image_window(game, game->img.die_img, game->start_x,
						game->start_y), game->dead = 1, game->started = 0, 0);
		game->loop_npc = 0;
		}
	}
	return (0);
}

// Gere l'affichage du compteur de pas sur l'ecran et affichage
// de l'exit une fois tout les collectibles recupere
void	case_event(t_data *game, int y, int x)
{
	char	*str;

	str = ft_itoa(game->steps);
	put_black_case(game);
	mlx_string_put(game->map.mlx_ptr, game->map.win_ptr, game->width
		* game->img_size - 20, game->height * game->img_size + 25, 0xFFFFFF,
		str);
	free(str);
	mlx_string_put(game->map.mlx_ptr, game->map.win_ptr, game->width
		* game->img_size - 70, game->height * game->img_size + 25, 0xFF0000,
		"STEPS :");
	mlx_string_put(game->map.mlx_ptr, game->map.win_ptr, game->width
		* game->img_size - 1000, game->height * game->img_size + 25, 0xFF0000,
		"PRESS 'h' FOR A LITTLE DANCE");
	if (game->collectible == 0)
		put_img("exit", game);
	if (game->grid[y][x] == 'E' && game->collectible == 0)
		ft_close_game(game);
}

// Affiche les enemy sur la carte selon leur position
void	put_enemy(t_data *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			x = j * game->img_size;
			y = i * game->img_size;
			if (game->grid[i][j] == 'M')
				mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr,
					game->img.npc_s, x, y);
			j++;
		}
		i++;
	}
}
