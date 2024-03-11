#pragma once

#include <iostream>
#include <string>

#include "menu.hpp"
#include "id.hpp"

struct Date { 

    int day; 
    int month; 
    int year; 

};

struct DataSupir { 

    int ID; 
    std::string nama; 
    Date tglLahir;
    char kelamin;
    std::string alamat;

};

struct Node {

    DataSupir data; 
    Node* next; 
    Node* prev; 

}; 

void adminMenu();



