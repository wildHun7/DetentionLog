#include "inmate.h"

    Inmate::Inmate() 
    {
        //intentionally empty
    }

    Inmate::Inmate(std::string _name, Human::Violation _violation): name(_name), violation(_violation)
    {
        //intentionally empty
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
