#include <iostream>
#include <vector>

std::vector<int> v;

bool Cifra8(int n)
{
    while (n != 0)
    {
        if (n % 10 == 8)
        {
            return true;
        }
        n = n / 10;
    }
    return false;
}

long int ProizCifr(int n) {
    long int ans = 1;
    while (n != 0) {
        ans *= n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int n, a;
    
    std::cin >> n;
    for (int i = 0; i < n * 2; i += 2) {
        std::cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < v.size(); i++) {
        if (ProizCifr(v[i]) == 144) {
            v.erase(v.begin() + i);
            i++;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (Cifra8(v[i]) == true) {
            v.insert(v.begin() + i, v[i]);
            i++;
        }
    }
    for (auto& v : v)
        std::cout << v << std::endl;
}
