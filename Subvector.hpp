#pragma once

class subvector
{
public:
    subvector();
    bool push_back(int d);
    int  pop_back();
    bool resize(unsigned new_capacity);
    void shrink_to_fit();
    void clear();
    ~subvector();
    bool init_from_file(char *filename);
    
    int *arr;
    unsigned top;
    unsigned capacity;
};
