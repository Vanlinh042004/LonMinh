#include "C++.h"
using namespace std;
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void Sort_Recursion(int a[], int n) {
	if (n == 1) return;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[n - 1]) swap(a[i], a[n - 1]); // đưa max về cuối O(n2)
	}
	Sort_Recursion(a, n - 1);
}
void Bubble(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); // đưa max về cuối O(n2)
		}
	}
}
void Selection(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) { // đưa min về đầu O(n2)
			if (a[j] < a[min]) min = j;
		}
		swap(a[i], a[min]);
	}
}
void Insert(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int x = a[i], pos = i - 1;
		while (pos >= 0 && x < a[pos]) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
#pragma region CoutingSort
int F(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) count++;
	}
	return count;
}
void Couting(int a[], int n) { // 0<a[i]<10^7
	int m = *max_element(a, a + n);
	int cnt[MAX];
	for (int i = 0; i < n; i++) {
		cnt[a[i]] = F(a, n, a[i]);
	}
	for (int j = 0; j <= m; j++) {
		if (cnt[j] != 0) {
			for (int i = 0; i < cnt[j]; i++) cout << j << ' ';
		}
	}

}
#pragma endregion
#pragma region Merge
void merge(int a[], int l, int m, int r) {
	vector<int> x(a + l, a + m);
	vector<int> y(a + m + 1, a + r);
	int i = 0, j = 0;
	while (i < x.size() && i < y.size()) {
		if (x[i] <= y[j]) {
			a[l] = x[i];
			++l; ++i;
		}
		else {
			a[l] = y[j];
			++l; ++j;
		}
	}
	while (i < x.size()) {
		a[l] = x[i];
		++l; ++i;
	}
	while (j < y.size()) {
		a[l] = y[j];
		++l; ++j;
	}
}
void Merge_Sort(int a[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	Merge_Sort(a, l, m);
	Merge_Sort(a, m + 1, r);
	merge(a, l, m, r);
}
#pragma endregion
#pragma region Quick
int Lomuto_Partition(int a[], int l, int r) {
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	i++;
	swap(a[i], a[r]);
	return i;
}
void QuickSort_Lomuto(int a[], int l, int r) {
	if (l >= r) return;
	int p = Lomuto_Partition(a, l, r);
	QuickSort_Lomuto(a, l, p - 1);
	QuickSort_Lomuto(a, p + 1, r);
}
int Hoare_Partition(int a[], int l, int r) {
	int pivot = a[l];
	int i = l - 1, j = r + 1;
	while (1) {
		do {
			++i;
		} while (a[i] < pivot);
		do {
			--j;
		} while (a[j] > pivot);
		if (i < j) swap(a[i], a[j]);
		else return j;
	}
}
void QuickSort_Hoare(int a[], int l, int r) {
	if (l >= r) return;
	int p = Hoare_Partition(a, l, r);
	QuickSort_Hoare(a, l, p);
	QuickSort_Hoare(a, p + 1, r);
}
#pragma endregion
#pragma region HeapSort
void Heapify(int a[], int n, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;
	if (l<n && a[l]>a[max]) {
		max = l;
	}
	if (r<n && a[r]>a[max]) {
		max = r;
	}
	if (max != i) {
		swap(a[max], a[i]);
		Heapify(a, n, max);
	}
}
void HeapSort(int a[], int n) {
	for (int i = (n / 2) - 1; i >= 0; i--) {
		Heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}
#pragma endregion
void RadixSort(int a[], int n) {
	int max = *max_element(a, a + n); // find max of array
	int digits = 0;
	while (max > 0) {	// find max number of digits
		digits++;
		max = max / 10;
	}
	int* a_temp[10];	// declare bucket
	for (int i = 0; i < 10; i++) {
		a_temp[i] = new int[n];
	}
	for (int i = 0; i < digits; i++) {
		int a_count[MAX] = { 0 };
		int exp = pow(10, i);
		for (int j = 0; j < n; j++) {
			int idx = (a[j] / exp) % 10;
			a_temp[idx][a_count[idx]++] = a[j];
		}
		int idx = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < a_count[j]; k++) {
				a[idx++] = a_temp[j][k];
			}
		}
	}
}
void main() {
	int a[MAX];
	int n = 0; cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
	}
	/*for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}*/
	cout << endl;
	RadixSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}

