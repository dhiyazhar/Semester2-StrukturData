#include "menu.hpp"
#include "admin.hpp"    

void mainMenu() {

    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "      BONJOUR       " << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << std::endl;

    std::cout << "Masuk sebagai:" << std::endl;
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. User" << std::endl;
    std::cout << "> ";

    int choice; 

    do {

        std::cin >> choice;

        switch (choice) { 

        case 1: 

            adminMenu();
            break;
        case 2: 

            break;
        default:
            system("cls");
            std::cout << "Maaf, pilihan anda salah. Silahkan pilih ulang.";
        }

    } while (choice != 1 && choice != 2);

}
