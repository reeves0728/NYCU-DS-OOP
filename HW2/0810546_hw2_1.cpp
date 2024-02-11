// C++ implementation of the approach
#include <iostream>
#include <vector>
using namespace std;

// Function to make array non-decreasing
bool checkPossibility(vector<int>& N) {
    for (int i = 1, err = 0; i < N.size(); i++)
        if (N[i] < N[i - 1])
            if (err++ || (i > 1 && i < N.size() - 1 && N[i - 2] > N[i] && N[i + 1] < N[i - 1]))
                return false;
    return true;
}

// Driver code
int main()
{
    int total;
    while (cin >> total) {
        vector<int> arr;
        for (int i = 0; i < total; i++) {
            int nums;
            cin >> nums;
            arr.push_back(nums);
        }

        if (checkPossibility(arr))
            cout << "true\n";
        else
            cout << "false\n";  
    }

    return 0;
}