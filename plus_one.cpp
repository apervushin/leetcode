#include <vector>

using namespace std;

class PlusOne {
public:
    vector<int> plusOne(vector<int>& digits) {
        int next {1};
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + next;
            if (sum >= 10) {
                digits[i] = sum % 10;
                next = 1;
            } else {
                digits[i] = sum;
                next = 0;
                break;
            }
        }

        if (next != 0) {
            digits.insert(digits.begin(), next);
        }

        return digits;
    }
};