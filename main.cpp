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
void addProduct ();
void addProductMenu();

void addNewProducts ();
void enterProductDetails ();



int prodNum = 1;
int audioSerialNum = 0;
int visualSerialNum = 0;
int numberOfProducts;

std::vector <std::string> productLineManufacturer;
std::vector <std::string> productLineName;
std::vector <std::string> productLineItemType;

std::string manufacturer;
std::string productName;
int itemTypeChoice;
std::string itemTypeCode;
std::string manufacturerCode;


int main() {

    std::cout << "Production Line Tracker" << std::endl << std::endl;
    showMenu();
    getChoice();

}

int showMenu() {

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add Music Player" << std::endl;
    std::cout << "4. Add Movie Player" << std::endl;
    std::cout << "5. Display Production Statistics" << std::endl;
    std::cout << "6. Exit" << std::endl;

    std::cout << "" << std::endl;
    return 0;

}

void getChoice() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1 :
            std::cout << "Produce Items Stub" << std::endl;
            addProduct();
            break;
        case 2 :
            std::cout << "Add Employee Account Stub" << std::endl;
            break;
        case 3 :
            std::cout << "Add Music Player Stub" << std::endl;
            addNewProducts();
            break;
        case 4 :
            std::cout << "Add Movie Player Stub" << std::endl;
            addNewProducts();
            break;
        case 5 :
            std::cout << "Display Production Statistics Stub" << std::endl;
            break;
        case 6:
            exit; //Program ends
            break;
        default:
            std::cout << "Not a valid selection" << std::endl;
            showMenu();
    }
}
void addProduct () {
    std::ofstream file;
    file.open ("production.txt");
    addProductMenu();
    int selectProduct;
    std::cin >> selectProduct;
    switch (selectProduct){
        case 1:
            manufacturer = "Apple";
            productName = "iPod";
            itemTypeCode = "AM";
            manufacturerCode = "App";
            std::cout << "Number of products: \n";
            std::cin >> numberOfProducts;
            for (int i=0; i <numberOfProducts; i++) {
                file << "Production Number: " << prodNum << " Serial Number: " << manufacturerCode << itemTypeCode;
                file << std::setfill('0') << std::setw(5) << audioSerialNum << std::endl;
                prodNum++;
                audioSerialNum++;
            }
            addProduct();
            break;
        case 2:
            manufacturer = "Microsoft";
            productName = "Zune";
            itemTypeCode = "AM";
            manufacturerCode = "Mic";
            std::cout << "Number of products: \n";
            std::cin >> numberOfProducts;
            for (int i=0; i <numberOfProducts; i++) {
                file << "Production Number: " << prodNum << " Serial Number: " << manufacturerCode << itemTypeCode;
                file << std::setfill('0') << std::setw(5) << audioSerialNum << std::endl;
                prodNum++;
                audioSerialNum++;
            }
            addProduct();
            break;

        case 3:
            manufacturer = "Sylvania";
            productName = "SDVD1187";
            itemTypeCode = "VM";
            manufacturerCode = "Syl";
            std::cout << "Number of products: \n";
            std::cin >> numberOfProducts;
            for (int i=0; i <numberOfProducts; i++) {
                file << "Production Number: " << prodNum << " Serial Number: " << manufacturerCode << itemTypeCode;
                file << std::setfill('0') << std::setw(5) << visualSerialNum << std::endl;
                prodNum++;
                visualSerialNum++;
            }
            addProduct();
            break;

        case 4:
            showMenu();
            getChoice();

    }
    file.close();
}

void addProductMenu () {
    std::cout << "Select your Product: " << std::endl;
    std::cout << "1. Apple, iPod, AM \n2. Microsoft, Zune, AM \n3. Sylvania, SDVD1187, VM\n4.Main Menu\n";

}

void addNewProducts () {
    std::cout << "Enter the number of new product you want to produce: \n";
    int numOfNewProduct;
    std::cin >> numOfNewProduct;
    for (int i = 0; i < numOfNewProduct; i ++){
        enterProductDetails ();
    }

    showMenu();
    getChoice;

}
void enterProductDetails () {
    std::cout << "Enter the Manufacturer: \n";
    std::cin >> manufacturer;
    std::cout << "Enter the Product Name \n";
    std::cin >> productName;

    manufacturerCode = manufacturer.substr(0, 3);

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


    if (itemTypeCode == "MM" || itemTypeCode == "AM") {
        std::cout << "Enter Number of product you want: \n";
        std::cin>>numberOfProducts;
        for (int i=0; i<numberOfProducts;i++ ) {
            std::cout << "Production Number: " << prodNum << " Serial Number: " << manufacturerCode
                      << itemTypeCode << std::setfill('0') << std::setw(5) << audioSerialNum << std::endl;
            prodNum++;
            audioSerialNum++;
        }
    } else if (itemTypeCode == "VI" || itemTypeCode == "VM") {
        for (int i=0; i<numberOfProducts;i++ ) {
            std::cout << "Production Number: " << prodNum << " Serial Number: " << manufacturerCode
                      << itemTypeCode << std::setfill('0') << std::setw(5) << visualSerialNum << std::endl;
            prodNum++;
            visualSerialNum++;
        }
    }

}
