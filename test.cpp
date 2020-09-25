//LAB 1 HESAMPOUR, KIARASH T TH

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

//structure containing ID, name, quantity and price
typedef struct item{
   string ID;
   string name;
   string quantity;
   string price;
};

//swap two structures, this helps in bubble sort function
void swap(item *xp, item *yp)
{
   item temp = *xp;
   *xp = *yp;
   *yp = temp;
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
int main(){
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
       case 2
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

