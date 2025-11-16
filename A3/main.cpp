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

    cout << "--- Quick Sort ---" << '\n';
    vector<long long> quickTimesRandom;
    vector<long long> quickTimesReversed;
    vector<long long> quickTimesNearlySorted;
    for (int size: sizes) {
        long long timeRandom = tester.measureQuickSort(generator.getSubarray(randomMax, size));
        long long timeReversed = tester.measureQuickSort(generator.getSubarray(reversedMax, size));
        long long timeNearlySorted = tester.measureQuickSort(generator.getSubarray(nearlySortedMax, size));
        quickTimesRandom.push_back(timeRandom);
        quickTimesReversed.push_back(timeReversed);
        quickTimesNearlySorted.push_back(timeNearlySorted);

        cout << "Size: " << setw(6) << size
                << " | Random: " << setw(8) << timeRandom << " μs"
                << " | Reversed: " << setw(8) << timeReversed << " μs"
                << " | Nearly Sorted: " << setw(8) << timeNearlySorted << " μs"
                << '\n';
    }

    tester.saveResultsToCSV("src/quick_sort_random.csv", sizes, quickTimesRandom);
    tester.saveResultsToCSV("src/quick_sort_reversed.csv", sizes, quickTimesReversed);
    tester.saveResultsToCSV("src/quick_sort_nearly_sorted.csv", sizes, quickTimesNearlySorted);


    cout << "\n--- Intro Sort ---" << '\n';
    vector<long long> introTimesRandom;
    vector<long long> introTimesReversed;
    vector<long long> introTimesNearlySorted;

    for (int size: sizes) {
        long long timeRandom = tester.measureIntroSort(generator.getSubarray(randomMax, size));
        long long timeReversed = tester.measureIntroSort(generator.getSubarray(reversedMax, size));
        long long timeNearlySorted = tester.measureIntroSort(generator.getSubarray(nearlySortedMax, size));
        introTimesRandom.push_back(timeRandom);
        introTimesReversed.push_back(timeReversed);
        introTimesNearlySorted.push_back(timeNearlySorted);

        cout << "Size: " << setw(6) << size
                << " | Random: " << setw(8) << timeRandom << " μs"
                << " | Reversed: " << setw(8) << timeReversed << " μs"
                << " | Nearly Sorted: " << setw(8) << timeNearlySorted << " μs"
                << '\n';

        tester.saveResultsToCSV("src/intro_sort_random.csv", sizes, introTimesRandom);
        tester.saveResultsToCSV("src/intro_sort_reversed.csv", sizes, introTimesReversed);
        tester.saveResultsToCSV("src/intro_sort_nearly_sorted.csv", sizes, introTimesNearlySorted);
    }
    return 0;
}
