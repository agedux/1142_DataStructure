#include <iostream>
#include <vector>
using namespace std;

void printPairs(const vector<int>& arr) {
    int stepCount = 0;

    stepCount++; // Loop initialization: i = 0
    for (int i = 0; i < arr.size(); i++) {
        stepCount++; // comparison: i < arr.size()

        stepCount++; // Loop initialization: j = i + 1
        for (int j = i + 1; j < arr.size(); j++) {
            stepCount++; // comparison: j < arr.size()

            stepCount = stepCount + 2; // 2 steps (accessing arr[i] and arr[j])
            cout << arr[i] << "," << arr[j] << endl;

            stepCount++; // increment: j++
        }
        stepCount++; // loop exit

        stepCount++; // increment: i++
    }
    stepCount++; // loop exit
}
/*
內層迴圈: (n^2-n)/2
Total operations:
1 (initial) + 4 * n (outside loop operations) + 4 * (n^2-n)/2 (inside loop operations) + 1 (loop exit)
= 2n^2 + 2n + 2
Therefore, O(n^2) complexity
*/
