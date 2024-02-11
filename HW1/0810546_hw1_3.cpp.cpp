#include <iostream>
#include <string>
using namespace std;

int main()
{
	int in1, in2, x, y, i, t;
	string act, f;

	cin >> in1 >> in2;
	int sc[in1 + 1][in2 + 1] = {0};
	while (cin >> x >> y >> f >> act)
	{
		for (i = 0; i < act.length(); i++)
		{
			string a;
			a = act[i];
			int s = sc[x][y];

			if ((y < 0 || y > in2) || (x < 0 || x > in1))
			{
				break;
			}

			if (a == "R")
			{
				if (f == "E")
				{
					f = "S";
				}
				else if (f == "W")
				{
					f = "N";
				}
				else if (f == "N")
				{
					f = "E";
				}
				else if (f == "S")
				{
					f = "W";
				}
			}

			else if (a == "F")
			{
				if (f == "E" && (s != 1 || x + 1 <= in1))
				{
					x += 1;
				}
				else if (f == "S" && (s != 1 || y - 1 > 0))
				{
					y -= 1;
				}

				else if (f == "N" && (s != 1 || y + 1 <= in2))
				{
					y += 1;
				}
				else if (f == "W" && (s != 1 || x - 1 > 0))
				{
					x -= 1;
				}
			}
			else if (a == "L")
			{
				if (f == "E")
				{
					f = "N";
				}
				else if (f == "W")
				{
					f = "S";
				}
				else if (f == "S")
				{
					f = "E";
				}

				else if (f == "N")
				{
					f = "W";
				}
			}
		}

		if (x < 0)
		{
			cout << x + 1 << " " << y << " " << f << " LOST" << endl;
			sc[x + 1][y] = 1;
		}
		else if (y > in2)
		{
			cout << x << " " << y - 1 << " " << f << " LOST" << endl;
			sc[x][y - 1] = 1;
		}
		else if (y < 0)
		{
			cout << x << " " << y + 1 << " " << f << " LOST" << endl;
			sc[x][y + 1] = 1;
		}
		else if (x > in1)
		{
			cout << x - 1 << " " << y << " " << f << " LOST" << endl;
			sc[x - 1][y] = 1;
		}

		else
		{
			cout << x << " " << y << " " << f << endl;
		}
	}
	return 0;
}
