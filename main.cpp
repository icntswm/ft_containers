// #include "stack.hpp"
#include "Vector.hpp"
// #include "stdio.h"
#include "Stack_test.hpp"
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

    ft::Vector<int> vec;


    // vec.push_back(5);
    // vec.pop_back();
    vec.assign(4,1);
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;


    vec.resize(10);
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
    // ft::vector<int> foo (3,100);   // three ints with a value of 100
    // ft::vector<int> bar (2,200);   // two ints with a value of 200

    // if (foo==bar) std::cout << "foo and bar are equal\n";
    // if (foo!=bar) std::cout << "foo and bar are not equal\n";
    // if (foo< bar) std::cout << "foo is less than bar\n";
    // if (foo> bar) std::cout << "foo is greater than bar\n";
    // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}