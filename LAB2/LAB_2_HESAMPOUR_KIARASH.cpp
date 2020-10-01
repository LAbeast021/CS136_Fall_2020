//LAB 2 HESAMPOUR, KIARASH T TH

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
using namespace std;

double powerCalculator(int, int );
int sumOfSquaresFrom1(int, int );
int sumOfSquaresFromn(int );

int main(){
    double power_value;
    int base_number, exponent_number, user_choice, number_of_terms, total_square_value;
    char rep = 'Y';

    while ( rep != 'N') {
        cout 
        << "Please Enter the number of one of the options : " << endl
        << "1: Raise a number to a power . " << endl
        << "2: produce  the sum of the squares  for the first n terms of the series [staring with 1] i.e.,(1+ 2^2 + 3^3 +....n^n) " << endl
        << "3: add the first n terms of the series [starting with n] i.e.,(n^n + ... 3^3 + 2^2 +1)" << endl
        << "4: Quit the Program " << endl;

        cin >> user_choice;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input error, Please Try again." << endl;
        }    

        switch (user_choice){
            case 1:
                cout << "Please enter the base number : " << endl;
                cin  >> base_number;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Input error, Please Try again." << endl;
                    break;
                }
                cout << "Please enter the exponent number : " << endl;
                cin  >> exponent_number;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Input error, Please Try again." << endl;
                    break;
                }
                
                power_value = powerCalculator ( base_number, exponent_number);
                cout << base_number << " to the power of " << exponent_number << " = " << power_value << endl; 
                break;

            case 2:
                cout << "Please enter the number of terms : " << endl;
                cin  >> number_of_terms;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Input error, Please Try again." << endl;
                    break;
                } 
                while ( number_of_terms == 0 || number_of_terms < 0) {
                    cout << "Entered value cannot be 0 or negative, Please try again." << endl;
                    cin  >> number_of_terms;
                } 
                total_square_value = sumOfSquaresFrom1 (number_of_terms, 1);
                cout << total_square_value << endl; 
                break; 

            case 3: 
            cout << "Please enter the number of terms : " << endl;
                cin  >> number_of_terms;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Input error, Please Try again." << endl;
                    break;
                } 
                while ( number_of_terms == 0 || number_of_terms < 0) {
                    cout << "Entered value cannot be 0 or negative, Please try again." << endl;
                    cin  >> number_of_terms;
                } 
                total_square_value = sumOfSquaresFromn (number_of_terms);
                cout << total_square_value << endl; 
                break;

            case 4:
                cout <<  "Thank you " << endl;
                rep = 'N';
                break;     
        
            default:
                cout << "Entered option is invalid, Please try again : " << endl;
                break;
        }

        }
    }

double powerCalculator(int base_number, int exponent_number) {
    if ( exponent_number == 0) {
        return 1;
    }
    else if ( base_number == 0) {
        return 0;
    }
    else if (exponent_number > 0) {
        return base_number * powerCalculator(base_number ,exponent_number - 1);
    }
    else {
        return 1 / powerCalculator(base_number , -exponent_number);
    }
    
} 
int sumOfSquaresFrom1(int number_of_terms, int initial_value ) {
    if ( initial_value == number_of_terms ) {
        cout << "(" << initial_value << " * " << initial_value << ") = " ; 
        return initial_value * initial_value ;
    }
    cout << "(" << initial_value << " * " << initial_value << ") + " ;
    return initial_value * initial_value + sumOfSquaresFrom1 (number_of_terms , initial_value +1 );
} 
int sumOfSquaresFromn(int number_of_terms ) {
    if(number_of_terms > 1){
        cout << "(" << number_of_terms << " * " << number_of_terms << ") + ";
       return number_of_terms * number_of_terms + sumOfSquaresFromn(number_of_terms -1 );
    }    

   else if(number_of_terms == 1){
       cout << "(1 * 1) = " ;
       return 1;
   }
}
