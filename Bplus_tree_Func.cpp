#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <random>

using namespace std;

struct Node {
    Node* parent;
    vector<int> keys;
    vector<Node*> children;
    vector<int> values;
    bool isLeaf;
    Node* next;
    Node* prev;
};

Node* createNode(Node* parent = nullptr, bool isLeaf = false, Node* prev = nullptr, Node* next = nullptr) {
    Node* node = new Node;
    node->parent = parent;
    node->isLeaf = isLeaf;
    node->prev = prev;
    node->next = next;
    return node;
}

int indexOfChild(Node* node, int key) {
    for (int i = 0; i < node->keys.size(); i++) {
        if (key < node->keys[i]) {
            return i;
        }
    }
    return node->keys.size();
}

int indexOfKey(Node* node, int key) {
    for (int i = 0; i < node->keys.size(); i++) {
        if (key == node->keys[i]) {
            return i;
        }
    }
    return -1;
}

Node* getChild(Node* node, int key) {
    return node->children[indexOfChild(node, key)];
}

tuple<int, Node*, Node*> splitInternal(Node* node) {
    Node* left = createNode(node->parent, false, nullptr, nullptr);
    int mid = node->keys.size() / 2;

    copy(node->keys.begin(), node->keys.begin() + mid, back_inserter(left->keys));
    copy(node->children.begin(), node->children.begin() + mid + 1, back_inserter(left->children));

    for (Node* child : left->children) {
        child->parent = left;
    }

    int key = node->keys[mid];
    node->keys.erase(node->keys.begin(), node->keys.begin() + mid + 1);
    node->children.erase(node->children.begin(), node->children.begin() + mid + 1);

    return make_tuple(key, left, node);
}

int get(Node* node, int key) {
    int index = indexOfKey(node, key);
    if (index == -1) {
        cout << "key " << key << " not found" << endl;
        return -1;
    }
    return node->values[index];
}

void set(Node* node, int key, int value) {
    int i = indexOfChild(node, key);
    if (find(node->keys.begin(), node->keys.end(), key) == node->keys.end()) {
        node->keys.insert(node->keys.begin() + i, key);
        node->values.insert(node->values.begin() + i, value);
    } else {
        node->values[i - 1] = value;
    }
}

tuple<int, Node*, Node*> splitLeaf(Node* node) {
    Node* left = createNode(node->parent, true, node->prev, node);
    int mid = node->keys.size() / 2;

    left->keys = vector<int>(node->keys.begin(), node->keys.begin() + mid);
    left->values = vector<int>(node->values.begin(), node->values.begin() + mid);

    node->keys.erase(node->keys.begin(), node->keys.begin() + mid);
    node->values.erase(node->values.begin(), node->values.begin() + mid);

    return make_tuple(node->keys[0], left, node);
}

Node* findLeaf(Node* root, int key) {
    Node* node = root;
    while (!node->isLeaf) {
        node = getChild(node, key);
    }
    return node;
}

void insert(Node*& root, tuple<int, Node*, Node*> result) {
    int key = get<0>(result);
    Node* left = get<1>(result);
    Node* right = get<2>(result);
    Node* parent = right->parent;
    if (parent == nullptr) {
        left->parent = right->parent = root = createNode(nullptr, false, nullptr, nullptr);
        root->keys = { key };
        root->children = { left, right };
        return;
    }
    parent->children[indexOfChild(parent, key)] = left;
    parent->keys.insert(parent->keys.begin() + indexOfChild(parent, key), key);
    if (parent->keys.size() > 2) {
        insert(root, splitInternal(parent));
    }
}

void removeFromLeaf(Node* node, int key) {
    int index = indexOfKey(node, key);
    if (index == -1) {
        cout << "Key " << key << " not found! Exiting ..." << endl;
        exit(0);
    }
    node->keys.erase(node->keys.begin() + index);
    node->values.erase(node->values.begin() + index);
    if (node->parent) {
        int indexInParent = indexOfChild(node->parent, key);
        if (indexInParent)
            node->parent->keys[indexInParent - 1] = node->keys.front();
    }
}

