#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "headers/config.h"
#include "headers/common/device_display.h"
#include "headers/common/scale.h"
#include "headers/game_controller.h"

struct DeviceDisplay getWindowSize() {
    ALLEGRO_MONITOR_INFO monitor_info;

    al_get_monitor_info(0, &monitor_info);

    struct DeviceDisplay device_display;

    device_display.width = monitor_info.x2 - monitor_info.x1;
    device_display.height = monitor_info.y2 - monitor_info.y1;

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

    return device_display;
}

int main()
{
    if(!al_init())
    {
        printf("couldn't initialize allegro\n");
        return 1;
    }

    if(!al_install_keyboard())
    {
        printf("couldn't initialize keyboard\n");
        return 1;
    }

    if(!al_init_image_addon()) {
        printf("couldn't initialize image\n");
        return 1;
    }

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / NUMBER_OF_FRAMES);
    if(!timer)
    {
        printf("couldn't initialize timer\n");
        return 1;
    }

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    if(!queue)
    {
        printf("couldn't initialize queue\n");
        return 1;
    }

    struct DeviceDisplay device_display = getWindowSize();
    ALLEGRO_DISPLAY* disp = al_create_display(device_display.width, device_display.height);

    if(!disp)
    {
        printf("couldn't initialize display\n");
        return 1;
    }

    ALLEGRO_FONT* font = al_create_builtin_font();
    if(!font)
    {
        printf("couldn't initialize font\n");
        return 1;
    }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    struct Scale display_scale;
    display_scale.x = device_display.width / WINDOW_WIDTH;
    display_scale.y = device_display.width / WINDOW_HEIGHT;

    init_game(display_scale);

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                update_game(event.timer.count);
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                on_key_press(event.keyboard.keycode);
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(255, 0, 0));
            draw_game();
            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}