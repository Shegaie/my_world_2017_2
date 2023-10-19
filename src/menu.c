/*
** EPITECH PROJECT, 2018
** hunter
** File description:
** menu functions
*/

#include "hunter.h"

int menu_event(sfSprite * sprite, sfTexture * texture,
	       sfMusic * music, sfRenderWindow * window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtKeyReleased) {
			sfSprite_destroy(sprite);
			sfTexture_destroy(texture);
			sfMusic_destroy(music);
			return (0);
		}
		if (event.type == sfEvtClosed) {
			return (1);
		}
	}
	return (2);
}

int display_menu(sfRenderWindow * window)
{
	sfTexture *texture;
	sfSprite *sprite;
	sfMusic *music;
	int status = 0;

	music = sfMusic_createFromFile("assets/Menu.ogg");
	texture = sfTexture_createFromFile("assets/Menu.png", NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfRenderWindow_display(window);
	sfMusic_play(music);
	while (sfRenderWindow_isOpen(window)) {
		status = menu_event(sprite, texture, music, window);
		if (status == 0)
			return (0);
		else if (status == 1)
			return (1);
	}
	return (0);
}

int loop_menu(sfRenderWindow * window)
{
	while (sfRenderWindow_isOpen(window)) {
		if (display_menu(window) == 0)
			break;
		else
			return (0);
	}
}
