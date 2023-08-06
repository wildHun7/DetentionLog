// SimpleProject.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "dc.h"
#include <thread>
#include <conio.h>
#include <optional>

auto displayMenu() -> void
{
    std::cout << "===================================== \n";
    std::cout << " Detention Center Log \n";
    std::cout << "===================================== \n";
    std::cout << " 1.Add inmate records\n";
    std::cout << " 2.Delete inmate records\n";
    std::cout << " 3.View all inmate records \n";
    std::cout << " 4.Update inmate records \n";
    //std::cout << " 5.Find inmate by ID \n";
}

auto string_to_vlt(std::string const s) -> std::optional<Human::Violation>
{
    if (s == "assault")     return Human::Violation::assault;
    if (s == "arson")       return Human::Violation::arson;
    if (s == "battery")     return Human::Violation::battery;
    if (s == "carjacking")  return Human::Violation::carjacking;
    if (s == "robbery")     return Human::Violation::robbery;

    return std::nullopt;
}

auto operator>>(std::istream& is, Human::Violation& v) -> std::istream&
{
    auto s = std::string();
    if (!(is >> s)) {
        return is;
    }
    if (auto result = string_to_vlt(s)) {
        v = *result;
    }
    return is;
}

auto vlt_to_string(Human::Violation const v) -> std::optional<std::string_view>
{
    if (v == Human::Violation::assault)     return "assault";
    if (v == Human::Violation::arson)       return "arson";
    if (v == Human::Violation::battery)     return "battery";
    if (v == Human::Violation::carjacking)  return "carjacking";
    if (v == Human::Violation::robbery)     return "robbery";

    return std::nullopt;
}

auto operator<<(std::ostream& os, Human::Violation v) -> std::ostream& {
    return os << vlt_to_string(v).value_or("not defined");
}

auto addInmate(DC& dc) -> void 
{
    std::cout << "Type ID and press Enter:\n";
    int inmateID = 0;
    std::cin >> inmateID;

    std::cout << "Type name and press Enter:\n";
    std::string inmate_name;
    std::cin >> inmate_name; 
    
    std::cout << "Type violation and press Enter:\n";
    Human::Violation inmate_vlt = Human::Violation::empty;
    std::cin >> inmate_vlt;
    
    std::unique_ptr<Human> h = std::make_unique<Inmate>(inmateID, std::move(inmate_name), std::move(inmate_vlt));
    dc.add(std::move(h)); 
}

auto remvInmate(DC& dc) -> void
{
    std::cout << "Type ID to remove a record:\n";  
    dc.remv();
}

auto displayInmates(DC& dc) -> void {
    dc.display();
}

auto updateInmate(DC& dc) -> void {
    dc.update();
}

auto main() -> int
{
    DC dc;
    int choice;
    while (1) {
        system("cls");
        displayMenu();
        std::cin >> choice;
        if (choice >= 5)
            continue;
        system("cls");

        switch (choice)
        {
        case 1:
            addInmate(dc);
            break;
        case 2:
            remvInmate(dc);
            break;
        case 3:
            displayInmates(dc);
            break;
        case 4:
            updateInmate(dc);
            break;
        default:
            std::cout << "Wrong choice. Try Again." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }
    }

    return 0;
}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
