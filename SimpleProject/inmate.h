#pragma once
#include "human.h"

class Inmate : public Human {

    public:
        Inmate();
        Inmate(int _id, std::string _name, Human::Violation _violation);

        auto getID() const -> int override;
        auto getName() const ->std::string override;
        auto getViolation() const ->Human::Violation override;
        
        auto setName(std::string _n) -> void override;
        auto setViolation(Human::Violation _v) -> void override;

    private:
        int id;
        std::string name;
        Human::Violation violation = Human::Violation::empty;  
};
