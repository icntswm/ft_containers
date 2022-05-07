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
    std::cout << "\033[31m\n --------- iterator insert (iterator position, const_reference val)\033[0m\n";
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


    std::cout << "\033[31m\n --------- void insert(iterator pos, size_type count, const_reference value)\033[0m\n";
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


    std::cout << "\033[31m\n --------- template< class InputIt > void insert(iterator pos, InputIt first, InputIt last)\033[0m\n";
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
    std::cout << "\033[31m\n --------- iterator erase(iterator pos)\033[0m\n";
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

    std::cout << "\033[31m\n --------- iterator erase(iterator first, iterator last)\033[0m\n";
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

void swap_test() {
    std::cout << "\033[31m\n --------- void swap(Vector & other)\033[0m\n";
    int _ratio = 10000;
    ft::Vector<int> my_vector;
    std::vector<int> v;
    my_vector.assign(1100 * _ratio, 11);
    ft::Vector<int> tmp1(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
    v.push_back(my_vector[2]);
    v.push_back(my_vector.size());
    v.push_back(my_vector.capacity());
    long *adr1 = reinterpret_cast<long *>(&my_vector);
    long *adr2 = reinterpret_cast<long *>(&tmp1);
    my_vector.swap(tmp1);
    if (reinterpret_cast<long *>(&my_vector) == adr1 && reinterpret_cast<long *>(&tmp1) == adr2)
    	v.push_back(1);
    v.push_back(my_vector[2]);
    v.push_back(my_vector.size());
    v.push_back(my_vector.capacity());
    my_vector.swap(tmp3);
    v.push_back(my_vector[2]);
    v.push_back(my_vector.size());
    v.push_back(my_vector.capacity());
    std::swap(my_vector, tmp2);
    v.push_back(my_vector[2]);
    v.push_back(my_vector.size());
    v.push_back(my_vector.capacity());
    std::swap(my_vector, tmp4);
    v.push_back(my_vector[2]);
    v.push_back(my_vector.size());
    v.push_back(my_vector.capacity());

    std::vector<int>::iterator vit;
    std::cout << "MY: \n";
    for (vit = v.begin(); vit != v.end(); vit++){
        std::cout << *vit << " ";
    }

    std::vector<int> std_vector;
    std::vector<int> vv;
    std_vector.assign(1100 * _ratio, 11);
    std::vector<int> tmp5(500 * _ratio, 5), tmp6(1000 * _ratio, 10), tmp7(1500 * _ratio, 15), tmp8(3000 * _ratio, 30);
    vv.push_back(std_vector[2]);
    vv.push_back(std_vector.size());
    vv.push_back(std_vector.capacity());
    long *adr3 = reinterpret_cast<long *>(&std_vector);
    long *adr4 = reinterpret_cast<long *>(&tmp5);
    std_vector.swap(tmp5);
    if (reinterpret_cast<long *>(&std_vector) == adr3 && reinterpret_cast<long *>(&tmp5) == adr4)
    	vv.push_back(1);
    vv.push_back(std_vector[2]);
    vv.push_back(std_vector.size());
    vv.push_back(std_vector.capacity());
    std_vector.swap(tmp7);
    vv.push_back(std_vector[2]);
    vv.push_back(std_vector.size());
    vv.push_back(std_vector.capacity());
    std::swap(std_vector, tmp6);
    vv.push_back(std_vector[2]);
    vv.push_back(std_vector.size());
    vv.push_back(std_vector.capacity());
    std::swap(std_vector, tmp8);
    vv.push_back(std_vector[2]);
    vv.push_back(std_vector.size());
    vv.push_back(std_vector.capacity());

    std::vector<int>::iterator stdvit;
    std::cout << "\nSTD: \n";
    for (stdvit = vv.begin(); stdvit != vv.end(); stdvit++){
        std::cout << *stdvit << " ";
    }
    std::cout << "\n";
}

void    assign_test()
{
    std::cout << "\033[31m\n --------- void assign(size_type count, const_reference value)\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(1);
    vecc2.push_back(2);
    vecc2.push_back(3);

    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);


    vecc2.assign(5, 7);
    vect2.assign(5, 7);
    std::cout << "MY: \n";
    for (iter3 = vecc2.begin(); iter3 != vecc2.end(); iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD: \n";
    for (iter4 = vect2.begin(); iter4 != vect2.end(); iter4++) {
        std::cout << *iter4 << " ";
    }
    std::cout << "\n";



    std::cout << "\033[31m\n --------- template<class InputIt> void assign(InputIt first, InputIt last)\033[0m\n";
    std::vector<int> tmp;

    tmp.push_back(11);
    tmp.push_back(12);
    tmp.push_back(13);

    vecc2.assign(tmp.begin(), tmp.end() - 1);
    vect2.assign(tmp.begin(), tmp.end() - 1);
    std::cout << "MY: \n";
    for (iter3 = vecc2.begin(); iter3 != vecc2.end(); iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD: \n";
    for (iter4 = vect2.begin(); iter4 != vect2.end(); iter4++) {
        std::cout << *iter4 << " ";
    }
    std::cout << "\n";
}

void at_test()
{
    std::cout << "\033[31m\n --------- reference at(size_type pos)\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(1);
    vecc2.push_back(2);
    vecc2.push_back(3);

    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);

    std::cout << "MY: \n";
    std::cout << vecc2.at(0);

    std::cout << "\nSTD: \n";
    std::cout << vect2.at(0);
    std::cout << "\n";
}

void back_test()
{
    std::cout << "\033[31m\n --------- reference back()\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(1);
    vecc2.push_back(2);
    vecc2.push_back(3);

    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);

    std::cout << "MY: \n";
    std::cout << vecc2.back();

    std::cout << "\nSTD: \n";
    std::cout << vect2.back();
    std::cout << "\n";
}

