/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Spline.h
 * Author: ur5f
 *
 * Created on July 14, 2016, 11:19 AM
 */

#ifndef SPLINE_H
#define SPLINE_H
#include "allegro5/color.h"
#include "GraphicElement.h"

class Spline: GraphicElement {
    
public:
    Spline();
    Spline(const Spline& orig);
    virtual ~Spline();
    void draw(bool debug = false) override;
    std::list<Point*> getPoints() override;

   
private:

    ALLEGRO_COLOR cor;
    union{
        struct{
            float a[2];
            float b[2];
            float c[2];
            float d[2];
        } points;
        float controlVerticesArray[8];
    } control ;
};


#endif /* SPLINE_H */

