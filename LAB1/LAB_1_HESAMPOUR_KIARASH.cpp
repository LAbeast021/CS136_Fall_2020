//LAB 1 HESAMPOUR, KIARASH T TH

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

//structure containing ID, name, quantity and price
typedef struct{
   string ID;
   string name;
   string quantity;
   string price;
}item;

//swap two structures, this helps in bubble sort function
void swap(item *xp, item *yp)
{
   item temp = *xp;
   *xp = *yp;
   *yp = temp;
}

//Searching By ID and if found print details else print not found
void searchByID(item inventory[100],int size){
   string ID;
   cout<<"Please give ID :";//taking ID from user
   cin>>ID;
   for(int i=0;i<size;i++){//looping through whole inventory
       if(inventory[i].ID==ID)//checking if ID matches, if yes print results and return
           cout<<inventory[i].ID<<"\t"<<inventory[i].name<<"\t"<<inventory[i].quantity<<"\t"<<inventory[i].price<<endl<<endl;
       return;
   }
   cout<<"ID not found.\n";
}

//sorting using bubble sort.
void sort(item inventory[100],int size,int sortBy){
   int i, j;
   bool condition;
   for (i = 0; i < size-1; i++) {
       for (j = 0; j < size-i-1; j++){
           //checking condition based in user selection
           if(sortBy==0){
               condition=inventory[j].ID > inventory[j+1].ID;
           }
           else if(sortBy==1){
               condition=inventory[j].name > inventory[j+1].name;
           }
           else if(sortBy==2){
               condition=inventory[j].quantity > inventory[j+1].quantity;
           }
           else if(sortBy==3){
               condition=inventory[j].price > inventory[j+1].price;
           }
           if (condition){ //if condition is true swap
               swap(&inventory[j], &inventory[j+1]);
           }
       }
   }
}

//reading file
void readFile(item inventory[100],int* size){
   ifstream file("inventory.txt");
   if (file.is_open()) {
       string line;
       //reading file line by line
       while (getline(file, line)) {
           size_t pos = 0;
           string token;
           item temp;
           pos = line.find(" ");//finding position of space
           token = line.substr(0, pos);//getting substring from start to space location
           temp.ID=token;//first is ID
           line.erase(0, pos + 1);//removing ID part from line
           //repeating process for name,price and quantity
           pos = line.find(" ");
           token = line.substr(0, pos);
           temp.name=token;
           line.erase(0, pos + 1);

           pos = line.find(" ");
           token = line.substr(0, pos);
           temp.quantity=token;
           line.erase(0, pos + 1);
           temp.price=line;
           inventory[*size]=temp;
           *size=*size+1;
       }
       file.close();
   }else{
       cout<<"Cannot open file.\n";
       EXIT_SUCCESS;
   }
}

//printing inventory
void printList(item inventory[100],int size){
   cout<<"\n=============================================\n";
   cout<<"=================Inventory===================\n";
   cout<<"=============================================\n";
   for(int i=0;i<size;i++){
       cout<<inventory[i].ID<<"\t"<<inventory[i].name<<"\t"<<inventory[i].quantity<<"\t"<<inventory[i].price<<endl;
   }
   cout<<"=============================================\n\n";
}

int showMenu(){
   //choice variable
   int choice=8;
   //showing Menu
   cout<<"Please choose :\n";
   cout<<"1) Print Inventory.\n";
   cout<<"2) Search By ID.\n";
   cout<<"3) Sort By ID.\n";
   cout<<"4) Sort By Name.\n";
   cout<<"5) Sort By Quantity.\n";
   cout<<"6) Sort By Price.\n";
   cout<<"7) Exit.\n";
   //taking choice
   cin>>choice;
   //take choice again for invalid input
   while(choice<1 || choice>7){
       cout<<"Please choose valid input: ";
       cin>>choice;
   }
   //clearing cin
   cin.clear();
   cin.ignore();
   return choice;
}
void main(){
   //array of structure item
   item inventory[100];
   int size=0;
   int choice=1;
   //reading file and storing in array
   readFile(inventory,&size);
   //continue untill user chooses to exit
   while(choice!=7){
       choice=showMenu();
       switch (choice)
       {
       case 1://for case 1 print inventory
           printList(inventory,size);
           break;
       case 2:
           //for input 2 search inventory by ID
           searchByID(inventory,size);
           break;
       case 3:
           //sort inventory by ID
           sort(inventory,size,0);
           break;
       case 4:
           // sort inventory by name
           sort(inventory,size,1);
           break;
       case 5:
           // sort inventory by quantity
           sort(inventory,size,2);
           break;
       case 6:
           // sort inventory by price
           sort(inventory,size,3);
           break;
       case 7:
           break;
       default:
           //printing message for invalid input
           cout<<"Invalid Input. Please try again.\n";
           break;
       }
   }
}

