#pragma once
#include "human.h"
#include "inmate.h"

class DC {
    public:
        std::vector< std::unique_ptr<Human> > humans;
        auto add(std::unique_ptr<Human>&& h) -> void;
        auto display() -> void;
        auto remv() -> void;
        auto update() -> void;
};