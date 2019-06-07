// ctrl + alt + l for style

/**@file main.cpp
 * @brief Entire media player production program (for now)
 *
 *  This program helps to keep track on the production.
 *  Creates a serial number for each product type you produce.
 *  Create employee's account.
 *
 * @author Karan Patel
 * @bug
 */


#include <iostream>
#include <fstream> // Stream class to both read and write from/to files.
#include <string>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>

//Prototype
int showMenu();

void getChoice();

void produceItems();

void addNewProducts();

void addEmployeeDetails();

bool continueProgram = true;
int audioSerialNum = 0;
int visualSerialNum = 0;
int trackNum = 1;

std::vector<std::string> productLineManufacturer;
std::vector<std::string> productLineName;
std::vector<std::string> productLineItemType;


int main() {
    productLineManufacturer.push_back("Apple");
    productLineName.push_back("iPod");
    productLineItemType.push_back("AM");
    productLineManufacturer.push_back("Microsoft");
    productLineName.push_back("Zune");
    productLineItemType.push_back("AM");
    productLineManufacturer.push_back("Sylvania");
    productLineName.push_back("SDVD1187");
    productLineItemType.push_back("VM");

    std::cout << "Production Line Tracker" << std::endl << std::endl;

    do {
        showMenu();
        getChoice();
    } while (continueProgram);
}

/**
 * Menu where the items are added, produce.
 * Create and see employee account using username and password.
 * Everything is done using this menu.
 * @return
 */
int showMenu() {

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add Product" << std::endl;
    std::cout << "4. Display Production Statistics" << std::endl;\
    std::cout << "5. Exit" << std::endl;

    std::cout << "" << std::endl;
    return 0;

}

void getChoice() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1 :
            produceItems();
            break;
        case 2 :
            addEmployeeDetails();
            break;
        case 3 :
            addNewProducts();
            break;
        case 4 :
            std::cout << "Display Production Statistics Stub" << std::endl;
            break;
        case 5 :
            continueProgram = false;//Program ends
            break;
        default:
            std::cout << "Not a valid selection" << std::endl;
    }
}

/**
 * When the user enters 1 from the main menu
 * This function allows user to produce number of items.
 * It then creates a specific serial number of that item type.
 * It also keeps track on how many total items are produced.
 */
void produceItems() {
    std::ofstream file;
    file.open("production.txt");

    std::cout << "Choose product to produce: \n";
    for (int i = 0; i < productLineManufacturer.size(); i++) {
        std::cout << i + 1 << ". " << productLineManufacturer[i] << " ";
        std::cout << productLineName[i] << " " << productLineItemType[i] << std::endl;
    }
    int productNum;
    std::cin >> productNum;
    std::cout << "Enter the number of product you want to produce: \n";
    int numOfNewProduct;
    std::cin >> numOfNewProduct;
    trackNum;

    int trackWhile = 1;

    while (trackWhile <= numOfNewProduct) {
        if ((productLineItemType.begin(), productLineItemType.end(), "AM") ||
            (productLineItemType.begin(), productLineItemType.end(), "MM")) {
            file << trackNum << ". " << productLineManufacturer[productNum - 1] << " ,"
                 << productLineName[productNum - 1] << ", " << productLineItemType[productNum - 1]
                 << " Serial Number: " << productLineManufacturer[productNum - 1].substr(0, 3) << std::setfill('0')
                 << std::setw(5) << audioSerialNum << std::endl;
            trackNum++;
            audioSerialNum++;

        } else if ((productLineItemType.begin(), productLineItemType.end(), "VI") ||
                   (productLineItemType.begin(), productLineItemType.end(), "VM")) {
            file << trackNum << ". " << productLineManufacturer[productNum - 1] << " ,"
                 << productLineName[productNum - 1] << ", " << productLineItemType[productNum - 1]
                 << " Serial Number: " << productLineManufacturer[productNum - 1].substr(0, 3) << std::setfill('0')
                 << std::setw(5) << visualSerialNum << std::endl;
            trackNum++;
            visualSerialNum++;
        }
        trackWhile++;
    }
}

//Adding new items to the production list
/**
 * Add new items to the product line.
 * If the user or customer want to a new item to produce from this company
 * it can be done here.
 */
void addNewProducts() {

    std::string manufacturer;
    std::string productName;
    std::string itemTypeCode;
    int itemTypeChoice;

    std::cout << "Enter the Manufacturer: \n";
    std::cin >> manufacturer;
    std::cout << "Enter the Product Name \n";
    std::cin >> productName;

    std::cout << "Enter the Item Type: \n";
    std::cout << "1. Audio\n2. Visual\n3. AudioMobile\n4. VisualMobile\n";
    std::cin >> itemTypeChoice;

    if (itemTypeChoice == 1) {
        itemTypeCode = "MM";
    } else if (itemTypeChoice == 2) {
        itemTypeCode = "VI";
    } else if (itemTypeChoice == 3) {
        itemTypeCode = "AM";
    } else if (itemTypeChoice == 4) {
        itemTypeCode = "VM";
    }
    productLineManufacturer.push_back(manufacturer);
    productLineName.push_back(productName);
    productLineItemType.push_back(itemTypeCode);

}

/**
 * Enter employee's first and last name.
 * It generates username for that employee.
 * Employee can also enter password to keep track on his items.
 */
void addEmployeeDetails() {

    std::cout << "Enter employee's full name \n ";

    std::string first_name;
    std::cin >> first_name;
    std::string last_name;
    std::cin >> last_name;
    std::string user_name;

    // create user name in proper format
    std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);
    std::transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);

    char firstName = first_name[0];
    user_name = firstName + last_name;

    std::cout << "User name: " + user_name + "\n";

    bool valid;
    bool lower = false;
    bool upper = false;
    bool digit = false;
    std::cout << "Enter employee's password.\n";
    std::cout << "Must contain a number and lowercase and uppercase letters.\n";

    const int SIZE = 30;
    char password[SIZE];

    std::cin >> password;

    // code to check if valid
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            upper = true;
        } else if (islower(password[i])) {
            lower = true;
        } else if (isdigit(password[i])) {
            digit = true;
        }
    }
    if (upper == true && lower == true && digit == true) {
        valid = true;
    } else {
        valid = false;
    }

    if (valid) {
        std::cout << "Employee's account is set\n";
    } else {
        std::cout << "invalid\n";
    }
}
