#include "../map.hpp"
#include <map>

void at_test()
{
    std::cout << "\033[31m\n --------- AT ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
     
    std_map.insert(std::make_pair(1, 1));
    std_map.insert(std::make_pair(11, 11));
    std_map.insert(std::make_pair(111, 111));

    ft_map.insert(ft::make_pair(1, 1));
    ft_map.insert(ft::make_pair(11, 11));
    ft_map.insert(ft::make_pair(111, 111));

    std::cout << "\033[34mMY: \033[0m\n";
    std::cout << ft_map.at(11);
    // std::cout << ft_map.at(22);
    
    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.at(11);
    // std::cout << std_map.at(22);
    std::cout << "\n";
}

void operator_squarebrek_test()
{
    std::cout << "\033[31m\n --------- OPERATOR[] ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
        
    std_map[1] = 1;
    std_map[11] = 11;
    std_map[111] = 111;

    ft_map[1] = 1;
    ft_map[11] = 11;
    ft_map[111] = 111;

    std::cout << "\033[34mMY: \033[0m\n";
    std::cout << ft_map[111];

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map[111];
    std::cout << "\n";
}

void operator_equals_test()
{
    std::cout << "\033[31m\n --------- OPERATOR= ---------\033[0m\n";
    std::map<int, int> std_map;
    std::map<int, int> temp_std_map;
    ft::map<int, int> ft_map;
    ft::map<int, int> temp_ft_map;

    std_map[2] = 2;
    std_map[22] = 22;
    std_map[222] = 222;

    ft_map[2] = 2;
    ft_map[22] = 22;
    ft_map[222] = 222;

    temp_std_map = std_map;
    temp_ft_map = ft_map;
    std::cout << "\033[34mMY: \033[0m\n";
    std::cout << temp_ft_map[22];

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << temp_std_map[22];
    std::cout << "\n";
}

void begin_end_test()
{
    std::cout << "\033[31m\n --------- BEGIN && END ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    
    std::map<int, int>::iterator std_iter;
    ft::map<int, int>::iterator ft_iter;
    
    std_map[1] = 1;
    std_map[12] = 11;
    std_map[123] = 111;

    ft_map[1] = 1;
    ft_map[12] = 11;
    ft_map[123] = 111;

    std::cout << "\033[34mMY: \033[0m\n";
    for (ft_iter = ft_map.begin(); ft_iter != ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }

    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_iter = std_map.begin(); std_iter != std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\n";
}

