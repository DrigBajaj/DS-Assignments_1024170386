#include <iostream>
#include <vector>
using namespace std;
vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }
    return res;
}
int main() {
    vector<int> arr;
	arr.push_back(6);
	arr.push_back(8);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(3);
    vector<int> res = nextLargerElement(arr);
    for (size_t i = 0; i < res.size(); i++)
	{
    cout << res[i] << " ";
	}
    return 0;
}
