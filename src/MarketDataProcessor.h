#pragma once
#ifndef MARKETDATAPROCESSOR_H
#define MARKETDATAPROCESSOR_H

#include <vector>
#include <string>

using namespace std;

class MarketDataProcessor {
public:
    struct Products
    {
        string name;
        double price;
        int consumedForYear;
    };

    vector<Products> productsData;

    MarketDataProcessor();
    static void drawInterface();
    void choiceStep();

    void drawData();
    void addElementToTheEnd();
    void showData();
    void saveData();
    void sortData();
    void addBeforeSelectedElement();
    void addAfterSelectedElement();
    void replaceSelectedElement();
    void deleteFromSelectedElement();
    void sortBySelectedField();

    void getFromFile();
};

#endif