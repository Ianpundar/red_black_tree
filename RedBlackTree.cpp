#include "RedBlackTree.h"


template<class Key, class Value>
RedBlackTree<Key, Value>::Node::Node(Key key, Value val, bool color, int size) {
    this->key = key;
    this->val = val;
    this->right = nullptr;
    this->left = nullptr;
    this->color = color;
    this->size = size;
}

template<class Key, class Value>
bool RedBlackTree<Key, Value>::isRed(RedBlackTree::Node *x) {
    if (x == nullptr) throw "Node x is a nullptr";
    return x->color;
}

template<class Key, class Value>
int RedBlackTree<Key, Value>::size(RedBlackTree::Node *x) {
    if (x == nullptr) throw "Node x is a nullptr";
    return x->size;
}

template<class Key, class Value>
class RedBlackTree<Key, Value>::Node *RedBlackTree<Key, Value>::rotateRight(RedBlackTree::Node *h) {
    Node *x = h->left;
    if (h == nullptr) throw "Node h is a nullptr";
    if (x == nullptr) throw "Node x is a nullptr";
    if (x->color != RED) throw "No need to rotate";
    bool tempColor = h->color;
    h->left = x->right;
    x->right = h;
    h->color = x->color;
    x->color = tempColor;
    x->size = h->size;
    h->size = size(h->left) + size(h->right) + 1;
    return x;
}

template<class Key, class Value>
class RedBlackTree<Key, Value>::Node *RedBlackTree<Key, Value>::rotateLeft(RedBlackTree::Node *h) {
    Node *x = h->right;
    if (h == nullptr) throw "Node h is a nullptr";
    if (x == nullptr) throw "Node x is a nullptr";
    if (x->color != RED) throw "No need to rotate";
    bool tempColor = h->color;
    h->right = x->left;
    x->left = h;
    h->color = x->color;
    x->color = tempColor;
    x->size = h->size;
    h->size = size(h->left) + size(h->right) + 1;
    return x;
}

template<class Key, class Value>
void RedBlackTree<Key, Value>::filpColor(RedBlackTree::Node *h) {
    if (h == nullptr) throw "Node h is a nullptr";
    if (h->left == nullptr || h->right == nullptr) throw "Node h has nullptr children";
    if (isRed(h)) throw "Node h has already been red";
    if (!isRed(h->left) || !isRed(h->right)) throw "Node h can't flip color";
    h->color = RED;
    h->right = BLACK;
    h->left = BLACK;
    return;
}

template<class Key, class Value>
int RedBlackTree<Key, Value>::height(RedBlackTree::Node *x) {
    if (x == nullptr) return -1;
    return 1 + max(height(x->left), height(x->right));
}

template<class Key, class Value>
class RedBlackTree<Key, Value>::Node *RedBlackTree<Key, Value>::min(RedBlackTree::Node *x) {
    if (x->left == nullptr) return x;
    return min(x->left);
}

template<class Key, class Value>
class RedBlackTree<Key, Value>::Node *RedBlackTree<Key, Value>::max(RedBlackTree::Node *x) {
    if (x->right == nullptr) return x;
    return max(x->right);
}

template<class Key, class Value>
Value RedBlackTree<Key, Value>::get(RedBlackTree::Node *x, Key key) {
    while (x != nullptr) {
        if (x->key > key) x = x->left;
        if (x->key < key) x = x->right;
        if (x->key == key) return x->val;
    }
    return nullptr;
}

template<class Key, class Value>
class RedBlackTree<Key, Value>::Node *RedBlackTree<Key, Value>::put(RedBlackTree::Node *h, Key key, Value val) {
    if (h == nullptr) {
        Node node(key, val, RED, 1);
        return &node;
    }

    if (key > h->key) h->right = put(h->right, key, val);
    if (key < h->key) h->left = put(h->left, key, val);
    if (key == h->key) h->val = val;

    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) h = filpColor(h);
    h->size = size(h->left) + size(h->right) + 1;
}

template<class Key, class Value>
RedBlackTree<Key, Value>::RedBlackTree() {
    root = nullptr;
}

template<class Key, class Value>
int RedBlackTree<Key, Value>::size() {
    return size(root);
}

template<class Key, class Value>
bool RedBlackTree<Key, Value>::isEmpty() {
    return root == nullptr;
}

template<class Key, class Value>
Value RedBlackTree<Key, Value>::get(Key key) {
    if (key == nullptr) throw "Key key is a nullptr";
    return get(root, key);
}

template<class Key, class Value>
bool RedBlackTree<Key, Value>::contains(Key key) {
    if (key == nullptr) throw "Key key is a nullptr";
    return get(key) != nullptr;
}

template<class Key, class Value>
void RedBlackTree<Key, Value>::put(Key key, Value val) {
    if (key == nullptr) throw "Key key is a nullptr";
    if (val == nullptr) {
        deleteKey(key);
        return;
    }

    root = put(root, key, val);
    root->color = BLACK;
}

template<class Key, class Value>
int RedBlackTree<Key, Value>::height() {
    return height(root);
}

template<class Key, class Value>
Key RedBlackTree<Key, Value>::min() {
    if (isEmpty()) throw "The red-black tree is empty";
    return min(root)->key;
}

template<class Key, class Value>
Key RedBlackTree<Key, Value>::max() {
    if (isEmpty()) throw "The red-black tree is empty";
    return max(root)->key;
}



