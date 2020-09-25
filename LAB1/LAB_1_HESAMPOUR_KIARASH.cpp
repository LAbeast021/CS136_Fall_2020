//LAB 1 HESAMPOUR, KIARASH T TH

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>

using namespace std;

 struct Inventory_items{
        string itemID;
        string itemName;
        int itemQuantity;
        float itemPrice;
    };

void printInventory (Inventory_items [],int);
void searchInventoryByIDOrName (Inventory_items [],int);
void sortInventory (Inventory_items [] ,int, int);
void printReport (Inventory_items [],int);

int main (){
    
    int sizeOfInventory = 0, userChoice;
    Inventory_items inventory [10];

    ifstream inFile ;
    inFile.open("./dataFile.txt");
        if(!inFile.is_open()){
            cout << " An error occurd while opening the input file  . " << endl;
            return 1;
    };
    while (!inFile.fail() && !inFile.eof()) {
        Inventory_items tempItems;
        inFile >> tempItems.itemID >> tempItems.itemName >> tempItems.itemQuantity >> tempItems.itemPrice ;
        transform(tempItems.itemName.begin(), tempItems.itemName.end(), tempItems.itemName.begin(), ::toupper);
        if (tempItems.itemPrice < 0) tempItems.itemPrice = 0;
        if (tempItems.itemQuantity < 0) tempItems.itemQuantity = 0;
        inventory[sizeOfInventory] = tempItems;
        sizeOfInventory += 1;
    }
    inFile.close();


   while(userChoice !=8 ){
       cout 
            << "Please choose one of the following options : " << endl
            << "1) Print Inventory . " << endl
            << "2) Search item By ID or Name  . " << endl
            << "3) Sort items By ID . " << endl
            << "4) Sort items By Name . " << endl
            << "5) Sort items By Quantity . " << endl
            << "6) Sort items By Price . " << endl
            << "7) Print a Report of the inventory " << endl
            << "8) Exit the program . " << endl
            << "________________________________________________________________" << endl;
        cin >> userChoice;
        if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Input error, Please Try again." << endl;

        }
        while( userChoice < 1 || userChoice > 8){
            cout <<" Entered Option is not valid , Please try again :  "  << endl;
            cin >> userChoice;
        }
        cin.clear();
        cin.ignore();
       switch (userChoice){

       case 1://for case 1 print inventory
           printInventory(inventory,sizeOfInventory);
           break;
       case 2:
           //for input 2 search inventory by ID
           searchInventoryByIDOrName(inventory,sizeOfInventory);
           break;
        case 7:
            printReport(inventory, sizeOfInventory);
            break;
       case 8:
           cout << " Thank you ." << endl;
           break;
       default:
       sortInventory (inventory, sizeOfInventory , userChoice);
       break;
       }
   }
}
void printInventory (Inventory_items inventory[],int size){
    cout <<" --------------- Inventory --------------" <<endl;
    for(int i=0; i < size; i++){
       cout << inventory[i].itemID<<"\t"<< inventory[i].itemName <<"\t"<< inventory[i].itemQuantity <<"\t"<< inventory[i].itemPrice <<endl;
    }
   cout <<"_________________________________________________________" << endl;
};

void searchInventoryByIDOrName (Inventory_items inventory[],int size) {
   string enteredIDOrName;
   cout <<"Please enter the ID or the Name of the item you are looking for : ";
   cin >> enteredIDOrName;
   transform(enteredIDOrName.begin(), enteredIDOrName.end(), enteredIDOrName.begin(), ::toupper);
   for(int i = 0 ; i < size ; i++){
       if(inventory[i].itemID == enteredIDOrName || inventory[i].itemName == enteredIDOrName){
           cout << "----------------------------------------------------------------------" << endl;
           cout << " Result found for " << enteredIDOrName << " : " << endl;
           cout << inventory[i].itemID<<"\t"<<inventory[i].itemName<<"\t"<<inventory[i].itemQuantity<<"\t"<<inventory[i].itemPrice<<endl;
           cout << "----------------------------------------------------------------------" << endl;
       }
       return;
   }
   cout <<" item with id or name '" << enteredIDOrName << " Couldn’t be found ." << endl;

};
void sortInventory (Inventory_items inventory[],int size, int userChoice){
    Inventory_items tempInventory;
    int iteration, index;
    bool changePosition;
    for (iteration = 1; iteration < size; iteration++){
        for (index = 0; index < size - iteration; index++){
            switch(userChoice) {
                case 3 :
                changePosition = inventory[index].itemID > inventory[index+1].itemID;
                case 4 :
                changePosition = inventory[index].itemName > inventory[index+1].itemName;
                case 5 :
                changePosition = inventory[index].itemQuantity > inventory[index+1].itemQuantity;
                case 6 :
                changePosition = inventory[index].itemPrice > inventory[index+1].itemPrice;
            }
            if (changePosition) {
                tempInventory = inventory[index];
                inventory[index] = inventory[index + 1];
                inventory[index + 1] = tempInventory;
            }
        }    
    }

};
void printReport (Inventory_items inventory [] , int size){
    float totalWorth = 0;
    int totalCount = 0;
    for(int i=0; i < size; i++){
        totalWorth += inventory[i].itemPrice;
        totalCount += inventory[i].itemQuantity;
    }
    cout 
    << "\t\t ----------------- Report ------------------" << endl
    << " Number Of Unique Items in the Inventory : \t" << size << endl
    << " Total Worth Of the Inventory  : \t" << totalWorth << endl
    << " Total Count of the items in the inventory : \t" << totalCount << endl 
    << " ------------------------------------------------" << endl;
}