void begin_end_test()
{
    std::cout << "\033[31m\n --------- iterator begin() && iterator end()\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(1);
    vecc2.push_back(2);
    vecc2.push_back(3);

    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);

    std::cout << "MY: \n";
    for (iter3 = vecc2.begin() + 1; iter3 != vecc2.end(); iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD: \n";
    for (iter4 = vect2.begin() + 1; iter4 != vect2.end(); iter4++) {
        std::cout << *iter4 << " ";
    }
    std::cout << "\n";
}

void capacity_test()
{
    std::cout << "\033[31m\n --------- size_type capacity()\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(1);
    vecc2.push_back(2);
    vecc2.push_back(3);

    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);

    vecc2.assign(111, 1);
    vect2.assign(111, 1);
    std::cout << "MY: \n";
    std::cout << vecc2.capacity();

    std::cout << "\nSTD: \n";
    std::cout << vect2.capacity();
    std::cout << "\n";
}

void clear_test()
{
    std::cout << "\033[31m\n --------- void clear()\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(1);
    vecc2.push_back(2);
    vecc2.push_back(3);

    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);


    std::cout << "MY before: \n";
    for (iter3 = vecc2.begin(); iter3 != vecc2.end(); iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD before: \n";
    for (iter4 = vect2.begin(); iter4 != vect2.end(); iter4++) {
        std::cout << *iter4 << " ";
    }
    vecc2.clear();
    vect2.clear();
    std::cout << "\nMY after: \n";
    for (iter3 = vecc2.begin(); iter3 != vecc2.end(); iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD after: \n";
    for (iter4 = vect2.begin(); iter4 != vect2.end(); iter4++) {
        std::cout << *iter4 << " ";
    }
    std::cout << "\n";
}

void data_test()
{
    std::cout << "\033[31m\n --------- pointer data()\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(17);
    vecc2.push_back(27);
    vecc2.push_back(37);

    vect2.push_back(17);
    vect2.push_back(27);
    vect2.push_back(37);

    std::cout << "MY: \n";
    std::cout << *vecc2.data();

    std::cout << "\nSTD: \n";
    std::cout << *vect2.data();
    std::cout << "\n";
}

void empty_test()
{
    std::cout << "\033[31m\n --------- bool empty() const\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    // vecc2.push_back(1);
    // vecc2.push_back(2);
    // vecc2.push_back(3);

    // vect2.push_back(1);
    // vect2.push_back(2);
    // vect2.push_back(3);

    std::cout << "MY: \n";
    std::cout << vecc2.empty();

    std::cout << "\nSTD: \n";
    std::cout << vect2.empty();
    std::cout << "\n";
}

void front_test()
{
    std::cout << "\033[31m\n --------- reference front()\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(11);
    vecc2.push_back(22);
    vecc2.push_back(33);

    vect2.push_back(11);
    vect2.push_back(22);
    vect2.push_back(33);

    std::cout << "MY: \n";
    std::cout << vecc2.front();

    std::cout << "\nSTD: \n";
    std::cout << vect2.front();
    std::cout << "\n";
}

void max_size_test()
{
    std::cout << "\033[31m\n --------- size_type size() const && size_type max_size() const\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(1);
    vecc2.push_back(2);
    vecc2.push_back(3);

    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);

    vecc2.assign(111, 1);
    vect2.assign(111, 1);
    std::cout << "MY: \n";
    std::cout << vecc2.size() << " / " << vecc2.max_size();

    std::cout << "\nSTD: \n";
    std::cout << vect2.size() << " / " << vect2.max_size();
    std::cout << "\n";
}

