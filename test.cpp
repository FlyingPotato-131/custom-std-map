#include<string>
#include "tree.h"

using namespace yeet;

int main() {
    node<int> negr(0);
    node<int> negr1(0);

    node<int> negr2(static_cast<node<int>&&>(negr));

    node<int> n(1, &negr, &negr1);


    std::cout << n.leftptr() << ' ' << n.rightptr() << '\n';
    std::cout << negr.leftptr() << ' ' << negr.rightptr();
}
