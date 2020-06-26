#include <string>
#include <vector>

using namespace std;

class IntegerToRoman {
public:
    string intToRoman(int num) {
        string result;
        for (pair<int, string> value : values) {
            while (num >= value.first) {
                result.append(value.second);
                num -= value.first;
            }
        }
        return result;
    }
private:
    vector<pair<int, string>> values = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},
    };
};