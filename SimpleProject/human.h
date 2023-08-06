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
        friend auto operator>>(std::istream&, Human::Violation&) -> std::istream&;

        virtual auto getID() const -> int = 0;
        virtual auto getName() const -> std::string = 0;
        virtual auto getViolation() const ->Human::Violation = 0;
        
        virtual auto setName(std::string) -> void = 0;
        virtual auto setViolation(Human::Violation&) -> void = 0;
};

