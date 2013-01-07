#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <vector>

int knapsack_recursive(int index, int size, int weights[], int values[]);
int knapsack_iterative(int index, int size, int weights[], int values[]);

std::vector<int> subset_sum(const std::vector<int>& array, int sum);

void do_dp();

#endif
