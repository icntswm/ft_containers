#include "stack.hpp"
#include "vector.hpp"
// #include "stdio.h"
#include "Stack_test.hpp"
#include <stack>
#include <vector>
#include <deque>
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

int main()
{
    // ft::Stack<int> st;

    test_Stack<std::stack<int, std::vector<int> >, std::vector<int> >();
}