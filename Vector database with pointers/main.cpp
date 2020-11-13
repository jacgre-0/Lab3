#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using Database = std::vector<std::string>;

void initialise(Database* database);
void insert(Database* database);
void print(const Database* database);
bool search(const Database* database, const std::string& searchStr);
std::string deleteElement(Database* database, const std::string& element);
void save(const Database* database, const std::string& filePath);
bool load(Database* database, const std::string& filePath);

int main() {
    Database database;
    std::string substr{};
    std::string personToDelete{};
    std::string saveFilePath{};
    std::string loadFilePath{};
    int choice{};

    while (true) {
        std::cout << "MENU: " << "\n"
            << "1. initialise database\n"
            << "2. insert\n"
            << "3. search\n"
            << "4. delete\n"
            << "5. print\n"
            << "6. quit\n"
            << "7. save database to file\n"
            << "8. load file into database\n"
            << "Make your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            initialise(&database);
            break;
        case 2:
            insert(&database);
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Type the search string: ";
            std::cin >> substr;

            if (!search(&database, substr)) {
                std::cout << "Could not find any elements that matches the search string" << std::endl;
            }
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "Type the person to delete: ";
            std::cin >> personToDelete;

            std::cout << deleteElement(&database, personToDelete) << std::endl;
            std::cout << std::endl;
            break;
        case 5:
            print(&database);
            std::cout << std::endl;
            break;
        case 6:
            return 0;
        case 7:
            std::cout << "\n Type the filepath where the file is located: ";
            std::cin >> saveFilePath;

            save(&database, saveFilePath);
            std::cout << "Saved database to " << saveFilePath << std::endl;
            break;
        case 8:
            std::cout << "\n Type the filepath where the file is located: ";
            std::cin >> loadFilePath;

            if (load(&database, loadFilePath)) {
                std::cout << "Loaded contents of " << loadFilePath << " into database succesfully" << std::endl;
            }
            else {
                std::cout << "Could not load file into database because the file might not exist" << std::endl;
            }

            break;
        default:
            std::cout << "Error! only numbers between 1 and 6 is allowed." << std::endl;
            break;
        }
    }

    return 0;
}

void initialise(Database* database) {
    //We don't have to clear it if it is already empty
    if (!database->empty()) {
        bool initialise{};

        std::cout << "Are you sure? (1/0) ";
        std::cin >> initialise;

        if (initialise) {
            database->clear();
        }
    }
}

void insert(Database* database) {
    std::string input{};

    while (true) {
        std::cout << "Write a name you would like to insert in the database (write Q/q to stop): ";
        std::cin >> input;

        if (input == "Q" || input == "q")
            return;

        database->push_back(input);
    }
}

void print(const Database* database) {
    for (int i = 0; i < database->size(); i++) {
        std::cout << database->at(i) << std::endl;
    }
}

std::string deleteElement(Database* database, const std::string& element) {
    std::string returnMessage{};
    for (int i = 0; i < database->size(); i++) {
        if (database->at(i) == element) {
            database->erase(database->begin() + i);
            return returnMessage.append("Deleted ").append(element).append(" from database!\n");
        }
    }
    return returnMessage
        .append("Could not delete ").append(element)
        .append("\nReason: ").append(element).append(" was not found in the database!\n");
}

bool search(const Database* database, const std::string& searchStr) {
    bool returnCode{ false };

    for (int i = 0; i < database->size(); i++) {
        if (database->at(i).find(searchStr) != std::string::npos) {
            std::cout << database->at(i) << std::endl;
            returnCode = true;
        }
    }
    return returnCode;
}

void save(const Database* database, const std::string& filePath) {
    std::ofstream out;

    //If the does not exist, ofstream::open will automatically create it.
    out.open(filePath);

    //Some error has occured
    if (!out.good()) {
        std::cout << "Error opening file..." << std::endl;
        return;
    }

    for (int i = 0; i < database->size(); i++) {
        out << database->at(i) << "\n";
    }
    out.close();
}
bool load(Database* database, const std::string& filePath) {
    std::string content{};

    std::ifstream in(filePath);

    //Means that the filePath does not exist or some other error occured. 
    if (!in.good()) {
        return false;
    }

    if (!database->empty()) {
        database->clear();
    }

    while (std::getline(in, content)) {
        database->push_back(content);
    }

    in.close();

    return true;
}