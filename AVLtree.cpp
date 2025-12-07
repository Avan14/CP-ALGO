#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int baf(Node *node)
{
    if (!node) return 0;
    int lh = node->left ? node->left->height : 0;
    int rh = node->right ? node->right->height : 0;
    return lh - rh;
}

int getH(Node* n) {
    return n ? n->height : 0;
}

class AVLtree
{
    Node *root;

public:
    AVLtree()
    {
        root = nullptr;
    }

    Node *leftRotate(Node *A)
    {
        Node *B = A->right;
        Node *Y = B->left;

        B->left = A;
        A->right = Y;

        A->height = 1 + max(getH(A->left), getH(A->right));
        B->height = 1 + max(getH(B->left), getH(B->right));

        return B;
    }

    Node *rightRotate(Node *A)
    {
        Node *B = A->left;
        Node *Y = B->right;

        B->right = A;
        A->left = Y;

        A->height = 1 + max(getH(A->left), getH(A->right));
        B->height = 1 + max(getH(B->left), getH(B->right));

        return B;
    }

    Node *insert(Node *node, int key)
    {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(getH(node->left), getH(node->right));
        int bf = baf(node);

        if (bf > 1 && key < node->left->key)
            return rightRotate(node);

        if (bf < -1 && key > node->right->key)
            return leftRotate(node);

        if (bf > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (bf < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    bool search(int key)
    {
        Node *current = root;
        while (current)
        {
            if (current->key == key)
                return true;
            if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    Node *inOrderSucesspor(Node *node)
    {
        Node *cur = node;
        while (cur->left)
            cur = cur->left;
        return cur;
    }

    Node * remove(Node *node, int key)
    {
        if (!node)
            return node;

        if (key < node->key)
            node->left = remove(node->left, key);
        else if (key > node->key)
            node->right = remove(node->right, key);
        else
        {
            if (!node->left && !node->right)
            {
                delete node;
                return nullptr;
            }
            else if (!node->left)
            {
                Node *tmp = node->right;
                delete node;
                return tmp;
            }
            else if (!node->right)
            {
                Node *tmp = node->left;
                delete node;
                return tmp;
            }
            else
            {
                Node *tmp = inOrderSucesspor(node->right);
                node->key = tmp->key;
                node->right = remove(node->right, tmp->key);
            }
        }

        node->height = 1 + max(getH(node->left), getH(node->right));
        int bf = baf(node);

        if (bf > 1 && baf(node->left) >= 0)
            return rightRotate(node);

        if (bf < -1 && baf(node->right) <= 0)
            return leftRotate(node);

        if (bf > 1 && baf(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (bf < -1 && baf(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}
