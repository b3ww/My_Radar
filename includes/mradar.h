/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** mradar
*/

#ifndef MRADAR_H_
    #define MRADAR_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Config.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>
    #include <SFML/Window/Keyboard.h>

    typedef struct plane {
        sfSprite *sprite;
        sfRectangleShape *hitbox;
        int begin[2];
        int arrivate[2];
        int speed;
        float orientation;
        float x_move;
        float y_move;
        int wait;
        float time_move;
        sfBool alive;
    } plane_t;

    typedef struct tower {
        sfSprite *sprite;
        sfCircleShape *hitbox;
        int place[2];
        int radius;
    } tower_t;

    typedef struct area {
        sfIntRect measure;
        sfRectangleShape *view;
        plane_t **planes;
        int nb_planes;
        sfBool split;
        sfBool alloc;
        struct area *next_area[4];
    } area_t;

    typedef struct menu {
        sfSprite *bg;
    } menu_t;

    typedef struct elements {
        struct tower **towers;
        struct plane **planes;
        int nb_towers;
        int nb_planes;
        sfSprite *background;
        sfClock *clock;
        area_t *area;
        float time;
        float add_time;
        sfBool view_tree;
        sfBool view_sprite;
        sfBool view_hitbox;
        sfText *timer;
        menu_t *menu;
    } elements_t;

    /* script parsing */
    int valid_script(char *path);
    elements_t *get_elements(char *path);
    char **get_script_content(char *path);
    char **split_in_lines(char *str);
    void get_elements_in_script(elements_t *elements, char **script);
    plane_t *get_plane_informations(char *line);
    tower_t *get_tower_informations(char *line);
    /*---*/

    /* init */
    void init_elements(elements_t *elements);
    void set_plane_orientation(elements_t *elements);
    menu_t *init_menu(void);
    /*---*/

    /* utils */
    int mgetnbr(char const *str);
    char **mstr_to_word_array(char *str);
    float get_angle(plane_t *plane);
    int alive(elements_t *elements, plane_t *plane);
    void mpstr(char const *str);
    const char *float_to_str(float value);
    /*---*/

    /* main */
    int mainloop(elements_t *elements, sfBool game);
    void draw_elements(sfRenderWindow *window, elements_t *elements);
    void update_elements(elements_t *elements);
    void update_planes(elements_t *elements);
    void get_colisions(elements_t *elements, area_t *area);
    int in_tower(elements_t *elements, plane_t *plane);
    sfBool play_game(sfRenderWindow *window, elements_t *elements,
    sfKeyCode key);
    sfBool play_menu(sfRenderWindow *window, menu_t *menu, sfKeyCode key);
    /*---*/

    /* quad tree */
    area_t *init_area(elements_t *elements);
    void update_quad_tree(elements_t *elements);
    void split_area(area_t *area);
    int get_plane_in_area(elements_t *elements, area_t *area);
    /*---*/

    /* reload */
    void reload_game(elements_t *elements);
    /*---*/

    /* destroy */
    void destroy_elements(elements_t *elements);
    /*---*/

    /* Merci à la demoiselle pour les assets : Menu et Simulation Background */
#endif /* !MRADAR_H_ */
