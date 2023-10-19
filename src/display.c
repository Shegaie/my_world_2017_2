/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** display
*/

#include "hunter.h"

void display_background(sfRenderWindow * window)
{
	obj_t background;

	background.texture =
		sfTexture_createFromFile("assets/background2.png", NULL);
	background.sprite = sfSprite_create();
	sfSprite_setTexture(background.sprite, background.texture, sfTrue);
	sfRenderWindow_drawSprite(window, background.sprite, NULL);
	sfSprite_destroy(background.sprite);
	sfTexture_destroy(background.texture);
}

int init_obj(obj_t *man, obj_t *doggo, obj_t *dead_doggo)
{
	sfVector2f doggo_pos = { 0, 670 };
	sfVector2f man_pos = { 880 , doggo_pos.y };

	doggo->texture = sfTexture_createFromFile("assets/newsheet3.png", NULL);
	doggo->sprite = sfSprite_create();
	doggo->pos = doggo_pos;
	sfSprite_setTexture(doggo->sprite, doggo->texture, sfTrue);
	man->texture = sfTexture_createFromFile("assets/shotgun1.png", NULL);
	man->sprite = sfSprite_create();
	sfSprite_setTexture(man->sprite, man->texture, sfTrue);
	man->pos = man_pos;
	dead_doggo->texture = sfTexture_createFromFile("assets/dead.png", NULL);
	dead_doggo->sprite = sfSprite_create();
	sfSprite_setTexture(dead_doggo->sprite, dead_doggo->texture, sfTrue);
	return (0);
}

int init_game(sfGame *game, obj_t *man, obj_t *doggo, sfRenderWindow * window)
{
	sfVector2f scale = { 0.7, 0.7 };
	sfVector2f scale2 = { 1.3, 1.1 };

	game->music = sfMusic_createFromFile("assets/Theme.ogg");
	game->man_rect.left = 0;
	game->man_rect.top = 5;
	game->man_rect.width = 100;
	game->man_rect.height = 150;
	game->doggo_rect.left = 0;
	game->doggo_rect.top = 0;
	game->doggo_rect.width = 80;
	game->doggo_rect.height = 55;
	game->window = window;
	game->speed = 1;
	game->cpt = 0;
	game->shoot = 0;
	game->load = 0;
	sfSprite_setScale(man->sprite, scale);
	sfSprite_setScale(doggo->sprite, scale2);
	return (0);
}

int loop(obj_t *man, obj_t *doggo, obj_t *dead_doggo, sfGame *game)
{
	game->time = sfClock_getElapsedTime(game->clock);
	game->seconds = game->time.microseconds / 1000000.0;
	if (game->seconds > 0.1) {
		if (game_update(game, man, doggo, dead_doggo) == 1)
			return (0);
		game_draw(game, man, doggo, dead_doggo);
		sfClock_restart(game->clock);
	}
	return (1);
}

int display(sfRenderWindow * window)
{
	obj_t man;
	obj_t doggo;
	obj_t dead_doggo;
	sfGame game;

	game.clock = sfClock_create();
	init_obj(&man, &doggo, &dead_doggo);
	init_game(&game, &man, &doggo, window);
	loop_menu(window);
	sfMusic_play(game.music);
	while (sfRenderWindow_isOpen(window)) {
		if (loop(&man, &doggo, &dead_doggo, &game) == 0)
			return (0);
	}
	return (0);
}
