#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<int>& arr, int l, int r) {
    sort(arr.begin() + l, arr.begin() + r + 1);
    return arr[l + (r - l) / 2];
}

int medianOfMedians(vector<int>& arr, int l, int r) {
    int n = r - l + 1;
    if (n <= 5) return findMedian(arr, l, r);
    vector<int> medians;
    for (int i = 0; i < n / 5; i++) {
        int subLeft = l + i * 5;
        int subRight = subLeft + 4;
        if (subRight > r) subRight = r;
        medians.push_back(findMedian(arr, subLeft, subRight));
    }
    return medianOfMedians(medians, 0, medians.size() - 1);
}

int partition(vector<int>& arr, int l, int r, int pivot) {
    int pivotIndex = find(arr.begin() + l, arr.begin() + r + 1, pivot) - arr.begin();
    swap(arr[pivotIndex], arr[r]);
    int store = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[store]);
            store++;
        }
    }
    swap(arr[store], arr[r]);
    return store;
}

int quickselect(vector<int>& arr, int l, int r, int k) {
    if (l == r) return arr[l];
    int pivot = medianOfMedians(arr, l, r);
    int pivotIndex = partition(arr, l, r, pivot);
    if (pivotIndex == k) return arr[pivotIndex];
    else if (k < pivotIndex)
        return quickselect(arr, l, pivotIndex - 1, k);
    else
        return quickselect(arr, pivotIndex + 1, r, k);
}

int main() {
    vector<int> arr = {10, 7, 9, 3, 5, 2, 7, 8, 9, 10};
    int n = arr.size();
    int k;
    cout << "Enter the value of k (0-indexed): ";
    cin >> k;
    int ans = quickselect(arr, 0, n - 1, k);
    cout << "The " << k + 1 << "-th smallest element is: " << ans << "\n";
    return 0;
}
