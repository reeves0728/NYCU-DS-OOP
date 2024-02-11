#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::vector<std::string> findRepeatedSequences(const std::string &s)
{
    std::unordered_map<std::string, int> sequenceCount;
    std::vector<std::string> result;

    if (s.length() < 10)
    {
        return result; // Return empty result if the string is less than 10 characters long
    }

    for (int i = 0; i <= s.length() - 10; ++i)
    {
        std::string sequence = s.substr(i, 10);
        ++sequenceCount[sequence];

        if (sequenceCount[sequence] == 2)
        {
            result.push_back(sequence);
        }
    }

    return result;
}

int main()
{
    std::string s;
    while (std::cin >> s)
    {
        std::vector<std::string> repeatedSequences = findRepeatedSequences(s);

        if (repeatedSequences.empty())
        {
            std::cout << "none\n";
        }
        else
        {
            std::sort(repeatedSequences.begin(), repeatedSequences.end());

            for (const std::string &sequence : repeatedSequences)
            {
                std::cout << sequence << '\n';
            }
        }
    }

    return 0;
}
