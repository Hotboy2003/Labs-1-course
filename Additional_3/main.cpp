#include <iostream>
#include "Function.hpp"


int main() {
    int n;
    ao::Read(n);
    std::cout<<ao::MaxCifr(n)<<" "<<ao::ChastCifr(n)<<" "<<ao::Sum(n);
}
