#include <iostream>

using namespace std;

struct node {

    string value;
    node *prev;
    node *next;

    explicit node(string x) {
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

    void push_top(string item) {
        cnt++;
        node *new_head_node = new node(item);
        if (front_node == nullptr) {
            front_node = rear_node =  new_head_node;
        } else {
            rear_node->next = new_head_node;
            rear_node = new_head_node;
        }
    }

    string front() {
        if (front_node != nullptr) {
            return front_node->value;
        }
        return "";
    }

    string pop_front() {
        if(front_node != nullptr){
            string item_to_show = front_node->value;
            cnt--;

            front_node = front_node->next;
            if(front_node == nullptr){
                rear_node = nullptr;
            }else{
                front_node->prev = nullptr;
            }

            return item_to_show;
        }
        return "";
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



    //freopen(R"(D:\kbtu\3\2021\ADS\hm1\1.txt)", "r", stdin);
    int class_num; string surname;

    queue nine; queue ten ;queue eleven;

    while(cin >> class_num){
        cin >> surname;
        if(class_num == 9){
            nine.push_top(surname);
        }
        if(class_num == 10){
            ten.push_top(surname);
        }
        if(class_num == 11){
            eleven.push_top(surname);
        }
    }

    while (!nine.empty()){
        cout << "9 "<<  nine.pop_front() << endl;
    }
    while (!ten.empty()){
        cout << "10 "<< ten.pop_front() << endl;
    }
    while (!eleven.empty()){
        cout << "11 "<< eleven.pop_front() << endl;
    }

    return 0;
}