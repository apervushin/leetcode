#include <vector>
#include <unordered_set>

using namespace std;

class ValidSudoku {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidHorizontal(board)
            && isValidVertical(board)
            && isValidSquares(board);
    }

private:
    unordered_set<char> state;

    bool isValidHorizontal(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            state.clear();
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                const auto &pair = state.insert(board[i][j]);
                if (!pair.second) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidVertical(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            state.clear();
            for (int j = 0; j < board[i].size(); j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                const auto &pair = state.insert(board[j][i]);
                if (!pair.second) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSquares(vector<vector<char>>& board) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                state.clear();
                for (int k = i * 3; k < (i + 1) * 3; k++) {
                    for (int l = j * 3; l < (j + 1) * 3; l++) {
                        if (board[k][l] == '.') {
                            continue;
                        }
                        const auto &pair = state.insert(board[k][l]);
                        if (!pair.second) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};