#include <iostream>
#include <string>
#include <sstream>
#include <codecvt>
#include <Windows.h>
#include "../MarketDataProcessor.h"

using namespace std;

string convertWStringToString(const wstring &wStr) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wStr);
}

double readDouble() {
    double value;
    string input;
    getline(cin >> ws, input);
    stringstream ss(input);
    if (!(ss >> value) || !ss.eof()) {
        cout << "Помилка: Будь ласка, введіть коректне число." << endl;
        return 0.0;
    }
    return value;
}

int readInt() {
    int value;
    string input;
    getline(cin >> ws, input);
    stringstream ss(input);
    if (!(ss >> value) || !ss.eof()) {
        cout << "Помилка: Будь ласка, введіть ціле число." << endl;
        return 0;
    }
    return value;
}

void MarketDataProcessor::addElementToTheEnd() {
    Product product;
    wstring wStr;

    UINT inputEncoding = GetConsoleCP();
    std::cout << "Кодування вводу: " << inputEncoding << std::endl;

    cout << "\n\t" << "Уведіть назву товару: ";
    getline(cin >> ws, product.name);

    cout << "\n\t" << "Уведіть ціну товару: ";
    product.price = readDouble();

    cout << "\n\t" << "Уведіть кількість спожитого товару за рік: ";
    product.consumedForYear = readInt();

    productsData.push_back(product);
    cout << "\nДоданий продукт:\nНазва: " << product.name << "\nЦіна: " << product.price
         << "\nКількість спожитого за рік: " << product.consumedForYear << endl;
}