void removeFromInternal(Node* node, int key) {
    int index = indexOfKey(node, key);
    if (index != -1) {
        Node* leftMostLeaf = node->children[index + 1];
        while (!leftMostLeaf->isLeaf)
            leftMostLeaf = leftMostLeaf->children.front();

        node->keys[index] = leftMostLeaf->keys.front();
    }
}

void borrowKeyFromRightLeaf(Node* node, Node* next) {
    node->keys.push_back(next->keys.front());
    next->keys.erase(next->keys.begin());
    node->values.push_back(next->values.front());
    next->values.erase(next->values.begin());
    for (int i = 0; i < node->parent->children.size(); i++) {
        if (node->parent->children[i] == next) {
            node->parent->keys[i - 1] = next->keys.front();
            break;
        }
    }
}

void borrowKeyFromLeftLeaf(Node* node, Node* prev) {
    node->keys.insert(node->keys.begin(), prev->keys.back());
    prev->keys.erase(prev->keys.end() - 1);
    node->values.insert(node->values.begin(), prev->values.back());
    prev->values.erase(prev->values.end() - 1);
    for (int i = 0; i < node->parent->children.size(); i++) {
        if (node->parent->children[i] == node) {
            node->parent->keys[i - 1] = node->keys.front();
            break;
        }
    }
}

void mergeNodeWithRightLeaf(Node* node, Node* next) {
    node->keys.insert(node->keys.end(), next->keys.begin(), next->keys.end());
    node->values.insert(node->values.end(), next->values.begin(), next->values.end());
    node->next = next->next;
    if (node->next) node->next->prev = node;
    for (int i = 0; i < next->parent->children.size(); i++) {
        if (next->parent->children[i] == next) {
            next->parent->keys.erase(next->parent->keys.begin() + i - 1);
            next->parent->children.erase(next->parent->children.begin() + i);
            break;
        }
    }
}

void mergeNodeWithLeftLeaf(Node* node, Node* prev) {
    prev->keys.insert(prev->keys.end(), node->keys.begin(), node->keys.end());
    prev->values.insert(prev->values.end(), node->values.begin(), node->values.end());
    prev->next = node->next;
    if (prev->next) prev->next->prev = prev;
    for (int i = 0; i < node->parent->children.size(); i++) {
        if (node->parent->children[i] == node) {
            node->parent->keys.erase(node->parent->keys.begin() + i - 1);
            node->parent->children.erase(node->parent->children.begin() + i);
            break;
        }
    }
}

void borrowKeyFromRightInternal(int myPositionInParent, Node* node, Node* next) {
    node->keys.insert(node->keys.end(), node->parent->keys[myPositionInParent]);
    node->parent->keys[myPositionInParent] = next->keys.front();
    next->keys.erase(next->keys.begin());
    node->children.insert(node->children.end(), next->children.front());
    next->children.erase(next->children.begin());
    node->children.back()->parent = node;
}

void borrowKeyFromLeftInternal(int myPositionInParent, Node* node, Node* prev) {
    node->keys.insert(node->keys.begin(), node->parent->keys[myPositionInParent - 1]);
    node->parent->keys[myPositionInParent - 1] = prev->keys.back();
    prev->keys.erase(prev->keys.end() - 1);
    node->children.insert(node->children.begin(), prev->children.back());
    prev->children.erase(prev->children.end() - 1);
    node->children.front()->parent = node;
}

void mergeNodeWithRightInternal(int myPositionInParent, Node* node, Node* next) {
    node->keys.insert(node->keys.end(), node->parent->keys[myPositionInParent]);
    node->parent->keys.erase(node->parent->keys.begin() + myPositionInParent);
    node->parent->children.erase(node->parent->children.begin() + myPositionInParent + 1);
    node->keys.insert(node->keys.end(), next->keys.begin(), next->keys.end());
    node->children.insert(node->children.end(), next->children.begin(), next->children.end());
    for (Node* child : node->children) {
        child->parent = node;
    }
}

void mergeNodeWithLeftInternal(int myPositionInParent, Node* node, Node* prev) {
    prev->keys.insert(prev->keys.end(), node->parent->keys[myPositionInParent - 1]);
    node->parent->keys.erase(node->parent->keys.begin() + myPositionInParent - 1);
    node->parent->children.erase(node->parent->children.begin() + myPositionInParent);
    prev->keys.insert(prev->keys.end(), node->keys.begin(), node->keys.end());
    prev->children.insert(prev->children.end(), node->children.begin(), node->children.end());
    for (Node* child : prev->children) {
        child->parent = prev;
    }
}

