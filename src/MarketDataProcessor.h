#pragma once
#ifndef MARKETDATAPROCESSOR_H
#define MARKETDATAPROCESSOR_H

#include <vector>
#include <string>

using namespace std;
// Описание структуры класса
class MarketDataProcessor {
public:
    MarketDataProcessor();
    void start();

    struct Product {
        string name;
        double price;
        int consumedForYear;
    };

    vector<Product> productsData;

     void drawInterface();
     void choiceStep(bool &programAlive);
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