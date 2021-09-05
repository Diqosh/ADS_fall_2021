#include <iostream>

using namespace std;

struct node{

    int value;
    node * prev;
    node * next;

    node(int x){
        value = x;
        prev = next= nullptr;
    }
};

struct stack{
protected:
    node * top_element;
    int cnt;
public:
    stack(){
        top_element = nullptr;
        cnt = 0;
    }

    void push_top(int item){
        node *new_head_node = new node(item);
        cnt++;

        if (top_element == nullptr) {
            top_element = new_head_node;
        }else{
            top_element->next = new_head_node;
            new_head_node->prev = top_element;
            top_element = new_head_node;
        }
    }

    int top(){
        if (top_element != nullptr){
            return top_element->value;
        }
        return -1;
    }

    void pop(){
        top_element = top_element->prev;
        top_element->next = nullptr;
        cnt--;
    }

    bool empty(){
        return top_element == nullptr;
    }

    int size(){
        return cnt;
    }
};

int main(){

    stack st;
    int a[] = {1, 3, 4, 5};
    int n = sizeof(a)/sizeof(int);

    for (int i = 0; i < n; ++i) {
        st.push_top(a[i]);
    }
//    cout << st.size();
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    cout << 1;

    return 0;
}
