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

int main(){
    //freopen(R"(D:\kbtu\3\2021\ADS\informatics_hm1\1.txt)", "r", stdin);
    queue first;
    queue second;
    int cnt = 0;

    int a, first_item, second_item;
    for (int i = 0; i < 5; ++i) {
        cin >> a;
        first.push_top(a);
    }
    for (int i = 0; i < 5; ++i) {
        cin >> a;
        second.push_top(a);
    }
    while(!first.empty() && !second.empty()){
        first_item = first.front(), second_item = second.front();
        if((first_item == 0 && second_item == 9) || (first_item == 9 && second_item == 0)){
            if(first_item == 0){
                first.push_top(first.pop_front());
                first.push_top(second.pop_front());
                cnt++;
            }else{
                second.push_top(first.pop_front());
                second.push_top(second.pop_front());
                cnt++;
            }
        }else{
            if(first_item > second_item){
                first.push_top(first.pop_front());
                first.push_top(second.pop_front());
                cnt++;
            }else{
                second.push_top(first.pop_front());
                second.push_top(second.pop_front());
                cnt++;
            }
        }
    }
    if(cnt > 1000000){
        cout << "botva";
        return 0;
    }
    if(!first.empty()){
        cout << "first "<< cnt;;
    }else{
        cout << "second "<< cnt;
    }




    return 0;
}
