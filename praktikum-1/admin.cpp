#include "admin.hpp"

Node *head, *tail, *currentNode;

void init() {
    head = NULL;
    currentNode = NULL;
}

int isEmpty() {
    if(head == NULL) {
        return 1;
    } else { 
        return 0;
    }
}

void tambahDataSupir(DataSupir newData) {

    Node *newNode; 
    newNode = new Node; 
    newNode->data = newData;

    if (isEmpty() == 1) {

        head = newNode;
        tail = newNode;
        tail -> next = head;
        tail -> prev = head; 

    } else {
        newNode -> next = head; 
        head -> prev = newNode;
        head = newNode;
        head -> prev = tail;
        tail -> next = head;
    }

    std::cout << "Data masuk" << std::endl;

}

void displayTambahDataSupir() {

    int ID;
    std::string nama;
    Date tglLahir;
    char kelamin; 
    std::string alamat;

    std::cout << "===================" << std::endl;
    std::cout << "  Dashboard Admin  " << std::endl;
    std::cout << "===================" << std::endl;

    std::cout << " TAMBAH DATA SUPIR " << std::endl;

    std::cin.ignore();
    
    std::cout << "Nama : > "; 
    std::getline(std::cin, nama);

    std::cout << "Jenis Kelamin (l/p) : > ";
    std::cin >> kelamin;
    
    std::cout << "Tanggal Lahir (dd mm yyyy) : > "; 
    std::cin >> tglLahir.day >> tglLahir.month >> tglLahir.year;

    std::cin.ignore();
    std::cout << "Alamat : > ";
    std::getline(std::cin, alamat);

    //ID = generateID(nama, kelamin, tglLahir, head);

    DataSupir newData {

        ID,
        nama,
        tglLahir,
        kelamin,
        alamat

    };

    tambahDataSupir(newData);

    adminMenu();

}

void tampilkanDataSupir(DataSupir data) { 

    std::cout << "|------------------|" << std::endl;
    std::cout << "  Nama : " << data.nama << std::endl;
    std::cout << "  ID : " << data.ID << std::endl;
    std::cout << "  Tanggal Lahir: " << data.tglLahir.day << "-" << data.tglLahir.month << "-" << data.tglLahir.year << std::endl;
    std::cout << "  Jenis Kelamin : " << data.kelamin << std::endl;
    std::cout << "  Alamat : " << data.alamat << std::endl;
    std::cout << "|------------------|" << std::endl;

}

void displayTampilkanDataSupir() {

    std::cout << head << std::endl;
    
    if (isEmpty() == 1) {
        std::cout << "Data masih kosong." << std::endl;
        return;
    }

    Node *currentNode = head;
    int choice; 
    
    do {
        tampilkanDataSupir(currentNode->data);
        std::cout << "1. Next" << std::endl;
        std::cout << "2. Previous" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "> ";

        std::cin >> choice;

        switch(choice) {

            case 1: 
                currentNode = currentNode->next;
                break;
            case 2:
                currentNode = currentNode->prev;
                break;
            case 0: 
                adminMenu();
                break;
            default: 
                std::cout << "Maaf.";

        }
    } while (choice != 0);
    

}

void displayAdminMenu() {

    std::cout << "===================" << std::endl;
    std::cout << "  Dashboard Admin  " << std::endl;
    std::cout << "===================" << std::endl;

    std::cout << "1. Tampilkan Data Supir" << std::endl;
    std::cout << "2. Hapus Data Supir" << std::endl;
    std::cout << "3. Ubah Data Supir" << std::endl;
    std::cout << "4. Tambah Data Supir" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "> ";

}

void adminMenu() {

    int choice;

    do {

        displayAdminMenu();
        std::cin >> choice;
        
        switch (choice) {
        case 1:
            displayTampilkanDataSupir();
            break;
        case 2: 

            break;
        case 3: 

            break;
        case 4: 
            displayTambahDataSupir();
            break;
        case 0: 
            mainMenu();
            break;
        default: 
            system("cls");
            std::cout << "Maaf, pilihan anda salah. Silakan pilih ulang.";
        }

    } while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4);

}