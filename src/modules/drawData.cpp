#include "iostream"
#include <iomanip>
#include <locale>
#include "../MarketDataProcessor.h"

using namespace std;

void MarketDataProcessor::drawData() {
    if (productsData.empty()) {
        cout << "\t����� ����, ������� �������� ��������!" << endl;
        return;
    }

    int iteration = 0;
    size_t arrSize = productsData.size();
    int arrLength = static_cast<int>(arrSize);

    cout << "\n" << endl;

    for (const Product &product: productsData) {
        ++iteration;

        if (iteration == 1) {
            cout << "\t|" << setw(30) << setfill('=') << left << "����� ��������" << "|" << setw(15) << left
                 << "ֳ��" << "|" << setw(15) << left << "���������� �� ��" << setw(6) << "" << "|" << endl;
        } else {
            cout << "\t+" << setw(70) << setfill('=') << "" << "+" << endl;
        }

        cout << "\t|" << setw(32) << setfill('-') << left << product.name << "|" << setw(15)
             << left << product.price << "|" << setw(15) << left << product.consumedForYear << setw(6) << "" << "|"
             << endl;

        if (iteration == arrLength) {
            cout << "\t+" << setw(70) << setfill('=') << "" << "+" << endl;
        }
    }
};