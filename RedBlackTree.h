#ifndef RED_BLACK_TREE_REDBLACKTREE_H
#define RED_BLACK_TREE_REDBLACKTREE_H


template<class Key, class Value>
class RedBlackTree {
private:
    class Node {
    private:
        Key key;
        Value val;
        Node *left, *right;
        bool color;
        int size;
    public:
        Node(Key key, Value val, bool color, int size);
    };

    static const bool RED = true;
    static const bool BLACK = false;

    Node *root;

    bool isRed(Node *x);
    int size(Node *x);
    Value get(Node *x, Key key);
    Node *put(Node *h, Key key, Value val);
    void deleteMin(Node *h);
    void deleteMax(Node *h);
    void deleteKey(Node *h, Key key);
    Node *rotateRight(Node *h);
    Node *rotateLeft(Node *h);
    void filpColor(Node *h);
    int height(Node *x);
    Node *min(Node *x);
    Node *max(Node *x);
    Node *floor(Node *x, Key key);
    Node *ceiling(Node *x, Key key);
    Node *select(Node *x, int k);
    int rank(Key key, Node *x);

public:
    RedBlackTree();
    int size();
    bool isEmpty();
    Value get(Key key);
    bool contains(Key key);
    void put(Key key, Value val);
    void deleteMin();
    void deleteMax();
    void deleteKey(Key key);
    int height();
    Key min();
    Key max();
    Key floor(Key key);
    Key ceiling(Key key);
    Key select(int k);
    int rank(Key key);
    int size(Key lo, Key hi);
    ~RedBlackTree();
};


#endif //RED_BLACK_TREE_REDBLACKTREE_H
