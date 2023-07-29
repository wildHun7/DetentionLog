#include "dc.h"

void DC::add(std::unique_ptr<Human>&& h) 
{ 
    this->humans.push_back(move(h)); 
}

void DC::display() 
{   
    for (auto& i : humans)
    {
        std::cout << "Name: " << i->getName() << " | Violation: " << i->getViolation() << std::endl;
    }
    system("pause");
}

void DC::remv()
{
    std::string n;
    std::cin >> n;
    auto it = find_if(humans.begin(), humans.end(), [&n](const std::unique_ptr<Human>& h)
        {
            return h != nullptr && h->getName() == n;
        });
    if (it != humans.end())
        humans.erase(it);
    else
        std::cout << "Empty!";
    system("pause");
}