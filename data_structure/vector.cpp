#include <iostream>

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
    int get_value_at_pos(int pos){
        node *temp_node = front_node;
        for (int i = 0; temp_node != nullptr && i < size_counter; ++i) {
            if (i == pos){
                return temp_node->value;
            }
            temp_node = temp_node->next;
        }
        return -1;
    }

    void insert(int pos, int element){
        if (pos == 0) push_front(element);
        if(pos == size_counter) push_back(element);
        node *temp_node = front_node;
        node *new_node = new node(element);
        for (int i = 0; temp_node != nullptr && i < size_counter; ++i) {
            if (i == pos){
                if (temp_node->prev != nullptr){
                    temp_node->prev->next = new_node;
                    new_node->prev = temp_node->prev;
                }
                temp_node->prev = new_node;
                new_node->next = temp_node;
            }

            temp_node = temp_node->next;
        }
    }
    void delete_node(node *del){
        if (front_node == nullptr || del == nullptr) return;

        if(front_node == del) front_node = del->next;

        if(del->next != nullptr) del->next->prev = del->prev;

        if(del->prev != nullptr) del->prev->next = del->next;

        free(del);
        size_counter--;
    }
    void delete_node_at_pos(int pos){
        node *current = front_node;
        if (pos == 0) pop_front();
        if (pos == size_counter - 1) pop_rear();
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
    void clear(){
        node *temp = front_node;
        node *del = temp;
        for (int i = 0; temp != nullptr && i < size_counter; ++i) {
            temp = temp->next;
            free(del);
            del = temp;
        }
        front_node = rear_node = nullptr;
        size_counter = 0;
    }


};
// delete;


int main(){

    vector_ll v, v2;
    int arr[] = {1, 4, 5, 7, 8};
    int a = sizeof (arr)/ sizeof(int);
    for (int i = 0; i < a; ++i) {
        v.push_back(arr[i]);
    }

    while (!v.empty()){
        cout << v.get_value_at_pos(v.size()-1) << endl;
        v.pop_rear();
    }

    return 0;
}