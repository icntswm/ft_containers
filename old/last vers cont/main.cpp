// #include "stack.hpp"
#include "Vector.hpp"
// #include "stdio.h"
#include "Stack_test.hpp"
#include "iterator.hpp"
#include <stack>
#include <vector>
#include <deque>
#include <iostream>
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

int main()
{
    // ft::Stack<int> st;

    // test_Stack<std::stack<int, std::vector<int> >, std::vector<int> >();

    // std::vector<int>::reverse_iterator it;

    // ft::Vector<int> vec;
    // ft::Vector<int>::iterator lol;
    // ft::Vector<int>::reverse_iterator ri;


    // vec.push_back(5);
    // vec.assign(4,1);
    // vec.pop_back();
    // vec.pop_back();
    
    // std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
    // for (lol = vec.begin(); lol != vec.end(); lol++)
    // {
    //     std::cout << *lol << std::endl;
    // }

    // for (ri = vec.rbegin(); ri != vec.rend(); ri++)
    // {
    //     std::cout << *ri << std::endl;
    // }



        ft::Vector<int> vector;
        std::vector<int> v;
        vector.assign(1000, 1);
        v.push_back(*(vector.rend() - 1));
        v.push_back(*(vector.rend() - 2));


        std::vector<int> lol;
        lol.assign(1000, 1);
        std::cout << "my: " << *(vector.rend() - 1) << std::endl;
        std::cout << "std: " << *(lol.rend() - 1) << std::endl;







    // ft::Vector<int> vector;
    // std::vector<int> v;
    // vector.assign(1000, 1);
    // // g_start2 = timer();
    // v.push_back(*(vector.end() - 1));
    // v.push_back(*(vector.end() - 2));
    // g_end2 = timer();
    // return v;

    // vec.resize(10);
    // std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;

    // ft::vector<int> foo (3,100);   // three ints with a value of 100
    // ft::vector<int> bar (2,200);   // two ints with a value of 200

    // if (foo==bar) std::cout << "foo and bar are equal\n";
    // if (foo!=bar) std::cout << "foo and bar are not equal\n";
    // if (foo< bar) std::cout << "foo is less than bar\n";
    // if (foo> bar) std::cout << "foo is greater than bar\n";
    // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}








