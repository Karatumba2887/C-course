#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include "../MarketDataProcessor.h"
#include "../helpers/helpers.cpp"

using namespace std;
namespace fs = filesystem;

void MarketDataProcessor::getFromFile() {
    fs::path path = getPathToFiles();

    productsData.clear();

    for (const auto &entry: fs::directory_iterator(path)) {
        const string fileName = entry.path().string();

        bool isTxt = fileName.find(".txt") != string::npos;

        if (!isTxt) {
            continue;
        }

        string line;
        ifstream txtFile(fileName);

        if (!txtFile.is_open()) {
            cout << "Неможливо відкрити: " << fileName << endl;
            continue;
        }

        while (getline(txtFile, line)) {
            istringstream strStream(line);

            string name, priceStr, consumedStr;

            getline(strStream, name, ';');
            getline(strStream, priceStr, ';');
            getline(strStream, consumedStr, ';');

            if (name.empty() || priceStr.empty() || consumedStr.empty()) {
                continue;
            }

            try {
                Product newProduct = {name, stod(priceStr), stoi(consumedStr)};
                productsData.push_back(newProduct);
            } catch (...) {
                cout << "Помилка отримання продукту з файла" << endl;
                continue;
            }
        }

        txtFile.close();
    }
}
