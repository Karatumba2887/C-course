#include <iostream>
#include "../MarketDataProcessor.h"
#include "../helpers/helpers.cpp"

using namespace std;

void MarketDataProcessor::addElementToTheEnd() {
    Product product;

    cout << "\n\t" << "������ ����� ������: ";
    getline(cin >> ws, product.name);

    cout << "\n\t" << "������ ���� ������: ";
    product.price = readDouble();

    cout << "\n\t" << "������ ������� ��������� ������ �� ��: ";
    product.consumedForYear = readInt();

    productsData.push_back(product);
    cout << "\n\t������� �������:\n\t�����: " << product.name << "\n\tֳ��: " << product.price
         << "\n\tʳ������ ��������� �� ��: " << product.consumedForYear << endl;
}