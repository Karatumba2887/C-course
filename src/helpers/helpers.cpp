#include <codecvt>
#include <iomanip>
#include <string>

using namespace std;

inline wstring convertStringToWstring(const string& str) {
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
    wstring wide_str = converter.from_bytes(str);
    return wide_str;
}