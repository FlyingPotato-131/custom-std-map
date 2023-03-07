#pragma once
#include "tree"
#include <functional>
#include <iostream> 

template<typename val, typename cmp>
yeet::node<val, cmp>::node() {
    this->right = nullptr;
    this->left = nullptr;
    this->parent = nullptr;
};

template<typename val, typename cmp>
yeet::node<val, cmp>::node(val value, node *left, node *right, node *parent) {
    this->value = value;
    this->right = right;
    this->left = left;
    this->parent = parent;
    if(left != nullptr && right != nullptr){
        this->height = std::max(left->height, right->height) + 1;
    }else if(right != nullptr){
        this->height = right->height + 1;
    }else if(left != nullptr){
        this->height = left->height + 1;
    }else{
        this->height = 1;
    }
};

template<typename val, typename cmp>
yeet::node<val, cmp>::node(const node &other) {
    this->value = other.value;
    this->right = other.right;
    this->left = other.left;
    this->parent = other.parent;
    this->height = other.height;
};

template<typename val, typename cmp>
yeet::node<val, cmp>::node(node &&other) {
    this->value = other.value;
    this->right = other.right;
    this->left = other.left;
    this->parent = other.parent;
    this->height = other.height;
    other.right = nullptr;
    other.left = nullptr;
    other.parent = nullptr;
};

template<typename val, typename cmp>
yeet::node<val, cmp>::~node() {
    // if(right != nullptr){
    //     right->~node();
    // }
    // if(left != nullptr){
    //     left->~node();
    // }
    // std::free(this);
};

// template<typename val, typename cmp>
// yeet::node<val, cmp> &yeet::node<val, cmp>::operator=(const node &other) {
//     left = other.left;
//     right = other.right;
//     value = other.value;
//     parent = other.parent;
//     height = other.height;
// };

// template<typename val, typename cmp>
// yeet::node<val, cmp>& yeet::node<val, cmp>::operator=(node &&other) {};

template<typename val, typename cmp>
val yeet::node<val, cmp>::getvalue() {return this->value;}

template<typename val, typename cmp>
yeet::node<val, cmp>* yeet::node<val, cmp>::leftptr() {return this->left;}

template<typename val, typename cmp>
yeet::node<val, cmp>* yeet::node<val, cmp>::rightptr() {return this->right;}

template<typename val, typename cmp>
yeet::node<val, cmp>* yeet::node<val, cmp>::parentptr() {return this->parent;}

template<typename val, typename cmp>
void yeet::node<val, cmp>::setvalue(val v) {value = v;}

template<typename val, typename cmp>
void yeet::node<val, cmp>::setleft(yeet::node<val, cmp>* l) {left = l;}

template<typename val, typename cmp>
void yeet::node<val, cmp>::setright(yeet::node<val, cmp>* r) {right = r;}

template<typename val, typename cmp>
void yeet::node<val, cmp>::setparent(yeet::node<val, cmp>* p) {parent = p;}

template<typename val, typename cmp>
void yeet::node<val, cmp>::updateheight(){
     if(left != nullptr && right != nullptr){
        this->height = std::max(left->height, right->height) + 1;
    }else if(right != nullptr){
        this->height = right->height + 1;
    }else if(left != nullptr){
        this->height = left->height + 1;
    }else{
        this->height = 1;
    }
}

// template<typename val, typename cmp>
// yeet::tree<val, cmp>::tree() {head = nullptr;}

// template<typename val, typename cmp>
// yeet::tree<val, cmp>::tree(node<val, cmp> nd) {head = &nd;}

// template<typename val, typename cmp>
// yeet::tree<val, cmp>::tree(const tree &other){
//    head = other.head; 
// }

// template<typename val, typename cmp>
// yeet::tree<val, cmp>::tree(tree &&other){
//     head = other.head;
//     other.head = nullptr;
// }

// template<typename val, typename cmp>
// yeet::tree<val, cmp>::~tree() {
//     // head->yeet::node<val, cmp>::~node();
// }

template<typename val, typename cmp>
void yeet::node<val, cmp>::leftrot(){
    yeet::node<val, cmp> *A = this;
    yeet::node<val, cmp> *B = this->right;
    yeet::node<val, cmp> *C = this->right->right;
    A->setright(B->leftptr());
    if(A->rightptr() != nullptr){
        A->right->setparent(A); 
    }
    B->setparent(A->parentptr());
    A->setparent(B);
    B->setleft(A);
    if(B->parent != nullptr){
        B->parent->setright(B);
    }
    A->updateheight();
    B->updateheight();
    C->updateheight();
}

template<typename val, typename cmp>
void yeet::node<val, cmp>::rightrot(){
    yeet::node<val, cmp> *A = this;
    yeet::node<val, cmp> *B = this->left;
    yeet::node<val, cmp> *C = this->left->left;
    A->setleft(B->rightptr());
    if(A->leftptr() != nullptr){
        A->left->setparent(A); 
    }
    B->setparent(A->parentptr());
    A->setparent(B);
    B->setright(A);
    if(B->parent != nullptr){
        B->parent->setleft(B);
    }
    A->updateheight();
    B->updateheight();
    C->updateheight();
}

template<typename val, typename cmp = std::less<val>>
using tree = yeet::node<val, cmp> *;

template<typename val, typename cmp>
std::ostream &printTree(std::ostream &out, tree<val, cmp> const tree, bool right, std::string const &prefix)
{
    if(tree != nullptr)
    {
        out << prefix << (right ? "└──" : "├──" ) << tree->value << "(" << tree->height << ")" << std::endl;
        printTree(out, tree->right, false, prefix + (right ? "    " : "│   "));
        printTree(out, tree->left, true, prefix + (right ? "    " : "│   "));
    }
    return out;
}

template<typename val, typename cmp>
std::ostream &operator<<(std::ostream &out, tree<val, cmp> const tree)
{
    return printTree(out, tree, true, "");
}