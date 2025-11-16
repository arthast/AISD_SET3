#include <iostream>
#include <vector>
#include <iomanip>
#include "ArrayGenerator.h"
#include "SortAlgorithms.h"
#include "SortTester.h"

using namespace std;

const int MIN_SIZE = 500;
const int MAX_SIZE = 10000;
const int STEP = 100;
const int MIN_VALUE = 0;
const int MAX_VALUE = 6000;
const int NUM_RUNS = 5;
const vector<int> thresholds = {5, 10, 20, 30, 50, 300, 500, 1000};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ArrayGenerator generator(MIN_VALUE, MAX_VALUE);
    SortTester tester(NUM_RUNS);
    vector<int> sizes;
    for (int size = MIN_SIZE; size <= MAX_SIZE; size += STEP) {
        sizes.push_back(size);
    }
    vector<int> randomMax = generator.generateRandomArray(MAX_SIZE);
    vector<int> reversedMax = generator.generateReversedArray(MAX_SIZE);
    vector<int> nearlySortedMax = generator.generateNearlySortedArray(MAX_SIZE);

    cout << "--- Merge Sort ---" << '\n';
    vector<long long> mergeTimesRandom;
    vector<long long> mergeTimesReversed;
    vector<long long> mergeTimesNearlySorted;
    for (int size: sizes) {
        long long timeRandom = tester.measureMergeSort(generator.getSubarray(randomMax, size));
        long long timeReversed = tester.measureMergeSort(generator.getSubarray(reversedMax, size));
        long long timeNearlySorted = tester.measureMergeSort(generator.getSubarray(nearlySortedMax, size));
        mergeTimesRandom.push_back(timeRandom);
        mergeTimesReversed.push_back(timeReversed);
        mergeTimesNearlySorted.push_back(timeNearlySorted);

        cout << "Size: " << setw(6) << size
                << " | Random: " << setw(8) << timeRandom << " μs"
                << " | Reversed: " << setw(8) << timeReversed << " μs"
                << " | Nearly Sorted: " << setw(8) << timeNearlySorted << " μs"
                << '\n';
    }

    tester.saveResultsToCSV("src/merge_sort_random.csv", sizes, mergeTimesRandom);
    tester.saveResultsToCSV("src/merge_sort_reversed.csv", sizes, mergeTimesReversed);
    tester.saveResultsToCSV("src/merge_sort_nearly_sorted.csv", sizes, mergeTimesNearlySorted);


    cout << "\n--- Merge+Insertion Sort ---" << '\n';
    for (int threshold: thresholds) {
        cout << "\nthreshold: " << threshold << '\n';
        vector<long long> hybridTimesRandom;
        vector<long long> hybridTimesReversed;
        vector<long long> hybridTimesNearlySorted;

        for (int size: sizes) {
            long long timeRandom = tester.measureHybridSort(generator.getSubarray(randomMax, size), threshold);
            long long timeReversed = tester.measureHybridSort(generator.getSubarray(reversedMax, size), threshold);
            long long timeNearlySorted = tester.measureHybridSort(generator.getSubarray(nearlySortedMax, size),
                                                                  threshold);
            hybridTimesRandom.push_back(timeRandom);
            hybridTimesReversed.push_back(timeReversed);
            hybridTimesNearlySorted.push_back(timeNearlySorted);

            if (size % 1000 == 0) {
                cout << "Size: " << setw(6) << size
                        << " | Random: " << setw(8) << timeRandom << " μs"
                        << " | Reversed: " << setw(8) << timeReversed << " μs"
                        << " | Nearly Sorted: " << setw(8) << timeNearlySorted << " μs"
                        << '\n';
            }
        }

        tester.saveResultsToCSV("src/hybrid_sort_random_t" + to_string(threshold) + ".csv",
                                sizes, hybridTimesRandom);
        tester.saveResultsToCSV("src/hybrid_sort_reversed_t" + to_string(threshold) + ".csv",
                                sizes, hybridTimesReversed);
        tester.saveResultsToCSV("src/hybrid_sort_nearly_sorted_t" + to_string(threshold) + ".csv",
                                sizes, hybridTimesNearlySorted);
    }
    return 0;
}
