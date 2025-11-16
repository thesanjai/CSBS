#include <bits/stdc++.h>
using namespace std;

bool flag = 0;
void PrintSubsetSum(int i, int n, int set[], int targetSum,
					vector<int>& subset)
{
	if (targetSum == 0) {

		flag = 1;
		cout << "[ ";
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i] << " ";
		}
		cout << "]";
		return;
	}

	if (i == n) {
		return;
	}

	PrintSubsetSum(i + 1, n, set, targetSum, subset);

	if (set[i] <= targetSum) {

		subset.push_back(set[i]);

		PrintSubsetSum(i + 1, n, set, targetSum - set[i],
					subset);

		subset.pop_back();
	}
}

int main()
{
	int set[] = { 1, 2, 1 };
	int sum = 3;
	int n = sizeof(set) / sizeof(set[0]);
	vector<int> subset;
	cout << "Output 1:" << endl;
	PrintSubsetSum(0, n, set, sum, subset);
	cout << endl;
	flag = 0;

	int set2[] = { 3, 34, 4, 12, 5, 2 };
	int sum2 = 30;
	int n2 = sizeof(set) / sizeof(set[0]);
	vector<int> subset2;
	cout << "Output 2:" << endl;
	PrintSubsetSum(0, n2, set2, sum2, subset2);
	if (!flag) {
		cout << "There is no such subset";
	}

	return 0;
}

