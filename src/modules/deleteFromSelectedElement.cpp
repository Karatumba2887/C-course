#include <iostream>
#include "../MarketDataProcessor.h"
#include "../helpers/helpers.cpp"

using namespace std;

void MarketDataProcessor::deleteFromSelectedElement() {
    cout << "\n\t" << "�������� ������ �������� ��������� �� ����� ��������: ";
    int index = readInt();

    productsData.erase(productsData.begin() + index, productsData.end());

    Product product;

    cout << "\n\t" << "��������� �� �������� ���� �������� �� ��������: " << index << endl;
};
