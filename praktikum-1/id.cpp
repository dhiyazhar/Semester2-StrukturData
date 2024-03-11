#include "id.hpp"
#include "admin.hpp"

std::string digitNama(std::string& nama) {
    
    char hurufPertama = toupper(nama[0]) - 'A' + 1;
    char hurufTerakhir = toupper(nama[nama.size() - 1]) - 'A' + 1;

    int hasilHuruf = abs(hurufPertama - hurufTerakhir);

    if (hasilHuruf < 10) {
        
        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << hasilHuruf;

        return ss.str();

    } else { 
        
        return std::to_string(hasilHuruf);

    }

}

std::string digitGender(char gender) {

    return std::to_string((gender == 'L' || 'l') ? 1 : 0);   

}

std::string digitTglLahir(int day, int month, int year) {

    int sum = (day % 10) + (month % 10) + (year % 10);
    return std::to_string(sum % 9);

}

bool cekDuplikatID(int id, Node* head) {
    Node* currentNode = head;
    if (currentNode == nullptr) return false;  

    do {
        if (currentNode->data.ID == id) {
            return true;  
        }
        currentNode = currentNode->next;
    } while (currentNode != head);

    return false; 
}


int generateID(std::string& nama, char gender, Date tglLahir, Node* head) {

    std::cout << digitNama(nama) << std::endl;
    std::cout << digitNama(nama) + digitGender(gender) + digitTglLahir(tglLahir.day, tglLahir.month, tglLahir.year) << std::endl;

    std::string empatDigit = (digitNama(nama) + digitGender(gender) + digitTglLahir(tglLahir.day, tglLahir.month, tglLahir.year);

    std::string digit5 = "0000"; 

    std::string ID = empatDigit + digit5;

    while (cekDuplikatID(ID, head)) {

        int digit5Int = std::stoi(digit5);
        digit5Int++;

        if (digit5Int == 10000) {
            empatDigit *= 10;
            digit5 = 0;
        }

        ID = empatDigit + digit5;

    }

    return ID;
    
}