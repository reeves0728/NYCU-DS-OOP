#include <iostream>
using namespace std;

int main()
{
	int i, j;
	while (cin >> i >> j)
	{
		int count, ans = 0, temp;

		cout << i << " " << j << " "; 

		if (j < i)
		{
			temp = i;
			i = j;
			j = temp;

		}

		for (int t = i; t <= j; t++)
		{
			int k = t;
			count = 1;
			

			while (k > 1)
			{
				if (k % 2 == 0)
				{
					k = k / 2;
					count = count + 1;
				}
				else
				{
					k = 3 * k + 1;
					count = count + 1;
				}
			}

			if (count > ans)
			{
				ans = count;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}

