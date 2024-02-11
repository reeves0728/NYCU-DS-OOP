#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define MAX_E 210

int arr[200010];
int frequency[MAX_E];

int calculateMedian(int d)
{
  int prefixSum = 0;
  for (int i = 0; i < MAX_E; i++)
  {
    prefixSum += frequency[i];
    if (prefixSum * 2 > d)
    {
      return 2 * i;
    }
    else if (prefixSum * 2 == d)
    {
      for (int j = i + 1;; j++)
      {
        if (frequency[j])
        {
          return i + j;
        }
      }
    }
  }
  return -1;
}

int main()
{
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int result = 0;
  for (int i = 0; i < n; i++)
  {
    if (i >= d)
    {
      if (arr[i] >= calculateMedian(d))
      {
        ++result;
      }
      frequency[arr[i - d]]--;
    }
    frequency[arr[i]]++;
  }
  cout << result << endl;
  return 0;
}
