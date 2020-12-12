//LAB 3 HESAMPOUR, KIARASH T TH

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
using namespace std;

// Defines class Address
class Address{
    // Data member to store address information
    string buildingNumber;
    string streetName;
    string city;
    public:
    // Default constructor to assign default values to data member
    Address()
    {
    buildingNumber = streetName = city = "";
    }

    // Default constructor to assign parameter values to data member
    Address(string bn, string sn, string ci)
    {
    buildingNumber = bn;
    streetName = sn;
    city = ci;
    }

    // Function to return building number
    string getBuildingNumber()
    {
    return buildingNumber;
    }

    // Function to return street name
    string getStreetName(){
        return streetName;
    }

    // Function to return city name
    string getCity(){
        return city;
    }

    // Function to display address
    void showAddress(){
        cout<<" "<<buildingNumber<<" "<<streetName<<" "<<city<<" ";
    }
};// End of class Address

// Defines class AddressBook
class AddressBook{
// Data member to store address book information
string firstName;
string lastName;
string phoneNumber;
Address addresses;

public:
// Default constructor to assign default values to data member
AddressBook(){
    firstName = lastName = phoneNumber = "";
}
// Default constructor to assign parameter values to data member
AddressBook(string fn, string ln, string ph, Address add){
    firstName = fn;
    lastName = ln;
    phoneNumber = ph;
    addresses = add;
}

// Function to change first name
void setFirstName(string fn){
    firstName = fn;
}

// Function to change last name
void setLastName(string ln){
    lastName = ln;
}
// Function to change address
void setAddress(Address add){
    addresses = add;
}

// Function to change phone number
void setPhoneNumber(string pn){
    phoneNumber = pn;
}

// Function to return first name
string getFirstName(){
    return firstName;
}

// Function to return last name
string getLastName(){
    return lastName;
}

// Function to return address
Address getAddress(){
    return addresses;
}

// Function to return phone number
string getPhoneNumber(){
    return phoneNumber;
}

// Function to display address book information
void showAddressBook(){
    cout<<firstName<<" "<<lastName<<" ";
    addresses.showAddress();
    cout<<phoneNumber<<endl<<endl;
}
};// End of class AddressBook

// Defines structure Node definition
struct Node{
    // Declares an object of class AddressBook
    AddressBook data;
    // Pointer to point to next node
    struct Node *next;

// Default constructor
    Node(){
        next = NULL;
    }

    // Parameterized constructor
    Node(AddressBook item){
    data = item;
    next = NULL;
}
}*first;// End of structure Node

// Defines class Record
class Record{
    public:
    // Prototype of functions
    bool isEmpty();
    void display();
    void addRecord(AddressBook);
    void removeRecord(string);

    bool contains(string);
    void searchRecord(string, int);
    int count();

    ~ Record();
    Record();
};// End of class

// Default constructor to create the first node
Record::Record(){
    first = new Node();
}

// Function to return true if list is empty otherwise returns false
bool Record::isEmpty(){
    return first->next == nullptr;
}

// Function to search a record based on parameter type
void Record::searchRecord(string data, int type){
// Creates a temporary node points to first node
Node* p = first->next;
// Initial found status is -1 for not found
int found = -1;

// Loops till end of the list
while (p != nullptr){
// Checks if type value is 1 then search first name
if(type == 1){
// Checks if current node first name is equals to parameter data
if(p->data.getFirstName().compare(data) == 0){
// Calls the function to display information
p->data.showAddressBook();
// Sets the found status to 1 for found
found = 1;
// Come out of the loop
break;
}
}
// Otherwise type value is 2 search phone number
else{
// Checks if current node phone number is equals to parameter data
if(p->data.getPhoneNumber().compare(data) == 0){
// Calls the function to display information
p->data.showAddressBook();
// Sets the found status to 1 for found
found = 1;
// Come out of the loop
break;
}
}
// Move to next node
p = p->next;
}

// Checks if found status is -1 then record not found
if(found == -1)
cout<<"\n\t Record "<<data<<" not found.";
}

// Function to display add the node information
void Record::display(){
// Creates a temporary node points to first node
Node* p = first->next;

cout<<"\n\n **************** Address Book information **************** \n";
// Loops till end of the list
while (p != nullptr){
// Calls the function to display information
p->data.showAddressBook();
// Move to next node
p = p->next;
}
cout << endl;
}

// Function to add parameter AddressBook object to list
void Record::addRecord(AddressBook item){
// Calls the function to check if parameter object item first name is not available in the list
if(!contains(item.getFirstName())){
// Create new node and put item into node
Node* newNode = new Node(item);
// Adds the parameter object at the beginning of the list
newNode->next = first->next;
// First node next points to new node
first->next = newNode;
}

// Otherwise record already available
else
cout<<"\n Duplicate record not allowed. Name: "<<item.getFirstName();
}

// Function to remove a node based on the parameter first name
void Record::removeRecord(string firstName){
// Creates a temporary node points to first node
Node* p = first->next;

int i, counter = 0, pos = 0;
// Checks if list is empty then display error message
if (p == nullptr){
cout<<"\n List is empty."<<endl;
return;
}

// Loops till end of the list
while (p != nullptr){
// Increase the position counter by one
pos++;
// Checks if current node first name is equals to parameter first name
if(p->data.getFirstName().compare(firstName) == 0)
// Come out of the loop
break;
// Mover to next node
p = p->next;
}

// Creates two temporary node points to first node
Node *s, *ptr;
// Points to first node
s = first;

// Checks if found position is 1 then first node to delete
if (pos == 1){
// First node points to next node
first = s->next;
}
// Otherwise not the first node
else{
// Stores number of nodes in the list
counter = count();
// Loops till found position
if (pos > 0 && pos <= counter){
// Points to first node
s = first;

// Loops till found position
for (i = 1; i < pos; i++){
// Points to previous node
ptr = s;
// Move to next node
s = s->next;
}
// previous node next points to current node next
ptr->next = s->next;
}
// Otherwise not found
else
cout<<"\n Record "<<firstName<<" not found."<<endl;
// Release the memory
free(s);
cout<<firstName<<" Deleted"<<endl;
}
}

