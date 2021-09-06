
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
    node * rear_node;
    int cnt;
public:
    stack(){
        rear_node = nullptr;
        cnt = 0;
    }

    void push(int item){
        node *new_head_node = new node(item);
        cnt++;

        if (rear_node == nullptr) {
            rear_node = new_head_node;
        }else{
            rear_node->next = new_head_node;
            new_head_node->prev = rear_node;
            rear_node = new_head_node;
        }
    }

    int top(){
        if (rear_node != nullptr){
            return rear_node->value;
        }
        return -1;
    }

    int pop(){
        if (rear_node != nullptr){
            int item_to_show = rear_node->value;
            cnt--;
            rear_node = rear_node->prev;
            return item_to_show;
        }
        return -1;
    }

    bool empty(){
        return rear_node == nullptr;
    }

    void clear(){
        while(rear_node != nullptr){
            rear_node = rear_node->prev;
            if(rear_node != nullptr){
                rear_node->next = nullptr;
            }
        }
        cnt = 0;
    }

    int size(){
        return cnt;
    }
};


