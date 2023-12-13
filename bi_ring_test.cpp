#include "bi_ring.h"
#include "bi_ring_test.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

void fill_the_initial_ring(bi_ring<int, string> &ring)
{
    ring.push_back(1, "one");
    ring.push_back(2, "two");
    ring.push_back(3, "three");
    ring.push_back(4, "four");
    ring.push_back(5, "five");
    cout << "===== Initial ring =====\n ";
    ring.print();
}

bool test_copy_constructor(bi_ring<int, string> ring)
{
    bi_ring<int, string> ring_copy(ring);

    cout << "===== Copy constructor test =====\n ";
    ring_copy.print();

    if (ring_copy.getSize() != ring.getSize())
    {
        cout << "Size test in copy constructor failed\n";
        return false;
    }
    return true;
}
bool test_assignment_operator(bi_ring<int, string> ring)
{
    bi_ring<int, string> ring_copy = ring;

    cout << "===== Assignment operator test =====\n ";
    ring_copy.print();

    if (ring_copy.getSize() != ring.getSize())
    {
        cout << "Size test in assignment operator failed\n";
        return false;
    }
    return true;
}

bool test_getInfo(bi_ring<int, string> ring) // tests getInfo() method
{
    cout << "===== getInfo test =====\n ";

    bi_ring<int, string>::iterator it = ring.begin();
    string info;

    ring.getInfo(it, info);
    if (info != "One")
    {
        cout << "Test 1 in getInfo failed\n";
        return false;
    }

    ring.getInfo(it += 2, info);
    if (info != "Three")
    {
        cout << "Test 2 in getInfo failed\n";
        return false;
    }

    ring.getInfo(--it, info);
    if (info != "Two")
    {
        cout << "Test 3 in getInfo failed\n";
        return false;
    }

    ring.getInfo(it++, info);
    if (info != "Two")
    {
        cout << "Test 4 in getInfo failed\n";
        return false;
    }

    ring.getInfo(it -= 18, info);
    if (info != "Five")
    {
        cout << "Test 5 in getInfo failed\n";
        return false;
    }

    return true;
}
bool test_search(bi_ring<int, string> ring)
{
    cout << "===== search test =====\n ";

    bi_ring<int, string>::iterator it = ring.begin();

    if (ring.search(1, 1) != it)
    {
        cout << "Test 1 in search failed\n";
        return false;
    }

    if (ring.search(2, 1) != ++it)
    {
        cout << "Test 2 in search failed\n";
        return false;
    }

    it = ring.search(5, 1);
    if (it == bi_ring<int, string>::iterator())
    {
        cout << "Test 3 in search failed\n";
        return false;
    }
    if (it->key != 5)
    {
        cout << "Test 3 in search failed\n";
        return false;
    }

    // tests searching 4th occurence of 3 which occurs only once, so it should return iterator initialized with nullptr
    it = ring.search(3, 4);
    if (it != bi_ring<int, string>::iterator())
    {
        cout << "Test 4 in search failed\n";
        return false;
    }

    it = ring.search(8, 1); // tests searching for non-existing key
    if (it != bi_ring<int, string>::iterator())
    {
        cout << "Test 5 in search failed\n";
        return false;
    }

    return true;
}

bool test_getSize(bi_ring<int, string> ring)
{
    cout << "===== getSize test =====\n ";

    if (ring.getSize() != 5)
    {
        cout << "Test 1 in getSize failed\n";
        return false;
    }

    ring.pop_back();
    if (ring.getSize() != 4)
    {
        cout << "Test 2 in getSize failed\n";
        return false;
    }

    ring.pop_front();
    if (ring.getSize() != 3)
    {
        cout << "Test 3 in getSize failed\n";
        return false;
    }

    ring.erase(ring.begin() += 1);
    if (ring.getSize() != 2)
    {
        cout << "Test 4 in getSize failed\n";
        return false;
    }

    ring.clear();
    if (ring.getSize() != 0)
    {
        cout << "Test 5 in getSize failed\n";
        return false;
    }

    return true;
}
bool test_isEmptyAndClear(bi_ring<int, string> ring)
{
    cout << "===== isEmpty and clear test =====\n ";

    if (ring.isEmpty() != false)
    {
        cout << "Test 1 in isEmpty failed\n";
        return false;
    }

    ring.clear();
    if (ring.isEmpty() != true)
    {
        cout << "Test 2 in isEmpty failed\n";
        return false;
    }

    ring.push_back(1, "one");
    if (ring.isEmpty() != false)
    {
        cout << "Test 3 in isEmpty failed\n";
        return false;
    }

    ring.clear();
    if (ring.isEmpty() != true)
    {
        cout << "Test 4 in isEmpty failed\n";
        return false;
    }

    return true;
}

