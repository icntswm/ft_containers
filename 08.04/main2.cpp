#include "Vector.hpp"
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(10);

    // std::vector<int>::iterator it = vec.begin() + 7;
    std::vector<int>::reverse_iterator it2 = vec.rbegin();
    // it2 = it;
    std::cout << *it2 << "\n";
    // for (it = vec.begin(); it != vec.end(); it++) {
    //     std::cout << *it << " ";
    // }


    // ft::Vector<int> *vec1 = NULL;
    // vec1->assign(10, 7);
    // ft::Vector<int> it1 = vec1->begin();
    // std::cout << *it1 << "\n";
}