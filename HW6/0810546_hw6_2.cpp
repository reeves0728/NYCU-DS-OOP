#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            bool rows[9] = {false};
            bool cols[9] = {false};
            bool blocks[9] = {false};
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != 'x')
                {
                    if (rows[board[i][j] - '1'])
                        return false;
                    rows[board[i][j] - '1'] = true;
                }
                if (board[j][i] != 'x')
                {
                    if (cols[board[j][i] - '1'])
                        return false;
                    cols[board[j][i] - '1'] = true;
                }

                if (board[((i / 3) * 3 + j / 3)][((i % 3) * 3) + j % 3] != 'x')
                {
                    if (blocks[board[((i / 3) * 3 + j / 3)][((i % 3) * 3) + j % 3] - '1'])
                        return false;
                    blocks[board[((i / 3) * 3 + j / 3)][((i % 3) * 3) + j % 3] - '1'] = true;
                }
            }
        }
        return true;
    }
};

int main()
{
    char temp;
    vector<char> tempBoard;
    vector<vector<char>> board;
    int tempcheck = 0;
    int check = 0;
    Solution solution;
    while (cin >> temp)
    {
        tempBoard.push_back(temp);
        tempcheck++;
        // cout << "tempcheck = " << tempcheck << endl;
        if (tempcheck == 9)
        {
            // cout << "in tempcheck ==9" << endl;
            board.push_back(tempBoard);
            check++;
            tempcheck = 0;
            tempBoard.clear();
        }
        if (check == 9)
        {

            bool isValid = solution.isValidSudoku(board);
            cout << (isValid ? "true" : "false") << endl;
            check = 0;
            board.clear();
        }
    }

    return 0;
}
