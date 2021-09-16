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
    node *front_node, *rear_node;
    int cnt;
public:
    queue() {
        front_node = rear_node = nullptr;
        cnt = 0;
    }

    void push_top(int item) {
        cnt++;
        node *new_head_node = new node(item);
        if (front_node == nullptr) {
            front_node = rear_node =  new_head_node;
        } else {
            rear_node->next = new_head_node;
            rear_node = new_head_node;
        }
    }

    int front() {
        if (front_node != nullptr) {
            return front_node->value;
        }
        return -1;
    }

    int pop_front() {
        if(front_node != nullptr){
            int item_to_show = front_node->value;
            cnt--;
            front_node = front_node->next;
            if(front_node == nullptr){
                rear_node = nullptr;
            }else{
                front_node->prev = nullptr;
            }

            return item_to_show;
        }

        return -1;
    }
    void clear(){
        while(front_node != nullptr){
            front_node = front_node->next;
            if (front_node != nullptr) {
                front_node->prev = nullptr;
            }
        }
        cnt = 0;
    }

    int size(){
        return cnt;
    }
    bool empty() {
        return front_node == nullptr;
    }


};

int main() {

    //freopen(R"(D:\kbtu\3\2021\ADS\hm1\1.txt)", "r", stdin);
    queue st;
    string command;
    int var;
    while(cin >> command){
        if (command == "size_counter") cout << st.size() << endl;
        if(command == "push"){
            cin >> var;
            st.push_top(var);
            cout << "ok" << endl;
        }
        if(command == "front"){
            if (st.size() != 0) {
                cout << st.front() << endl;
            }
            else {
                cout << "error" << endl;
            }

        }
        if (command == "clear"){
            st.clear();
            cout << "ok" << endl;
        }
        if(command == "pop"){
            if(st.size()){
                cout << st.pop_front() << endl;
            }else{
                cout << "error\n";
            }
        }
        if(command == "exit"){
            cout << "bye" << endl;
            return 0;
        }
    }

    cout << 1;
    return 0;
}