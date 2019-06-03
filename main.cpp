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
bool continueProgram = true;


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
std::string manufacturerCode = manufacturer.substr(0, 3);


int main() {

    std::cout << "Production Line Tracker" << std::endl << std::endl;

    do {
         showMenu();
         getChoice();
       } while (continueProgram);



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
            break;
        case 4 :
            std::cout << "Add Movie Player Stub" << std::endl;
            break;
        case 5 :
            std::cout << "Display Production Statistics Stub" << std::endl;
            break;
        case 6:
            continueProgram = false; //When the user enters 6, the do-while ends nad returns to main menu
            break;
        default:
            std::cout << "Not a valid selection" << std::endl;
    }
}
void addProduct () {
    std::cout << "Select your Product: " << std::endl;
    std::cout << "1. Apple, iPod, AM \n2. Microsoft, Zune, AM \n3. Sylvania, SDVD1187, VM\n4.Main Menu\n";
    std::ofstream file;
    file.open ("production.txt");
    int selectProduct;
    std::cin >> selectProduct;
    switch (selectProduct){
        case 1: manufacturer = "Apple";
            productName = "iPod";
            itemTypeCode = "AM";
            manufacturerCode = "App";
            std::cout << "Number of products: \n";
            std::cin >> numberOfProducts;
            for (int i=0; i <numberOfProducts; i++) {
                file<< "Production Number: " << prodNum << " Serial Number: " << manufacturerCode << itemTypeCode;
                file<< std::setfill('0') << std::setw(5) << audioSerialNum << std::endl;
                prodNum++;
                audioSerialNum++;
            }
         break;
        case 2: manufacturer = "Microsoft";
            productName = "Zune";
            itemTypeCode = "AM";
            manufacturerCode = "Mic";
           std::cout << "Number of products: \n";
            std::cin >> numberOfProducts;
            for (int i=0; i <numberOfProducts; i++) {
                file<< "Production Number: " << prodNum << " Serial Number: " << manufacturerCode << itemTypeCode;
                file << std::setfill('0') << std::setw(5) << audioSerialNum << std::endl;
                prodNum++;
                audioSerialNum++;
            }
           break;
        case 3: manufacturer = "Sylvania";
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
           break;
        case 4: showMenu();

    }
    file.close();
}




















