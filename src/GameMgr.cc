/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameMgr.cpp
 * Author: ur5f
 * 
 * Created on June 15, 2016, 10:24 AM
 */
#include <iostream>
#include "GameMgr.h"
#include "Point.h"

#include <allegro5/allegro.h>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <allegro5/mouse.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>



#define REFRESH_RATE 59

using namespace std;

GameMgr::GameMgr() {

}

GameMgr::~GameMgr() {
}

bool GameMgr::load() {
    // iniciar gerador de números randômicos
    std::srand(std::time(0));

    // Inicializando a biblioteca
    if (!al_init()) {
        cerr << "failed to initialize allegro!" << endl;
        return -1;
    }

    // Criando a nossa janela
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    al_set_new_display_flags(ALLEGRO_OPENGL);

    display = al_create_display(320, 200);
    if (!display) {
        cerr << "falha ao criar a tela!" << endl;
        return -1;
    }

    screen_width = al_get_display_width(display);
    screen_height = al_get_display_height(display);


    // inicializando uso do teclado
    if (!al_install_keyboard()) {
        cerr << "Falha ao inicializar o teclado." << endl;
        return false;
    }

    // inicializando uso do mouse
    if (!al_install_mouse()) {
        cerr << "Falha ao inicializar o mouse." << endl;
        return false;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos) {
        cerr << "Falha ao criar fila de eventos." << endl;
        al_destroy_display(display);
        return false;
    }

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(display));


    draw_timer = al_create_timer(1.0 / REFRESH_RATE);
    al_start_timer(draw_timer);
    al_register_event_source(fila_eventos, al_get_timer_event_source(draw_timer));

    logic_timer = al_create_timer(1.0 / 59);
    al_start_timer(logic_timer);
    al_register_event_source(fila_eventos, al_get_timer_event_source(logic_timer));

    al_init_primitives_addon(); // inicializando o trabalho com primitivas gr�ficas
    al_init_image_addon();

    // Inicia o add-on para uso de fontes
    al_init_font_addon();
    // Inicia o add-on para uso de fontes True Type
    al_init_ttf_addon();

    // Carregando o arquivo de fonte, o arquivo de fonte deve estar na pasta do projeto
    // loading......
    load_resources();

    return true;
}

int GameMgr::load_resources() {
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_remove_path_component(path, -1);
    al_remove_path_component(path, -1);
    al_remove_path_component(path, -1);
    al_append_path_component(path, "res");
    al_set_path_filename(path, "tahoma.ttf");    
    fonte = al_load_font(al_path_cstr(path, '/'), 14, 0);


    al_destroy_path(path);

    return 0;
}

void GameMgr::update() {
    
}

void GameMgr::processInput() {
    ALLEGRO_EVENT evento;
    while (!al_is_event_queue_empty(fila_eventos)) {
        //al_clear_to_color(al_map_rgb(0, 0, 0)); // Colorindo a janela de preto
        al_wait_for_event(fila_eventos, &evento);

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) { // uma tecla foi pressionada            
            switch (evento.keyboard.keycode) {
                case ALLEGRO_KEY_UP:

                    break;
                case ALLEGRO_KEY_DOWN:

                    break;
                case ALLEGRO_KEY_LEFT:

                    break;
                case ALLEGRO_KEY_RIGHT:

                    break;
                case ALLEGRO_KEY_ENTER:
                    if (evento.keyboard.modifiers | ALLEGRO_KEYMOD_ALT) {
                        auto mode = al_get_display_flags(display);
                        if (mode | ALLEGRO_WINDOWED) {
                            al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);
                        } else {
                            al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, false);
                        }
                    }
                    break;
                case ALLEGRO_KEY_Q:
                case ALLEGRO_KEY_ESCAPE:
                    al_destroy_display(display); // Finaliza a janela
                    exit(0);

            }
        } else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) { // click no mouse
            // botão de saida
            if (evento.mouse.x > 0 && evento.mouse.x < 20 &&
                    evento.mouse.y > 0 && evento.mouse.y < 20) // cordenadas do botao
                exit(0);       
        }
        else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
            if(evento.mouse.dz >0)
                camera_scale*=(++mouse_scroll);
            else if(evento.mouse.dz < 0) 
                camera_scale*=(--mouse_scroll);

            al_identity_transform(&camera);
            al_scale_transform(&camera, camera_scale, camera_scale);
            al_use_transform(&camera);
                    
                
            
        } else if (evento.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
            al_acknowledge_resize(display);
            screen_width = al_get_display_width(display);
            screen_height = al_get_display_height(display);
            _redraw = true;
        } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // click no mouse
            al_destroy_display(display); // Finaliza a janela
            exit(0);
        } else if (evento.type == ALLEGRO_EVENT_TIMER) {
            if (evento.timer.source == draw_timer) {                
                _redraw = true;
            } else if (evento.timer.source == logic_timer)
                _tick = true;
        }
    }
}

void GameMgr::redraw() {
    if (_redraw) {
        double t = al_get_time();
        _redraw = false;
        al_clear_to_color(al_map_rgb(0, 0, 0));

        if (fonte) {
            al_draw_filled_rounded_rectangle(4, 4, 100, 30, 8, 8, al_map_rgba(0, 0, 0, 20));
            al_draw_textf(fonte, al_map_rgb(255, 255, 255), 54, 8, ALLEGRO_ALIGN_CENTRE, "FPS: %d, zmouse: %d", fps, mouse_scroll);
        }        
        //-----------------------------------------------------------------------
        
        
        al_draw_filled_rectangle(100,100,200,200,al_map_rgba(0,255, 0, 255));
               
        float p[] = {100, 10, 20, 30, 90, 100, 100, 100};
        al_draw_spline(p,al_map_rgba(255, 0, 0, 255),0);
        
        Point p1 = Point(100,10);
        Point p2 = Point(20, 30);
        Point p3 = Point(90, 100);
        Point p4 = Point(100, 100);
        
        p1.draw(true);
        p2.draw(true);
        p3.draw(true);
        p4.draw(true);
        
        //-----------------------------------------------------------------------       
        fps_accum++;
        if (t - fps_time > 1){
            fps = fps_accum;
            fps_accum = 0;
            fps_time = t;
        }
        al_flip_display(); // Atualiza a tela        
    }
}


void GameMgr::cameraUpdate(float *cameraPosition, float x, float y, int width, int height){
    cameraPosition[0] = -(screen_width/2) + (x + width/2);
    cameraPosition[1] = -(screen_height/2) + (y + height/2);
    
    if(cameraPosition[0] <0)
        cameraPosition[0] = 0;
    if(cameraPosition[1] <0)
        cameraPosition[1] = 0;
}


int GameMgr::run() {
    load();
    while (true) {
        update();
        processInput();
        redraw();
    }
    return 0;
}
