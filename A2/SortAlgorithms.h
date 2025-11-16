#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H
#include <vector>

using namespace std;

class SortAlgorithms {
public:
    static void insertionSort(vector<int>& arr, int left, int right) {
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

    static void mergeSort(vector<int>& arr, int left, int right) {
        if (right - left == 1)
            return;
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);
        merge(arr, left, mid, right);
    }

    static void hybridMergeSort(vector<int>& arr, int left, int right, int threshold) {
        if (right - left <= threshold) {
            insertionSort(arr, left, right);
            return;
        }
        int mid = (left + right) / 2;
        hybridMergeSort(arr, left, mid, threshold);
        hybridMergeSort(arr, mid, right, threshold);
        merge(arr, left, mid, right);
    }
private:
    static void merge(vector<int>& arr, int left, int mid, int right) {
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
};
#endif // SORTALGORITHMS_H
