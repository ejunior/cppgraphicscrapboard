/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cc
 * Author: ur5f
 *
 * Created on July 13, 2016, 1:21 PM
 */

#include <cstdlib>
#include "GameMgr.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    auto gm = new GameMgr();
    gm->run();    
    return 0;
}

