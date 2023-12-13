#ifndef BI_RING_TEST_H
#define BI_RING_TEST_H

#include "bi_ring.h"
#include <iostream>

using namespace std;

// fills the ring with some values to prepare it for further tests
// that's why this function receives a reference to the ring

void fill_the_initial_ring(bi_ring<int, string>&);

// other tests receive a copy of the ring
// iterators are tested by using them inside the tests
bool test_copy_constructor(bi_ring<int, string>);
bool test_assignment_operator(bi_ring<int, string>);

bool test_getInfo(bi_ring<int, string>);
bool test_search(bi_ring<int, string>);

bool test_getSize(bi_ring<int, string>);
bool test_isEmptyAndClear(bi_ring<int, string>);

bool test_push_front(bi_ring<int, string>);
bool test_push_back(bi_ring<int, string>);
bool test_pop_front(bi_ring<int, string>);
bool test_pop_back(bi_ring<int, string>);
bool test_insert(bi_ring<int, string>);
bool test_erase(bi_ring<int, string>);

void test_ostream_operator(bi_ring<int, string>);

bool test_unique(bi_ring<int, string>);
bool test_split(bi_ring<int, string>);

#endif