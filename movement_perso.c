/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_perso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:10:53 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:23:48 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"
#include "so_long.h"

//Permet de recuperer les touches pressee par l'user 
//et execute les commandes associees
int	user_keypress(int keycode, t_data *game)
{
	if (keycode == XK_a || keycode == XK_s || keycode == XK_d
		|| keycode == XK_w)
	{
		move_down(keycode, game);
		move_left(keycode, game);
		move_right(keycode, game);
		move_up(keycode, game);
		ft_printf(CYAN "Number of steps : %d\n" RESETCOLOR, game->steps);
	}
	if (keycode == XK_Escape)
	{
		close_game(game);
	}
	if (game->collectible == 0)
		put_img("exit", game);
	if (game->grid[game->start_y][game->start_x] == 'E'
		&& game->collectible == 0)
		close_game(game);
	return (0);
}

//Verifie si les deplacements sont possibles 
//Si la touche 'a' est pressee
void	move_left(int keycode, t_data *game)
{
	if (keycode == XK_a && game->grid[game->start_y][game->start_x - 1] == '1')
		ft_printf(ROUGE "You can't climb in trees\n" RESETCOLOR);
	else if (keycode == XK_a && game->grid[game->start_y][game->start_x
		- 1] == 'C')
	{
		put_img("floor", game);
		game->steps++;
		game->start_x--;
		game->collectible--;
		game->grid[game->start_y][game->start_x] = '0';
		put_img("playerA", game);
	}
	else if (keycode == XK_a)
	{
		put_img("floor", game);
		game->steps++;
		game->start_x--;
		put_img("playerA", game);
	}
}

//Verifie si les deplacements sont possibles 
//Si la touche 'd' est pressee
void	move_right(int keycode, t_data *game)
{
	if (keycode == XK_d && game->grid[game->start_y][game->start_x + 1] == '1')
		ft_printf(ROUGE "You can't climb in trees\n" RESETCOLOR);
	else if (keycode == XK_d && game->grid[game->start_y][game->start_x
		+ 1] == 'C')
	{
		put_img("floor", game);
		game->steps++;
		game->start_x++;
		game->collectible--;
		game->grid[game->start_y][game->start_x] = '0';
		put_img("playerD", game);
	}
	else if (keycode == XK_d)
	{
		put_img("floor", game);
		game->steps++;
		game->start_x++;
		put_img("playerD", game);
	}
}

//Verifie si les deplacements sont possibles 
//Si la touche 's' est pressee
void	move_down(int keycode, t_data *game)
{
	if (keycode == XK_s && game->grid[game->start_y + 1][game->start_x] == '1')
		ft_printf(ROUGE "You can't climb in trees\n" RESETCOLOR);
	else if (keycode == XK_s && game->grid[game->start_y
			+ 1][game->start_x] == 'C')
	{
		put_img("floor", game);
		game->steps++;
		game->start_y++;
		game->collectible--;
		game->grid[game->start_y][game->start_x] = '0';
		put_img("playerS", game);
	}
	else if (keycode == XK_s)
	{
		put_img("floor", game);
		game->steps++;
		game->start_y++;
		put_img("playerS", game);
	}
}

//Verifie si les deplacements sont possibles 
//Si la touche 'w' est pressee
void	move_up(int keycode, t_data *game)
{
	if (keycode == XK_w && game->grid[game->start_y - 1][game->start_x] == '1')
		ft_printf(ROUGE "You can't climb in trees\n" RESETCOLOR);
	else if (keycode == XK_w && game->grid[game->start_y
			- 1][game->start_x] == 'C')
	{
		put_img("floor", game);
		game->steps++;
		game->start_y--;
		game->collectible--;
		game->grid[game->start_y][game->start_x] = '0';
		put_img("playerW", game);
	}
	else if (keycode == XK_w)
	{
		put_img("floor", game);
		game->steps++;
		game->start_y--;
		put_img("playerW", game);
	}
}
