#include "inmate.h"

    Inmate::Inmate() 
    {
        //intentionally empty
    }

    Inmate::Inmate(int _id, std::string _name, Human::Violation _violation): id(std::move(_id)), name(std::move(_name)), violation(std::move(_violation))
    {
        //intentionally empty
    }

    auto Inmate::getID() const -> int
    {
        return this->id;
    }

    auto Inmate::getName() const -> std::string
    { 
        return this->name; 
    }

    auto Inmate::getViolation() const -> Human::Violation
    {
        return this->violation;
    }

    auto Inmate::setName(std::string _n) -> void
    {
        this->name = _n;
    }

    auto Inmate::setViolation(Human::Violation _v) -> void
    {
        this->violation = _v;
    }
