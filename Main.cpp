#include "mat.hpp"
#include <iostream>
using namespace std;

int main() {

    cout << "Welcome to the mat shop!" << endl;
    cout << "Here you can make custom mats." << endl;

    int row;
    cout << "Enter height of mat: ";
    cin >> row;
    cout << endl;

    int col;
    cout << "Enter width of mat: ";
    cin >> col;
    cout << endl;

    char symb1;
    cout << "Enter first char design: ";
    cin >> symb1;
    cout << endl;

    char symb2;
    cout << "Enter second char design: ";
    cin >> symb2;
    cout << endl;

    cout << "Making your custom mat..." << endl;
    try {
        cout << ariel::mat(col, row, symb1, symb2) << endl;
    }
    catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;
    }

    cout << endl << "Come back soon!" << endl;

    return 0;
}