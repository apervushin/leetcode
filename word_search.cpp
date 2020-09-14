#include <vector>
#include <string>
#include <stack>

using namespace std;

class WordSearch {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (exist(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool exist(vector<vector<char>> &board, string& word, int i, int j, int pos) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size()) {
            return false;
        }
        if (word[pos] != board[i][j]) {
            return false;
        }
        if (pos == word.size() - 1) {
            return true;
        }
        char tmp = board[i][j];
        board[i][j] = '-';
        bool result = exist(board, word, i - 1, j, pos + 1)
                || exist(board, word, i, j + 1, pos + 1)
                || exist(board, word, i + 1, j, pos + 1)
                || exist(board, word, i, j - 1, pos + 1);
        board[i][j] = tmp;
        return result;
    }
};