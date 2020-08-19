

class SqrtX {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int min = 1;
        int max = x;
        while (min < max) {
            int result = avg(min, max);
            long pow = (long)result * result;
            if (pow > x) {
                max = result;
            } else if (pow < x) {
                min = result + 1;
            } else {
                return result;
            }
        }
        return min - 1;
    }

private:
    int avg(int a, int b) {
        return ((long)a + b) / 2;
    }
};