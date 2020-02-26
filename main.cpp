
#include <iostream>
#include "Subvector.hpp"

int main()
{
    subvector a;
    for(unsigned i = 0; i < 10; i++)
    {
        a.push_back(i);
        a.push_back(i);
        std::cout << a.top << "\t" << a.capacity << "\t" << a.pop_back() << "\n";
    }
}
