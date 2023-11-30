#include "ObjectController.h"

ObjectController::ObjectController(ObjectDatabase& model, ObjectView& view)
    : model_(model), view_(view)
{}

void ObjectController::addObject(const std::string& name, const std::string& mail, const std::string& password, const std::string& note) {
    Object object(name, mail, password, note);
    model_.addObject(object);
}

void ObjectController::removeObject(int index) {
    model_.removeObject(index);
}

void ObjectController::updateObject(int index, const std::string& mail, const std::string& password, const std::string& note) {
    Object& object = model_.getObject(index);
    object.setMail(mail);
    object.setPassword(password);
    object.setNote(note);
}

void ObjectController::displayAllObjects() {
    for (int i = 0; i < model_.getNumObjects();i++) {
        Object& object = model_.getObject(i);
        view_.showObject(object);
    }
}
 while (true) {
        int choice = view.showMenu();
        if (choice == 1) {
            std::string name, mail, password, note;
            view.getInput(name, mail, password, note);
            controller.addObject(name, mail, password, note);
        } else if (choice == 2) {
            int index;
            std::cout << "Enter index of object to remove: ";
            std::cin >> index;
            controller.removeObject(index);
        } else if (choice == 3) {
            int index;
            std::cout << "Enter index of object to view: ";
            std::cin >> index;
            Object& object = database.getObject(index);
            view.showObject(object);
        } else if (choice == 4) {
            int index;
            std::cout << "Enter index of object to update: ";
            std::cin >> index;
            std::string mail, password, note;
            view.getUpdateInput(mail, password, note);
            controller.updateObject(index, mail, password, note);
        } else if (choice == 5) {
            std::string name;
            view.getSearchInput(name);
            int index = database.findObjectIndexByName(name);
            if (index != -1) {
                Object& object = database.getObject(index);
                view.showObject(object);
            } else {
                view.showError("Object not found.");
            }
        } else if (choice == 6) {
            controller.displayAllObjects();
        } else if (choice == 7) {
            break;
        } else {
            view.showError("Invalid choice.");
        }
    }
    