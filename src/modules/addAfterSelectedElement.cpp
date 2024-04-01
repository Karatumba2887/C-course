#include <iostream>
#include "../MarketDataProcessor.h"
#include "../helpers/helpers.cpp"

using namespace std;

void MarketDataProcessor::addAfterSelectedElement(){
    cout << "\n\t" << "Напишіть індекс елементу після якого додати новий: ";
    int index = readInt();

    Product product;

    cout << "\n\t" << "Уведіть назву товару: ";
    getline(cin >> ws, product.name);

    cout << "\n\t" << "Уведіть ціну товару: ";
    product.price = readDouble();

    cout << "\n\t" << "Уведіть кількість спожитого товару за рік: ";
    product.consumedForYear = readInt();

    productsData.insert(productsData.begin() + index + 1, product);
    cout << "\n\tДоданий продукт:\n\tНазва: " << product.name << "\n\tЦіна: " << product.price
         << "\n\tКількість спожитого за рік: " << product.consumedForYear << endl;
};