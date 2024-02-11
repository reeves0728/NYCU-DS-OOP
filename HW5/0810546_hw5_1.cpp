#include <cstdio>

void merge(int L, int R, int *M, int *T, long long int &count)
{
	int Lptr, Rptr, mid, ptr = L;
	Lptr = L, mid = (L + R) / 2, Rptr = mid + 1;
	for (int i = L; i <= R; i++)
		T[i] = M[i];
	while (Lptr <= mid && Rptr <= R)
	{
		if (T[Lptr] > T[Rptr])
			M[ptr++] = T[Rptr++], count += mid - Lptr + 1;
		else
			M[ptr++] = T[Lptr++];
	}
	while (Lptr <= mid)
		M[ptr++] = T[Lptr++];
	while (Rptr <= R)
		M[ptr++] = T[Rptr++];
}

void mergeSort(int L, int R, int *M, int *T, long long int &count)
{
	if (R > L)
	{
		int mid = (L + R) / 2;
		mergeSort(L, mid, M, T, count);
		mergeSort(mid + 1, R, M, T, count);
		merge(L, R, M, T, count);
	}
}

int main()
{
	int M[500000];
	int T[500000];
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", M + i);
		long long int count = 0;
		mergeSort(0, n - 1, M, T, count);
		printf("%lld\n", count);
	}
	return 0;
}