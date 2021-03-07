
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;

        while (true) {
            int request = start + ((end - start) / 2);
            int response = guess(request);
            if (response == 0) {
                return request;
            } else if (response < 0) {
                end = request - 1;
            } else {
                start = request + 1;
            }
        }
    }
};