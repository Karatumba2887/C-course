#include <iostream>
#include <limits>
#include "../MarketDataProcessor.h"

using namespace std;

void MarketDataProcessor::choiceStep(bool &programAlive) {
    int choice;

    while (true) {
        cout << "\tВаш вибір - ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 11) {
            cout << "\n\tНеправильні дані. Введіть ціле число від 1 до 11." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    system("cls");

    switch (choice) {
        case 1:
            this->showData();
            break;
        case 2:
            this->addElementToTheEnd();
            break;
        case 3:
            this->drawData();
            break;
        case 4:
            this->saveData();
            break;
        case 5:
            this->sortBySelectedField();
            break;
        case 6:
            this->addBeforeSelectedElement();
            break;
        case 7:
            this->addAfterSelectedElement();
            break;
        case 8:
            this->replaceSelectedElement();
            break;
        case 9:
            this->deleteFromSelectedElement();
            break;
        case 10:
            // sort avg min max by field
            this->sortData();
            break;
        case 11:
            programAlive = false;
            break;
        default:
            cout << "Критична помилка!" << endl;
            programAlive = false;
            system("pause");
            break;
    }
    cout << "\t";
    cout << "Натисніть будь яку клавішу для продовження роботи програми..." << endl;
    cout << "\t";
    system("pause");
    system("cls");
}