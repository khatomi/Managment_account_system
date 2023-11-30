#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Define the object class to store its information
class Object {
public:
    string name;
    string mail;
    string password;
    string note;

    Object(string name, string mail, string password, string note) {
        this->name = name;
        this->mail = mail;
        this->password = password;
        this->note = note;
    }
};

// Define the data structure to store the objects in memory
class ObjectDatabase {
private:
    vector<Object> objects;

public:
    void addObject(Object object) {
        objects.push_back(object);
    }

    void removeObject(int index) {
        objects.erase(objects.begin() + index);
    }

    Object& getObject(int index) {
        return objects[index];
    }

    int getNumObjects() {
        return objects.size();
    }

    // Save the objects to a text file
    void saveToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (Object& object : objects) {
                file << object.name << "," << object.mail << "," << object.password << "," << object.note << endl;
            }
            file.close();
        } else {
            cerr << "Error: could not open file " << filename << endl;
        }
    }

    // Load the objects from a text file
    void loadFromFile(string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            objects.clear();
            string line;
            while (getline(file, line)) {
                size_t pos1 = line.find(",");
                size_t pos2 = line.find(",", pos1 + 1);
                size_t pos3 = line.find(",", pos2 + 1);
                string name = line.substr(0, pos1);
                string mail = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string password = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string note = line.substr(pos3 + 1);
                addObject(Object(name, mail, password, note));
            }
            file.close();
        } else {
            cerr << "Error: could not open file " << filename << endl;
        }
    }

    // Find the index of an object by its name
    int findObjectIndexByName(string name) {
        for (int i = 0; i< objects.size(); i++) {
            if (objects[i].name == name) {
                return i;
            }
        }
        return -1;
    }

    // Update an object's information
    void updateObject(int index, string mail, string password, string note) {
        objects[index].mail = mail;
        objects[index].password = password;
        objects[index].note = note;
    }

    // Display all objects' information
    void displayAllObjects() {
        for (Object& object : objects) {
            cout << "Name: " << object.name << endl;
            cout << "Mail: " << object.mail << endl;
            cout << "Password: " << object.password << endl;
            cout << "Note: " << object.note << endl << endl;
        }
    }
};

// Define the controller class to interact with the model and view
class ObjectController {
private:
    ObjectDatabase database;

public:
    // Load the objects from a file when the controller is created
    ObjectController(string filename) {
        database.loadFromFile(filename);
    }

    // Add a new object to the database
    void addObject(string name, string mail, string password, string note) {
        Object object(name, mail, password, note);
        database.addObject(object);
        database.saveToFile("objects.txt");
    }

    // Remove an object from the database
    void removeObject(int index) {
        database.removeObject(index);
        database.saveToFile("objects.txt");
    }

    // Get an object from the database
    Object& getObject(int index) {
        return database.getObject(index);
    }

    // Get the number of objects in the database
    int getNumObjects() {
        return database.getNumObjects();
    }

    // Find an object index by its name
    int findObjectIndexByName(string name) {
        return database.findObjectIndexByName(name);
    }

    // Update an object's information
    void updateObject(int index, string mail, string password, string note) {
        database.updateObject(index, mail, password, note);
        database.saveToFile("objects.txt");
    }

    // Display all objects' information
    void displayAllObjects() {
        database.displayAllObjects();
    }
};

// Define the view class to interact with the user
class ObjectView {
public:
    // Display a menu of options to theuser
    int showMenu() {
        int choice;
        cout<<"###################### khatomi ###################### \n"<<endl;
        cout<<"-_-_-_-_-_-_-_-_-_-_-__-__- Account -_-_-_-_-_-_-_-_-_-_-__-__-\n";
        cout << "1. Add object" << endl;
        cout << "2. Remove object" << endl;
        cout << "3. View object" << endl;
        cout << "4. Update object" << endl;
        cout << "5. Search by object name" << endl;
        cout << "6. Display all objects" << endl;
        cout << "7. Exit \n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }

    // Get the user's input to add a new object
    void getInput(string& name, string& mail, string& password, string& note) {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Email: ";
        cin >> mail;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter note: ";
        cin >> note;
    }

    // Display the information of an object to the user
    void showObject(Object& object) {
        cout << "Name: " << object.name << endl;
        cout<<"**********************"<<endl;
        cout << "Mail: " << object.mail << endl;
          cout<<"**********************"<<endl;
        cout << "Password: " << object.password << endl;
          cout<<"**********************"<<endl;
        cout<< "Note: " << object.note << endl;
          cout<<"**********************"<<endl;
    }

    // Get the user's input to update an object's information
    void getUpdateInput(string& mail, string& password, string& note) {
        cout << "Enter new mail (press enter to keep the current value): ";
        cin.ignore();
        getline(cin, mail);
        cout << "Enter new password (press enter to keep the current value): ";
        getline(cin, password);
        cout << "Enter new note (press enter to keep the current value): ";
        getline(cin, note);
    }

    // Get the user's input to search for an object by name
    void getSearchInput(string& name) {
        cout << "Enter object name to search for: ";
        cin >> name;
    }

    // Display an error message to the user
    void showError(string message) {
        cerr << "Error: " << message << endl;
    }
};

// Define the main function to run the program
int main() {
    // Create the controller and view objects
    ObjectController controller("objects.txt");
    ObjectView view;

     // Loop until the user chooses to exit
    int choice = 0;
    while (choice != 7) {
        choice = view.showMenu();
        switch (choice) {
            case 1: {
                // Get input from the user and add the object to the database
                string name, mail, password, note;
                view.getInput(name, mail, password, note);
                controller.addObject(name, mail, password, note);
                break;
            }
            case 2: {
                // Get the index of the object to remove and remove it from the database
                int index;
                cout << "Enter index of object to remove: ";
                cin >> index;
                if (index >= 0 && index < controller.getNumObjects()) {
                    controller.removeObject(index);
                } else {
                    view.showError("Invalid index");
                }
                break;
            }
            case 3: {
                // Get the index of the object to view and display its information
                int index;
                cout << "Enter index of object to view: ";
                cin >> index;
                if (index >= 0 && index < controller.getNumObjects()) {
                    Object& object = controller.getObject(index);
                    view.showObject(object);
                } else {
                    view.showError("Invalid index");
                }
                break;
            }
            case 4: {
                // Get the index of the object to update and update its information
                int index;
                cout << "Enter index of object to update: ";
                cin >> index;
                if (index >= 0 && index < controller.getNumObjects()) {
                    string mail, password, note;
                    view.getUpdateInput(mail, password, note);
                    controller.updateObject(index, mail, password, note);
                } else {
                    view.showError("Invalid index");
                }
                break;
            }
            case 5: {
                // Search for an object by name and display its information
                string name;
                view.getSearchInput(name);
                int index = controller.findObjectIndexByName(name);
                if (index >= 0) {
                    Object& object = controller.getObject(index);
                    view.showObject(object);
                } else {
                    view.showError("Object not found");
                }
                break;
            }
            case 6: {
                // Display all objects' information
                controller.displayAllObjects();
                break;
            }
            case 7: {
                // Exit the program
                break;
            }
            default: {
                view.showError("Invalid choice");
                break;
            }
        }
    }

    return 0;
}