#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



class BST {

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (node->data >= data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    Node *findMin(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }


    Node *delete_node(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = delete_node(node->left, data);
        else if (data > node->data)
            node->right = delete_node(node->right, data);
        else {
            if (node->left == NULL && node->right == NULL)
                node = NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *tmp = findMin(node->right);
                node->data = tmp->data;
                node->right = delete_node(node->right, tmp->data);
            }
        }
        return node;
    }
    bool find(Node * current, int x){
        if(current == NULL) return false;
        if(current->data == x) return true;
        if(current->data > x) return find(current->left, x);
        return find(current->right, x);
    }

public:
    Node *root;
    BST() {
        root = NULL;
    }
    void add(int x){
        Node * res = insert(root, x);

        if(root == NULL){
            root = res;
        }
    }
    void del(int x){
        root = delete_node(root, x);
    }
    int max(){
        return findMax(root)->data;
    }

    bool find(int x){
        return find(root, x);
    }

};


