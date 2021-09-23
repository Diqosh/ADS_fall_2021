#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    node *prev;
    node *next;
    int value;
    node(int a){
        value = a;
        prev = nullptr;
        next = nullptr;
    }
};

struct vector_ll{
private:
    node *front_node, *rear_node;
    int size_counter = 0;
public:
    vector_ll(){
        front_node = rear_node = nullptr;
    }
    void push_front(int item){
        size_counter++;
        node *new_node = new node(item);
        if(front_node == nullptr){
            front_node = rear_node = new_node;
        }else{
            front_node->prev = new_node;
            new_node->next = front_node;
            front_node = new_node;
        }
    }

    void push_back(int item){
        size_counter++;
        node *new_node = new node(item);
        if(rear_node == nullptr){
            front_node = rear_node = new_node;
        }else{
            rear_node->next = new_node;
            new_node->prev = rear_node;
            rear_node = new_node;
        }
    }

    int pop_rear(){
        if(rear_node != nullptr){
            size_counter--;
            int item_to_show = rear_node->value;
            if (rear_node->prev != nullptr){
                rear_node = rear_node->prev;
                rear_node->next = nullptr;
            }else{
                rear_node = front_node = nullptr;
            }
            return item_to_show;
        }
        return -1;
    }

    int pop_front(){
        if(front_node != nullptr){
            size_counter--;
            int item_to_show = front_node->value;
            if(front_node->next != nullptr){
                front_node = front_node->next;
                front_node->prev = nullptr;
            }else{
                front_node = rear_node = nullptr;
            }
            return  item_to_show;
        }
        return -1;
    }
    bool empty(){
        return front_node == nullptr;
    }

    int size(){
        return size_counter;
    }

    void insert(int pos, int element){

    }
    void delete_node(node *del){
        if (front_node == nullptr || del == nullptr) return;

        if(front_node == del) front_node = del->next;

        if(del->next != nullptr) del->next->prev = del->prev;

        if(del->prev != nullptr) del->prev->next = del->next;

        free(del);
    }
    void delete_node_at_pos(int pos){
        node *current = front_node;

        for(int i = 0; current != nullptr and i < pos;i++)
            current = current->next;

        if (current == nullptr) return;

        delete_node(current);
    }

    int find_pos(int item){
        node *temp = front_node;
        for (int i = 0; temp != nullptr && i < size_counter; ++i) {
            if (temp->value == item) return i;
            temp = temp->next;
        }
        return -1;
    }


};

int main(){
    freopen("input.txt", "r", stdin);
    vector_ll v;
    vector<int> vi;
    string s;

    ofstream f;
    f.open("output.txt");
    while (cin >> s){

        int a = stoi(s.substr(1));


        if (s[0] == '+'){

            v.push_back(a);
        }else if(s[0] == '-'){

            if(v.find_pos(a) == -1){
                f << "ERROR";
                return 0;
            }else{
                int pos =  v.find_pos(a);
                v.delete_node_at_pos(pos);
            }

        }
    }
    if (v.empty()) {
        f << "EMPTY";
    }
    while (!v.empty()){
        vi.push_back(v.pop_front()) ;
    }
    sort(vi.begin(), vi.end());
    for (auto i : vi){
        f << i << " ";
    }



    return 0;
}