void rbegin_rend_test()
{
    std::cout << "\033[31m\n --------- RBEGIN && REND ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    
    std::map<int, int>::reverse_iterator std_iter;
    ft::map<int, int>::reverse_iterator ft_iter;
    
    std_map[1] = 1;
    std_map[12] = 11;
    std_map[123] = 111;

    ft_map[1] = 1;
    ft_map[12] = 11;
    ft_map[123] = 111;

    std::cout << "\033[34mMY: \033[0m\n";
    for (ft_iter = ft_map.rbegin(); ft_iter != ft_map.rend(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }

    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_iter = std_map.rbegin(); std_iter != std_map.rend(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\n";
}

void empty_test()
{
    std::cout << "\033[31m\n --------- EMPTY ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std::cout << "\033[34mMY: \033[0m\n";
    std::cout << ft_map.empty();

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.empty();

    std_map[2] = 2;
    ft_map[2] = 2;

    std::cout << "\033\n[34mMY: \033[0m\n";
    std::cout << ft_map.empty();

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.empty();
    std::cout << "\n";
}

void size_test()
{
    std::cout << "\033[31m\n --------- SIZE ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std_map[2] = 2;
    std_map[3] = 3;
    std_map[32] = 32;

    ft_map[2] = 2;
    ft_map[3] = 3;
    ft_map[32] = 32;

    std::cout << "\033\n[34mMY: \033[0m\n";
    std::cout << ft_map.size();

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.size();
    std::cout << "\n";
}

void clear_test()
{
    std::cout << "\033[31m\n --------- CLEAR ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std_map[2] = 2;
    std_map[3] = 3;
    std_map[32] = 32;

    ft_map[2] = 2;
    ft_map[3] = 3;
    ft_map[32] = 32;

    std::cout << "\033\n[34mMY: \033[0m\n";
    std::cout << ft_map.size();
    ft_map.clear();
    std::cout << "\n" << ft_map.size();

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.size();
    std_map.clear();
    std::cout << "\n" << std_map.size();
    std::cout << "\n";
}

void insert_test()
{
    std::cout << "\033[31m\n --------- INSERT ---------\033[0m\n";
    std::map<int, int> std_map;
    std::map<int, int> temp_std_map;
    ft::map<int, int> ft_map;
    ft::map<int, int> temp_ft_map;

    std::map<int, int>::iterator std_iter;
    ft::map<int, int>::iterator ft_iter;

    temp_std_map[345] = 543;
    temp_std_map[456] = 654;
    temp_std_map[567] = 765;

    temp_ft_map[345] = 543;
    temp_ft_map[456] = 654;
    temp_ft_map[567] = 765;
     
    
    std_map.insert(std::make_pair(1, 1));
    std_map.insert(std::make_pair(11, 11));
    std_map.insert(std::make_pair(111, 111));

    std_iter = std_map.begin();
    std_map.insert(std_iter, std::make_pair(22, 222));

    std_map.insert(temp_std_map.begin(), temp_std_map.end());


    ft_map.insert(ft::make_pair(1, 1));
    ft_map.insert(ft::make_pair(11, 11));
    ft_map.insert(ft::make_pair(111, 111));

    ft_iter = ft_map.begin();
    ft_map.insert(ft_iter, ft::make_pair(22, 222));

    ft_map.insert(temp_ft_map.begin(), temp_ft_map.end());

    std::cout << "\033[34mMY: \033[0m\n";
    for (ft_iter = ft_map.begin(); ft_iter != ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }

    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_iter = std_map.begin(); std_iter != std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\n";
}

void erase_test()
{
    std::cout << "\033[31m\n --------- ERASE ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std::map<int, int>::iterator std_iter;
    ft::map<int, int>::iterator ft_iter;

    std_map[1] = 1;
    std_map[11] = 11;
    std_map[111] = 111;
    std_map[123] = 321;
    std_map[321] = 123;
    std_map[234] = 432;
    std_map[1567] = 1567;

    ft_map[1] = 1;
    ft_map[11] = 11;
    ft_map[111] = 111;
    ft_map[123] = 321;
    ft_map[321] = 123;
    ft_map[234] = 432;
    ft_map[1567] = 1567;
        
    std::cout << "\033[34mMY: \033[0m\n";
    for (ft_iter = ft_map.begin(); ft_iter != ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }

    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_iter = std_map.begin(); std_iter != std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\n";

    std_map.erase(std_map.begin(), ++std_map.begin());
    ft_map.erase(ft_map.begin(), ++ft_map.begin());

    std_map.erase(--std_map.end());
    ft_map.erase(--ft_map.end());

    std_map.erase(234);
    ft_map.erase(234);

    std::cout << "\033[34mMY: \033[0m\n";
    for (ft_iter = ft_map.begin(); ft_iter != ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }

    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_iter = std_map.begin(); std_iter != std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\n";
}

void swap_test()
{
    std::cout << "\033[31m\n --------- SWAP ---------\033[0m\n";
    std::map<int, int> std_map;
    std::map<int, int> temp_std_map;
    ft::map<int, int> ft_map;
    ft::map<int, int> temp_ft_map;

    std::map<int, int>::iterator std_iter;
    ft::map<int, int>::iterator ft_iter;

    std_map[2] = 2;
    std_map[3] = 3;
    std_map[32] = 32;

    temp_std_map[5678] = 7866;
    temp_std_map[3453] = 12312;
    temp_std_map[7567] = 34573;


    ft_map[2] = 2;
    ft_map[3] = 3;
    ft_map[32] = 32;

    temp_ft_map[5678] = 7866;
    temp_ft_map[3453] = 12312;
    temp_ft_map[7567] = 34573;

    std::cout << "\033[36mbefore the swap:\n\033[34mMY: \033[0m\n";
    for (ft_iter = ft_map.begin(); ft_iter != ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }
    std::cout << "\ntemp: ";
    for (ft_iter = temp_ft_map.begin(); ft_iter != temp_ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }

    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_iter = std_map.begin(); std_iter != std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\ntemp: ";
    for (std_iter = temp_std_map.begin(); std_iter != temp_std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std_map.swap(temp_std_map);
    ft_map.swap(temp_ft_map);
    std::cout << "\n\033[36mafter the swap:\n\033[34mMY: \033[0m\n";
    for (ft_iter = ft_map.begin(); ft_iter != ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }
    std::cout << "\ntemp: ";
    for (ft_iter = temp_ft_map.begin(); ft_iter != temp_ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }

    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_iter = std_map.begin(); std_iter != std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\ntemp: ";
    for (std_iter = temp_std_map.begin(); std_iter != temp_std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\n";
}

void count_test()
{
    std::cout << "\033[31m\n --------- COUNT ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std_map[2] = 2;
    std_map[3] = 3;
    std_map[32] = 32;

    ft_map[2] = 2;
    ft_map[3] = 3;
    ft_map[32] = 32;

    std::cout << "\033\n[34mMY: \033[0m\n";
    std::cout << ft_map.count(32) << "\n";
    std::cout << ft_map.count(1);

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.count(32) << "\n";
    std::cout << std_map.count(1);
    
    std::cout << "\n";
}

void find_test()
{
    std::cout << "\033[31m\n --------- FIND ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std_map[2] = 12;
    std_map[3] = 13;
    std_map[32] = 132;

    ft_map[2] = 12;
    ft_map[3] = 13;
    ft_map[32] = 132;

    std::cout << "\033\n[34mMY: \033[0m\n";
    std::cout << ft_map.find(32)->second << "\n";
    // ft::map<int, int>::iterator ft_iter = ft_map.find(1); //???????????????????????????????????
    // std::cout << ft_iter->second;


    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.find(32)->second << "\n";
    // std::map<int, int>::iterator std_iter = std_map.find(1);
    // std::cout << std_iter->second;
    
    std::cout << "\n";
}

void equal_range_test()
{
    std::cout << "\033[31m\n --------- EQUAL_RANGE ---------\033[0m\n";
    std::map<int, int> std_map;
    std::map<int, int> temp_std_map;
    ft::map<int, int> ft_map;
    ft::map<int, int> temp_ft_map;

    std::map<int, int>::iterator std_iter;
    ft::map<int, int>::iterator ft_iter;

    std_map[2] = 12;
    std_map[3] = 13;
    std_map[32] = 132;

    ft_map[2] = 12;
    ft_map[3] = 13;
    ft_map[32] = 132;

    // temp_std_map = std_map.equal_range(3);
    // temp_ft_map = ft_map.equal_range(3);
    
    std::cout << "\033[34mMY: \033[0m\n";
    for (ft_iter = temp_ft_map.begin(); ft_iter != temp_ft_map.end(); ft_iter++) {
        std::cout << "[" << ft_iter->first << "]" << " = " << ft_iter->second << "  |  ";
    }

    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_iter = temp_std_map.begin(); std_iter != temp_std_map.end(); std_iter++) {
        std::cout << "[" << std_iter->first << "]" << " = " << std_iter->second << "  |  ";
    }
    std::cout << "\n";
}

void lower_bound_test()
{
    std::cout << "\033[31m\n --------- LOWER_BOUND ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std_map[2] = 22;
    std_map[3] = 333;
    std_map[32] = 312;

    ft_map[2] = 22;
    ft_map[3] = 333;
    ft_map[32] = 312;

    std::cout << "\033\n[34mMY: \033[0m\n";
    std::cout << ft_map.lower_bound(3)->second << "\n";
    std::cout << ft_map.lower_bound(1)->second;

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.lower_bound(3)->second << "\n";
    std::cout << std_map.lower_bound(1)->second;
    
    std::cout << "\n";
}

void upper_bound_test()
{
    std::cout << "\033[31m\n --------- UPPER_BOUND ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std_map[2] = 22;
    std_map[3] = 333;
    std_map[32] = 312;
    std_map[13] = 1363;
    std_map[3322] = 13432;

    ft_map[2] = 22;
    ft_map[3] = 333;
    ft_map[32] = 312;
    ft_map[13] = 1363;
    ft_map[3322] = 13432;

    std::cout << "\033\n[34mMY: \033[0m\n";
    std::cout << ft_map.upper_bound(3)->second << "\n";
    std::cout << ft_map.upper_bound(1)->second;

    std::cout << "\033[34m\nSTD: \033[0m\n";
    std::cout << std_map.upper_bound(3)->second << "\n";
    std::cout << std_map.upper_bound(1)->second;
    
    std::cout << "\n";
}

void key_comp_test()
{
    std::cout << "\033[31m\n --------- KEY_COMP ---------\033[0m\n";
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std_map[2] = 22;
    std_map[3] = 333;
    std_map[32] = 312;
    std_map[13] = 1363;
    std_map[3322] = 13432;
    std_map[4] = 12;

    ft_map[2] = 22;
    ft_map[3] = 333;
    ft_map[32] = 312;
    ft_map[13] = 1363;
    ft_map[3322] = 13432;
    ft_map[4] = 12;

    std::cout << "\033\n[34mMY: \033[0m\n";
    if (ft_map.key_comp()(ft_map[2], ft_map[3]))
        std::cout << "the second is greater than the first\n";
    else
        std::cout << "the first is greater than the second\n";

    std::cout << "\033[34m\nSTD: \033[0m\n";
    if (std_map.key_comp()(std_map[2], std_map[3]))
        std::cout << "the second is greater than the first\n";
    else
        std::cout << "the first is greater than the second\n";
    
    std::cout << "\n";
}

void iter_test()
{
    std::cout << "\033[31m\n --------- ITERATOR TESTS ---------\033[0m\n";
    std::map<int, int> vec;
    ft::map<int, int> my_vec;
    
    vec[1] = 11;   my_vec[1] = 11; 
    vec[2] = 22;   my_vec[2] = 22; 
    vec[3] = 33;   my_vec[3] = 33; 
    vec[4] = 44;   my_vec[4] = 44; 
    vec[5] = 55;   my_vec[5] = 55; 
    vec[6] = 66;   my_vec[6] = 66; 
    vec[7] = 77;   my_vec[7] = 77; 
    vec[8] = 88;   my_vec[8] = 88; 
    vec[9] = 99;   my_vec[9] = 99; 
    vec[10] = 100;  my_vec[10] = 100; 

    std::cout << "\033[32mITERATOR: \n\033[0m";
    std::cout << "\nCheck \"it = const it\":";
    std::cout << "\n\033[34mMY: \033[0m\n";
    ft::map<int, int>::iterator my_it = ++my_vec.begin();
    ft::map<int, int>::const_iterator my_const_it2 = my_vec.begin();
    std::cout << "[" << my_const_it2->first << "] = " << my_const_it2->second << "  |  ";
    my_const_it2 = my_it;
    std::cout << "[" << my_const_it2->first << "] = " << my_const_it2->second << "  |  ";


    std::cout << "\033\n[34mSTD: \033[0m\n";
    std::map<int, int>::iterator it = ++vec.begin();
    std::map<int, int>::const_iterator const_it2 = vec.begin();

    std::cout << "[" << const_it2->first << "] = " << const_it2->second << "  |  ";
    const_it2 = it;
    std::cout << "[" << const_it2->first << "] = " << const_it2->second << "  |  ";


    std::map<int, int>::iterator std_i;
    ft::map<int, int>::iterator  my_i;

    std::cout << "\nOther: ";
    std::cout << "\n\033[34mMY: \033[0m\n";
    for (my_i = my_vec.begin(); my_i != my_vec.end(); my_i++) {
        std::cout << "[" << my_i->first << "] = " << my_i->second << "  |  ";
    }
    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_i = vec.begin(); std_i != vec.end(); std_i++) {
        std::cout << "[" << std_i->first << "] = " << std_i->second << "  |  ";
    }
    std::cout << "\n";

    std::cout << "\n\033[34mMY: \033[0m\n";
    for (my_i = ++my_vec.begin(); my_i != --my_vec.end(); my_i++) {
        std::cout << "[" << my_i->first << "] = " << my_i->second << "  |  ";
    }
    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_i = ++vec.begin(); std_i != --vec.end(); std_i++) {
        std::cout << "[" << std_i->first << "] = " << std_i->second << "  |  ";
    }
    std::cout << "\n";

    std::map<int, int>::const_iterator const_std_i;
    ft::map<int, int>::const_iterator  const_my_i;

    std::cout << "\nConst Other: ";
    std::cout << "\n\033[34mMY: \033[0m\n";
    for (const_my_i = my_vec.begin(); const_my_i != my_vec.end(); const_my_i++) {
        std::cout << "[" << const_my_i->first << "] = " << const_my_i->second << "  |  ";
    }
    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (const_std_i = vec.begin(); const_std_i != vec.end(); const_std_i++) {
        std::cout << "[" << const_std_i->first << "] = " << const_std_i->second << "  |  ";
    }
    std::cout << "\n";

    std::cout << "\n\033[34mMY: \033[0m\n";
    for (const_my_i = ++my_vec.begin(); const_my_i != --my_vec.end(); const_my_i++) {
        std::cout << "[" << const_my_i->first << "] = " << const_my_i->second << "  |  ";
    }
    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (const_std_i = ++vec.begin(); const_std_i != --vec.end(); const_std_i++) {
       std::cout << "[" << const_std_i->first << "] = " << const_std_i->second << "  |  ";
    }
    std::cout << "\n";


    std::cout << "\033[32m\nREVERSE ITERATOR: \n\033[0m";
    std::cout << "\nCheck \"it = const it\":";
    std::cout << "\n\033[34mMY: \033[0m\n";
    ft::map<int, int>::reverse_iterator my_rit = ++my_vec.rbegin();
    ft::map<int, int>::const_reverse_iterator my_const_rit2 = my_vec.rbegin();
    std::cout << "[" << my_const_rit2->first << "] = " << my_const_rit2->second << "  |  ";
    my_const_rit2 = my_rit;
    std::cout << "[" << my_const_rit2->first << "] = " << my_const_rit2->second << "  |  ";


    std::cout << "\033\n[34mSTD: \033[0m\n";
    std::map<int, int>::reverse_iterator rit = ++vec.rbegin();
    std::map<int, int>::const_reverse_iterator const_rit2 = vec.rbegin();

    std::cout << "[" << const_rit2->first << "] = " << const_rit2->second << "  |  ";
    const_rit2 = rit;
    std::cout << "[" << const_rit2->first << "] = " << const_rit2->second << "  |  ";

    std::map<int, int>::reverse_iterator std_ri;
    ft::map<int, int>::reverse_iterator  my_ri;

    std::cout << "\nOther: ";
    std::cout << "\n\033[34mMY: \033[0m\n";
    for (my_ri = my_vec.rbegin(); my_ri != my_vec.rend(); my_ri++) {
        std::cout << "[" << my_ri->first << "] = " << my_ri->second << "  |  ";
    }
    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_ri = vec.rbegin(); std_ri != vec.rend(); std_ri++) {
        std::cout << "[" << std_ri->first << "] = " << std_ri->second << "  |  ";
    }
    std::cout << "\n";

    std::cout << "\n\033[34mMY: \033[0m\n";
    for (my_ri = ++my_vec.rbegin(); my_ri != --my_vec.rend(); my_ri++) {
        std::cout << "[" << my_ri->first << "] = " << my_ri->second << "  |  ";
    }
    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (std_ri = ++vec.rbegin(); std_ri != --vec.rend(); std_ri++) {
        std::cout << "[" << std_ri->first << "] = " << std_ri->second << "  |  ";
    }
    std::cout << "\n";

    std::map<int, int>::const_reverse_iterator const_std_ri;
    ft::map<int, int>::const_reverse_iterator  const_my_ri;

    std::cout << "\nConst Other: ";
    std::cout << "\n\033[34mMY: \033[0m\n";
    for (const_my_ri = my_vec.rbegin(); const_my_ri != my_vec.rend(); const_my_ri++) {
        std::cout << "[" << const_my_ri->first << "] = " << const_my_ri->second << "  |  ";
    }
    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (const_std_ri = vec.rbegin(); const_std_ri != vec.rend(); const_std_ri++) {
        std::cout << "[" << const_std_ri->first << "] = " << const_std_ri->second << "  |  ";
    }
    std::cout << "\n";

    std::cout << "\n\033[34mMY: \033[0m\n";
    for (const_my_ri = ++my_vec.rbegin(); const_my_ri != --my_vec.rend(); const_my_ri++) {
        std::cout << "[" << const_my_ri->first << "] = " << const_my_ri->second << "  |  ";
    }
    std::cout << "\033[34m\nSTD: \033[0m\n";
    for (const_std_ri = ++vec.rbegin(); const_std_ri != --vec.rend(); const_std_ri++) {
        std::cout << "[" << const_std_ri->first << "] = " << const_std_ri->second << "  |  ";
    }
    std::cout << "\n";

}

int main()
{
    at_test();
    operator_squarebrek_test();
    operator_equals_test();
    begin_end_test();
    rbegin_rend_test();
    empty_test();
    size_test();
    clear_test();
    insert_test();
    erase_test();
    swap_test();
    count_test();
    find_test(); //?????????????????????????????????????
    // equal_range_test(); //?????????????????????????????????????
    lower_bound_test();
    upper_bound_test();
    key_comp_test();
    iter_test();
}