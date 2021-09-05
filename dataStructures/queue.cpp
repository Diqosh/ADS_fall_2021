#include <iostream>

using namespace std;

struct node {

    int value;
    node *prev;
    node *next;

    node(int x) {
        value = x;
        prev = next = nullptr;
    }
};

struct queue {
protected:
    node *first_node, *rear_node;
public:
    queue() {
        first_node = rear_node = nullptr;
    }

    void push_top(int item) {
        node *new_head_node = new node(item);
        if (first_node == nullptr) {
            first_node = new_head_node;
            rear_node = new_head_node;
        } else {
            rear_node->next = new_head_node;
            new_head_node->prev = first_node;
            rear_node = new_head_node;
        }
    }

    int front_element() {
        if (first_node != nullptr) {
            return first_node->value;
        }
        return -1;
    }

    void pop() {
        first_node = first_node->next;
        first_node->prev = nullptr;
    }

    bool empty() {
        return first_node == nullptr;
    }


};

int main() {
    queue qu;
    int a[] = {1, 2, 3, 45};
    int n = sizeof(a)/sizeof(int);
    for (int i = 0; i < n; ++i) {
        qu.push_top(a[i]);
    }

    while (!qu.empty()){
        cout << qu.front_element() << endl;
        qu.pop();
    }

    return 0;
}