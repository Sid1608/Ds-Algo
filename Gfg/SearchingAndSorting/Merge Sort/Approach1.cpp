#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

class Solution
{
public:
	void merge(int arr[], int l, int mid, int r)
	{
		int n = mid - l + 1;
		int m = r - mid;
		int a[n], b[m];
		for (int i = 0; i < n; i++)
			a[i] = arr[l + i];
		for (int i = 0; i < m; i++)
			b[i] = arr[mid + 1 + i];
		int i = 0, j = 0, k = l;
		while (i < n && j < m)
		{
			if (a[i] <= b[j])
			{
				arr[k++] = a[i++];
			}
			else
			{
				arr[k++] = b[j++];
			}
		}
		for (; i < n; i++)
			arr[k++] = a[i];
		for (; j < m; j++)
			arr[k++] = b[j];
	}

public:
	void mergeSort(int arr[], int l, int r)
	{
		if (l < r)
		{
			int mid = (l + r) / 2;
			mergeSort(arr, l, mid);
			mergeSort(arr, mid + 1, r);
			merge(arr, l, mid, r);
		}
	}
};

int main()
{
	int n, T, i;

	scanf("%d", &T);

	while (T--)
	{

		scanf("%d", &n);
		int arr[n + 1];
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		Solution ob;
		ob.mergeSort(arr, 0, n - 1);
		printArray(arr, n);
	}
	return 0;
}