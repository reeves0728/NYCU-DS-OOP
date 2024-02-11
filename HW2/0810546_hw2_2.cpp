// CPP program to solve the given equation 
#include <iostream> 
#include <string>
using namespace std;

// Function to solve the given equation 
string solveEquation(string equation)
{
    int n = equation.size(), sign = 1, coeff = 0;
    int total = 0, i = 0;

    // Traverse the equation 
    for (int j = 0; j < n; j++) {
        if (equation[j] == '+' || equation[j] == '-') {
            if (j > i)
                total += sign * stoi(equation.substr(i, j - i));
            i = j;
        }

        // For cases such as: x, -x, +x 
        else if (equation[j] == 'x') {
            if ((i == j) || equation[j - 1] == '+')
                coeff += sign;
            else if (equation[j - 1] == '-')
                coeff -= sign;
            else
                coeff += sign * stoi(equation.substr(i, j - i));
            i = j + 1;
        }

        // Flip sign once '=' is seen 
        else if (equation[j] == '=') {
            if (j > i)
                total += sign * stoi(equation.substr(i, j - i));
            sign = -1;
            i = j + 1;
        }
    }

    // There may be a number left in the end 
    if (i < n)
        total += sign * stoi(equation.substr(i));

    // For infinite solutions 
    if (coeff == 0 && total == 0)
        return "IDENTITY";

    // For no solution 
    if (coeff == 0 && total)
        return "IMPOSSIBLE";

    // x = total sum / coeff of x 
    // '-' sign indicates moving 
    // numeric value to right hand side 
    int ans = -total / coeff;
    return to_string(ans);
}

// Driver code 
int main()
{
    int total;
    cin >> total;
    string* equation = new string[total];
    for (int i = 0; i < total; i++) {
        cin >> equation[i];
    }

    for (int i = 0; i < total; i++) {
        cout << solveEquation(equation[i]) << endl;;
    }

    return 0;
}
