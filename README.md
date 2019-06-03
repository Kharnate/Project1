# Project1
COP 2001 

Save records of production to a text file named "production.txt." 
Create a repl in repl.it.
Link: https://repl.it/@KARANPATEL3/Create-a-File-productiontxt

Add later:

void addNewProducts () {
    std::cout << "Enter the number of product you want to produce: \n";
    int numOfNewProduct;
    std::cin >> numOfNewProduct;
    for (int i = 0; i = numOfNewProduct; i ++){
        enterProductDetails ();
    }

}
void enterProductDetails (){
    std::cout << "Enter the Manufacturer: \n";
    std::cin >> manufacturer;
    std::cout << "Enter the Product Name \n";
    std::cin >> productName;

    std::cout << "Enter the Item Type: \n";
    std::cout << "1. Audio\n2. Visual\n3. AudioMobile\n4. VisualMobile";
    std::cin >> itemTypeChoice;


}
