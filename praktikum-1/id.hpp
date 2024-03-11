#pragma once 

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

struct Node;
struct Date;

int generateID(std::string& nama, char kelamin, Date tglLahir, Node* head);
