#include <iostream>
#include "VectorList.h"
int main() {

    VectorList<int> a;
    std::vector<int> v1={1,2,3,4};
    std::vector<int> v2={4,5,6,7,4,88};

    a.append(v1.begin(),v1.end());
    a.append(v2.begin(),v2.end());

    std::cout<<a.size()<<std::endl;
    return 0;
}
