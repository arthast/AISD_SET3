#include <vector>
#include <iostream>

using namespace std;

const int COUNT = 15;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> result;
    int i = left, j = mid;
    while (i < mid && j < right) {
        if (arr[i] < arr[j]) {
            result.push_back(arr[i++]);
        } else {
            result.push_back(arr[j++]);
        }
    }

    while (i < mid) result.push_back(arr[i++]);
    while (j < right) result.push_back(arr[j++]);

    for (i = left; i < right; i++)
        arr[i] = result[i - left];
}

void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i < right; i++) {
        int j = i - 1;
        int tmp = arr[i];
        while (j >= left && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = tmp;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (right - left == 1)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, left, mid, right);
}

void hybridMergeSort(vector<int>& arr, int left, int right) {
    if (right - left <= COUNT) {
        insertionSort(arr, left, right);
        return;
    }
    int mid = (left + right) / 2;
    hybridMergeSort(arr, left, mid);
    hybridMergeSort(arr, mid, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    hybridMergeSort(a, 0, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
