// ctrl + alt + l for style

/**@file main.cpp
 * @brief Entire media player production program (for now)
 *
 *  This program helps to keep track the production and creates a serial number for each product type.
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

//Prototype
int showMenu();

void produceItems();

void addNewProducts();

std::vector<std::string> productLineManufacturer;
std::vector<std::string> productLineName;
std::vector<std::string> productLineItemType;

std::string manufacturer;
std::string productName;
int itemTypeChoice;
std::string itemTypeCode;


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
    bool continueProgram = true;

    do {
        showMenu();
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1 :
                produceItems();
                break;
            case 2 :
                std::cout << "Add Employee Account Stub" << std::endl;
                break;
            case 3 :
                addNewProducts();
                break;
            case 4 :
                std::cout << "Display Production Statistics Stub" << std::endl;
                break;
            case 5:
                continueProgram = false;//Program ends
                break;
            default:
                std::cout << "Not a valid selection" << std::endl;
        }
    } while (continueProgram);


}

int showMenu() {

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add Product" << std::endl;
    std::cout << "4. Display Production Statistics" << std::endl;
    std::cout << "5. Exit" << std::endl;

    std::cout << "" << std::endl;
    return 0;

}


void produceItems() {

    std::ofstream file;
    file.open("production.txt");

    int audioSerialNum = 0;
    int visualSerialNum = 0;

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
    int trackNum = 1;


    while (trackNum <= numOfNewProduct) {
        if ((productLineItemType.begin(), productLineItemType.end(), "AM") ||
            (productLineItemType.begin(), productLineItemType.end(), "MM")) {
            file << trackNum << ". " << productLineManufacturer[productNum - 1] << " ,";
            file << productLineName[productNum - 1] << ", " << productLineItemType[productNum - 1];
            file << " Serial Number: " << productLineManufacturer[productNum - 1].substr(0, 3) << std::setfill('0');
            file << std::setw(5) << audioSerialNum << std::endl;
            trackNum++;
            audioSerialNum++;
        } else if ((productLineItemType.begin(), productLineItemType.end(), "VI") ||
                   (productLineItemType.begin(), productLineItemType.end(), "VM")) {
            file << trackNum << ". " << productLineManufacturer[productNum - 1] << " ,";
            file << productLineName[productNum - 1] << ", " << productLineItemType[productNum - 1];
            file << " Serial Number: " << productLineManufacturer[productNum - 1].substr(0, 3) << std::setfill('0');
            file << std::setw(5) << visualSerialNum << std::endl;
            trackNum++;
            visualSerialNum++;
        }
    }

    file.close();
}


//Adding new items to the production list
void addNewProducts() {
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

