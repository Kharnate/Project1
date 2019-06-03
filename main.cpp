// ctrl + alt + l for style

/**@file main.cpp
 * @brief Entire media player production program (for now)
 *
 *  This program helps to keep track the production and creates a serial number for each product type.
 *
 * @author Karan patel
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

void getChoice();

void produceItems();


void addNewProducts();


int prodNum = 1;
int audioSerialNum = 0;
int visualSerialNum = 0;


std::vector<std::string> productLineManufacturer;
std::vector<std::string> productLineName;
std::vector<std::string> productLineItemType;

std::string manufacturer;
std::string productName;
int itemTypeChoice;
std::string itemTypeCode;
std::string manufacturerCode;

std::vector<std::string> productNum;
std::vector<std::string> productManufacturer;
std::vector<std::string> productItemType;
std::vector<std::string> serialNum;


int main() {
    productLineManufacturer.push_back("Apple");
    productLineName.push_back("iPod");
    productLineItemType.push_back("AM");
    productLineManufacturer.push_back("Microsoft");
    productLineName.push_back("Zune");
    productLineItemType.push_back("AM");
    productLineManufacturer.push_back("Sylvania");
    productLineName.push_back("SDVD1187");
    productLineItemType.push_back("Vm");
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
                showMenu();
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
    for (int i = 0; i < productNum; i++) {

    }
}
/*
void oldAdd() {
    std::ofstream file;
    file.open("production.txt");
    //addProductMenu();
    int selectProduct;
    std::cin >> selectProduct;
    switch (selectProduct) {
        case 1:
            manufacturer = "Apple";
            productName = "iPod";
            itemTypeCode = "AM";
            manufacturerCode = "App";
            std::cout << "Number of products: \n";
            std::cin >> numberOfProducts;
            for (int i = 0; i < numberOfProducts; i++) {
                file << "Production Number: " << prodNum << " Serial Number: " << manufacturerCode << itemTypeCode;
                file << std::setfill('0') << std::setw(5) << audioSerialNum << std::endl;
                prodNum++;
                audioSerialNum++;
            }
            produceItems();
            break;
        case 2:
            manufacturer = "Microsoft";
            productName = "Zune";
            itemTypeCode = "AM";
            manufacturerCode = "Mic";
            std::cout << "Number of products: \n";
            std::cin >> numberOfProducts;
            for (int i = 0; i < numberOfProducts; i++) {
                file << "Production Number: " << prodNum << " Serial Number: " << manufacturerCode << itemTypeCode;
                file << std::setfill('0') << std::setw(5) << audioSerialNum << std::endl;
                prodNum++;
                audioSerialNum++;
            }
            produceItems();
            break;

        case 3:
            manufacturer = "Sylvania";
            productName = "SDVD1187";
            itemTypeCode = "VM";
            manufacturerCode = "Syl";
            std::cout << "Number of products: \n";
            std::cin >> numberOfProducts;
            for (int i = 0; i < numberOfProducts; i++) {
                file << "Production Number: " << prodNum << " Serial Number: " << manufacturerCode << itemTypeCode;
                file << std::setfill('0') << std::setw(5) << visualSerialNum << std::endl;
                prodNum++;
                visualSerialNum++;
            }
            produceItems();
            break;

        case 4:
            showMenu();
            getChoice();

    }
    file.close();
}
*/

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
