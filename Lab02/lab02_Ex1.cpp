#include <iostream>
#include <vector>
using namespace std;

int findMax(const vector<int>& arr) {
    int stepCount = 0;

    int max = arr[0];
    stepCount = stepCount + 2; // 2 steps (assignment and array access)

    stepCount++; // loop initialization: 1 step (assignment i = 1)
    for (int i = 1; i < arr.size(); i++) {
        stepCount++; // comparison: 1 step (i < arr.size())

        stepCount = stepCount + 2; // 2 steps (array access and comparison)
        if (arr[i] > max) {
            max = arr[i];
            stepCount = stepCount + 2; // 2 steps (array access and comparison)
        }

        stepCount++; // increment: 1 step (i++)
    }
    stepCount++; // finally failed comparison (loop exit)

    stepCount++; // return sum
    return max;
}
/*
Total operations:
3 (initial) + 6 * (n - 1) (loop operations) + 1 (loop exit) + 1 (return sum)
= 6n - 1
Therefore, O(n) complexity
*/
