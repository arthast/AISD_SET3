#include <vector>
#include <iostream>
#include <cmath>
#include <random>

using namespace std;

mt19937 rng(random_device{}());

void insertionSort(vector<int> &arr, int left, int right) {
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

void heapify(vector<int> &arr, int n, int i, int l) {
    while (2 * i + 1 < n) {
        int j = 2 * i + 1;
        if (j + 1 < n && arr[l + j] < arr[l + j + 1]) {
            j++;
        }
        if (arr[l + i] >= arr[l + j]) {
            break;
        }
        swap(arr[l + i], arr[l + j]);
        i = j;
    }
}

void heapSort(vector<int> &arr, int left, int right) {
    int n = right - left;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, left);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[left], arr[left + i]);
        heapify(arr, i, 0, left);
    }
}

int partition(vector<int> &arr, int left, int right) {
    uniform_int_distribution<int> dist(left, right - 1);
    int pivotIndex = dist(rng);
    swap(arr[pivotIndex], arr[right - 1]);

    int pivot = arr[right - 1];
    int i = left - 1;

    for (int j = left; j < right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right - 1]);
    return i + 1;
}

void basicQuick(vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int m = partition(arr, left, right);
    basicQuick(arr, left, m);
    basicQuick(arr, m + 1, right);
}

void introQuick(vector<int> &arr, int left, int right, int deep) {
    int size = right - left;

    if (size < 16) {
        insertionSort(arr, left, right);
        return;
    }

    if (deep == 0) {
        heapSort(arr, left, right);
        return;
    }

    int m = partition(arr, left, right);
    introQuick(arr, left, m, deep - 1);
    introQuick(arr, m + 1, right, deep - 1);
}

void introsort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int deep = 2 * static_cast<int>(log2(right - left));
    introQuick(arr, left, right, deep);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    introsort(a, 0, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
