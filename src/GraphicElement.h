/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphicElement.h
 * Author: ur5f
 *
 * Created on July 14, 2016, 1:09 PM
 */

#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <list>
#include "Point.h"


class GraphicElement {
public:  
    virtual ~GraphicElement();

    virtual void draw(bool debug = false);    
    virtual std::list<Point*> getPoints();
};

#endif /* GRAPHICELEMENT_H */

