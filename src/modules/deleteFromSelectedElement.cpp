#include <iostream>
#include "../MarketDataProcessor.h"
#include "../helpers/helpers.cpp"

using namespace std;

void MarketDataProcessor::deleteFromSelectedElement() {
    cout << "\n\t" << "Напишіть індекс елементу починаючи від якого видаляти: ";
    int index = readInt();

    productsData.erase(productsData.begin() + index, productsData.end());

    Product product;

    cout << "\n\t" << "Видаленно усі елементи післе елементу під індексом: " << index << endl;
};
