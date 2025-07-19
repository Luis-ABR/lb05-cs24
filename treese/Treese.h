#ifndef TREESE_H
#define TREESE_H

#include <string>
#include <cstddef>
#include <stdexcept>
#include <iostream>

class Treese {
private:
    struct Node {
        Node*         left;
        Node*         right;
        size_t        weight;       // length of left subtree
        size_t        total_length; // entire subtree length
        std::string   data;         // only nonempty for leaves

        // Leaf constructor
        Node(const std::string& s)
          : left(nullptr),
            right(nullptr),
            weight(0),
            total_length(s.size()),
            data(s)
        {}

        // Internal constructor
        Node(Node* l, Node* r)
          : left(l),
            right(r),
            weight(l ? l->total_length : 0),
            total_length(weight + (r ? r->total_length : 0)),
            data()
        {}
    };

    Node* root;

    // Deep-copy a subtree
    static Node* copy_node(const Node* n);
    // Recursively delete a subtree
    static void  delete_node(Node* n);
    // Random-access helper
    static char  at_node(const Node* n, size_t idx);
    // In-order print helper
    static void  print_node(const Node* n);

public:
    // ctors / assign / dtor
    Treese();
    Treese(const std::string& s);
    Treese(const Treese& o);
    Treese& operator=(const Treese& o);
    ~Treese();

    // public API
    size_t   length() const;
    char     at(size_t idx) const;
    void     print() const;
    Treese   concat(const Treese& o) const;
};

#endif // TREESE_H
