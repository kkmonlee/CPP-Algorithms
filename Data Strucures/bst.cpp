#include <stdio.h>
#include <iostream>

#define MAX_D 10001
using namespace std;
typedef long long lld;

class BST;

class Node {
    public:
        char key;
        int satelliteData;

        Node();
        Node(char key, int satelliteData);

        BST *left;
        BST *right;
        Node *parent;

        BST *myTree;
};

class BST {
    public:
        Node *root;

        BST();
        BST(Node *root);

        bool isEmpty();

        Node *search(char key);

        Node *minimum();
        Node *maximum();

        Node *predecessor(Node *x);
        Node *successor(Node *x);

        void Insert(Node *x);
        void Delete(Node *x);

        void set(char key, int value);

        void inOrderPrint(bool brackets);

        void prettyPrint();
};

Node::Node(char key, int satelliteData) {
    this->key = key;
    this->satelliteData = satelliteData;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
    this->myTree = NULL;
}

BST::BST() {
    this->root = NULL;
}

bool BST::isEmpty() {
    return (root == NULL);
}

Node *BST::search(char key) {
    if (isEmpty())
        return NULL;
    if (root->key > key)
        return root->left->search(key);
    else if (root->key < key)
        return root->right->search(key);
    else
        return root;
}

Node *BST::maximum() {
    if (isEmpty())
        return NULL;
    if (root->right == NULL)
        return root;
    return root->right->maximum();
}

Node *BST::minimum() {
    if (isEmpty())
        return NULL;
    if (root->left == NULL)
        return root;
    return root->left->minimum();
}

Node *BST::predecessor(Node *x) {
    if (x->left != NULL)
        return x->left->maximum();
    Node *top = x->parent;
    while (top != NULL && top -> key > x -> key) {
        x = top;
        top = top->parent;
    }
    return top;
}

Node *BST::successor(Node *x) {
    if (x->right != NULL)
        return x->right->minimum();
    Node *top = x->parent;
    while (top != NULL && top->key < x->key) {
        x = top;
        top = top->parent;
    }
    return top;
}

void BST::Insert(Node *x) {
    if (isEmpty()) {
        Node *n = new Node(x->key, x->satelliteData);
        n->parent = NULL;
        n->myTree = this;
        root = n;
        return;
    }

    Node *curr = root;

    while (true) {
        if (x->key < curr->key) {
            if (curr->left == NULL) {
                BST *L = new BST();
                Node *n = new Node(x->key, x->satelliteData);
                n->parent = curr;
                n->myTree = L;
                L->root = n;
                curr->left = L;
                return;
            } else curr = curr->left->root;
        } else if (x->key > curr->key) {
            if (curr->right == NULL) {
                BST *R = new BST();
                Node *n = new Node(x->key, x->satelliteData);
                n->parent = curr;
                n->myTree = R;
                R->root = n;
                curr->right = R;
                return;
            } else curr = curr->right->root;
        } else return;
    }
}

void BST::Delete(Node *del) {
    Node *tmp;

    if (del->left == NULL && del->right == NULL) {
        if (del->parent != NULL) {
            if (del->parent->left != NULL && del->parent->left->root->key == del->key) {
                del->parent->left = NULL;
            } else if (del->parent->right != NULL && del->parent->right->root->key == del->key) {
                del->parent->right = NULL;
            }
        }
        delete del;
        return;
    }
    
    if (del->right == NULL) {
        tmp = del->left->root;
        if (del->parent != NULL) {
            if (del->parent->left != NULL && del->parent->left->root->key == del->key) {
                del->parent->left = tmp->myTreel
            } else if (del->parent->right != NULL && del->parent->right->root->key == del->key) {
                del->parent->right = tmp->myTree;
            }
        }
        tmp->parent = del->parent;
        delete del;
        return;
    } else {
        tmp = successor(del);
        del->key = tmp->key;
        del->satelliteData = tmp->satelliteData;
        Delete(tmp);
    }
}

void BST::set(char key, int value) {
    if (search(key) != NULL) {
        Insert(new Node(key, value));
    }
}

void BST::inOrderPrint(bool brackets) {
    if (root == NULL) {
        if (brackets) printf("{}");
        return;
    }

    if (brackets) printf("{");
    if (root->left != NULL) root-left->inOrderPrint(brackets);
    if (root != NULL) printf(" %c ", root->key);
    if (root->right != NULL) root->right->inOrderPrint(brackets);
    if (brackets) printf("}");
}

int main() {
    // Test with
    // BST *test = new BST();
    // test->inOrderPrint(true);
}
