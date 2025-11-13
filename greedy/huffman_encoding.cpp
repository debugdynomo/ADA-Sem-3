#include <iostream>
using namespace std;

#define MAX 256

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* createNode(char ch, int freq, Node* left, Node* right) {
    Node* n = new Node;
    n->ch = ch;
    n->freq = freq;
    n->left = left;
    n->right = right;
    return n;
}

int extractMin(Node* nodes[], int size) {
    int minIndex = -1;
    for (int i = 0; i < size; i++) {
        if (nodes[i] != NULL) {
            if (minIndex == -1 || nodes[i]->freq < nodes[minIndex]->freq)
                minIndex = i;
        }
    }
    return minIndex;
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        cout << root->ch << " : ";
        for (int i = 0; i < top; i++)
            cout << arr[i];
        cout << endl;
    }
}

Node* buildHuffman(char *chars, int *freq, int n) {
    Node* nodes[MAX];

    // initialize array
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(chars[i], freq[i], NULL, NULL);

    int size = n;

    while (size > 1) {
        // pick two smallest
        int i1 = extractMin(nodes, size);
        Node* min1 = nodes[i1];

        // shift array left to remove nodes[i1]
        for (int i = i1; i < size - 1; i++)
            nodes[i] = nodes[i + 1];
        size--;

        int i2 = extractMin(nodes, size);
        Node* min2 = nodes[i2];

        for (int i = i2; i < size - 1; i++)
            nodes[i] = nodes[i + 1];
        size--;

        // create parent
        Node* parent = createNode('#', min1->freq + min2->freq, min1, min2);

        // insert parent at end
        nodes[size] = parent;
        size++;
    }

    return nodes[0];
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    // Dynamic char and freq arrays using new
    char* chars = new char[n];
    int* freq = new int[n];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    Node* root = buildHuffman(chars, freq, n);

    int arr[MAX], top = 0;
    cout << "\nHuffman Codes:\n";
    printCodes(root, arr, top);

    delete[] chars;
    delete[] freq;

    return 0;
}