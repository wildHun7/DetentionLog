#pragma once
#include "human.h"
#include "inmate.h"

class DC {
    public:
        std::vector< std::unique_ptr<Human> > humans;
        void add(std::unique_ptr<Human>&& h);
        void display();
        void remv();
        
};