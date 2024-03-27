#include "iostream"
#include <iomanip>
#include <locale>
#include <codecvt>
#include "../MarketDataProcessor.h"

using namespace std;

string options[] = {
        "Ввести інформацію про овочі і фрукти",
        "Додати елемент в кінець списку",
        "Переглянути всю інформацію",
        "Додати інформацію в текстовий файл",
        "Сортувати продукти за ціною",
        "Додати новий елемент перед обраним",
        "Додати новий елемент після обраного",
        "Змінити обраний елемент",
        "Видалити елемент, починаючи від обраного",
        "Визначення якого продукту продано біше всіх та меньше всіх та того що знаходится по середині."
};

wstring convertStringToWstring(string str) {
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
    wstring wide_str = converter.from_bytes(str);
    return wide_str;
}

int findLongestStringLengthInArray(const string strings[], int arrSize) {
    int maxLength = 0;

    for (int i = 0; i < arrSize; ++i) {
        const wstring converted = convertStringToWstring(strings[i]);
        int charLength = converted.size();

        if (charLength > maxLength) {
            maxLength = charLength;
        }
    }

    return maxLength;
}

const int arrSize = sizeof(options) / sizeof(options[0]);
const int longestStrLength = findLongestStringLengthInArray(options, arrSize);

void MarketDataProcessor::drawInterface() {
    int iteration = 0;

    cout << setw(longestStrLength+6) << setfill('-') << "|" << endl;

    for (const string& option : options) {
        ++iteration;
        if (iteration > 1) {
            cout << setw(longestStrLength+6) << setfill('-') << "|" << endl;
        }
        cout <<"| " << iteration << "| " << setw(longestStrLength) << option << " |" << endl;
    }
}