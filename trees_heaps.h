#ifndef TREES_HEAPS_H
#define TREES_HEAPS_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}


vector<int> make_binary_tree(int numnodes) {
    vector<int> tree;
    for(int i = 0; i < numnodes; i++) {
        tree.push_back(rand() % 100);
    }
    return tree;
}

vector<int> make_binary_search_tree(int numnodes = 63) {
    vector<int> tree;
    for(int i = 0; i < numnodes; i++) {
        tree.push_back(rand() % 100);
    }
    return tree;
}

void print_tree(const vector<int>& tree) {
    for(vector<int>::const_iterator iter = tree.begin(); iter != tree.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int node(int height, int index) {
    return exp2(height) + index - 1;
}

void print_spaces(int num) {
    for(int i = 0; i < num; i++)
        cout << " ";
}

// TODO add formatting so levels that have more nodes
// don't take up more space---not the same amount of space between each?
void print_pretty_tree(const vector<int>& tree) {
    const int max_width = exp2(log2(tree.size() + 1) - 1) * 8;
    cout << "Printing tree with max width: " << max_width << endl << endl;
    for(int i = 1; i < log2(tree.size() + 1) + 1; i++) {
        const int between = max_width/(exp2(i-1) + 1);
//        cout << "Printing level: " << i-1 << " with between space: " << between << " and num nodes: " << exp2(i-1) << endl;
        print_spaces(between);
        for(int k = 0; k < exp2(i-1); k++) {
            cout << tree[node(i-1, k)];
            print_spaces(between);
        }
        cout << "|" << endl << endl;
    }
}

void min_heapify(vector<int>& tree, int i) {
    const int val = tree[i];
    int smallest = i;
    if ((i*2+1) < tree.size() && tree[i*2+1] < tree[i])
        smallest = i*2+1;
    if ((i*2 + 2) < tree.size() && tree[i*2+2] < tree[smallest])
        smallest = i*2 + 2;
    if (smallest != i) {
        const int tmp = tree[smallest];
        tree[smallest] = tree[i];
        tree[i] = tmp;
        min_heapify(tree, smallest);
    }
}

void find_nth_smallest(const vector<int>& t, int nth) {
    // Heapify it
    vector<int> tree = t;
    for(int i = tree.size()/2; i >= 0; i--) {
        min_heapify(tree, i);
    }
    // Take N off the top and heapify each time
    for(int i = 0; i < nth - 1; i++) {
        tree[0] = INT_MAX;
        min_heapify(tree, 0);
    }
    cout << "FINAL: " << tree[0] << endl;
}

void do_trees() {
    vector<int> tree = make_binary_tree(15);
    vector<int> bst = make_binary_search_tree(31);

    print_tree(tree);
    print_pretty_tree(tree);
    find_nth_smallest(tree, 5);

    print_pretty_tree(bst);
}

#endif // TREES_HEAPS_H
