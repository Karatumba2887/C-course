#include "iostream"
#include <iomanip>
#include <locale>
#include "../helpers/helpers.cpp"
#include "../MarketDataProcessor.h"

using namespace std;

void MarketDataProcessor::showData() {
    // Сохраняем текущую глобальную локаль
    locale currentLocale = locale();

    locale::global(locale(""));

    if (productsData.empty()) {
        getFromFile();
        // Second check after getFromFile() if not products in files
        if (productsData.empty()) {
            cout << "Empty files" << endl;
            return;
        }
    }

    int iteration = 0;
    size_t arrSize = productsData.size();
    int arrLength = static_cast<int>(arrSize);

    cout << "\n" << endl;
    wcout.imbue(locale());

    for (const Product &product: productsData) {
        ++iteration;

        if (iteration == 1) {
            wcout << L"\t|" << setw(30) << setfill(L'=') << left << L"Назва продукту" << L"|" << setw(15) << left
                  << L"Ціна" << L"|" << setw(15) << left << L"Споживання за рік" << setw(6) << L"" << L"|" << endl;
        } else {
            wcout << L"\t+" << setw(70) << setfill(L'=') << L"" << L"+" << endl;
        }

        wcout << L"\t|" << setw(32) << setfill(L'-') << left << convertStringToWstring(product.name) << L"|" << setw(15)
              << left << product.price << L"|" << setw(15) << left << product.consumedForYear << setw(6) << L"" << L"|"
              << endl;

        if (iteration == arrLength) {
            wcout << L"\t+" << setw(70) << setfill(L'=') << L"" << L"+" << endl;
        }
    }

    // Восстанавливаем исходную глобальную локаль
    locale::global(currentLocale);
    // Сбрасываем локализацию для wcout
    wcout.imbue(currentLocale);

    cout << "\t";
    cout << "Натисніть будь яку клавішу для продовження роботи програми..." << endl;
    cout << "\t";
    system("pause");
    system("cls");
}