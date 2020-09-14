#include <vector>

using namespace std;

class GasStation {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int start_pos = 0;
        int diff = 0;

        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                diff += sum;
                start_pos = i + 1;
                sum = 0;
            }
        }

        return sum + diff >= 0 ? start_pos : -1;
    }
};