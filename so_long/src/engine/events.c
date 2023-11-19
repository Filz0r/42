/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:08:37 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/19 22:37:18 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	on_keypress(int keysym, t_data *game)
{
	printf("pressed: %d\n", keysym);
	if (keysym == XK_a || keysym == XK_Left)
	{
		move_player(game, LEFT);
		printf("this is left\n");
	}
	else if (keysym == XK_s || keysym == XK_Down)
	{
		move_player(game, DOWN);
		printf("this is down\n");
	}
	else if (keysym == XK_d || keysym == XK_Right)
	{
		move_player(game, RIGHT);
		printf("this is right\n");
	}
	else if (keysym == XK_w || keysym == XK_Up)
	{
		move_player(game, UP);
		ft_printf("up was pressed\n");
	}
	game->steps++;
	ft_printf("Player has moved %d times.\n", game->steps);
	if (keysym == XK_Escape)
		quit_game(game);
	return (0);
}

void	move_player(t_data *game, int action)
{
	//moving up
	if (action == UP)
		handle_movement(game, game->map->player->x, game->map->player->y - 1, UP);
	else if (action == DOWN)
		handle_movement(game, game->map->player->x, game->map->player->y + 1, DOWN);
	/*else if (action == LEFT)
		handle_movement_left(game->map, game->map->player->x, game->map->player->y);
	else if (action == RIGHT)
		handle_movement_right(game->map, game->map->player->x, game->map->player->y);*/
}

void	handle_movement(t_data *g, int x, int y, int action)
{
	if (g->map->map[y][x] == '0')
	{
		g->map->map[y][x] = 'P';
		g->map->map[y][x] = '0';
	}
	else if (g->map->map[y][x] == '1')
		return ;
	else if (g->map->map[y][x] == 'C')
		remove_collectible(g, x, y);
	if (action == UP)
		g->map->player->y--;
	else if (action == DOWN)
		g->map->player->y++;
	else if (action == LEFT)
		g->map->player->x--;
	else if (action == RIGHT)
		g->map->player->x++;
}

void	remove_collectible(t_data *g, int x, int y)
{
	t_list	*curr;
	t_list	*prev;
	t_point	*temp;

	curr = g->collectibles;
	while (curr)
	{
		temp = (t_point *)curr->content;
		if (temp->x == x && temp->y == y)
		{
			if (prev)
				prev->next = curr->next;
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

int	quit_game(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game);
	exit(1);
}
