#include "dc.h"

void DC::add(std::unique_ptr<Human>&& h) 
{ 
    this->humans.push_back(move(h)); 
}

void DC::display() 
{   
    for (auto& i : humans)
    {
        std::cout << "ID: " << i->getID() <<  "| Name: " << i->getName() << " | Violation: " << i->getViolation() << std::endl;
    }
    system("pause");
}

void DC::remv()
{
    int i;
    std::cin >> i;
    auto it = find_if(humans.begin(), humans.end(), [&i](const std::unique_ptr<Human>& h)
        {
            return h != nullptr && h->getID() == i;
        });
    if (it != humans.end())
        humans.erase(it);
    else
        std::cout << "Empty!";
    system("pause");
}