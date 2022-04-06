// #include "stack.hpp"
#include "Vector.hpp"
// #include "stdio.h"

#include "iterator.hpp"
#include <stack>
#include <vector>
#include <deque>
#include <iostream>
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };

// int main()
// {
//     // ft::Stack<int> st;

//     // test_Stack<std::stack<int, std::vector<int> >, std::vector<int> >();

//     // std::vector<int>::reverse_iterator it;

    // ft::Vector<int> vec;
//     // ft::Vector<int>::iterator lol;
//     // ft::Vector<int>::reverse_iterator ri;


    // vec.push_back(5);
//     // vec.assign(4,1);
//     // vec.pop_back();
//     // vec.pop_back();
    
//     // std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
//     // for (lol = vec.begin(); lol != vec.end(); lol++)
//     // {
//     //     std::cout << *lol << std::endl;
//     // }

//     // for (ri = vec.rbegin(); ri != vec.rend(); ri++)
//     // {
//     //     std::cout << *ri << std::endl;
//     // }



//         // ft::Vector<int> vector;
//         // std::vector<int> v;
//         // vector.assign(10, 1);
//         // v.assign(10, 1);
//         int _ratio = 10000;
//         std::vector<int> vector;
//         std::vector<int> v;
//         std::vector<int> tmp;
//         tmp.assign(2600 * _ratio, 1);
//         vector.assign(4200 * _ratio, 1);
//         vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
//         v.push_back(vector[3]);
//         v.push_back(vector.size());
//         v.push_back(vector.capacity());

//         std::vector<int>::iterator it = v.begin();

//         std::cout << "STD: " << "\n";
//         for (it = v.begin(); it != v.end(); it++) {
//             std::cout << *it << "\n";
//         }
//         std::cout << "STD size: " << v.size() << "\n";
//         std::cout << "STD capacity: " << v.capacity() << "\n";


//         ft::Vector<int> vector1;
//         ft::Vector<int> v1;
//         ft::Vector<int> tmp1;
//         tmp1.assign(2600 * _ratio, 1);
//         vector1.assign(4200 * _ratio, 1);
//         vector1.insert(vector1.end() - 1000 * _ratio, tmp1.begin(), tmp1.end());
//         v1.push_back(vector1[3]);
//         v1.push_back(vector1.size());
//         v1.push_back(vector1.capacity());

//         ft::Vector<int>::iterator iter;

//         std::cout << "MY: " << "\n";
//         for (iter = v1.begin(); iter != v1.end(); iter++) {
//             std::cout << *iter<< "\n";
//         }
//         std::cout << "MY size: " << v1.size() << "\n";
//         std::cout << "MY capacity: " << v1.capacity() << "\n";



//         // if (v == v1) {
//         //     std::cout << "OK\n";
//         // }
//         // else {
//         //     std::cout << "FAIL\n";
//         // }
//         // ft::Vector<int> vector;
//         // std::vector<int> v;
//         // vector.assign(10, 1);
//         // vector.insert(vector.end() - 8, 2);

//         // v.assign(10, 1);
//         // v.insert(v.end() - 8, 2);
//         // // v.push_back(vector[212]);
//         // // v.push_back(vector.size());
//         // // v.push_back(vector.capacity());
//         // // std::vector<int>::iterator it = v.begin();
//         // ft::Vector<int>::iterator myIt = vector.begin();
//         // std::vector<int>::iterator it = v.begin();

//         // // v.insert(it, 13);
//         // // vector.insert(myIt, 13);


//         // v.insert(it, 3, 7);
//         // vector.insert(myIt, 3, 7);


//         // std::cout << "STD: " << "\n";
//         // for (it = v.begin(); it != v.end(); it++) {
//         //     std::cout << *it << "\n";
//         // }

//         // std::cout << "MY: " << "\n";
//         // for (myIt = vector.begin(); myIt != vector.end(); myIt++) {
//         //     std::cout << *myIt << "\n";
//         // }
//         // std::cout << "STD: " << "\n";
//         // for (it = v.begin(); it != v.end(); it++) {
//             // std::cout << *it << "\n";
//         // }



//         // v.push_back(*(vector.rend() - 1));
//         // v.push_back(*(vector.rend() - 2));


//         // std::vector<int> lol;
//         // lol.assign(1000, 1);
//         // std::cout << "my: " << *(vector.rend() - 1) << std::endl;
//         // std::cout << "std: " << *(lol.rend() - 1) << std::endl;







//     // ft::Vector<int> vector;
//     // std::vector<int> v;
//     // vector.assign(1000, 1);
//     // // g_start2 = timer();
//     // v.push_back(*(vector.end() - 1));
//     // v.push_back(*(vector.end() - 2));
//     // g_end2 = timer();
//     // return v;

