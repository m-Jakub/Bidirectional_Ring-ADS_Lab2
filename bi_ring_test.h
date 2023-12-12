#include "bi_ring.h"
#include "bi_ring_test.cpp"
#include <iostream>


// fills the ring with some values to prepare it for further tests
// that's why this function receives a reference to the ring
void fill_the_initial_ring(&bi_ring<int, string> ring);

// other tests receive a copy of the ring
// iterators are tested by using them inside the tests
bool test_copy_constructor(bi_ring<int, string> ring);
bool test_assignment_operator(bi_ring<int, string> ring);

bool test_getInfo(bi_ring<int, string> ring);
bool test_search(bi_ring<int, string> ring);

bool test_getSize(bi_ring<int, string> ring);
bool test_isEmpty(bi_ring<int, string> ring);

bool test_push_front(bi_ring<int, string> ring);
bool test_push_back(bi_ring<int, string> ring);
bool test_pop_front(bi_ring<int, string> ring);
bool test_pop_back(bi_ring<int, string> ring);
bool test_insert(bi_ring<int, string> ring);
bool test_erase(bi_ring<int, string> ring);
bool test_clear(bi_ring<int, string> ring);

void test_ostream_operator(bi_ring<int, string> ring);
