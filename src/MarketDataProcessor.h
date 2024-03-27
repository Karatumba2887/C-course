#pragma once
#ifndef MARKETDATAPROCESSOR_H
#define MARKETDATAPROCESSOR_H

#include <vector>
#include <string>

class MarketDataProcessor {
public:
    struct Products
    {
        std::string name; // имя
        double price; // цена средняя на рынке
        long consumedForYear; // Кол во тон в год потреблено
    };
    std::vector<Products> productsData;

    MarketDataProcessor();
    void drawInterface();

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

private:
    void getFromFile();
};

#endif