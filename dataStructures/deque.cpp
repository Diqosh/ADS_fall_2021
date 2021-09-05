#include <iostream>

using namespace std;


struct node{
    int value;
    node * next;
    node * prev;

    node(int x){
        value = x;
        next = nullptr;
        prev = nullptr;
    }
};

struct deque{
protected:
    node *first_node, *rear_node;
public:
    deque(){
        first_node = rear_node = nullptr;
    }

    void push_bottom(int item){
        node * new_back_node = new node(item);
        if (first_node == nullptr){
            first_node = new_back_node;
            rear_node = new_back_node;
        }else{
            first_node->prev = new_back_node;
            new_back_node->next = first_node;
            first_node = new_back_node;
        }
    }

    void push_top(int item){
        node * new_top_node = new node(item);
        if (first_node == nullptr) {
            first_node = new_top_node;
            rear_node = new_top_node;
        } else{
            rear_node->next = new_top_node;
            new_top_node->prev = rear_node;
            rear_node = new_top_node;
        }
    }

    void pop_bottom(){
        first_node = first_node->next;
        first_node->prev = nullptr;
        if (first_node == nullptr) rear_node = nullptr;

    }

    void pop_top(){
        rear_node = rear_node->prev;
        rear_node->next = nullptr;
        if (rear_node == nullptr) first_node = nullptr;
    }

    int bottom(){
        if (first_node != nullptr){
            return first_node->value;
        }
        return -1;
    }

    int top(){
        if (rear_node != nullptr){
            return rear_node->value;
        }
        return -1;
    }

    bool empty(){
        return first_node != nullptr;
    }




};


int main(){
    deque qu;
    int a[] = {1, 2, 3, 45};
    int n = sizeof(a)/sizeof(int);
    for (int i = 0; i < n; ++i) {
        qu.push_top(a[i]);
    }
    qu.pop_top();
    cout << qu.top();

    return 0;
}