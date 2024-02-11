#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstdlib>


using namespace std;

const int N = 55;

typedef long long LL;

int n;
LL root[N];

bool input()
{
	if (scanf("%d", &n) != 1) return false;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &root[i]);
	}
	return true;
}

void solve()
{
	vector<LL> v1, v2;
	v1.push_back(1); v1.push_back(-root[0]);

	for (int i = 1; i < n; i++) {
		v2 = v1;
		v1.push_back(0);
		for (int j = 0; j < v2.size(); j++) {
			v2[j] *= -root[i];
		}

		for (int j = 0; j < v2.size(); j++) {
			v1[j + 1] += v2[j];
		}
	}

	int size = v1.size();
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			if (v1[i] != 0) {
				if (i != 0) {
					if (v1[i] > 0) printf(" + ");
					else printf(" - ");

					if (llabs(v1[i]) != 1) printf("%lld", llabs(v1[i]));
				}

				if (i == size - 2) printf("x");
				else printf("x^%d", size - 1 - i);
			}
		}
		else {
			if (v1[i] >= 0) printf(" + ");
			else printf(" - ");
			printf("%lld = 0\n", llabs(v1[i]));
		}
	}
}

int main()
{


	while (input()) {
		solve();
	}
	return 0;
}