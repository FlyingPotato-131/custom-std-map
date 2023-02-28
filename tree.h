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
};

template<typename val, typename cmp>
yeet::node<val, cmp>::node(const node &other) {
    this->value = other.value;
    this->right = other.right;
    this->left = other.left;
    this->parent = other.parent;
};

template<typename val, typename cmp>
yeet::node<val, cmp>::node(node &&other) {
    this->value = other.value;
    this->right = other.right;
    this->left = other.left;
    this->parent = other.parent;
    other.right = nullptr;
    other.left = nullptr;
    other.parent = nullptr;
};

template<typename val, typename cmp>
yeet::node<val, cmp>::~node() {};

template<typename val, typename cmp>
yeet::node<val, cmp>& yeet::node<val, cmp>::operator=(const node &other) {};

template<typename val, typename cmp>
yeet::node<val, cmp>& yeet::node<val, cmp>::operator=(node &&other) {};

template<typename val, typename cmp>
val yeet::node<val, cmp>::get_value() {return this->value;}

template<typename val, typename cmp>
yeet::node<val, cmp>* yeet::node<val, cmp>::leftptr() {return this->left;}

template<typename val, typename cmp>
yeet::node<val, cmp>* yeet::node<val, cmp>::rightptr() {return this->right;}

template<typename val, typename cmp>
yeet::node<val, cmp>* yeet::node<val, cmp>::parentptr() {return this->parent;}

