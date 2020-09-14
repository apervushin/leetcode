#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LargestNumber {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        vector<string> nums_s;
        for (int i : nums) {
            nums_s.push_back(to_string(i));
        }

        sort(nums_s.begin(), nums_s.end(), [](const string& s1, const string& s2) -> bool {
            return s1 + s2 > s2 + s1;
        });

        bool none_zero_presented = false;
        for (string s : nums_s) {
            if (!none_zero_presented && s != "0") {
                none_zero_presented = true;
            }
            if (none_zero_presented || s!= "0") {
                result.append(s);
            }
        }
        if (result.empty()) {
            result = "0";
        }
        return result;
    }
};