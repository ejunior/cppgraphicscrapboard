/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameMgr.hpp
 * Author: ur5f
 *
 * Created on June 15, 2016, 10:24 AM
 */

#ifndef GAMEMGR_H
#define GAMEMGR_H


#include <list>

// random
#include <cstdlib>
#include <ctime>

#include <allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_ttf.h>

class GameMgr {
protected:      
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    
    bool _redraw = true;
    bool _tick = true;
    
    ALLEGRO_FONT *fonte = NULL;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_TRANSFORM camera;
    
    int screen_width = 320;     
    int screen_height = 200;
    
    ALLEGRO_TIMER *draw_timer;
    ALLEGRO_TIMER *logic_timer;   

    //fps counter
    int fps=0, fps_accum=0;
    double fps_time=0;
    
    int mouse_scroll=0;
    float camera_position[2]{0,0};
    float camera_scale = 1;
    
public:
    GameMgr();   
    virtual ~GameMgr();
    int run();    
    
private:
    bool load();
    void update();
    void processInput();
    void redraw();
    
    load_resources();
    
    void cameraUpdate(float *cameraPosition, float x, float y, int width, int height);
};

#endif /* GAMEMGR_H */

