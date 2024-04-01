#include <iostream>
#include "../MarketDataProcessor.h"
#include "../helpers/helpers.cpp"

using namespace std;

void MarketDataProcessor::addAfterSelectedElement(){
    cout << "\n\t" << "�������� ������ �������� ���� ����� ������ �����: ";
    int index = readInt();

    Product product;

    cout << "\n\t" << "������ ����� ������: ";
    getline(cin >> ws, product.name);

    cout << "\n\t" << "������ ���� ������: ";
    product.price = readDouble();

    cout << "\n\t" << "������ ������� ��������� ������ �� ��: ";
    product.consumedForYear = readInt();

    productsData.insert(productsData.begin() + index + 1, product);
    cout << "\n\t������� �������:\n\t�����: " << product.name << "\n\tֳ��: " << product.price
         << "\n\tʳ������ ��������� �� ��: " << product.consumedForYear << endl;
};