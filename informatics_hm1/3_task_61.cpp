#include <iostream>

using namespace std;


struct node {
    int value;
    node *next;
    node *prev;

    node(int x) {
        value = x;
        next = nullptr;
        prev = nullptr;
    }
};

struct deque {
protected:
    node *front_node, *rear_node;
    int cnt;
public:
    deque() {
        front_node = rear_node = nullptr;
        cnt = 0;
    }

    void push_front(int item) {
        cnt++;
        node *new_back_node = new node(item);
        if (front_node == nullptr) {
            front_node = new_back_node;
            rear_node = new_back_node;
        } else {
            front_node->prev = new_back_node;
            new_back_node->next = front_node;
            front_node = new_back_node;
        }
    }

    void push_rear(int item) {
        cnt++;
        node *new_top_node = new node(item);
        if (front_node == nullptr) {
            front_node = new_top_node;
            rear_node = new_top_node;
        } else {
            rear_node->next = new_top_node;
            new_top_node->prev = rear_node;
            rear_node = new_top_node;
        }
    }

    int pop_front() {
        if (front_node != nullptr) {
            int item_to_show = front_node->value;
            --cnt;
            front_node = front_node->next;
            if (front_node != nullptr) {
                front_node->prev = nullptr;
            }
            if (front_node == nullptr) rear_node = nullptr;
            return item_to_show;
        }
        return -1;


    }

    int pop_rear() {
        if (rear_node != nullptr) {
            int item_to_show = rear_node->value;
            --cnt;
            rear_node = rear_node->prev;
            if (rear_node != nullptr) {
                rear_node->next = nullptr;
            }
            if (rear_node == nullptr) front_node = nullptr;
            return item_to_show;
        }
        return -1;

    }

    int front() {
        if (front_node != nullptr) {
            return front_node->value;
        }
        return -1;
    }

    int rear() {
        if (rear_node != nullptr) {
            return rear_node->value;
        }
        return -1;
    }

    void clear() {
        front_node = rear_node = nullptr;
        cnt = 0;
    }


    int size() {
        return cnt;
    }
};

int main() {
    //freopen(R"(D:\kbtu\3\2021\ADS\informatics_hm1\1.txt)", "r", stdin);
    deque dq;
    string command;
    int var;
    while (cin >> command) {
        if (command == "push_front") {
            cin >> var;
            dq.push_front(var);
            cout << "ok" << endl;
        }
        if (command == "push_back") {
            cin >> var;
            dq.push_rear(var);
            cout << "ok" << endl;
        }

        if (command == "pop_front") {
            if (dq.size() != 0) cout << dq.pop_front() << endl;
            else cout << "error" << endl;
        }

        if (command == "pop_back") {
            if (dq.size() != 0) cout << dq.pop_rear() << endl;
            else cout << "error" << endl;
        }

        if (command == "front") {
            if (dq.size() != 0) cout << dq.front() << endl;
            else cout << "error" << endl;
        }

        if (command == "back") {
            if (dq.size() != 0) cout << dq.rear() << endl;
            else cout << "error" << endl;
        }

        if (command == "size") cout << dq.size() << endl;

        if (command == "clear") {
            dq.clear();
            cout << "ok\n";
        }

        if (command == "exit") {
            cout << "bye" << endl;
            return 0;
        }
    }

    return 0;
}
