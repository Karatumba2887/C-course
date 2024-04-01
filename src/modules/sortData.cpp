#include "iostream"
#include <algorithm> // ��� std::min, std::max
#include <numeric>   // ��� std::accumulate
#include "../MarketDataProcessor.h"

void MarketDataProcessor::sortData() {
    drawData();

    int size = static_cast<int>(productsData.size());

    // ������� ����������� ��������
    double priceMin = std::min_element(productsData.begin(), productsData.end(),
                                       [](const Product& a, const Product& b) {
                                           return a.price < b.price;
                                       })->price;

    // ������� ������������ ��������
    double priceMax = std::max_element(productsData.begin(), productsData.end(),
                                       [](const Product& a, const Product& b) {
                                           return a.price < b.price;
                                       })->price;

    // ������� ������� ��������
    double sum = std::accumulate(productsData.begin(), productsData.end(), 0.0,
                                 [](double total, const Product& product) {
                                     return total + product.price;
                                 }); // ����� ���� ���������
    double priceAvg = sum / size;


    std::cout << "\n\t" << "����������� ����: " << priceMax << std::endl;
    std::cout << "\n\t" << "̳������� ����: " << priceMin << std::endl;
    std::cout << "\n\t" << "������� ����: " << priceAvg << std::endl;
};