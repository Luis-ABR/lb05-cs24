#include "Treese.h"

// --- copy a subtree ---
Treese::Node* Treese::copy_node(const Node* n) {
    if (!n) return nullptr;
    if (!n->left && !n->right) {
        // leaf
        return new Node(n->data);
    }
    Node* L = copy_node(n->left);
    Node* R = copy_node(n->right);
    return new Node(L, R);
}

// --- delete a subtree ---
void Treese::delete_node(Node* n) {
    if (!n) return;
    delete_node(n->left);
    delete_node(n->right);
    delete n;
}

// --- random access ---
char Treese::at_node(const Node* n, size_t idx) {
    if (!n) throw std::out_of_range("Index out of range.");
    if (!n->left && !n->right) {
        // leaf
        if (idx >= n->data.size())
            throw std::out_of_range("Index out of range.");
        return n->data[idx];
    }
    if (idx < n->weight) {
        return at_node(n->left, idx);
    } else {
        return at_node(n->right, idx - n->weight);
    }
}

// --- in-order print ---
void Treese::print_node(const Node* n) {
    if (!n) return;
    if (!n->left && !n->right) {
        std::cout << n->data;
    } else {
        print_node(n->left);
        print_node(n->right);
    }
}

// --- constructors / assignment / destructor ---
Treese::Treese()
  : root(nullptr)
{}

Treese::Treese(const std::string& s)
  : root(s.empty() ? nullptr : new Node(s))
{}

Treese::Treese(const Treese& o)
  : root(copy_node(o.root))
{}

Treese& Treese::operator=(const Treese& o) {
    if (this != &o) {
        delete_node(root);
        root = copy_node(o.root);
    }
    return *this;
}

Treese::~Treese() {
    delete_node(root);
}

// --- public API ---
size_t Treese::length() const {
    return root ? root->total_length : 0;
}

char Treese::at(size_t idx) const {
    return at_node(root, idx);
}

void Treese::print() const {
    print_node(root);
}

Treese Treese::concat(const Treese& o) const {
    if (!root && !o.root) return Treese();
    if (!root)           return Treese(o);
    if (!o.root)         return Treese(*this);

    Treese r;
    Node* L = copy_node(root);
    Node* R = copy_node(o.root);
    r.root = new Node(L, R);
    return r;
}
#ifndef __linux__
int main() { return 0; }
#endif
