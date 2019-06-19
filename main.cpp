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
int show_menu();

void get_choice();

void display_production();

void set_employee_account();

bool continue_program = true;
int audio_serial_number = 0; //AM
int audio_mobile_serial_number = 0; //MM
int visual_serial_number = 0; //VI
int visual_mobile_serial_number = 0; //VM
int track_number = 1;

struct Product {
    std::string manufacturer;
    std::string name;
    std::string itemType;
};

//products is a vector that stores all products (Product) struct details (manufacturer, name and item type)
std::vector<Product> products;

void add_new_products(std::vector<Product> &);

void produce_items(const std::vector<Product> &);


int main() {
    Product Apple = {"Apple", "iPod", "AM"};
    products.push_back(Apple);
    Product Microsoft = {"Microsoft", "Zune", "AM"};
    products.push_back(Microsoft);
    Product Sylvania = {"Sylvania", "SDVD1187", "VM"};
    products.push_back(Sylvania);

    std::cout << "Production Line Tracker" << std::endl << std::endl;

    do {
        show_menu();
        get_choice();
    } while (continue_program);
}

/**
 * Menu where the items are added, produce.
 * Create and see employee account using username and password.
 * Everything is done using this menu.
 * @return
 */
int show_menu() {

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add Product" << std::endl;
    std::cout << "4. Display Production Statistics" << std::endl;\
    std::cout << "5. Exit" << std::endl;

    std::cout << "" << std::endl;
    return 0;

}

void get_choice() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1 :
            produce_items(products);
            break;
        case 2 :
            set_employee_account();
            break;
        case 3 :
            add_new_products(products);
            break;
        case 4 :
            display_production();
            break;
        case 5 :
            continue_program = false;//Program ends
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
void produce_items(const std::vector<Product> &products) {

    std::ofstream file;
    file.open("production.txt", std::ios::app); // std::ios::app appends to the file

    std::ofstream product_line_file;
    product_line_file.open ("product_line.txt", std::ios::app);

    std::cout << "Choose product to produce: \n";
    for (int i = 0; i < products.size(); i++) {
        product_line_file << i + 1 << ". " << products[i].manufacturer << " " <<
                  products[i].name << " " << products[i].itemType << std::endl;
    }
    int product_number;
    std::cin >> product_number;
    std::cout << "Enter the number of product you want to produce: \n";
    int num_of_new_products;
    std::cin >> num_of_new_products;

    int track_while_loop = 0;

    while (track_while_loop < num_of_new_products) {
        if (products[product_number - 1].itemType == "AM") {
            if (audio_serial_number >= audio_mobile_serial_number) {
                audio_serial_number = audio_serial_number;
            } else {
                audio_serial_number = audio_mobile_serial_number;
            }
            file << track_number << ". " << products[product_number - 1].manufacturer << ", " <<
                 products[product_number - 1].name << ", " << products[product_number - 1].itemType << " Serial Number: "
                 <<
                 products[product_number - 1].manufacturer.substr(0, 3) << std::setfill('0') << std::setw(5)
                 << audio_serial_number << std::endl;
            track_number++;
            audio_serial_number++;
        } else if (products[product_number - 1].itemType == "MM") {
            if (audio_mobile_serial_number >= audio_serial_number) {
                audio_mobile_serial_number = audio_mobile_serial_number;
            } else {
                audio_mobile_serial_number = audio_serial_number;
            }
            file << track_number << ". " << products[product_number - 1].manufacturer << ", " <<
                 products[product_number - 1].name << ", " << products[product_number - 1].itemType << " Serial Number: "
                 <<
                 products[product_number - 1].manufacturer.substr(0, 3) << std::setfill('0') << std::setw(5)
                 << audio_mobile_serial_number << std::endl;
            track_number++;
            audio_mobile_serial_number++;
        } else if (products[product_number - 1].itemType == "VI") {
            if (visual_serial_number >= visual_mobile_serial_number) {
                visual_serial_number = visual_serial_number;
            } else {
                visual_serial_number = visual_mobile_serial_number;
            }
            file << track_number << ". " << products[product_number - 1].manufacturer << ", " <<
                 products[product_number - 1].name << ", " << products[product_number - 1].itemType << " Serial Number: "
                 <<
                 products[product_number - 1].manufacturer.substr(0, 3) << std::setfill('0') << std::setw(5)
                 << visual_serial_number << std::endl;
            track_number++;
            visual_serial_number++;
        } else if (products[product_number - 1].itemType == "VM") {
            if (visual_mobile_serial_number >= visual_serial_number) {
                visual_mobile_serial_number = visual_mobile_serial_number;
            } else {
                visual_mobile_serial_number = visual_serial_number;
            }
            file << track_number << ". " << products[product_number - 1].manufacturer << ", " <<
                 products[product_number - 1].name << ", " << products[product_number - 1].itemType << " Serial Number: "
                 <<
                 products[product_number - 1].manufacturer.substr(0, 3) << std::setfill('0') << std::setw(5)
                 << visual_mobile_serial_number << std::endl;
            track_number++;
            visual_mobile_serial_number++;
        }
        track_while_loop++;

    }
}

//Adding new items to the production list
/**
 * Add new items to the product line.
 * If the user or customer want to a new item to produce from this company
 * it can be done here.
 */
void add_new_products(std::vector<Product> &products) {

    std::string manufacturer;
    std::string product_name;
    std::string item_type_code;
    int item_type_choice;

    std::cout << "Enter the Manufacturer: \n";
    std::cin >> manufacturer;
    std::cout << "Enter the Product Name \n";
    std::cin >> product_name;

    std::cout << "Enter the Item Type: \n";
    std::cout << "1. Audio\n2. Visual\n3. AudioMobile\n4. VisualMobile\n";
    std::cin >> item_type_choice;

    if (item_type_choice == 1) {
        item_type_code = "MM";
    } else if (item_type_choice == 2) {
        item_type_code = "VI";
    } else if (item_type_choice == 3) {
        item_type_code = "AM";
    } else if (item_type_choice == 4) {
        item_type_code = "VM";
    }
    Product new_product;
    new_product.manufacturer = manufacturer;
    new_product.name = product_name;
    new_product.itemType = item_type_code;

    products.push_back(new_product);

}


/**
 * Enter employee's first and last name.
 * It generates username for that employee.
 * Employee can also enter password to keep track on his items.
 */
void set_employee_account() {

    std::ofstream employee_account_file;
    employee_account_file.open ("employee.txt", std::ios::app);

    std::cout << "Enter employee's full name \n ";

    std::string first_name;
    std::cin >> first_name;
    std::string last_name;
    std::cin >> last_name;
    std::string user_name;

    // create user name in proper format
    std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);
    std::transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);

    char get_first_name = first_name[0];
    user_name = get_first_name + last_name;

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
        std::cout << "Employee's account is set\n";
    } else {
        valid = false;
    }

    if (valid) {
        std::cout << "Employee's account is set\n";
    } else {
        std::cout << "invalid\n Enter the password again\n";
        std::cin >> password;

    }

    employee_account_file << first_name << ", " << last_name << "\t" << user_name << ", " << password << std::endl;
}

void display_production() {
    std::cout << "Production Track: \n";
    std::cout << "Audio: " << audio_serial_number << std::endl;
    std::cout << "Audio Mobile: " << audio_mobile_serial_number << std::endl;
    std::cout << "Visual: " << visual_serial_number << std::endl;
    std::cout << "Visual Mobile: " << visual_mobile_serial_number << std::endl;

}