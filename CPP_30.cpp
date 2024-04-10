#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> findTriplets (vector<int> arr, int n, int K) {
	
	vector<vector<int>> ans;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			for (int k = j + 1; j < n; k++) {

				if (arr[i] + arr[j] + arr[k] == K) {

					vector<int> temp;
					temp.push_back(arr[i]);
					temp.push_back(arr[j]);
					temp.push_back(arr[k]);
					ans.push_back(temp);
				}
			}
		}
	}

	if (ans.empty()) {

		vector<int> temp;
		temp.push_back(-1);
		ans.push_back(temp);
		return ans;

	} else {

		return ans;
	}
}

int main() {

    vector<int> arr;

    int n;

    cout << "Size : ";
    cin >> n;

    int K;

    cout << "K : ";
    cin >> K;

    int a;

    cout << "Array : ";

    for (int i = 0; i < n; i++) {

        cin >> a;
        arr.push_back(a);

    }

    vector<vector<int>> ans = findTriplets (arr, n, K);

    cout << ans.size();

    for (int i = 0; i < ans.size(); i++) {

        cout << "Triplets : ";

        for (int j = 0; j < 3; j++) {

            cout << ans[i][j] << " ";
        }
    }
}