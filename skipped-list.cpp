#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
public:
    int key;
    vector<Node*> forward;

    Node(int k, int level) : key(k), forward(level + 1, nullptr) {}
};

class SkipList {
    int MAXLVL;     // maximum level for the list
    float P;        // probability for random level generator
    int level;      // current max level of skip list
    Node* header;   // pointer to header node

public:
    SkipList(int MAXLVL = 16, float P = 0.5) {
        this->MAXLVL = MAXLVL;
        this->P = P;
        this->level = 0;
        header = new Node(-1, MAXLVL); // dummy head
    }

    int randomLevel() {
        int lvl = 0;
        while (((float)rand() / RAND_MAX) < P && lvl < MAXLVL)
            lvl++;
        return lvl;
    }

    void insert(int key) {
        vector<Node*> update(MAXLVL + 1);
        Node* current = header;

        // Find place to insert, update[] stores path
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (!current || current->key != key) { // insert only if not present
            int rlevel = randomLevel();
            if (rlevel > level) {
                for (int i = level + 1; i <= rlevel; i++) {
                    update[i] = header;
                }
                level = rlevel;
            }

            Node* n = new Node(key, rlevel);
            for (int i = 0; i <= rlevel; i++) {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }
        }
    }

    bool search(int key) {
        Node* current = header;
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
        }
        current = current->forward[0];
        return (current && current->key == key);
    }

    void erase(int key) {
        vector<Node*> update(MAXLVL + 1);
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];
        if (current && current->key == key) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != current) break;
                update[i]->forward[i] = current->forward[i];
            }
            delete current;

            while (level > 0 && header->forward[level] == nullptr) {
                level--; // reduce skip list level if empty
            }
        }
    }

    void display() {
        cout << "\n***** Skip List *****\n";
        for (int i = level; i >= 0; i--) {
            Node* node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node) {
                cout << node->key << " ";
                node = node->forward[i];
            }
            cout << "\n";
        }
    }
};

int main() {
    srand(time(0));

    SkipList lst(16, 0.5);

    lst.insert(3);
    lst.insert(6);
    lst.insert(7);
    lst.insert(9);
    lst.insert(12);
    lst.insert(19);
    lst.insert(17);
    lst.insert(26);
    lst.insert(21);
    lst.insert(25);

    lst.display();

    cout << "\nSearch 19: " << (lst.search(19) ? "Found" : "Not Found") << endl;
    cout << "Search 15: " << (lst.search(15) ? "Found" : "Not Found") << endl;

    lst.erase(19);
    cout << "\nAfter deleting 19\n";
    lst.display();

    return 0;
}
