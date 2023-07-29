#pragma once
#include "human.h"

class Inmate : public Human {

    public:
        Inmate();
        Inmate(std::string _name, Human::Violation _violation);

        std::string getName() const override;
        Human::Violation getViolation() const override;
        void setName(std::string _n) override;
        void setViolation(Human::Violation _v) override;

    private:
        std::string name;
        //int id;
        Human::Violation violation = Human::Violation::empty;  
};
