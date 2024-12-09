#include <iostream>
#include <queue>
using namespace std;

// Binary Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree Node
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Heap
class MinHeap {
    vector<int> heap;
    
    void heapifyUp(int index) {
        if (index && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        if (leftChild < size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int size() { return heap.size(); }

    void insert(int key) {
        heap.push_back(key);
        int index = size() - 1;
        heapifyUp(index);
    }

    void printHeap() {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }
};

// Binary Tree Functions
TreeNode* insertBinaryTree(TreeNode* root, int data) {
    if (!root) return new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (!temp->left) {
            temp->left = new TreeNode(data);
            break;
        } else q.push(temp->left);
        if (!temp->right) {
            temp->right = new TreeNode(data);
            break;
        } else q.push(temp->right);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Binary Search Tree Functions
BSTNode* insertBST(BSTNode* root, int data) {
    if (!root) return new BSTNode(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else
        root->right = insertBST(root->right, data);
    return root;
}

BSTNode* searchBST(BSTNode* root, int key) {
    if (!root || root->data == key)
        return root;
    if (key < root->data)
        return searchBST(root->left, key);
    return searchBST(root->right, key);
}

BSTNode* minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

BSTNode* deleteBST(BSTNode* root, int key) {
    if (!root) return root;
    if (key < root->data)
        root->left = deleteBST(root->left, key);
    else if (key > root->data)
        root->right = deleteBST(root->right, key);
    else {
        if (!root->left) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        BSTNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void inorderBST(BSTNode* root) {
    if (!root) return;
    inorderBST(root->left);
    cout << root->data << " ";
    inorderBST(root->right);
}

void preorderBST(BSTNode* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderBST(root->left);
    preorderBST(root->right);
}

void postorderBST(BSTNode* root) {
    if (!root) return;
    postorderBST(root->left);
    postorderBST(root->right);
    cout << root->data << " ";
}

// Main Function
int main() {
    TreeNode* binaryTreeRoot = nullptr;
    BSTNode* bstRoot = nullptr;
    MinHeap minHeap;
    // welcome display
    cout << ",   .     .                   .\n 
            | . |     |                   |\n 
            | ) ) ,-. | ,-. ,-. ;-.-. ,-. |\n 
            |/|/  |-' | |   | | | | | |-'  \n 
            ' '   `-' ' `-' `-' ' ' ' `-' o\n" << endl;
    int choice, data;
    while (true) {
        cout << "Choose Data Structure:\n1. Binary Tree\n2. Binary Search Tree\n3. Min Heap\n4. Exit\n";
        cin >> choice;
        if (choice == 4) break;

        switch (choice) {
            case 1:
                cout << "Binary Tree Operations:\n1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n";
                cin >> choice;
                if (choice == 1) {
                    cout << "Enter data to insert: ";
                    cin >> data;
                    binaryTreeRoot = insertBinaryTree(binaryTreeRoot, data);
                } else if (choice == 2) {
                    inorder(binaryTreeRoot);
                    cout << endl;
                } else if (choice == 3) {
                    preorder(binaryTreeRoot);
                    cout << endl;
                } else if (choice == 4) {
                    postorder(binaryTreeRoot);
                    cout << endl;
                }
                break;
            case 2:
                cout << "Binary Search Tree Operations:\n1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n";
                cin >> choice;
                if (choice == 1) {
                    cout << "Enter data to insert: ";
                    cin >> data;
                    bstRoot = insertBST(bstRoot, data);
                } else if (choice == 2) {
                    inorderBST(bstRoot);
                    cout << endl;
                } else if (choice == 3) {
                    preorderBST(bstRoot);
                    cout << endl;
                } else if (choice == 4) {
                    postorderBST(bstRoot);
                    cout << endl;
                } else if (choice == 5) {
                    cout << "Enter data to search: ";
                    cin >> data;
                    BSTNode* result = searchBST(bstRoot, data);
                    if (result) cout << "Found\n";
                    else cout << "Not Found\n";
                } else if (choice == 6) {
                    cout << "Enter data to delete: ";
                    cin >> data;
                    bstRoot = deleteBST(bstRoot, data);
                }
                break;
            case 3:
                cout << "Min Heap Operations:\n1. Insert\n2. Print Heap\n";
                cin >> choice;
                if (choice == 1) {
                    cout << "Enter data to insert: ";
                    cin >> data;
                    minHeap.insert(data);
                } else if (choice == 2) {
                    minHeap.printHeap();
                }
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}