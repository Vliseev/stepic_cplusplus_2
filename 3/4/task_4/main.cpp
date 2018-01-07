#include <iostream>
#include "VectorList.h"
int main() {


    std::pair<std::vector<int>::iterator,int> y;
    VectorList<int> a;
    std::vector<int> v1={1,2};
    std::vector<int> v2={31,2,4};


    std::cout<<"is empty"<<a.empty();
    a.append(v1.begin(),v1.end());
    a.append(v2.begin(),v2.end());


    VectorList<int>::const_iterator it;
    VectorList<int>::const_reverse_iterator rit;

    rit= a.rbegin();

    for (rit = a.rbegin(); rit != a.rend();) {
        std::cout << (*rit) << std::endl;
        ++rit;
    }

    std::cout<<"is empty"<<a.empty();

    return 0;
}
