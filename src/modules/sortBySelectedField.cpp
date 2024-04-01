#include "iostream"
#include "vector"
#include "../MarketDataProcessor.h"

using namespace std;

// Шейкерне сортування за споживанням
void cocktailSort(vector<MarketDataProcessor::Product>& arr) {
    bool swapped = true;
    int start = 0;
    size_t endSize = arr.size() - 1;
    int end = static_cast<int>(endSize);

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr[i].consumedForYear > arr[i + 1].consumedForYear) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        --end;

        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (arr[i].consumedForYear > arr[i + 1].consumedForYear) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

// Інтерполяційний пошук по Споживанню за рік
int interpolationSearch(vector<MarketDataProcessor::Product>& arr, int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= arr[low].consumedForYear && key <= arr[high].consumedForYear) {
        // Calculate the position using interpolation formula
        int pos = low + ((double)(high - low) / (arr[high].consumedForYear - arr[low].consumedForYear)) * (key - arr[low].consumedForYear);

        // If key is found
        if (arr[pos].consumedForYear == key) {
            return pos;
        }

        // If key is smaller, ignore right half
        if (arr[pos].consumedForYear > key)
            high = pos - 1;
            // If key is larger, ignore left half
        else
            low = pos + 1;
    }

    return -1; // Return -1 if key is not found
}

void MarketDataProcessor::sortBySelectedField()  {
    int searchKey;
    cout << "\n\t" << "Введіть ціле число для пошуку продукту за полем 'спожито за рік': " << endl;
    cout << "\t" << "Число - ";
    cin >> searchKey;
    cout << "\n";

    cocktailSort(productsData);

    size_t arrSizeT = productsData.size();
    int arrSize = static_cast<int>(arrSizeT);

    int pos = interpolationSearch(productsData, arrSize, searchKey);

    if (pos == -1) {
        cout << "\n\t" << "Элемент за цим пошуком не знайдено..." << endl;
    } else {
        cout << "\n\tЗнайдений продукт:\n\tНазва: " << productsData[pos].name << "\n\tЦіна: " << productsData[pos].price
             << "\n\tКількість спожитого за рік: " << productsData[pos].consumedForYear << endl;
    }

    cout << "\n\t" << "Відсортованний массив: " << endl;
    drawData();
}