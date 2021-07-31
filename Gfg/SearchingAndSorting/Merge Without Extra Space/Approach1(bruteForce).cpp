#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
// time complexity:o(n*m)
// space complexity:o(1)
class Solution
{
public:
	void merge(int arr1[], int arr2[], int n, int m)
	{
		int i = 0, j = 0;
		while (i < n && j < m)
		{
			if (arr1[i] > arr2[j])
			{
				swap(arr1[i], arr2[j]);
				i++;
				for (int k = 1; k < m; k++)
				{
					if (arr2[k] < arr2[k - 1])
						swap(arr2[k], arr2[k - 1]);
					else
						break;
				}
			}
			else
				i++;
		}
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, i;
		cin >> n >> m;
		int arr1[n], arr2[m];
		for (i = 0; i < n; i++)
		{
			cin >> arr1[i];
		}
		for (i = 0; i < m; i++)
		{
			cin >> arr2[i];
		}
		Solution ob;
		ob.merge(arr1, arr2, n, m);
		for (i = 0; i < n; i++)
		{
			cout << arr1[i] << " ";
		}
		for (i = 0; i < m; i++)
		{
			cout << arr2[i] << " ";
		}
		cout << "\n";
	}
	return 0;
} // } Driver Code Ends