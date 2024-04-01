#include "../helpers/helpers.cpp"
#include "../MarketDataProcessor.h"

void MarketDataProcessor::showData() {
    getFromFile();
    drawData();
}