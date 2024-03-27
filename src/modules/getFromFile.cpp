#include <filesystem>
#include <iostream>
#include "../MarketDataProcessor.h"

using namespace std;
namespace fs = filesystem;

void MarketDataProcessor::getFromFile() {
    fs::path currentPath = fs::current_path();

    cout << "currentPath: " << currentPath << endl;

    currentPath /= "files";
    if (fs::exists(currentPath) && fs::is_directory(currentPath)) {
        cout << "Found 'data' directory at: " << currentPath << endl;
    } else {
        cout << "Failed to find 'data' directory." << endl;
    }
};