bool test_push_front(bi_ring<int, string> ring)
{
    cout << "===== push_front test =====\n ";
    ring.push_front(6, "six");
    ring.push_front(7, "seven");
    ring.push_front(2, "dwa");
    ring.push_front(7, "siedem");

        ring.print();

    if (ring.getSize() != 9)
    {
        cout << "Test 1 in push_front failed\n";
        return false;
    }

    bi_ring<int, string>::iterator it = ring.begin();

    if (it->key != 7)
    {
        cout << "Test 2 in push_front failed\n";
        return false;
    }

    if ((it -= 10)->key != 5)
    {
        cout << "Test 3 in push_front failed\n";
        return false;
    }

    bi_ring<int, string>::iterator it2 = ring.begin();

    if (it2->key != 7)
    {
        cout << "Test 4 in push_front failed\n";
        return false;
    }

    if ((it2 -= 1) != it)
    {
        cout << "Test 5 in push_front failed\n";
        return false;
    }

    return true;
}
bool test_push_back(bi_ring<int, string> ring)
{
    cout << "===== push_back test =====\n ";
    ring.push_back(18, "eighteen");
    ring.push_back(19, "nineteen");
    ring.push_back(14, "czternaście");
    ring.push_back(19, "dziewiętnaście");
    ring.push_back(19, "dziewiętnaście");

    ring.print();

    if (ring.getSize() != 10)
    {
        cout << "Test 1 in push_back failed\n";
        return false;
    }

    bi_ring<int, string>::iterator it = ring.begin();

    if (it->key != 1)
    {
        cout << "Test 2 in push_back failed\n";
        return false;
    }

    if ((it += 9)->key != 19)
    {
        cout << "Test 3 in push_back failed\n";
        return false;
    }

    bi_ring<int, string>::iterator it2 = ring.begin() + 9;

    if (it2->key != 19)
    {
        cout << "Test 4 in push_back failed\n";
        return false;
    }

    if (it2 != it)
    {
        cout << "Test 5 in push_back failed\n";
        return false;
    }

    return true;
}
bool test_pop_front(bi_ring<int, string> ring)
{
    cout << "===== pop_front test =====\n ";
    ring.pop_front();

    if (ring.getSize() != 4)
    {
        cout << "Test 1 in pop_front failed\n";
        return false;
    }

    if (ring.search(1, 1) != bi_ring<int, string>::iterator())
    {
        cout << "Test 2 in pop_front failed\n";
        return false;
    }

    ring.pop_front();
    ring.pop_front();

    if (ring.getSize() != 2)
    {
        cout << "Test 3 in pop_front failed\n";
        return false;
    }

    string info;
    ring.getInfo(ring.begin() + 3, info);
    if (info != "five")
    {
        cout << "Test 4 in pop_front failed\n";
        return false;
    }

    return true;
}
bool test_pop_back(bi_ring<int, string> ring)
{
    cout << "===== pop_back test =====\n ";
    ring.pop_back();

    if (ring.getSize() != 4)
    {
        cout << "Test 1 in pop_back failed\n";
        return false;
    }

    if (ring.search(5, 1) != bi_ring<int, string>::iterator())
    {
        cout << "Test 2 in pop_back failed\n";
        return false;
    }

    ring.pop_back();

    if (ring.getSize() != 3)
    {
        cout << "Test 3 in pop_back failed\n";
        return false;
    }

    string info;
    ring.getInfo(ring.begin() + 2, info);

    if (info != "three")
    {
        cout << "Test 4 in pop_back failed\n";
        return false;
    }

    return true;
}
bool test_insert(bi_ring<int, string> ring)
{
    cout << "===== insert test =====\n ";
    bi_ring<int, string>::iterator it;
    it = ring.insert(it, 1, "jeden");
    it = ring.insert(it - 1, 2, "dwa");
    it = ring.insert(it + 2, 3, "three");

    ring.print(); // 1 one 2 dwa 1 jeden 2 two 3 three 3 three 4 four 5 five

    if (ring.getSize() != 8)
    {
        cout << "Test 1 in insert failed\n";
        return false;
    }

    string info;
    ring.getInfo(ring.begin() + 2, info);
    if (info != "jeden")
    {
        cout << "Test 2 in insert failed\n";
        return false;
    }

    if (ring.search(2, 3) != bi_ring<int, string>::iterator())
    {
        cout << "Test 3 in insert failed\n";
        return false;
    }

    return true;
}
bool test_erase(bi_ring<int, string> ring)
{
    cout << "===== erase test =====\n ";
    bi_ring<int, string>::iterator it;
    it = ring.erase(ring.begin() + 2);
    it = ring.erase(it + 1);

    ring.print(); // 1 one 2 two 4 four

    if (ring.getSize() != 3)
    {
        cout << "Test 1 in erase failed\n";
        return false;
    }

    string info;
    ring.getInfo(ring.begin() + 1, info);
    if (info != "two")
    {
        cout << "Test 2 in erase failed\n";
        return false;
    }

    if (ring.search(4, 1) != ring.begin()+2)
    {
        cout << "Test 3 in erase failed\n";
        return false;
    }
    
    return true;
}

void test_ostream_operator(bi_ring<int, string> ring)
{
    cout << "===== ostream operator test =====\n ";
    cout << ring;
}

int main()
{

    bi_ring<int, string> ring;

    fill_the_initial_ring(ring);

    assert(test_copy_constructor(ring));
    assert(test_assignment_operator(ring));
    
    assert(test_getInfo(ring));
    assert(test_search(ring));

    assert(test_getSize(ring));
    assert(test_isEmptyAndClear(ring));

    assert(test_push_front(ring));
    assert(test_push_back(ring));
    assert(test_pop_front(ring));
    assert(test_pop_back(ring));
    assert(test_insert(ring));
    assert(test_erase(ring));

    test_ostream_operator(ring);
   
    cout << "\n\nAll tests passed\n";
    return 0;
}