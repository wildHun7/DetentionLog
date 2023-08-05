#pragma once
#include "human.h"

class Inmate : public Human {

    public:
        Inmate();
        Inmate(int _id, std::string _name, Human::Violation _violation);

        int getID() const override;
        std::string getName() const override;
        Human::Violation getViolation() const override;
        
        void setName(std::string _n) override;
        void setViolation(Human::Violation _v) override;

    private:
        int id;
        std::string name;
        Human::Violation violation = Human::Violation::empty;  
};
