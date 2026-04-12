#include <iostream>
#include <vector>
using namespace std;

int sumArray(const vector<int> & arr) {
    int stepCount = 0;
    int sum = 0;
    stepCount++; // 1 step (assignment)
    stepCount++; // Loop initialization: 1 step (assignment i = 0)
        for (int i = 0; i < arr.size(); i++) {
            stepCount++; // Comparison: 1 step (i < arr.size())
            sum = sum + arr[i]; stepCount = stepCount + 3;
            // 3 step (array access + addition + assignment)
            stepCount++; // Increment: 1 step (i++)
        }
    stepCount++; // final failed comparison (loop exit)
    stepCount++; // return sum
    cout << "Step count: " << stepCount << endl;
    return sum;

    // 5n + 4
}

int findNumber(const vector<int>& arr, int target) {
    int stepCount = 0;
    stepCount ++; // Loop initialization: i = 0
        for (int i = 0; i < arr.size(); i++) {
            stepCount ++; // Loop comparison: i < arr.size()
            stepCount ++; // Array access: arr[i]
            stepCount ++; // Comparison with target: arr[i] == target
            if (arr[i] == target) {
                stepCount ++; // return operation
                cout << "Step count: " << stepCount << endl;
                return i;
            }
            stepCount ++; // Increment: i++
        }
    stepCount ++; // loop exit comparison
    stepCount ++; // return operation
    cout << "Step count: " << stepCount << endl;
    return -1;

    // 4n + 3
}