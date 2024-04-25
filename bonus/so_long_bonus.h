/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:28:43 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/11 10:36:17 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../so_long.h"

// parsing
int		ft_check_is_close(t_data *game);
int		check_npc_pos(t_data *game);
void	flood_fill_npc(t_data *game, int x, int y);
int		ft_error_message(t_data *game);
void	ft_parse_error(t_data *game);
void	ft_parse_map(t_data *game, char *filename);
void	ft_init_struct(t_data *game);
void	ft_reload_map(t_data *game);
void	ft_flood_fill(t_data *game, int x, int y);
// init game
void	init_assets_player(t_map *mlx, t_data *game);
void	init_dance_player(t_map *mlx, t_data *game);
void	init_assets_npc(t_map *mlx, t_data *game);
void	init_nb_npc(t_data *game);
// player fonction
void	make_dance(t_data *game);
void	ft_move_up(int keycode, t_data *game);
void	ft_move_down(int keycode, t_data *game);
void	ft_move_right(int keycode, t_data *game);
void	ft_move_left(int keycode, t_data *game);
// npc fonction
bool	check_in_front_npc(t_data *game, t_npc *npc, int i);
int		random_move(t_data *game);
void	put_enemy(t_data *game);
void	npc_move_up(t_data *game, t_npc *npc, int i);
void	npc_move_down(t_data *game, t_npc *npc, int i);
void	npc_move_right(t_data *game, t_npc *npc, int i);
void	npc_move_left(t_data *game, t_npc *npc, int i);
void	check_nb_enemy(t_data *game);
// utils
void	put_image_window(t_data *game, void *images, int x, int y);
void	put_black_case(t_data *game);
char	*print_steps(t_data *game);
void	free_npc(t_data *game);
void	free_assets_player(t_data *game);
void	free_assets_npc(t_data *game);
void	case_event(t_data *game, int y, int x);
int		ft_user_keypress(int keycode, t_data *game);
void	ft_error_xpm(t_data *game);
int		ft_close_game(t_data *game);
#endif