#include "inmate.h"

    Inmate::Inmate() 
    {
        //intentionally empty
    }

    Inmate::Inmate(int _id, std::string _name, Human::Violation _violation): id(std::move(_id)), name(std::move(_name)), violation(std::move(_violation))
    {
        //intentionally empty
    }

    int Inmate::getID() const
    {
        return this->id;
    }

    std::string Inmate::getName() const  
    { 
        return this->name; 
    }

    Human::Violation Inmate::getViolation() const
    {
        return this->violation;
    }

    void Inmate::setName(std::string _n)
    {
        this->name = _n;
    }

    void Inmate::setViolation(Human::Violation _v)
    {
        this->violation = _v;
    }
