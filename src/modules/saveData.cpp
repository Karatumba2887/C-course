#include <iostream>
#include <fstream>
#include <filesystem>
#include "../MarketDataProcessor.h"
#include "../helpers/helpers.cpp"

using namespace std;

namespace fs = filesystem;

void MarketDataProcessor::saveData() {
    fs::path filePath = getPathToFiles() / "products.txt";

    ofstream file(filePath, ios_base::out);

    if (file.is_open()) {

        for (const Product &product: productsData) {
            file << product.name << ";" << product.price << ";" << product.consumedForYear << ";" << "\n";
        }

        file.close();
    } else {
        cerr << "Не удалось открыть или создать файл для записи\n";
    }
};