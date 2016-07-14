/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.h
 * Author: ur5f
 *
 * Created on July 14, 2016, 1:09 PM
 */

#ifndef POINT_H
#define POINT_H
#include <allegro5/color.h>

class Point{
public:
    Point();
    Point(const Point& orig);
    Point(float x, float y);
    Point(float x, float y, ALLEGRO_COLOR c);
          
    ~Point();
    void draw(bool debug);
    
private:
    float x=0;
    float y=0;
    ALLEGRO_COLOR cor;
};

#endif /* POINT_H */

