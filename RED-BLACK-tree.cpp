#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int color;
    Node *left;
    Node *right;
    Node(int key, int color)
    {
        this->key = key;
        this->color = color;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Properties of RED-Black trees

// 1 -> nodes are either re / black;

// 2 root node is black

// 3 null nodes are always black

// 4 children of a red node are black

// 5 no of black nodes in any valid path form root to node contain equal no of red nodes

class RedBlackTree
{
    Node *root;

public:
    RedBlackTree()
    {
        root = nullptr;
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

    Node *insert( Node * root , int key){
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}