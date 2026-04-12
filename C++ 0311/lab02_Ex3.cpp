#include <iostream>
#include <vector>
using namespace std;

void copyArray(const vector<int>& source, vector<int>& dest) {
    int stepCount = 0;

    stepCount++; // loop initialization (i = 0)
    for (int i = 0; i < source.size(); i++) {
        stepCount++; // comparison: i < source.size()

        dest[i] = source[i];
        stepCount = stepCount + 3; // 2 steps array access and 1 step assignment

        stepCount++; // increment: i++
    }
    stepCount++; // loop exit
}
/*
Total operations:
1 (initial) + 5 * n (loop operations) + 1 (loop exit)
= 5n + 2
Therefore, O(n) complexity
*/

int countElement(const vector<int>& arr, int target) {
    int stepCount = 0;

    int count = 0;
    stepCount++; // assignment (count = 0)

    stepCount++; // loop initialization (i = 0)
    for (int i = 0; i < arr.size(); i++) {
        stepCount++; // comparison: i < arr.size()

        stepCount = stepCount + 2; // array access (arr[i]) and comparison (arr[i] == target)
        if (arr[i] == target) {
            count++;
            stepCount++; // addition (count++)
        }

        stepCount++; // increment: i++
    }
    stepCount++; // loop exit
    stepCount++; // return count
    return count;
}
/*
Total operations:
2 (initial) + 5 * n (loop operations) + 1 (loop exit) + 1 (return)
= 5n + 4
Therefore, O(n) complexity
*/
