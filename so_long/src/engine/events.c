/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:28:19 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/28 12:28:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

int	on_keypress(int keysym, t_game *game)
{
	printf("pressed: %d\n", keysym);
	if (keysym == XK_a || keysym == XK_Left)
		move_player(game, LEFT);
	else if (keysym == XK_s || keysym == XK_Down)
		move_player(game, DOWN);
	else if (keysym == XK_d || keysym == XK_Right)
		move_player(game, RIGHT);
	else if (keysym == XK_w || keysym == XK_Up)
		move_player(game, UP);
//	if (keysym == XK_Escape)
//		quit_game(game);
	return (1);
}

