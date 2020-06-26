#include <string>
#include <vector>

using namespace std;

class GenerateParentheses {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 1) {
            return {};
        }
        generateParenthesis(n * 2, "", 0);
        return result;
    }

private:
    void generateParenthesis(int total, const string& prefix, int not_closed) {
        if (prefix.length() == total) {
            result.push_back(prefix);
            return;
        }
        if (total - prefix.length() > not_closed) {
            string current = prefix;
            generateParenthesis(total, current.append("("), not_closed + 1);
        }
        if (not_closed > 0) {
            string current = prefix;
            generateParenthesis(total, current.append(")"), not_closed - 1);
        }
    }

    vector<string> result;
};