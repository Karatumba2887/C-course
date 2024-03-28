#include <iostream>
#include <limits>
#include "../MarketDataProcessor.h"

using namespace std;

void MarketDataProcessor::choiceStep() {
    int choice;

    while (true) {
        cout << "\tВаш вибір - ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 10) {
            cout << "\n\tНеправильні дані. Введіть ціле число від 1 до 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cout << "\t";
    system("pause");
};