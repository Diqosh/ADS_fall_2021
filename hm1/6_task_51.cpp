#include <iostream>

using namespace std;
struct node{

    char value;
    node * prev;
    node * next;

    explicit node(char x){
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

    void push(char item){
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

    char top(){
        if (rear_node != nullptr){
            return rear_node->value;
        }
        return '\0';
    }

    char pop(){
        if (rear_node != nullptr){
            char item_to_show = rear_node->value;
            cnt--;
            rear_node = rear_node->prev;
            return item_to_show;
        }
        return '\0';
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
int main(){
    freopen(R"(D:\kbtu\3\2021\ADS\informatics_hm1\1.txt)", "r", stdin);
    stack st;
    char bracket;
    while(cin >> bracket){
        if (bracket == '(' or bracket == '{' or bracket == '['){
            st.push(bracket);
        }else{

            if((bracket==')' and st.top() == '(') or (bracket==']' and st.top() == '[') or (bracket=='}' and st.top() == '{')){
                st.pop();
            }else{
                cout << "no";
                return 0;
            }
        }
    }
    if(st.empty()){
        cout << "yes";
    }else{
        cout << "no";
    }


    return 0;
}
