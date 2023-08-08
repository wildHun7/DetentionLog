#include "dc.h"

auto DC::add(std::unique_ptr<Human>&& h) -> void
{ 
    this->humans.push_back(move(h)); 
}

auto DC::display() -> void
{   
    for (const auto& i : humans)
    {
        std::cout << "ID: " << i->getID() <<  "| Name: " << i->getName() << " | Violation: " << i->getViolation() << std::endl;
    }
    system("pause");
}

auto DC::remv() -> void
{
    int id_to_remove;
    std::cin >> id_to_remove;
    auto it = find_if(humans.begin(), humans.end(), [&id_to_remove](const std::unique_ptr<Human>& h)
        {
            return h != nullptr && h->getID() == id_to_remove;
        });
    if (it != humans.end())
        humans.erase(it);
    else
        std::cout << "Empty!";
    system("pause");
}

auto DC::update() -> void
{
    std::cout << "Type ID and press Enter:\n";
    int id_to_update;
    std::cin >> id_to_update;
    auto it = find_if(humans.begin(), humans.end(), [&id_to_update](const std::unique_ptr<Human>& h)
        {
            return h != nullptr && h->getID() == id_to_update;
        });
    std::cout << "Type violation and press Enter:\n";
    Human::Violation inmate_vlt = Human::Violation::empty;
    std::cin >> inmate_vlt;
    humans[std::distance(humans.begin(), it)]->setViolation(inmate_vlt);
}