// Destructor to destroy list
Record::~Record()
{
delete first;
}

// Function to return true if parameter first name is available in the list
// Otherwise return false
bool Record::contains(string fn)
{
// Creates a temporary node points to first node
Node* p = first->next;

// Loops till end of the list
while (p != nullptr){
// Checks if current node first name is equals to parameter first name
if(p->data.getFirstName().compare(fn) == 0)
// Returns true
return true;

// Move to next node
p = p->next;
}
// Returns false for not found
return false;
}

// Function to return number of nodes in the list
int Record::count()
{
int counter = 0;
// Creates a temporary node points to first node
Node* p = first->next;

// Loops till end of the list
while (p != nullptr){
// Increase the counter by one
counter++;
// Move to next node
p = p->next;
}
// Returns the counter
return counter;
}

// Function to read addresses from file and stores it in Record ll
// Returns the record by reference
void readFile(Record &ll)
{
string fn, ln, ph, bn, st, ci;
// ifstream class object declared to read data from file
ifstream fileRead;

// Opens both the file for reading
fileRead.open("AddressBook.txt");

// Checks if the file unable to open for reading display's error message and stop
if(!fileRead){
cout<<"\n ERROR: Unable to open the file for reading.";
exit(0);
}

// Loops till end of the file
while(!fileRead.eof()){
// Reads a record
fileRead>>fn>>ln>>bn>>st>>ci>>ph;
// Creates an object of AddressBook and calls the function to add it
ll.addRecord(AddressBook(fn, ln, ph, Address(bn, st, ci)));
}
cout<<"\n Number of records read from file: "<<ll.count();
// Closer the file
fileRead.close();
}

// Function to write list contents to file
void writeFile(){
// ofstream class object declared to write data from file
ofstream fileWrite;

// Opens both the file for reading
fileWrite.open("AddressBook.txt");

// Checks if the file unable to open for writing display's error message and stop
if(!fileWrite){
cout<<"\n ERROR: Unable to open the file for writing.";
exit(0);
}// End of if condition

// Creates a temporary node points to first node
Node* p = first->next;

// Loops till end of the list
while (p != nullptr){
// Writes the current node information
fileWrite<<p->data.getFirstName()<<" "<<p->data.getLastName()<<" "
<<p->data.getAddress().getBuildingNumber()<<" "<<p->data.getAddress().getStreetName()<<" "
<<p->data.getAddress().getCity()<<" "<<p->data.getPhoneNumber()<<endl;
// Move to next node
p = p->next;
}

// Closer the file
fileWrite.close();
}

// Function to accept address information, creates an object of AddressBook and returns it
AddressBook acceptData(){
    string fn, ln, ph, bn, st, ci;
    // Accepts data
    cout<<"\n Enter first name: ";
    cin>>fn;
    cout<<"\n Enter last name: ";
    cin>>ln;
    cout<<"\n Enter building number: ";
    cin>>bn;
    cout<<"\n Enter street: ";
    cin>>st;
    cout<<"\n Enter city name: ";
    cin>>ci;
    cout<<"\n Enter phone number: ";
    cin>>ph;

    // Creates an object using parameterized constructor
    AddressBook add(fn, ln, ph, Address(bn, st, ci));
    // Returns the object
    return add;
}

// Function to display menu, accept user choice and returns it
int menu(){
    int choice;
    // Displays menu
    cout<<"\n\n **************** Address Book Menu **************** ";
    cout<<"\n\t 1 - Add Address \n\t 2 - Delete Address \n\t 3 - Search Address "
    <<"\n\t 4 - Display all Addresses \n\t 5 - Number of addresses \n\t 6 - Exit \n\t\t What is your choice? ";
    // Accepts user choice
    cin>>choice;
    // Returns user choice
    return choice;
}
// main function definition
int main(){
string name, phone;
int type;
// Creates an object of class Record
Record ll;
// Calls the function to read file contents
readFile(ll);

// Loops till user choice is not 6
do{
// Calls the function to accept user choice
// calls appropriate function based on user choice
switch(menu())
{
case 1:
ll.addRecord(acceptData());
break;
case 2:
cout<<"\n Enter the first name to delete address: ";
cin>>name;
ll.removeRecord(name);
break;
case 3:
cout<<"\n 1 - Search based on first name \n 2 - Search based on phone number.";
cin>>type;
if(type == 1)
{
cout<<"\n Enter first name: ";
cin>>name;
ll.searchRecord(name, 1);
}
else if(type == 2)
{
cout<<"\n Enter phone number: ";
cin>>phone;
ll.searchRecord(phone, 2);
}
else
cout<<"\n Invalid type of search.";
break;
case 4:
ll.display();
break;
case 5:
cout<<"\n Number of Addresses: "<<ll.count();
break;
case 6:
cout<<"\n\t\t Thanks.";
writeFile();
exit(0);
default:
cout<<"\n Invalid Choice!!";
}
}while(1);
return 0;
}