//     // vec.resize(10);
//     // std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;

//     // ft::vector<int> foo (3,100);   // three ints with a value of 100
//     // ft::vector<int> bar (2,200);   // two ints with a value of 200

//     // if (foo==bar) std::cout << "foo and bar are equal\n";
//     // if (foo!=bar) std::cout << "foo and bar are not equal\n";
//     // if (foo< bar) std::cout << "foo is less than bar\n";
//     // if (foo> bar) std::cout << "foo is greater than bar\n";
//     // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//     // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
// }

class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

void insert_test() {
    std::cout << "\n --------- iterator insert (iterator position, const_reference val)\n";
    ft::Vector<int> vec1;
    std::vector<int> vector1;

    vec1.push_back(5);
    vec1.push_back(5);
    vec1.push_back(5);

    vector1.push_back(5);
    vector1.push_back(5);
    vector1.push_back(5);

    vec1.insert(vec1.end(), 9);
    vector1.insert(vector1.end(), 9);

    std::cout << "MY: \n";
    ft::Vector<int>::iterator it1;
    for (it1 = vec1.begin(); it1 != vec1.end(); it1++) {
        std::cout << *it1 << " ";
    }

    std::cout << "\nSTD: \n";
    std::vector<int>::iterator it2;
    for (it2 = vector1.begin(); it2 != vector1.end(); it2++) {
        std::cout << *it2 << " ";
    }
    std::cout << "\n";


    std::cout << "\n --------- void insert(iterator pos, size_type count, const_reference value) \n";
    ft::Vector<int> vec2;
    std::vector<int> vector2;

    vec2.push_back(5);
    vec2.push_back(5);
    vec2.push_back(5);

    vector2.push_back(5);
    vector2.push_back(5);
    vector2.push_back(5);

    vec2.insert(vec2.begin() + 2, 5, 9);
    vector2.insert(vector2.begin() + 2, 5, 9);

    std::cout << "MY: \n";
    ft::Vector<int>::iterator it3;
    for (it3 = vec2.begin(); it3 != vec2.end(); it3++) {
        std::cout << *it3 << " ";
    }

    std::cout << "\nSTD: \n";
    std::vector<int>::iterator it4;
    for (it4 = vector2.begin(); it4 != vector2.end(); it4++) {
        std::cout << *it4 << " ";
    }
    std::cout << "\n";


    std::cout << "\n --------- template< class InputIt > void insert(iterator pos, InputIt first, InputIt last)\n";
    ft::Vector<int> vec3;
    std::vector<int> vector3;
    std::vector<int> tmp;

    vec3.push_back(5);
    vec3.push_back(5);
    vec3.push_back(5);

    vector3.push_back(5);
    vector3.push_back(5);
    vector3.push_back(5);


    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);

    vec3.insert(vec3.end() - 1, tmp.begin() + 1, tmp.end());
    vector3.insert(vector3.end() - 1, tmp.begin() + 1, tmp.end());

    std::cout << "MY: \n";
    ft::Vector<int>::iterator it5;
    for (it5 = vec3.begin(); it5 != vec3.end(); it5++) {
        std::cout << *it5 << " ";
    }

    std::cout << "\nSTD: \n";
    std::vector<int>::iterator it6;
    for (it6 = vector3.begin(); it6 != vector3.end(); it6++) {
        std::cout << *it6 << " ";
    }
    std::cout << "\n";
}

void erase_test()
{
    std::cout << "\n --------- iterator erase(iterator pos)\n";
    std::vector<int> vector1;
    ft::Vector<int> vec1;
    ft::Vector<int>::iterator it1;
    std::vector<int>::iterator it2;
    
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);

    vector1.push_back(1);
    vector1.push_back(2);
    vector1.push_back(3);
    vector1.push_back(4);
    vector1.push_back(5);


    vector1.erase(vector1.end() - 2);
    vec1.erase(vec1.end() - 2);
    std::cout << "MY: \n";
    for (it1 = vec1.begin(); it1 != vec1.end(); it1++) {
        std::cout << *it1 << " ";
    }

    std::cout << "\nSTD: \n";
    for (it2 = vector1.begin(); it2 != vector1.end(); it2++) {
        std::cout << *it2 << " ";
    }
    std::cout << "\n";

    std::cout << "\n --------- iterator erase(iterator first, iterator last)\n";
    std::vector<int> vector2;
    ft::Vector<int> vec2;
    ft::Vector<int>::iterator it3;
    std::vector<int>::iterator it4;
    
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);

    vector2.push_back(1);
    vector2.push_back(2);
    vector2.push_back(3);
    vector2.push_back(4);
    vector2.push_back(5);


    vector2.erase(vector2.begin() + 1, vector2.end() - 1);
    vec2.erase(vec2.begin() + 1, vec2.end() - 1);
    std::cout << "MY: \n";
    for (it3 = vec2.begin(); it3 != vec2.end(); it3++) {
        std::cout << *it3 << " ";
    }

    std::cout << "\nSTD: \n";
    for (it4 = vector2.begin(); it4 != vector2.end(); it4++) {
        std::cout << *it4 << " ";
    }
    std::cout << "\n";
}

