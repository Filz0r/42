/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:16:41 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/16 16:34:16 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

/**
 * @brief this function tries to move the player in the direction received by
 * action, it is executed every time you release a key from the keyboard.
 * And the game is hard coded to always try to move 8 pixels in the direction
 * it gets as input.
 * @param game you know, t_game brev
 * @param action int that determines the direction the player is trying
 * to move to
 * @return Always returns 1.
 *
 * NOTE: the only reason this function returns an int is to rate limit
 * the key release events.
 */
int	move_player(t_game *game, int action)
{
	if (action == UP)
		return (check_collision(game, game->map->player->x,
				game->map->player->y - 8, action));
	else if (action == DOWN)
		return (check_collision(game, game->map->player->x,
				game->map->player->y + 8, action));
	else if (action == LEFT)
		return (check_collision(game, game->map->player->x - 8,
				game->map->player->y, action));
	else
		return (check_collision(game, game->map->player->x + 8,
				game->map->player->y, action));
}

/**
 * @brief This function is responsible for converting the positions saved
 * in memory from a scale of 1:SIZE back to a proportion of 1:1, in this
 * implementation it is hard-coded with the thresholds that don't the allow the
 * player to walk over walls, but at the same time the player is still able
 * to overlap some walls, this is because this movement system should only
 * be used with games that have an isometric viewport.
 * @param game t_game brev
 * @param x x position we want to move to
 * @param y y position we want to move to
 * @param action direction we are trying to move to
 * @return always returns 1
 *
 * NOTE: looking at this function it might not always make sense, the reason is
 * well fuck the Norm am I right? basically look at this function and at
 * handle collision as one unique function that shouldn't be broken down but
 * ended up having to be broken down because norminette.
 */
int	check_collision(t_game *g, int x, int y, int action)
{
	t_point	check;
	t_point	norm_check;

	g->current = PLAYER_WALKING;
	check = (t_point){x, y,
		((double)x / SIZE), ((double)y / SIZE)};
	if (action == DOWN)
		norm_check = normalize_point(check, 0.375, 0.10);
	else if (action == LEFT)
		norm_check = normalize_point(check, 0.3515, 0.45);
	else if (action == RIGHT)
		norm_check = normalize_point(check, 0.725, 0.45);
	else
		norm_check = normalize_point(check, 0.375, 0.55);
	if (action == RIGHT)
		g->mirror = 0;
	else if (action == LEFT)
		g->mirror = 1;
	handle_restof_movement(g, norm_check, x, y);
	return (1);
}

/**
  * @brief This function is the conclusion of check_collision, it basically
  * grabs the converted value calculated beforehand and tries to check if it
  * will result in a collision or not and tries to act accordingly,
  * this function grabs the normalized point the player wants to move into
  * and checks if it collides with the normalized point of a wall, collectible
  * enemy or exit but instead of moving the player position we interpolate
  * the values of x and y, that we want to move into, by a 0.35 multiplier,
  * this means that the player will move approximately 12 pixels after each
  * move, instead of the 8 pixels that we use to check if the collision is
  * going to happen or not, this decision was purely made to make the movement
  * as smooth as possible without having the player jump across tiles.
  * @param game t_game struct
  * @param norm_point a t_point struct containing an 1:1 scale position its
  * only used to detect if this position is going to coincide with an object
  * that requires collision, if it does the game acts accordingly.
  * @param x the x position of where we want to move the player into
  * @param y the y position of where we want to move the player into
  *
  * NOTE: The implementation of the collision system might not make a lot of
  * sense from the outside, mostly because I calculate some points that
  * are only used to check if the player is moving into a collidable object
  * but in the end the program uses a different position to actually move the
  * player this was made to improve smoothness of the animations, if we tried
  * to interpolate an already normalized point, the player would jump positions
  * instead of walking, and if we were to limit the player to only walk
  * x amount of pixels it would result in the walking mechanism to be
  * extremely slow and this adaptation was made to make the entire process
  * smoother.
*/
void	handle_restof_movement(t_game *g, t_point norm_point, int x, int y)
{
	t_point	interpolated;

	interpolated = interpolate_point(*(g->map->player),
			(t_point){x, y, x, y}, 0.35);
	if (g->map->map[norm_point.y][norm_point.x] == '1')
		return ;
	else if (g->map->map[norm_point.y][norm_point.x] == 'C')
		remove_collectible(g, norm_point);
	else if (g->map->map[norm_point.y][norm_point.x] == 'E'
		&& g->map->collectibles == NULL)
	{
		ft_printf("Congratulations you won!\n");
		quit_game(g, EXIT_SUCCESS);
	}
	else
		handle_fire_collision(g, norm_point);
	g->moves++;
	if (PRINT_MOVES == 1)
		ft_printf("The player has made %d moves\n", g->moves);
	*(g->map->player) = interpolated;
	render_frame(g, g->current);
}

/**
 * @brief Detects if the normalized point the player is walking into is a
 * fire object or not, if the player is walking into a fire object, the
 * game should print the final 3 frames coinciding with the player death
 * animation, whoever things go so fast that the game quits before this happens.
 * @param game t_game structure
 * @param norm_point t_point variable containing the normalized position we
 * are trying to walk into.
 */
void	handle_fire_collision(t_game *g, t_point norm_point)
{
	t_list	*temp;
	t_point	pt;

	if (KILL_PLAYER != 1)
		return ;
	temp = g->flooded_tiles;
	while (temp)
	{
		pt = *((t_point *)temp->content);
		if (norm_point.x == pt.x / SIZE && norm_point.y == pt.y / SIZE)
		{
			render_frame(g, PLAYER_DYING);
			render_frame(g, PLAYER_DYING);
			render_frame(g, PLAYER_DYING);
			ft_printf("Either fire spawned on top of you or you ran into it\n");
			ft_printf("Better luck next time!\n");
			quit_game(g, EXIT_SUCCESS);
		}
		temp = temp->next;
	}
}