void operator_equals_test()
{
    std::cout << "\033[31m\n --------- Vector & operator=(const Vector & other)\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    ft::Vector<int> temp_vecc;
    std::vector<int> temp_vect;
    
    vecc2.push_back(11);
    vecc2.push_back(22);
    vecc2.push_back(33);

    vect2.push_back(11);
    vect2.push_back(22);
    vect2.push_back(33);

    temp_vecc = vecc2;
    temp_vect = vect2;
    std::cout << "MY: \n";
    for (iter3 = temp_vecc.begin(); iter3 != temp_vecc.end(); iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD: \n";
    for (iter4 = temp_vect.begin(); iter4 != temp_vect.end(); iter4++) {
        std::cout << *iter4 << " ";
    }
    std::cout << "\n";
}

void operator_squarebrek_test()
{
    std::cout << "\033[31m\n --------- reference operator[](size_type pos)\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    
    vecc2.push_back(11);
    vecc2.push_back(22);
    vecc2.push_back(33);

    vect2.push_back(11);
    vect2.push_back(22);
    vect2.push_back(33);

    std::cout << "MY: \n";
    std::cout << vecc2[1];

    std::cout << "\nSTD: \n";
    std::cout << vect2[1];
    std::cout << "\n";
}

void pop_push_back_test()
{
    std::cout << "\033[31m\n --------- void pop_back() && void push_back(const_reference value)\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::iterator iter3;
    std::vector<int>::iterator iter4;
    
    vecc2.push_back(11);
    vecc2.push_back(22);
    vecc2.push_back(33);

    vect2.push_back(11);
    vect2.push_back(22);
    vect2.push_back(33);

    vecc2.pop_back();
    vect2.pop_back();    
    std::cout << "MY: \n";
    for (iter3 = vecc2.begin(); iter3 != vecc2.end(); iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD: \n";
    for (iter4 = vect2.begin(); iter4 != vect2.end(); iter4++) {
        std::cout << *iter4 << " ";
    }
    std::cout << "\n";
}

void rbegin_rend_test()
{
    std::cout << "\033[31m\n --------- reverse_iterator rbegin() && reverse_iterator rend()\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::reverse_iterator iter3;
    std::vector<int>::reverse_iterator iter4;
    
    vecc2.push_back(1);
    vecc2.push_back(2);
    vecc2.push_back(3);
    vecc2.push_back(4);

    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);
    vect2.push_back(4);

    std::cout << "MY: \n";
    for (iter3 = vecc2.rbegin() + 1; iter3 != vecc2.rend() - 1; iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD: \n";
    for (iter4 = vect2.rbegin() + 1; iter4 != vect2.rend() - 1; iter4++) {
        std::cout << *iter4 << " ";
    }
    std::cout << "\n";
}

void reserve_test()
{
    std::cout << "\033[31m\n --------- void reserve(size_type n)\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    
   

    vecc2.reserve(1221);
    vect2.reserve(1221);
    std::cout << "MY: \n";
    std::cout << vecc2.capacity();

    std::cout << "\nSTD: \n";
    std::cout << vect2.capacity();
    std::cout << "\n";
}

void resize_test()
{
    std::cout << "\033[31m\n --------- void resize (size_type n, value_type val = value_type())\033[0m\n";
    std::vector<int> vect2;
    ft::Vector<int> vecc2;
    ft::Vector<int>::reverse_iterator iter3;
    std::vector<int>::reverse_iterator iter4;
    
    vecc2.resize(17, 4);
    vect2.resize(17, 4);
    std::cout << "MY: \n";
    std::cout << vecc2.size() << "\n";
    for (iter3 = vecc2.rbegin() + 1; iter3 != vecc2.rend() - 1; iter3++) {
        std::cout << *iter3 << " ";
    }

    std::cout << "\nSTD: \n";
    std::cout << vect2.size() << "\n";
    for (iter4 = vect2.rbegin() + 1; iter4 != vect2.rend() - 1; iter4++) {
        std::cout << *iter4 << " ";
    }
    std::cout << "\n";
}

int main(){
    assign_test();                  //++
    at_test();                      //+-
    back_test();                    //+-
    begin_end_test();               //+-+-
    capacity_test();                //+
    clear_test();                   //+
    data_test();                    //+-
    empty_test();                   //+
    erase_test();                   //++
    front_test();                   //+-
    insert_test();                  //+++
    max_size_test();                //+
    operator_equals_test();         //+
    operator_squarebrek_test();     //+-
    pop_push_back_test();           //++
    rbegin_rend_test();             //+-+-
    reserve_test();                 //+
    resize_test();                  //+
    swap_test();                    //+



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







