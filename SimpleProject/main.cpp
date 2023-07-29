// SimpleProject.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "dc.h"
#include <thread>
#include <conio.h>
#include <optional>

void displayMenu()
{
    std::cout << "===================================== \n";
    std::cout << " Detention Center Log \n";
    std::cout << "===================================== \n";
    std::cout << " 1.Add inmate records\n";
    std::cout << " 2.Delete inmate records\n";
    std::cout << " 3.View all inmate records \n";
    //std::cout << " 4.Update inmate records \n";
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

auto operator>>(std::istream& is, Human::Violation v) -> std::istream&
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
    return os << vlt_to_string(v).value_or("N/A");
}

auto addInmate(DC& dc) -> void 
{
    std::cout << "Type name and press Enter:\n";
    std::string n;
    std::cin >> n; 
    
    std::cout << "Type violation and press Enter:\n";
    Human::Violation vlt = Human::Violation::empty;
    std::cin >> vlt;
    
    std::unique_ptr<Human> h = std::make_unique<Inmate>(std::move(n), std::move(vlt));
    dc.add(std::move(h));
}

auto remvInmate(DC& dc) -> void
{
    std::cout << "Type name to remove the record:\n";  //id would be better
    dc.remv();
}

auto displayInmates(DC& dc) -> void {
    dc.display();
}

auto main() -> int
{
    DC dc;
    int choice;
    while (1) {
        system("cls");
        displayMenu();
        std::cin >> choice;
        std::cout << std::endl;
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
