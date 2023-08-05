#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

class Human {
    protected:
        Human() = default;

    public:
        virtual ~Human() = default;
        Human(const Human& ch) = default;
        Human& operator=(const Human& cah) = default;
        Human(Human&& mh) noexcept = default;
        Human& operator=(Human&& mah) noexcept = default; 

        enum class Violation
        {
            assault,
            arson,
            battery,
            carjacking,
            robbery,
            empty
        };

        friend auto operator<<(std::ostream&, Human::Violation) -> std::ostream&;

        virtual int getID() const = 0;
        virtual std::string getName() const = 0;
        virtual Human::Violation getViolation() const = 0;
        
        virtual void setName(std::string) = 0;
        virtual void setViolation(Human::Violation) = 0;
};

