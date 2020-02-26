
#include "Subvector.hpp"
#include <cmath>
#include <fstream>

subvector::subvector()
{
    top = capacity = 0;
    arr = nullptr;
}

bool subvector::resize (unsigned new_capacity)
{
    int* cpy = arr;
    arr = new int[new_capacity];
    
    if (arr==nullptr)
        return 1;
    
    for (int i = 0;i < top; i++)
        arr[i] = cpy[i];
    
    delete cpy;
    capacity = new_capacity;
    
    return 0;
}
bool subvector::push_back(int d)
{
    if(top + 1 > capacity)
        if(resize(round(exp(log(2) * ceil(log(top + 1) / log(2))))))
            return 1;
    
    arr[top] = d;
    top++;
    
    return 0;
}

int subvector::pop_back()
{
    top--;
    return arr[top];

}

void subvector::shrink_to_fit()
{
    if(capacity > top)
        resize(top);
}

void subvector::clear()
{
    top = 0;
}

subvector::~subvector()
{
    if(arr != nullptr)
        delete arr;
}

bool subvector::init_from_file(char* filename)
{
    std::ifstream file;
    file.open(filename);
    
    int tmp;
    
    while(file >> tmp)
        push_back(tmp);
    
    file.close();
    
    return 0;
}