int main(){

    // insert_test();
    erase_test();



//-------------------------------------------------------------------------------- ITERATORS
    // // std::vector<int> vec1;
    // // ft::Vector<int> vector;
    // // std::vector<int>::reverse_iterator it;
    // // ft::Vector<int>::reverse_iterator it1;

    // // vec.push_back(1);
    // // vec.push_back(2);
    // // vec.push_back(3);
    // // vec.push_back(4);
    // // vec.push_back(5);

    // // vector.push_back(1);
    // // vector.push_back(2);
    // // vector.push_back(3);
    // // vector.push_back(4);
    // // vector.push_back(5);

    // std::vector<int> vec;
    // ft::Vector<int> vector;
    // std::vector<int>::const_iterator rev_it;
    // ft::Vector<int>::const_iterator rev_it1;

    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);
    // vec.push_back(5);

    // vector.push_back(1);
    // vector.push_back(2);
    // vector.push_back(3);
    // vector.push_back(4);
    // vector.push_back(5);
    
    // // std::cout << "reverse iterator: \n";
    // // std::cout << "MY: \n";
    // // for (it1 = ++vector.rbegin(); it1 != vector.rend() - 2; it1++) {
    // //     std::cout << *it1 << " ";
    // // }

    // // std::cout << "\nSTD: \n";
    // // for (it = ++vec.rbegin(); it != vec.rend() -2; it++) {
    // //     std::cout << *it << " ";
    // // }
    // // std::cout << "\n";

    // std::cout << "const reverse iterator: \n";
    // std::cout << "MY: \n";
    // for (rev_it1 = vector.begin(); rev_it1 != vector.end(); rev_it1++) {
    //     std::cout << "lol\n";
    //     std::cout << *rev_it1 << " ";
    // }

    // std::cout << "\nSTD: \n";
    // for (rev_it = vec.begin(); rev_it != vec.end(); rev_it++) {
    //     std::cout << *rev_it << " ";
    // }
    // std::cout << "\n";
//-------------------------------------------------------------------------------------------		

    // int _ratio = 10000;
    // std::vector<int> vector4;
    // std::vector<int> v;
    // vector4.assign(2600 * _ratio, 1);
    // v.push_back(*(vector4.insert(vector4.end() - 800 * _ratio, 44)));
    // v.push_back(vector4.size());
    // v.push_back(vector4.capacity());
    // std::unique_ptr<B> k2(new B(3));
    // std::unique_ptr<B> k3(new B(4));
    // std::unique_ptr<B> k4(new B(-1));
    // std::vector<A> vv;
    // std::vector<B*> v1;

    // v1.push_back(&(*k2));
    // v1.push_back(&(*k3));
    // v1.push_back(&(*k4));
    // try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    // catch (...) {
    // 	v.push_back(vv.size());
    // 	v.push_back(vv.capacity());
    // }

    // std::cout << "STD: \n";
    // std::vector<int>::iterator it;
    // for (it = v.begin(); it != v.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }

    // ft::Vector<int> vector5;
    // ft::Vector<int> v2;
    // vector5.assign(2600 * _ratio, 1);
    // v2.push_back(*(vector5.insert(vector5.end() - 800 * _ratio, 44)));
    // v2.push_back(vector5.size());
    // v2.push_back(vector5.capacity());
    // std::unique_ptr<B> k5(new B(3));
    // std::unique_ptr<B> k6(new B(4));
    // std::unique_ptr<B> k7(new B(-1));
    // ft::Vector<A> vvv;
    // ft::Vector<B*> v3;

    // v3.push_back(&(*k5));
    // v3.push_back(&(*k6));
    // v3.push_back(&(*k7));
    // try { vvv.insert(vvv.begin(), v3.begin(), v3.end()); }
    // catch (...) {
    // 	v2.push_back(vvv.size());
    // 	v2.push_back(vvv.capacity());
    // }

    // std::cout << "\nMY: \n";
    // ft::Vector<int>::iterator iter;
    // for (iter = v2.begin(); iter != v2.end(); iter++)
    // {
    //     std::cout << *iter << " ";
    // }
    // std::cout << "\n";
}







