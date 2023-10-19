/*
** EPITECH PROJECT, 2017
** hunter
** File description:
** hunter.h
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>

typedef struct {
	sfEvent *event;
	sfRenderWindow *window;
	float speed;
	sfClock *clock;
	sfTime time;
	float seconds;
	int cpt;
	int load;
	int shoot;
	sfIntRect man_rect;
	sfIntRect doggo_rect;
	sfMusic *music;
	float xsave;
	float ysave;
} sfGame;

typedef struct {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
} obj_t;

void display_background(sfRenderWindow * window);
int display(sfRenderWindow * window);
int game_event(sfGame game, sfEvent event);
int game_update(sfGame * game, obj_t *man, obj_t *doggo, obj_t *dead_doggo);
void game_draw(sfGame * game, obj_t *man, obj_t *doggo, obj_t *dead_doggo);
void game_destroy(sfGame * game, obj_t *man,obj_t *doggo);
int analyse_events(sfGame game, sfEvent event);
void manage_mouse_click(sfGame * game, sfMouseButtonEvent event);
