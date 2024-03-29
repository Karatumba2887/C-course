#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include "../MarketDataProcessor.h"

using namespace std;
namespace fs = filesystem;

void MarketDataProcessor::getFromFile() {
    fs::path path = fs::current_path();
    path /= "files";

    if (!(fs::exists(path) && fs::is_directory(path))) {
        cout << "Не вдалося знайти каталог 'files'." << endl;
        // TODO: add create file and folder logic
        return;
    }

    productsData.clear();

    for (const auto &entry: fs::directory_iterator(path)) {
        const string fileName = entry.path().string();

        bool isTxt = fileName.find(".txt") != string::npos;

        if (!isTxt) {
            continue;
        }

        string line;
        ifstream txtfile(fileName);

        if (!txtfile.is_open()) {
            cout << "Неможливо відкрити: " << fileName << endl;
            continue;
        }

        while (getline(txtfile, line)) {
            istringstream strStream(line);

            string name, priceStr, consumedStr;

            getline(strStream, name, ';');
            getline(strStream, priceStr, ';');
            getline(strStream, consumedStr, ';');

            if (name.empty() || priceStr.empty() || consumedStr.empty()) {
                continue;
            }

            try {
                Products newProduct = {name, stod(priceStr), stoi(consumedStr)};
                productsData.push_back(newProduct);
            } catch (...) {
                cout << "Помилка отримання продукту з файла" << endl;
                continue;
            }
        }

        txtfile.close();
    }
};
