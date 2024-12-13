#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
// #include <sstream>
#include <iostream>
#include <string>
#include "../heaptree/heaptree.hpp"
// #include <heaptree/heaptree.hpp>

// TESTS:
TEST_CASE("Tests for HeapTree<int>")
{
    HeapTree<int> test_1;
    test_1.Insert(1, 70);
    test_1.Insert(2, 100);
    test_1.Insert(7, 20);
    test_1.Insert(5, 300);
    test_1.Insert(3, 300);
    test_1.Print();

    test_1.Remove(1);
    test_1.Print();

    test_1.Remove(3);
    test_1.Print();

    CHECK_EQ(test_1.Search(5), 300);
    std::cout << test_1.Search(5) << std::endl;
    CHECK_EQ(test_1.Search(2), 100);
    std::cout << test_1.Search(2) << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    CHECK_THROWS(test_1.Insert(2, 9943));
}

TEST_CASE("Tests for HeapTree<std::string>")
{
    HeapTree<std::string> test_2;
    test_2.Insert(3, "tatatta");
    test_2.Insert(9, "rrrrrr r");
    test_2.Insert(6, "ssss ssss");
    test_2.Insert(8, "trt");
    test_2.Insert(20, "");
    test_2.Print();

    test_2.Remove(8);
    test_2.Print();

    test_2.Remove(9);
    test_2.Print();

    CHECK_EQ(test_2.Search(3), "tatatta");
    std::cout << test_2.Search(3) << std::endl;
    CHECK_EQ(test_2.Search(6), "ssss ssss");
    std::cout << test_2.Search(6) << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    CHECK_THROWS(test_2.Insert(3, "eueueuu"));

    HeapTree<std::string> test_3;
    CHECK_THROWS(test_3.Search(2));
}

void memory_check()
{
    HeapTree<std::string> test;

    for (std::size_t i = 0; i < 100; i += 1)
    {
        test.Insert(i, "tatatta");
    }
}

TEST_CASE("HeapTree<std::string> destructor and memory check")
{
    for (std::size_t i = 0; i < 50000; i += 1)
    {
        memory_check();
    }
}