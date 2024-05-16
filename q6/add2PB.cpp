#include <iostream>
#include <fstream>
#include <string>

#define PHONEBOOK_FILE "phonebook.txt"

int main() {
    std::string name;
    std::string phone;

    // Prompt the user for the name and phone number
    std::cout << "Enter name (first and last): ";
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cerr << "Name cannot be empty" << std::endl;
        return 1;
    }

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone);

    if (phone.empty()) {
        std::cerr << "Phone number cannot be empty" << std::endl;
        return 1;
    }

    // Open the phonebook file in append mode
    std::ofstream phonebook(PHONEBOOK_FILE, std::ios::app);
    if (!phonebook) {
        std::cerr << "Error opening phonebook file" << std::endl;
        return 1;
    }

    // Write the entry to the file
    phonebook << name << "," << phone << "\n";

    std::cout << "Entry added successfully." << std::endl;
    return 0;
}