void remove(Node*& root, int key, Node* node = nullptr) {
    if (node == nullptr) {
        node = findLeaf(root, key);
    }
    if (node->isLeaf) {
        removeFromLeaf(node, key);
    } else {
        removeFromInternal(node, key);
    }

    if (node->keys.size() < 2) {
        if (node == root) {
            if (root->keys.empty() && !root->children.empty()) {
                root = root->children[0];
                root->parent = nullptr;
            }
            return;
        } else if (node->isLeaf) {
            Node* next = node->next;
            Node* prev = node->prev;

            if (next && next->parent == node->parent &&
                next->keys.size() > 2) {
                borrowKeyFromRightLeaf(node, next);
            } else if (prev && prev->parent == node->parent &&
                prev->keys.size() > 2) {
                borrowKeyFromLeftLeaf(node, prev);
            } else if (next && next->parent == node->parent &&
                next->keys.size() <= 2) {
                mergeNodeWithRightLeaf(node, next);
            } else if (prev && prev->parent == node->parent &&
                prev->keys.size() <= 2) {
                mergeNodeWithLeftLeaf(node, prev);
            }
        } else {
            int myPositionInParent = -1;

            for (int i = 0; i < node->parent->children.size(); i++) {
                if (node->parent->children[i] == node) {
                    myPositionInParent = i;
                    break;
                }
            }

            Node* next;
            Node* prev;

            if (node->parent->children.size() > myPositionInParent + 1) {
                next = node->parent->children[myPositionInParent + 1];
            } else {
                next = nullptr;
            }

            if (myPositionInParent) {
                prev = node->parent->children[myPositionInParent - 1];
            } else {
                prev = nullptr;
            }

            if (next && next->parent == node->parent &&
                next->keys.size() > 2) {
                borrowKeyFromRightInternal(myPositionInParent, node, next);
            } else if (prev && prev->parent == node->parent &&
                prev->keys.size() > 2) {
                borrowKeyFromLeftInternal(myPositionInParent, node, prev);
            } else if (next && next->parent == node->parent &&
                next->keys.size() <= 2) {
                mergeNodeWithRightInternal(myPositionInParent, node, next);
            } else if (prev && prev->parent == node->parent &&
                prev->keys.size() <= 2) {
                mergeNodeWithLeftInternal(myPositionInParent, node, prev);
            }
        }
    }
    if (node->parent) {
        remove(root, key, node->parent);
    }
}

void print(Node* root = nullptr, string prefix = "", bool last = true) {
    if (!root) root = createNode(nullptr, true, nullptr, nullptr);
    cout << prefix << "├ [";
    for (int i = 0; i < root->keys.size(); i++) {
        cout << root->keys[i];
        if (i != root->keys.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    prefix += last ? "   " : "╎  ";

    if (!root->isLeaf) {
        for (int i = 0; i < root->children.size(); i++) {
            bool last = (i == root->children.size() - 1);
            print(root->children[i], prefix, last);
        }
    }
}

int main() {
    Node* tree = createNode(nullptr, true, nullptr, nullptr);
    vector<int> random_list = {5, 9, 1, 3, 4, 59, 65, 45, 89, 29, 68, 108, 165, 298, 219, 569, 37, 47, 53, 6, 43, 51, 57, 49};
    vector<int> random_list_2 = vector<int>(random_list.begin(), random_list.end());

    for (int r : random_list_2) {
        for (int i : random_list) {
            cout << endl << "-------------" << endl;
            cout << "Inserting " << i << endl << endl;
            cout << "-------------" << endl << endl;
            set(tree, i, i);
            print(tree);
        }

        cout << endl << "-------------------------" << endl;
        cout << "All keys are inserted ..." << endl;
        cout << "-------------------------" << endl << endl;

        print(tree);

        shuffle(random_list.begin(), random_list.end(), default_random_engine(r));
        for (int i : random_list) {
            remove(tree, i);
            cout << endl << "-------------" << endl;
            cout << "Removing " << i << endl;
            cout << "-------------" << endl << endl;
            print(tree);
        }
    }

    return 0;
}
