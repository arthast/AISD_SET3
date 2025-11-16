#ifndef SORTTESTER_H
#define SORTTESTER_H
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include "SortAlgorithms.h"

using namespace std;

class SortTester {
private:
    int numRuns;

public:
    SortTester(int runs = 5) : numRuns(runs) {
    }

    long long measureMergeSort(vector<int> arr) {
        vector<long long> times;
        for (int run = 0; run < numRuns; run++) {
            vector<int> temp = arr;
            auto start = chrono::high_resolution_clock::now();
            SortAlgorithms::mergeSort(temp, 0, temp.size());
            auto elapsed = chrono::high_resolution_clock::now() - start;
            long long microsec = chrono::duration_cast<chrono::microseconds>(elapsed).count();
            times.push_back(microsec);
        }
        return getMedian(times);
    }

    long long measureHybridSort(vector<int> arr, int threshold) {
        vector<long long> times;
        for (int run = 0; run < numRuns; run++) {
            vector<int> temp = arr;
            auto start = chrono::high_resolution_clock::now();
            SortAlgorithms::hybridMergeSort(temp, 0, temp.size(), threshold);
            auto elapsed = chrono::high_resolution_clock::now() - start;
            long long microsec = chrono::duration_cast<chrono::microseconds>(elapsed).count();
            times.push_back(microsec);
        }
        return getMedian(times);
    }

    bool verifySorting(vector<int> arr) {
        vector<int> temp1 = arr;
        vector<int> temp2 = arr;
        SortAlgorithms::mergeSort(temp1, 0, temp1.size());
        sort(temp2.begin(), temp2.end());
        return temp1 == temp2;
    }

    void saveResultsToCSV(const string &filename,
                          const vector<int> &sizes,
                          const vector<long long> &times) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла: " << filename << endl;
            return;
        }
        file << "Size,Time_microseconds\n";
        for (size_t i = 0; i < sizes.size() && i < times.size(); i++) {
            file << sizes[i] << "," << times[i] << "\n";
        }
        file.close();
    }

private:
    long long getMedian(vector<long long> values) {
        sort(values.begin(), values.end());
        return values[values.size() / 2];
    }
};
#endif // SORTTESTER_H
