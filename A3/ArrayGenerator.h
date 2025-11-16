#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class ArrayGenerator {
private:
    mt19937 rng;
    int minValue;
    int maxValue;

public:
    ArrayGenerator(int minVal = 0, int maxVal = 6000, unsigned seed = random_device{}())
        : rng(seed), minValue(minVal), maxValue(maxVal) {
    }

    vector<int> generateRandomArray(int size) {
        vector<int> arr(size);
        uniform_int_distribution<int> dist(minValue, maxValue);
        for (int i = 0; i < size; i++) {
            arr[i] = dist(rng);
        }
        return arr;
    }

    vector<int> generateReversedArray(int size) {
        vector<int> arr(size);
        uniform_int_distribution<int> dist(minValue, maxValue);
        for (int i = 0; i < size; i++) {
            arr[i] = dist(rng);
        }
        sort(arr.begin(), arr.end(), greater<int>());
        return arr;
    }


    vector<int> generateNearlySortedArray(int size, int swaps = -1) {
        vector<int> arr(size);
        uniform_int_distribution<int> dist(minValue, maxValue);
        for (int i = 0; i < size; i++) {
            arr[i] = dist(rng);
        }
        sort(arr.begin(), arr.end());

        if (swaps == -1) {
            swaps = max(1, size / 50);
        }
        uniform_int_distribution<int> indexDist(0, size - 1);
        for (int i = 0; i < swaps; i++) {
            int idx1 = indexDist(rng);
            int idx2 = indexDist(rng);
            swap(arr[idx1], arr[idx2]);
        }
        return arr;
    }

    vector<int> getSubarray(const vector<int> &source, int size) {
        if (static_cast<size_t>(size) > source.size()) {
            size = source.size();
        }
        return vector<int>(source.begin(), source.begin() + size);
    }
};
#endif // ARRAYGENERATOR_H
