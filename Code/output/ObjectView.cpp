#include <iostream>
#include "ObjectView.h"

int ObjectView::showMenu() {
    std::cout << "Menu:\n"
              << "1. Add object\n"
              << "2. Remove object\n"
              << "3. View object\n"
              << "4. Update object\n"
              << "5. Search object\n"
              << "6. Display all objects\n"
              << "7. Exit\n"
              << "Enter choice: ";
    int choice;
    std::cin >> choice;
    return choice;
}

void ObjectView::getInput(std::string& name, std::string& mail, std::string& password, std::string& note) {
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter mail: ";
    std::cin >> mail;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter note: ";
    std::cin >> note;
}

void ObjectView::getUpdateInput(std::string& mail, std::string& password, std::string& note) {
    std::cout << "Enter new mail (or press enter to keep the same): ";
    std::cin >> mail;
    std::cout << "Enter new password (or press enter to keep the same): ";
    std::cin >> password;
    std::cout << "Enter new note (or press enter to keep the same): ";
    std::cin >> note;
}

void ObjectView::getSearchInput(std::string& name) {
    std::cout << "Enter name to search for: ";
    std::cin >> name;
}

void ObjectView::showError(const std::string& message) {
    std::cout << "Error: " << message << std::endl;
}

void ObjectView::showObject(const Object& object) {
    std::cout << "Name: " << object.getName() << std::endl
              << "Mail: " << object.getMail() << std::endl
              << "Password: " << object.getPassword() << std::endl
              << "Note: " << object.getNote() << std::endl;
}