#include <iostream>
#include <cxxabi.h>

namespace my_std {
    template<class T>
    void type_info(T a) {
        int status;
        char *realname;
        const std::type_info &ti = typeid(a);

        realname = abi::__cxa_demangle(ti.name(), 0, 0, &status);
        std::cout << ti.name() << "\t=> " << realname << "\t: " << status << '\n';
        free(realname);
    }
}

template<int64_t N>
struct Fib {
    static int64_t const
            value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template<>
struct Fib<0> {
    static int const value = 0;
};

template<>
struct Fib<1> {
    static int const value = 1;
};


int main() {
    std::cout << Fib<50>::value << std::endl;
    return 0;
}