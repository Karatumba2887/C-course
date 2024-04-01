#include <iostream>
#include <iomanip>
#include "../helpers/helpers.cpp"
#include "../MarketDataProcessor.h"

using namespace std;

string options[] = {
        "Вивести інформацію з текстового файлу",
        "Додати новий елемент в кінець масиву",
        "Переглянути всі елементи масиву",
        "Зберегти інформацію в текстовий файл",
        "Сортувати масиву за ціною (шейкерне сортування), та пошук елемента (інтерполяційний алгоритм)",
        "Додати новий елемент перед обраним",
        "Додати новий елемент після обраного",
        "Заміна обраного елемента",
        "Видалити елемент, починаючи від обраного",
        "Перегляд елементів і знаходження Max, Min та обчислення середнього по полю 'ціна'",
        "Закінчити виконання программи"
};

const int arrSize = sizeof(options) / sizeof(options[0]);

void MarketDataProcessor::drawInterface() {
    int iteration = 0;

    cout << "\n\n\t+" << setw(90 + 7) << setfill('-') << "|" << endl;

    for (const string &option: options) {
        ++iteration;

        if (iteration > 1) {
            cout << "\t|" << setw(90 + 6) << setfill('-') << "" << "|" << endl;
        }

        cout << "\t| " << iteration << "| " << option << endl;

        if (iteration == arrSize) {
            cout << "\t+" << setw(90 + 6) << setfill('-') << "" << "|" << endl;
        }
    }

    cout << "\n\tДля того щоб обрати дію, введіть цифру під якою знаходиться відповідна дія: \n" << endl;
}