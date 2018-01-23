#include <iostream>
#include <unordered_set>
#include "VectorList.h"
int main() {



    std::pair<std::vector<int>::iterator,int> y;
    VectorList<int> a;
    std::vector<int> t;
    a.append(t.begin(),t.end());
    std::cout<<"size "<<std::distance(a.begin(),a.end())<<"\n";

    std::vector<int> v1={1,2,6};
    std::vector<int> v2={31,2,4};

    a.append(v1.begin(),v1.end());
    a.append(v2.begin(),v2.end());

    for (auto rit = a.rbegin(); rit != a.rend();) {
        std::cout << (*rit) << std::endl;
        ++rit;
    }

    return 0;
}
