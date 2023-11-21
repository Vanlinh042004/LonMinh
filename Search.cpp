#include"C++.h"
using namespace std;
int Binary_Search(int a[], int l, int r, int x) {
	if (l > r) return -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) return m;
		if (a[m] > x) r = m - 1;
		if (a[m] < x) l = m + 1;
	}
	return -1;
}
int Binary_Search1(int a[], int l, int r, int x) {
	if (l > r) return -1;
	int m = (l + r) / 2;
	if (a[m] == x) return m;
	if (a[m] > x) Binary_Search1(a, l, m - 1, x);
	if (a[m] < x) Binary_Search1(a, m + 1, r, x);
}
int First_Search(int a[], int l, int r, int x) {
	int res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			res = m;
			r = m - 1;
		}
		if (a[m] > x) r = m - 1;
		if (a[m] < x) l = m + 1;
	}
	return res;
}
int Last_Search(int a[], int l, int r, int x) {
	int res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			res = m;
			l = m + 1;
		}
		if (a[m] > x) r = m - 1;
		if (a[m] < x) l = m + 1;
	}
	return res;
}
// lower_bound(iter1, iter2, key)=> trả về vị trí đầu tiên >= key
// vector.begin(), vector.end()
// upper_bound(iter 1, iter2, key) => > key
void main() {
	int a[MAX];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << First_Search(a, 0, n - 1, 3) << endl;
	cout << Last_Search(a, 0, n - 1, 3);
}