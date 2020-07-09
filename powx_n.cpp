#include <climits>
using namespace std;

class PowXN {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            unsigned int un;
            if (n == INT_MIN) {
                un = INT_MAX;
                un++;
            }  else {
                un = -n;
            }
            return 1.0 / myPowPositive(x, un);
        } else {
            return myPowPositive(x, n);
        }
    }

private:
    double myPowPositive(double x, unsigned int n) {
        if (n == 1) {
            return x;
        }
        double d = myPow(x, n / 2);
        return d * d * (n % 2 == 0 ? 1.0 : x);
    }
};