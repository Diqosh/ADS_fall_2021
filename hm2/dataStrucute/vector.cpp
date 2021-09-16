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

    void insert(int pos, int element){
        if(pos == 1){
            push_front(element);
        }else if(pos == size_counter+1){
            push_back(element);
        }else if(1 < pos and pos < size_counter + 1){
            int first_element_index = pos - 1, second_element_index = pos, cnt = 1;
            node *first_node = nullptr, * second_node = nullptr, *temp_node = nullptr, *new_node = new node(element);
            temp_node = front_node;
            while(true){
                if (cnt == first_element_index){
                    first_node = temp_node;
                    break;
                }
                cnt++;
                temp_node = temp_node->next;
            }

            while(true){
                if (cnt == second_element_index){
                    second_node = temp_node;
                    break;
                }
                cnt++;
                temp_node = temp_node->next;
            }
            first_node->next = new_node;
            new_node->prev = first_node;
            new_node->next = second_node;
            second_node->prev = new_node;
        }
    }
    void delete_node(int pos){
        if(pos == 1){
            pop_front();
        }else if(pos == size_counter){
            pop_rear();
        }else if(1 < pos and pos < size_counter){
            int first_element_index = pos - 1, second_element_index = pos+1, cnt = 1;
            node *first_node = nullptr, * second_node = nullptr, *to_delete_node, *temp_node = nullptr;
            temp_node = front_node;
            while(true){
                if (cnt == first_element_index){
                    first_node = temp_node;
                    break;
                }
                cnt++;
                temp_node = temp_node->next;
            }
            while(true){
                if (cnt == pos){
                    to_delete_node = temp_node;
                    break;
                }
                cnt++;
                temp_node = temp_node->next;
            }

            while(true){
                if (cnt == second_element_index){
                    second_node = temp_node;
                    break;
                }
                cnt++;
                temp_node = temp_node->next;
            }
            first_node->next = second_node;
            second_node->prev = first_node;
            delete to_delete_node;
        }
    }
    node * find_node(int item){
        node * temp = front_node;
        node * result = nullptr;
        while(temp != nullptr){
            if(temp->value == item){
                result = temp;
                break;
            }
            temp = temp->next;
        }
        return result;
    }
    int find_pos(int item){
        int cnt = 0;
        node * temp = front_node;
        node * result = nullptr;
        while(temp != nullptr){
            if(temp->value == item){
                result = temp;
                break;
            }
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }


};
// delete;


int main(){

    vector_ll v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.delete_node(4);
    while (!v.empty()){
        cout << v.pop_front() << endl;
    }
    return 0;
}