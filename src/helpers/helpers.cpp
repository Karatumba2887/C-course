#include <iostream>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

inline fs::path getPathToFiles() {
    fs::path path = fs::current_path();
    path /= "files";

    if (!(fs::exists(path) && fs::is_directory(path))) {
        if (!fs::create_directory(path)) {
            std::cerr << "Не вдалося знайти каталог 'files'" << std::endl;
            return fs::path(); // NOLINT(*-return-braced-init-list)
        }
        std::cout << "Каталог 'files' успішно створено." << std::endl;
    }

    return path;
}

using namespace std;

inline double readDouble() {
    double value;
    string input;
    getline(cin >> ws, input);
    stringstream ss(input);
    if (!(ss >> value) || !ss.eof()) {
        cout << "Помилка: Будь ласка, введіть коректне число." << endl;
        return 0.0;
    }
    return value;
}

inline int readInt() {
    int value;
    string input;
    getline(cin >> ws, input);
    stringstream ss(input);
    if (!(ss >> value) || !ss.eof()) {
        cout << "Помилка: Будь ласка, введіть ціле число." << endl;
        return 0;
    }
    return value;
}