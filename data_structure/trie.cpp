#include <iostream>

using namespace std;

const int N = 26;


class Node {

public:
    char value;
    Node *ch[N];

    Node(char value){
        this->value = value;
        for (int i = 0; i < N; ++i) {
            ch[i] = nullptr;
        }
    }
};


class Trie{
public:
    int cnt;
    Node *root;
    Trie(){
        root = new Node(' ');
        cnt = 0;
    }

    void insert(string s){
        Node *cur_node = root;
        for (int i = 0; i < s.size(); ++i) {
            if(cur_node->ch[s[i] - 'a'] != nullptr){
                cur_node = cur_node->ch[s[i] - 'a'];
            }else{
                Node *node = new Node(s[i]);
                cur_node->ch[s[i] - 'a'] = node;
                cur_node = node;
                cnt++;
            }
        }
    }
};


int main(){
    Trie *t = new Trie();
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        t->insert(s.substr(i));
    }
    cout << t->cnt;

    return 0;
}

