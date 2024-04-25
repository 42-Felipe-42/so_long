/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_perso_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:25:11 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:28:42 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Check si il n'y a pas de mur/enemy/collectible 
//a gauche quand la touche 'a' est presse
void	ft_move_left(int keycode, t_data *game)
{
	if (keycode != XK_a)
		return ;
	if (game->grid[game->start_y][game->start_x - 1] != '1'
		&& game->grid[game->start_y][game->start_x - 1] != 'M')
		game->steps++;
	case_event(game, game->start_y, game->start_x - 1);
	if (game->grid[game->start_y][game->start_x - 1] == 'M')
		return ;
	if (game->grid[game->start_y][game->start_x - 1] == '1')
	{
		ft_printf(ROUGE "You can't climb in trees\n" RESETCOLOR);
		return ;
	}
	if (game->grid[game->start_y][game->start_x] != 'E')
		game->grid[game->start_y][game->start_x] = '0';
	put_img("floor", game);
	game->start_x--;
	if (game->grid[game->start_y][game->start_x] == 'C')
		game->collectible--;
	if (game->grid[game->start_y][game->start_x] != 'E')
		game->grid[game->start_y][game->start_x] = 'P';
	put_image_window(game, game->img.player_a, game->start_x, game->start_y);
}

// Check si il n'y a pas de mur/enemy/collectible 
//a droite quand la touche 'd' est presse
void	ft_move_right(int keycode, t_data *game)
{
	if (keycode != XK_d)
		return ;
	if (game->grid[game->start_y][game->start_x + 1] != '1'
		&& game->grid[game->start_y][game->start_x + 1] != 'M')
		game->steps++;
	case_event(game, game->start_y, game->start_x + 1);
	if (game->grid[game->start_y][game->start_x + 1] == 'M')
		return ;
	if (game->grid[game->start_y][game->start_x + 1] == '1')
	{
		ft_printf(ROUGE "You can't climb in trees\n" RESETCOLOR);
		return ;
	}
	if (game->grid[game->start_y][game->start_x] != 'E')
		game->grid[game->start_y][game->start_x] = '0';
	put_img("floor", game);
	game->start_x++;
	if (game->grid[game->start_y][game->start_x] == 'C')
		game->collectible--;
	if (game->grid[game->start_y][game->start_x] != 'E')
		game->grid[game->start_y][game->start_x] = 'P';
	put_image_window(game, game->img.player_d, game->start_x, game->start_y);
}

// Check si il n'y a pas de mur/enemy/collectible 
//en bas quand la touche 's' est presse
void	ft_move_down(int keycode, t_data *game)
{
	if (keycode != XK_s)
		return ;
	if (game->grid[game->start_y + 1][game->start_x] != '1'
		&& game->grid[game->start_y + 1][game->start_x] != 'M')
		game->steps++;
	case_event(game, game->start_y + 1, game->start_x);
	if (game->grid[game->start_y + 1][game->start_x] == 'M')
		return ;
	if (game->grid[game->start_y + 1][game->start_x] == '1')
	{
		ft_printf(ROUGE "You can't climb in trees\n" RESETCOLOR);
		return ;
	}
	if (game->grid[game->start_y][game->start_x] != 'E')
		game->grid[game->start_y][game->start_x] = '0';
	put_img("floor", game);
	game->start_y++;
	if (game->grid[game->start_y][game->start_x] == 'C')
		game->collectible--;
	if (game->grid[game->start_y][game->start_x] != 'E')
		game->grid[game->start_y][game->start_x] = 'P';
	put_image_window(game, game->img.player_s, game->start_x, game->start_y);
}

// Check si il n'y a pas de mur/enemy/collectible 
//en haut quand la touche 'w' est presse
void	ft_move_up(int keycode, t_data *game)
{
	if (keycode != XK_w)
		return ;
	if (game->grid[game->start_y - 1][game->start_x] != '1'
		&& game->grid[game->start_y - 1][game->start_x] != 'M')
		game->steps++;
	case_event(game, game->start_y - 1, game->start_x);
	if (game->grid[game->start_y - 1][game->start_x] == 'M')
		return ;
	if (game->grid[game->start_y - 1][game->start_x] == '1')
	{
		ft_printf(ROUGE "You can't climb in trees\n" RESETCOLOR);
		return ;
	}
	if (game->grid[game->start_y][game->start_x] != 'E')
		game->grid[game->start_y][game->start_x] = '0';
	put_img("floor", game);
	game->start_y--;
	if (game->grid[game->start_y][game->start_x] == 'C')
		game->collectible--;
	if (game->grid[game->start_y][game->start_x] != 'E')
		game->grid[game->start_y][game->start_x] = 'P';
	put_image_window(game, game->img.player_w, game->start_x, game->start_y);
}

// Petite dance du chef (diminue la valeur du i pour une dance plsu rapide)
void	make_dance(t_data *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = game->start_x;
	y = game->start_y;
	while (i++ < 40000)
		put_image_window(game, game->img.dance_f2, x, y);
	while (i--)
		put_image_window(game, game->img.dance_f3, x, y);
	while (i++ < 40000)
		put_image_window(game, game->img.dance_f1, x, y);
	while (i--)
		put_image_window(game, game->img.dance_b2, x, y);
	while (i++ < 40000)
		put_image_window(game, game->img.dance_b1, x, y);
	while (i--)
		put_image_window(game, game->img.dance_b3, x, y);
	while (i++ < 40000)
		put_image_window(game, game->img.dance_f2, x, y);
	while (i--)
		put_image_window(game, game->img.dance_f3, x, y);
	while (i++ < 40000)
		put_image_window(game, game->img.dance_f1, x, y);
}
