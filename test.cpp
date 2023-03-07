#include <iostream>
#include<string>
#include "tree.h"

using namespace yeet;

int main() {
    // node<int> negr(0);
    // node<int> negr1(0);

    // node<int> negr2(static_cast<node<int>&&>(negr));

    // node<int> n(1, &negr, &negr1);


    // std::cout << n.leftptr() << ' ' << n.rightptr() << '\n';
    // std::cout << negr.leftptr() << ' ' << negr.rightptr();
    node<char> C('C');
    node<char> B('B', &C);
    node<char> A('A', &B);
    B.setparent(&A);
    C.setparent(&B);
    node<char> b('b', nullptr, nullptr, &B);
    node<char> a('a', nullptr, nullptr, &A);
    B.setright(&b);
    A.setright(&a);
    tree<char> Ta = &A;
    tree<char> Tb = &B;
    std::cout << Ta;
    A.rightrot();
    std::cout << Tb;
}
