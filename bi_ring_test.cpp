#include "bi_ring.h"
#include "bi_ring_test.h"
#include <iostream>

void fill_the_initial_ring(ring)
{
    push_back(1, "one");
    push_back(2, "two");
    push_back(3, "three");
    push_back(4, "four");
    push_back(5, "five");
    cout << "===== Initial ring =====\n ";
    ring.print();
}

bool test_copy_constructor(ring)
{
    bi_ring<int, string> ring_copy(ring);

    cout << "===== Copy constructor test =====\n ";
    ring_copy.print();

    if (ring_copy.getSize() != ring.getSize())
    {
        cout << "Size test in copy constructor failed\n";
        return false;
    }
    for (int i = 0; i < ring.getSize(); i++)
    {
        if (ring_copy[i] != ring[i])
        {
            cout << i << " Element test in copy constructor failed\n";
            return false;
        }
    }
    return true;
}
bool test_assignment_operator(ring)
{
    bi_ring<int, string> ring_copy = ring;

    cout << "===== Assignment operator test =====\n ";
    ring_copy.print();

    if (ring_copy.getSize() != ring.getSize())
    {
        cout << "Size test in assignment operator failed\n";
        return false;
    }
    for (int i = 0; i < ring.getSize(); i++)
    {
        if (ring_copy[i] != ring[i])
        {
            cout << i << " Element test in assignment operator failed\n";
            return false;
        }
    }
    return true;
}

bool test_getInfo(ring) // tests getInfo() method
{
    cout << "===== getInfo test =====\n ";

    Iterator<int, string> it = ring.begin();

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

    ring.getInfo(it -= 2, info);
    if (info != "One")
    {
        cout << "Test 5 in getInfo failed\n";
        return false;
    }

    return true;
}
bool test_search(ring)
{
    cout << "===== search test =====\n ";

    Iterator<int, string> it = ring.begin();

    if (ring.search(it, 1) != true)
    {
        cout << "Test 1 in search failed\n";
        return false;
    }

    if (ring.search(it += 2, 3) != true)
    {
        cout << "Test 2 in search failed\n";
        return false;
    }

    if (ring.search(--it, 2) != true)
    {
        cout << "Test 3 in search failed\n";
        return false;
    }

    if (ring.search(it++, 2) != true)
    {
        cout << "Test 4 in search failed\n";
        return false;
    }

    if (ring.search(it -= 2, 1) != true)
    {
        cout << "Test 5 in search failed\n";
        return false;
    }

    return true;


bool test_getSize(ring);
bool test_isEmpty(ring);

bool test_push_front(ring)
{
}
bool test_push_back(ring);
bool test_pop_front(ring);
bool test_pop_back(ring);
bool test_insert(ring);
bool test_erase(ring);
bool test_clear(ring);

bool test_ostream_operator();

int main()
{

    bi_ring<int, string> ring;

    return 0;
}