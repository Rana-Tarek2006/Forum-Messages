#pragma once
#include <iostream>
#include <string>
#include <initializer_list>

// Node structure for the AVL tree
template <typename Key, typename Value>
struct Node {
    Key key;                  // The key of the node
    Value value;              // The value associated with the key
    Node* left;               // Pointer to the left child
    Node* right;              // Pointer to the right child
    int height;               // Height of the node (used for balancing)

    // Constructor to initialize a node with a key and value
    Node(const Key& k, const Value& v)
        : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
};

// Map Class
template <typename Key, typename Value>
class Map {
private:
    Node<Key, Value>* root; // Root node of the AVL tree

    // Helper function to copy the tree from another map
    Node<Key, Value>* copyTree(Node<Key, Value>* node);

    // Helper function to delete the entire tree
    void deleteTree(Node<Key, Value>* node);

    // Helper function to perform in-order traversal and print the map
    void inorder(Node<Key, Value>* node) const;

    // Function to get the height of a node
    int getHeight(Node<Key, Value>* node);

    // Function to update the height of a node
    void updateHeight(Node<Key, Value>* node);

    // Function to calculate the balance factor of a node
    int getBalanceFactor(Node<Key, Value>* node);

    // Function to perform a right rotation
    Node<Key, Value>* rotateRight(Node<Key, Value>* y);

    // Function to perform a left rotation
    Node<Key, Value>* rotateLeft(Node<Key, Value>* x);

    // Function to balance an AVL tree node
    Node<Key, Value>* balance(Node<Key, Value>* node);

    // Function to insert a key-value pair into the AVL tree
    Node<Key, Value>* insert(Node<Key, Value>* node, const Key& key, const Value& value);

    // Function to find a node with a specific key in the AVL tree
    Node<Key, Value>* find(Node<Key, Value>* node, const Key& key) const;

public:
    // Default constructor
    Map();

    // Parameterized constructor
    Map(std::initializer_list<std::pair<Key, Value>> initList);

    // Copy constructor
    Map(const Map& other);

    // Destructor
    ~Map();

    // Assignment operator
    Map& operator=(const Map& other);

    // Overload [] operator
    Value& operator[](const Key& key);

    // Overload == operator
    bool operator==(const Map& other) const;

    // Overload != operator
    bool operator!=(const Map& other) const;

    // Insert a key-value pair into the map
    void insert(const Key& key, const Value& value);

    // Print the entire map
    void print() const;
};



// Default constructor
template <typename Key, typename Value>
Map<Key, Value>::Map() : root(nullptr) {}

// Parameterized constructor
template <typename Key, typename Value>
Map<Key, Value>::Map(std::initializer_list<std::pair<Key, Value>> initList) : root(nullptr) {
    for (const auto& pair : initList) {
        insert(pair.first, pair.second);
    }
}

// Copy constructor
template <typename Key, typename Value>
Map<Key, Value>::Map(const Map& other) : root(copyTree(other.root)) {}

// Destructor
template <typename Key, typename Value>
Map<Key, Value>::~Map() {
    deleteTree(root);
}

// Assignment operator
template <typename Key, typename Value>
Map<Key, Value>& Map<Key, Value>::operator=(const Map& other) {
    if (this != &other) {
        deleteTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

// Helper function to copy a tree
template <typename Key, typename Value>
Node<Key, Value>* Map<Key, Value>::copyTree(Node<Key, Value>* node) {
    if (!node) return nullptr;
    Node<Key, Value>* newNode = new Node<Key, Value>(node->key, node->value);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    newNode->height = node->height;
    return newNode;
}

// Helper function to delete the entire tree
template <typename Key, typename Value>
void Map<Key, Value>::deleteTree(Node<Key, Value>* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Helper function to perform in-order traversal
template <typename Key, typename Value>
void Map<Key, Value>::inorder(Node<Key, Value>* node) const {
    if (node) {
        inorder(node->left);
        std::cout << node->key << ": " << node->value << std::endl;
        inorder(node->right);
    }
}

// Print the map
template <typename Key, typename Value>
void Map<Key, Value>::print() const {
    inorder(root);
}

// Function to get the height of a node
template <typename Key, typename Value>
int Map<Key, Value>::getHeight(Node<Key, Value>* node) {
    return node ? node->height : 0;
}

// Function to update the height of a node
template <typename Key, typename Value>
void Map<Key, Value>::updateHeight(Node<Key, Value>* node) {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Function to calculate balance factor
template <typename Key, typename Value>
int Map<Key, Value>::getBalanceFactor(Node<Key, Value>* node) {
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotation
template <typename Key, typename Value>
Node<Key, Value>* Map<Key, Value>::rotateRight(Node<Key, Value>* y) {
    Node<Key, Value>* x = y->left;
    Node<Key, Value>* T = x->right;
    x->right = y;
    y->left = T;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left rotation
template <typename Key, typename Value>
Node<Key, Value>* Map<Key, Value>::rotateLeft(Node<Key, Value>* x) {
    Node<Key, Value>* y = x->right;
    Node<Key, Value>* T = y->left;
    y->left = x;
    x->right = T;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Balance a node
template <typename Key, typename Value>
Node<Key, Value>* Map<Key, Value>::balance(Node<Key, Value>* node) {
    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}

// Insert a key-value pair
template <typename Key, typename Value>
void Map<Key, Value>::insert(const Key& key, const Value& value) {
    root = insert(root, key, value);
}

// Recursive insertion
template <typename Key, typename Value>
Node<Key, Value>* Map<Key, Value>::insert(Node<Key, Value>* node, const Key& key, const Value& value) {
    if (!node) return new Node<Key, Value>(key, value);
    if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else if (key > node->key) {
        node->right = insert(node->right, key, value);
    } else {
        node->value = value;
        return node;
    }
    return balance(node);
}

// Find a node
template <typename Key, typename Value>
Node<Key, Value>* Map<Key, Value>::find(Node<Key, Value>* node, const Key& key) const {
    if (!node || node->key == key) return node;
    if (key < node->key) return find(node->left, key);
    return find(node->right, key);
}

// Overload [] operator
template <typename Key, typename Value>
Value& Map<Key, Value>::operator[](const Key& key) {
    Node<Key, Value>* node = find(root, key);
    if (!node) {
        insert(key, Value());
        node = find(root, key);
    }
    return node->value;
}

// Overload == operator
template <typename Key, typename Value>
bool Map<Key, Value>::operator==(const Map& other) const {
    // Implement equality check logic here
    return false; // Placeholder
}

// Overload != operator
template <typename Key, typename Value>
bool Map<Key, Value>::operator!=(const Map& other) const {
    return !(*this == other);
}
