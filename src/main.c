/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main
*/

#include "hunter.h"

int main()
{
	sfVideoMode mode = { 997, 800, 32 };
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "Hunter", sfClose, NULL);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		if (display(window) == 0)
			break;
	}
	return 0;
}
