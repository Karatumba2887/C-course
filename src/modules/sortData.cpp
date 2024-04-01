#include "iostream"
#include <algorithm> // Для std::min, std::max
#include <numeric>   // Для std::accumulate
#include "../MarketDataProcessor.h"

void MarketDataProcessor::sortData() {
    drawData();

    int size = static_cast<int>(productsData.size());

    // Находим минимальное значение
    double priceMin = std::min_element(productsData.begin(), productsData.end(),
                                       [](const Product& a, const Product& b) {
                                           return a.price < b.price;
                                       })->price;

    // Находим максимальное значение
    double priceMax = std::max_element(productsData.begin(), productsData.end(),
                                       [](const Product& a, const Product& b) {
                                           return a.price < b.price;
                                       })->price;

    // Находим среднее значение
    double sum = std::accumulate(productsData.begin(), productsData.end(), 0.0,
                                 [](double total, const Product& product) {
                                     return total + product.price;
                                 }); // Сумма всех элементов
    double priceAvg = sum / size;


    std::cout << "\n\t" << "Максимальна ціна: " << priceMax << std::endl;
    std::cout << "\n\t" << "Мінімальна ціна: " << priceMin << std::endl;
    std::cout << "\n\t" << "Середня ціна: " << priceAvg << std::endl;
};