#include <stack>
#include "../stack.hpp"
#include <vector>
#include "../vector.hpp"

int main(){
    std::cout << "\033[31m\n --------- STACK TEST ---------\033[0m\n\n";
    std::stack<int> st_std;
    ft::stack<int> st_my;
    
    std::cout << "\033[34mSTD\033[0m size: " << st_std.size() << " | \033[34mMY\033[0m size: " << st_my.size() << "\n";
    std::cout << "\033[34mSTD\033[0m empty: " << st_std.empty() << " | \033[34mMY\033[0m empty: " << st_my.empty() << "\n";
    
    st_std.push(11); st_my.push(11);
    st_std.push(12); st_my.push(12);
    st_std.push(13); st_my.push(13);

    std::cout << "\033[34mSTD\033[0m size: " << st_std.size() << " | \033[34mMY\033[0m size: " << st_my.size() << "\n";
    std::cout << "\033[34mSTD\033[0m top: " << st_std.top() << " | \033[34mMY\033[0m top: " << st_my.top() << "\n";
    std::cout << "\033[34mSTD\033[0m empty: " << st_std.empty() << " | \033[34mMY\033[0m empty: " << st_my.empty() << "\n";

    st_std.pop(); st_my.pop();
    st_std.pop(); st_my.pop();
    std::cout << "\033[34mSTD\033[0m size: " << st_std.size() << " | \033[34mMY\033[0m size: " << st_my.size() << "\n";
    st_std.pop(); st_my.pop();
    std::cout << "\033[34mSTD\033[0m size: " << st_std.size() << " | \033[34mMY\033[0m size: " << st_my.size() << "\n";
    std::cout << "\033[34mSTD\033[0m empty: " << st_std.empty() << " | \033[34mMY\033[0m empty: " << st_my.empty() << "\n";



    std::cout << "\n----------------------------\n\n";
    ft::stack<int> ft1;
    ft::stack<int> ft2;

    ft1.push(11);
    ft1.push(22);
    ft1.push(33);
    std::cout << "\033[34mft1\033[0m size: " << ft1.size() << " | \033[34mft2\033[0m size: " << ft2.size() << "\n";
    ft2 = ft1;
    std::cout << "\033[34mft1\033[0m size: " << ft1.size() << " | \033[34mft2\033[0m size: " << ft2.size() << "\n";
    std::cout << "\033[34mft1\033[0m top: " << ft1.top() << " | \033[34mft2\033[0m top: " << ft2.top() << "\n";


    //test stack constructor
    int _ratio = 10000;
    ft::stack<int> stk;

    std::vector<int> v;
	ft::vector<int> deque;
	for (int i = 0; i < 100 * _ratio; ++i)
		deque.push_back(i);
	for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
		stk.push(i);
	ft::stack<int> stack(deque);
	ft::stack<int> stack2(stk);
	ft::stack<int> stack3;
	stack3 = stack2;
	while (stack.size() > 0) {
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v.push_back(stack2.top());
		stack2.pop();
	}
}