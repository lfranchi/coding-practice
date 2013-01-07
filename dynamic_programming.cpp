#include "dynamic_programming.h"

#include <iostream>
#include <vector>

using namespace std;

int memoize_recursive[100][100] = {{0}};
int memoize_iterative[100][100] = {{0}};
int picks[100][100] = {{0}};
int picks_recursive[100][100] = {{0}};

int knapsack_recursive(int index, int size, int weights[], int values[])
{
    int takeValue = 0, dontTakeValue = 0;

    if (memoize_recursive[index][size] != 0)
        return memoize_recursive[index][size];

    if (index == 0) { // last item
        if (weights[index] <= size) { // we can fit it in
            picks[index][size] = 1;
            memoize_recursive[index][size] = values[0];
            return values[0];
        } else { // we can't fit the last item, so we have 0
            picks[index][size] = -1;
            memoize_recursive[index][size] = 0;
            return 0;
        }
    }

    if (weights[index] <= size) {
        // we have space, might have a better packing
        takeValue = values[index] + knapsack_recursive(index - 1, size - weights[index], weights, values);
    }

    dontTakeValue = knapsack_recursive(index - 1, size, weights, values);

    if (takeValue > dontTakeValue)
        picks[index][size] = 1;
     else
        picks[index][size] = -1;

    memoize_recursive[index][size] = max(takeValue, dontTakeValue);
    return memoize_recursive[index][size];
}

int knapsack_iterative(int num_items, int size, int weights[], int values[]) {
    for (int i = 1; i < num_items; i++) {
        for (int j = 1; j < size; j++) {
            // loop through all cells in the memoize table
            if (weights[i - 1] < j) { // If there is space left for us to work with
                // choose the bigger of: not choosing this item (i - 1), or this item's value + max value with reduced weight
                const int taken_value = values[i-1] + memoize_iterative[i-1][j-weights[i - 1]];
                memoize_iterative[i][j] = max(memoize_iterative[i-1][j], taken_value);
                if (taken_value > memoize_iterative[i-1][j]) // we chose it
                    picks_recursive[i][j] = 1;
                else
                    picks_recursive[i][j] = -1;
            } else { // no more space
                picks_recursive[i][j] = -1;
                memoize_iterative[i][j] = memoize_iterative[i-1][j];
            }
        }
    }
    return memoize_iterative[num_items][size];
}

void print_picks(bool recur, int item, int size, int weights[]) {
    cout << "Picks were: ";
    auto p = recur ? picks_recursive : picks;
    while (item > 0) { // go backwards through items
        item--;
        if (p[item][size] > 0) { // we picked this item
            cout << item << " ";
            size -= weights[item];
        }
    }
    cout << endl;
}


vector<int> subset_sum(const vector<int>& array, int sum ) {
    vector<vector<bool> > S(array.size() + 1, vector<bool>(sum + 1));
    // S is a table, length of array by sum.
    // S[i][j] is true if there is a subset of the first i elements that add up to j

    for(size_t i = 0; i < S.size(); i++) {
        // everything adds up to 0, we don't need any items
        S[i][0] = true;
    }

    for(int i = 1; i < sum + 1; i++) {
        // Nothing can add up to any more than 0
        S[0][i] = false;
    }

    for (int i = 1; i < S.size(); i++) {
        for (int j = 1; j < sum + 1; j++) {
            // if we can sum to this number with previous items, don't bother trying
            // else, if this new element is less than our sum, and we can make a sum to "this minus the new element", then record true
            S[i][j] = S[i-1][j] || (array[i-1] <= j && S[i-1][j-array[i-1]]);
        }
    }

    for(auto row : S) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    if(S[S.size() - 1][sum])
        cout << "Found subset that sums to " << sum << endl;
    else {
        cout << "Did NOT find subset that sums to " << sum << endl;
        return vector<int>();
    }

    vector<int> subset;

    // determine which numbers we actually used by:
    // 1. going to S[i][j] (Which we know is true)
    // 2. check if the row *above* is 0---this means this we chose /this/ item to make this sum
    //      else move up until we find the first 1 in the column
    // 3. subtract from our sum the item that was added, and repeat from 1.
    int n = sum;
    for (int i = S.size(); i >= 1 && n; i--) {
        if (!S[i-1][n]) {
            subset.push_back(array[i - 1]);
            n -= array[i - 1];
        }
    }
    cout << endl;
    return subset;
}

void do_dp() {
    int numItems = 4;
    int size = 10;
    int weights[4] = {5, 4, 6, 3};
    int values[4] = {10, 40, 30, 50};

    cout << "Max value: " << knapsack_recursive(numItems - 1, size, weights, values) << endl;
    print_picks(false, numItems - 1, size, weights);

    cout << "Max value: " << knapsack_recursive(numItems - 1, size, weights, values) << endl;
    print_picks(true, numItems, size, weights);

    vector<int> array;
    array.push_back(2);
    array.push_back(29);
    array.push_back(3);
    array.push_back(1);
    array.push_back(5);
    vector<int> subset = subset_sum(array, 4);
    cout << "Subset sum of ["; for(auto n : array) { cout << n << " "; } cout << "] and 5 is ";
    for(auto item : subset) {
        cout << item << " ";
    }
    cout << endl;
}
