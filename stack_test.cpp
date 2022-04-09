#include "stack.hpp"
#include <stack>
void size_test()
{
    // std::cout << "\033[31m\n --------- void reserve(size_type n)\033[0m\n";
    // std::stack<int> st_std;
    // ft::stack<int> st_my;
    

    // st_std.push(2);
    // for (int i = 0; i < st_my.size(); i++) {
    //     std::cout << st_my[i] << " ";
    // }
    // for ( i = 0; i < st_std.size(); i++) {
    //     std::cout << st_std[i] << " ";
    // }
    // std::cout << "\033[34mMY: \033[0m\n";
    // std::cout << vecc2.capacity();

    // std::cout << "\n\033[33m\nSTD: \033[0m\n";
    // std::cout << vect2.capacity();
    // std::cout << "\n";
}

int main(){
    std::cout << "\033[31m\n --------- stack test\033[0m\n\n";
    std::stack<int> st_std;
    ft::stack<int> st_my;
    
    std::cout << "\033[34mSTD\033[0m size: " << st_std.size() << " | \033[33mMY\033[0m size: " << st_my.size() << "\n";
    std::cout << "\033[34mSTD\033[0m empty: " << st_std.empty() << " | \033[33mMY\033[0m empty: " << st_my.empty() << "\n";
    
    st_std.push(11); st_my.push(11);
    st_std.push(12); st_my.push(12);
    st_std.push(13); st_my.push(13);

    std::cout << "\033[34mSTD\033[0m size: " << st_std.size() << " | \033[33mMY\033[0m size: " << st_my.size() << "\n";
    std::cout << "\033[34mSTD\033[0m top: " << st_std.top() << " | \033[33mMY\033[0m top: " << st_my.top() << "\n";
    std::cout << "\033[34mSTD\033[0m empty: " << st_std.empty() << " | \033[33mMY\033[0m empty: " << st_my.empty() << "\n";

    st_std.pop(); st_my.pop();
    st_std.pop(); st_my.pop();
    std::cout << "\033[34mSTD\033[0m size: " << st_std.size() << " | \033[33mMY\033[0m size: " << st_my.size() << "\n";
    st_std.pop(); st_my.pop();
    std::cout << "\033[34mSTD\033[0m size: " << st_std.size() << " | \033[33mMY\033[0m size: " << st_my.size() << "\n";
    std::cout << "\033[34mSTD\033[0m empty: " << st_std.empty() << " | \033[33mMY\033[0m empty: " << st_my.empty() << "\n";



    std::cout << "\n----------------------------\n\n";
    ft::stack<int> ft1;
    ft::stack<int> ft2;

    ft1.push(11);
    ft1.push(22);
    ft1.push(33);
    std::cout << "\033[34mft1\033[0m size: " << ft1.size() << " | \033[33mft2\033[0m size: " << ft2.size() << "\n";
    ft2 = ft1;
    std::cout << "\033[34mft1\033[0m size: " << ft1.size() << " | \033[33mft2\033[0m size: " << ft2.size() << "\n";
    std::cout << "\033[34mft1\033[0m top: " << ft1.top() << " | \033[33mft2\033[0m top: " << ft2.top() << "\n";

}