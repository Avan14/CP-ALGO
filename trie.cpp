#include <iostream>
using namespace std;

class Node
{
public:
    Node *links[26];
    bool flag = false;
    bool contiainsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }
    void put(char c, Node *node)
    {
        links[c = 'a'] = node;
    }
    Node *get(char c)
    {
        return links[c - 'a'];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node *node = root;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->contiainsKey(s[i]))
            {
                node->put(s[i], new Node());
            }
            node->get(s[i]);
        }
        node->flag = true;
    }
    bool search(string s)
    {
        Node *node = root;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->contiainsKey(s[i]))
            {
                return false;
            }
            node->get(s[i]);
        }
        return node->flag;
    }
    bool startsWith(string s)
    {
        Node *node = root;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->contiainsKey(s[i]))
            {
                return false;
            }
            node->get(s[i]);
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}