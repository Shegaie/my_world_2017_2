/*
** EPITECH PROJECT, 2018
** hunter
** File description:
** status modif in game
*/

#include "hunter.h"

void shoot_handle(sfGame * game, sfEvent event, obj_t * doggo, int rande)
{
	if (event.mouseButton.button == sfMouseLeft) {
		if (event.mouseButton.x > doggo->pos.x - 25
		    && event.mouseButton.x < doggo->pos.x + 80
		    && event.mouseButton.y > doggo->pos.y - 5
		    && event.mouseButton.y < doggo->pos.y + 60) {
			doggo->pos.x = -10;
			if (rande == 0)
				doggo->pos.y = 250;
			else if (rande == 1)
				doggo->pos.y = 500;
			else
				doggo->pos.y = 650;
			game->speed *= 1.17;
			game->cpt++;
			game->doggo_rect.left = 320;
			game->shoot = 1;
		}
		game->load = 1;
	}
}

int event_handle(sfGame * game, obj_t * man, obj_t * doggo)
{
	int rande = rand() % 3;
	sfEvent event;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			game_destroy(game, man, doggo);
			return (1);
		}
		if (event.type == sfEvtMouseButtonPressed) {
			man->pos.y = event.mouseButton.y - 30;
			shoot_handle(game, event, doggo, rande);
		}
	}
	return (0);
}

int status(sfGame * game, obj_t * man, obj_t * doggo, obj_t * dead_doggo)
{
	if (game->load == 1) {
		if (game->man_rect.left >= 305) {
			game->man_rect.left = -95;
			game->load = 0;
		}
		game->man_rect.left += 100;
	}
	if (game->shoot == 1) {
		dead_doggo->pos.x = game->xsave;
		dead_doggo->pos.y = game->ysave;
		sfSprite_setPosition(dead_doggo->sprite, dead_doggo->pos);
	}
	return (0);
}
