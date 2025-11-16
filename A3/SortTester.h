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

    long long measureQuickSort(vector<int> arr) {
        vector<long long> times;
        for (int run = 0; run < numRuns; run++) {
            vector<int> temp = arr;
            auto start = chrono::high_resolution_clock::now();
            SortAlgorithms::basicQuick(temp, 0, temp.size());
            auto elapsed = chrono::high_resolution_clock::now() - start;
            long long microsec = chrono::duration_cast<chrono::microseconds>(elapsed).count();
            times.push_back(microsec);
        }
        return getMedian(times);
    }

    long long measureIntroSort(vector<int> arr) {
        vector<long long> times;
        for (int run = 0; run < numRuns; run++) {
            vector<int> temp = arr;
            auto start = chrono::high_resolution_clock::now();
            SortAlgorithms::introSort(temp, 0, temp.size());
            auto elapsed = chrono::high_resolution_clock::now() - start;
            long long microsec = chrono::duration_cast<chrono::microseconds>(elapsed).count();
            times.push_back(microsec);
        }
        return getMedian(times);
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
