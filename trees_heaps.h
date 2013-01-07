#ifndef TREES_HEAPS_H
#define TREES_HEAPS_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val, TreeNode* left = 0, TreeNode* right = 0) : val(val), left(left), right(right) {}
};

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

TreeNode* left(TreeNode* n) {
    return n->left;
}

TreeNode* right(TreeNode* n) {
    return n->right;
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

TreeNode* make_node_tree() {
    TreeNode* a = new TreeNode("a");
    TreeNode* b = new TreeNode("b");
    TreeNode* c = new TreeNode("c");
    TreeNode* d = new TreeNode("d");
    TreeNode* e = new TreeNode("e");
    TreeNode* f = new TreeNode("f");
    TreeNode* g = new TreeNode("g");
    TreeNode* h = new TreeNode("h");

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;
    c->right = g;


    e->left = f;

    g->left = h;

    return a;
}

TreeNode* make_isomorphic() {
    TreeNode* a = new TreeNode("a");
    TreeNode* b = new TreeNode("b");
    TreeNode* c = new TreeNode("c");
    TreeNode* d = new TreeNode("d");
    TreeNode* e = new TreeNode("e");
    TreeNode* f = new TreeNode("f");
    TreeNode* g = new TreeNode("g");
    TreeNode* h = new TreeNode("h");

    a->left = c;
    c->left = g;
    g->right = h;

    a->right = b;
    b->left = e;
    e->left = f;
    b->right = d;

    return a;
}

void print_inorder_nodetree(TreeNode* root) {
    if (!root)
        return;
    if (root->left)
        print_inorder_nodetree(root->left);
    cout << root->val << " ";
    if (root->right)
        print_inorder_nodetree(root->right);
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

bool is_isomorphic(TreeNode* tree1, TreeNode* tree2) {
    if (!tree1 && !tree2)
        return true;

    if ((!tree1 && tree2) ||
        (tree1 && !tree2))
        return false;

    if (tree1->val != tree2->val)
        return false;

    if (!tree1->left && !tree2->left)
        return is_isomorphic(tree1->right, tree2->right);

    if (tree1->left && tree2->left && tree1->left->val == tree2->left->val)
        return is_isomorphic(tree1->left, tree2->left) &&
               is_isomorphic(tree1->right, tree2->right);
    else
        return is_isomorphic(tree1->left, tree2->right) &&
               is_isomorphic(tree1->right, tree2->left);
}


TreeNode* find_lca(TreeNode* root, string val1, string val2) {
    if (!root)
        return 0;

    if (root->val == val1 || root->val == val2)
            return root;

    TreeNode* leftLCA = find_lca(root->left, val1, val2);
    TreeNode* rightLCA = find_lca(root->right, val1, val2);

    if (leftLCA && rightLCA)
        return root;

    if (leftLCA)
        return leftLCA;
    else
        return rightLCA;
}

void do_trees() {
    vector<int> tree = make_binary_tree(15);
    vector<int> bst = make_binary_search_tree(31);

    print_tree(tree);
    print_pretty_tree(tree);
    find_nth_smallest(tree, 5);

    print_pretty_tree(bst);

    cout << "Node-based trees: " << endl;
    TreeNode* root = make_node_tree();
    TreeNode* iso = make_isomorphic();
    print_inorder_nodetree(root);
    cout << endl;
    print_inorder_nodetree(iso);
    cout << endl << "isomorphic?" << is_isomorphic(root, iso) << endl;

    cout << "LCA of E and F: " << find_lca(root, "e", "f")->val << endl;
}

#endif // TREES_HEAPS_H
