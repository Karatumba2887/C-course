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
        cout << "�������: ���� �����, ������ �������� �����." << endl;
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
        cout << "�������: ���� �����, ������ ���� �����." << endl;
        return 0;
    }
    return value;
}

void MarketDataProcessor::addElementToTheEnd() {
    Product product;
    wstring wStr;

    UINT inputEncoding = GetConsoleCP();
    std::cout << "��������� �����: " << inputEncoding << std::endl;

    cout << "\n\t" << "������ ����� ������: ";
    getline(cin >> ws, product.name);

    cout << "\n\t" << "������ ���� ������: ";
    product.price = readDouble();

    cout << "\n\t" << "������ ������� ��������� ������ �� ��: ";
    product.consumedForYear = readInt();

    productsData.push_back(product);
    cout << "\n������� �������:\n�����: " << product.name << "\nֳ��: " << product.price
         << "\nʳ������ ��������� �� ��: " << product.consumedForYear << endl;
}