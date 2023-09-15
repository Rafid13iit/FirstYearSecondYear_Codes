#include<iostream>
using namespace std;

struct BPlusNode {
    int *keys;
    BPlusNode **childPtrs;
    bool isLeaf;
    int numKeys;
} *root = NULL, *newNode = NULL, *currentNode = NULL;

BPlusNode* createNode() {
    int i;
    BPlusNode* newNode = new BPlusNode;
    newNode->keys = new int[6]; // Order 6
    newNode->childPtrs = new BPlusNode *[7];
    newNode->isLeaf = true;
    newNode->numKeys = 0;
    for (i = 0; i < 7; i++) {
        newNode->childPtrs[i] = NULL;
    }
    return newNode;
}

void traverse(BPlusNode *node) {
    cout << endl;
    int i;
    for (i = 0; i < node->numKeys; i++) {
        if (!node->isLeaf) {
            traverse(node->childPtrs[i]);
        }
        cout << " " << node->keys[i];
    }
    if (!node->isLeaf) {
        traverse(node->childPtrs[i]);
    }
    cout << endl;
}

void sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i; j <= n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int splitChild(BPlusNode *x, int i) {
    int j, mid;
    BPlusNode *newNode2, *childNode;
    newNode2 = createNode();
    newNode2->isLeaf = true;
    if (i == -1) {
        mid = x->keys[2];
        x->keys[2] = 0;
        x->numKeys--;
        childNode = createNode();
        childNode->isLeaf = false;
        x->isLeaf = true;
        for (j = 3; j < 6; j++) {
            newNode2->keys[j - 3] = x->keys[j];
            newNode2->numKeys++;
            x->keys[j] = 0;
            x->numKeys--;
        }
        for (j = 0; j < 6; j++) {
            x->childPtrs[j] = NULL;
        }
        childNode->keys[0] = mid;
        childNode->childPtrs[childNode->numKeys] = x;
        childNode->childPtrs[childNode->numKeys + 1] = newNode2;
        childNode->numKeys++;
        root = childNode;
    } else {
        childNode = x->childPtrs[i];
        mid = childNode->keys[2];
        childNode->keys[2] = 0;
        childNode->numKeys--;
        for (j = 3; j < 6; j++) {
            newNode2->keys[j - 3] = childNode->keys[j];
            newNode2->numKeys++;
            childNode->keys[j] = 0;
            childNode->numKeys--;
        }
        x->childPtrs[i + 1] = childNode;
        x->childPtrs[i + 1] = newNode2;
    }
    return mid;
}

void insert(int value) {
    int i, temp;
    currentNode = root;
    if (currentNode == NULL) {
        root = createNode();
        currentNode = root;
    } else {
        if (currentNode->isLeaf && currentNode->numKeys == 6) {
            temp = splitChild(currentNode, -1);
            currentNode = root;
            for (i = 0; i < (currentNode->numKeys); i++) {
                if ((value > currentNode->keys[i]) && (value < currentNode->keys[i + 1])) {
                    i++;
                    break;
                } else if (value < currentNode->keys[0]) {
                    break;
                } else {
                    continue;
                }
            }
            currentNode = currentNode->childPtrs[i];
        } else {
            while (!currentNode->isLeaf) {
                for (i = 0; i < (currentNode->numKeys); i++) {
                    if ((value > currentNode->keys[i]) && (value < currentNode->keys[i + 1])) {
                        i++;
                        break;
                    } else if (value < currentNode->keys[0]) {
                        break;
                    } else {
                        continue;
                    }
                }
                if ((currentNode->childPtrs[i])->numKeys == 6) {
                    temp = splitChild(currentNode, i);
                    currentNode->keys[currentNode->numKeys] = temp;
                    currentNode->numKeys++;
                    continue;
                } else {
                    currentNode = currentNode->childPtrs[i];
                }
            }
        }
    }
    currentNode->keys[currentNode->numKeys] = value;
    sort(currentNode->keys, currentNode->numKeys);
    currentNode->numKeys++;
}

int main() {
    int i, n, temp;
    cout << "Enter the number of elements to be inserted: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Enter the element: ";
        cin >> temp;
        insert(temp);
    }
    cout << "Traversal of constructed B+ tree:" << endl;
    traverse(root);
    return 0;
}
