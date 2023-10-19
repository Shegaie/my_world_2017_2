/*
** EPITECH PROJECT, 2017
** gameloop.c
** File description:
** gameloop
*/

#include "hunter.h"

int game_update(sfGame * game, obj_t *man, obj_t *doggo, obj_t *dead_doggo)
{
	game->xsave = doggo->pos.x;
	game->ysave = doggo->pos.y;
	(game->doggo_rect.left >= 240 ? game->doggo_rect.left = -80 : 1);
	if (doggo->pos.x > 900) {
		doggo->pos.x = -45;
		return (1);
	}
	sfRenderWindow_clear(game->window, sfBlack);
	game->doggo_rect.left += 80;
	doggo->pos.x += 10 * game->speed;
	if (event_handle(game, man,doggo) == 1)
		return (1);
	if (game->cpt == 11) {
		game_destroy(game, man, doggo);
		return (1);
	}
	status(game, man, doggo, dead_doggo);
	return 0;
}

void game_draw(sfGame *game, obj_t *man, obj_t *doggo, obj_t *dead_doggo)
{
	sfSprite_setPosition(man->sprite, man->pos);
	sfSprite_setTextureRect(man->sprite, game->man_rect);
	sfSprite_setPosition(doggo->sprite, doggo->pos);
	sfSprite_setTextureRect(doggo->sprite, game->doggo_rect);
	display_background(game->window);
	sfRenderWindow_drawSprite(game->window, man->sprite, NULL);
	if (game->shoot == 0)
		sfRenderWindow_drawSprite(game->window, doggo->sprite, NULL);
	if (game->shoot == 1) {
		sfRenderWindow_drawSprite(game->window,
				dead_doggo->sprite, NULL);
		game->shoot = 0;
	}
	sfRenderWindow_display(game->window);
}

void game_destroy(sfGame * game, obj_t *man, obj_t *doggo)
{
	sfSprite_destroy(doggo->sprite);
	sfTexture_destroy(doggo->texture);
	sfMusic_destroy(game->music);
	sfRenderWindow_close(game->window);
	sfRenderWindow_destroy(game->window);
}
