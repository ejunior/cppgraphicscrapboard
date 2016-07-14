/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.cc
 * Author: ur5f
 * 
 * Created on July 14, 2016, 1:09 PM
 */

#include "Point.h"

#include "allegro5/color.h"
#include "allegro5/allegro_primitives.h"

Point::Point() {
    //branco
    cor = al_map_rgb(255,255,255);
}

Point::Point(const Point& orig) {
}

Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
    this->cor = al_map_rgb(255,255,255);
}

Point::Point(float x, float y, ALLEGRO_COLOR c){
    this->x = x;
    this->y = y;
    this->cor =c;
        
}


Point::~Point() {
}

void Point::draw(bool debug = false){
    al_draw_pixel(x,y,cor);
    if(debug)
        al_draw_circle(x,y,3,al_map_rgb(127,0,0),1);
    
}

