#include <iostream>

using namespace std;

// Singly linked list
struct Node {
    int val;
    Node* next;

    Node(int val, Node* next) : val(val), next(next) {}
};

void print(Node* head) {
    Node* cur = head;
    while(cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* make(int len = 10, bool with_cycle=false) {
    Node* head = new Node(1111, 0);
    Node* fifth = 0;
    Node* last = head;
    for(int i = len; i >= 0; i--) {
        head = new Node(i, head);
        if (i == 4) fifth = head;
    }
    if (with_cycle)
        last->next = fifth;

    return head;
}

Node* reverse(Node* head) {
    Node* cur = head;
    Node* last = 0;
    while(cur) {
        Node* next = cur->next;
        cur->next = last;
        last = cur;
        cur = next;
    }
    return last;
}

Node* interweave(Node* head) {
    int len = 0;
    Node *tmp = head;
    while(tmp) {
        len++;
        tmp = tmp->next;
    }
    Node *mid = head;
    for(int i = 0; i < len/2; i++) mid = mid->next;
    mid = reverse(mid);
    Node *orig_head = head;
    for(int i = 0; i < len/2; i++) {
        Node *tmp = head->next;
        Node *tmp2 = mid->next;
        head->next = mid;
        mid->next = tmp;
        head = tmp;
        mid = tmp2;
    }
    head->next = 0;
    return orig_head;
}

int length(Node *head) {
    int len = 0;
    while(head) {
        head = head->next;
        len++;
    }
    return len;
}

int find_mth(Node *head, int m) {
    const int len = length(head);
    const int pos = len - m - 1;
    for(int i = 0; i < pos && head; i++) {
        head = head->next;
    }
    if(head)
        return head->val;
    else
        return -1;
}

int find_mth_2(Node *head, int m) {
    Node* last = head;
    int count = 0;

    while(head) {
        if(count > m)
            last = last->next;
        count++;
        head = head->next;
    }
    if(count >= m)
        return last->val;
    else
        return -1;
}

bool has_cycle(Node* head) {
    Node *fast = head;
    while(head) {
        head = head->next;
        for(int i = 0; i < 2 && fast; i++) {
            fast = fast->next;
        }

        if (fast == head)
            break;
    }
    return fast != 0;
}

Node* remove_duplicates(Node* head) {
    // easy way n^2, go through list, for each node, try to find it in the rest ofthe list
    // alternative: use hash table / set for seen elements, and compare (requires O(n) storage)
    // alternative: sort the list, then remove duplicates. only works if we can change the list order though
}

// Doubly linked lists
struct DNode {
    int val;
    DNode* next, *prev;

    DNode(int val, DNode* next, DNode* prev) : val(val), next(next), prev(prev) {}
};

void print(DNode* head) {
    DNode* cur = head;
    while(cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

void rprint(DNode* tail) {
    DNode* cur = tail;
    while(cur) {
        cout << cur->val << endl;
        cur = cur->prev;
    }
    cout << endl;
}

DNode* make_double() {
    DNode* head = new DNode(12, 0, 0);
    for(int i = 10; i >= 0; i--) {
        DNode* old_head = head;
        head = new DNode(i, head, 0);
        old_head->prev = head;
    }
    return head;
}

DNode* reverse_double(DNode* head) {
    DNode* cur = head;
    DNode* last = 0;
    while(cur) {
        DNode* next = cur->next;
        last = cur;
        cur->next = cur->prev;
        cur->prev = next;
        cur = next;

    }
    return last;
}

void run_linked_lists() {
    Node*  head = make();
    print(head);
    Node* reversed = reverse(head);
    cout << "Reversed: ";
    print(reversed);
    cout << "3th element from end: " << find_mth(head, 12) << " " << find_mth_2(head, 3) << endl;
    cout << "Last element: " << find_mth(head, 0) << " " << find_mth_2(head, 0) << endl;

    cout << "List has cycle? (should be false): " << has_cycle(head) << endl;
    cout << "List has cycle? (should be true): " << has_cycle(make(true)) << endl;

    cout << "Interweaving: ";
    head = make(11);
    print(head);
    cout << "Interweaved: ";
    Node* intereweaved = interweave(head);
    print(intereweaved);

    DNode* dhead = make_double();
    cout << "Doubly linked list: ";
    print(dhead);

    DNode* dreversed = reverse_double(dhead);
    cout << "reversed : ";
    print(dreversed);
}
