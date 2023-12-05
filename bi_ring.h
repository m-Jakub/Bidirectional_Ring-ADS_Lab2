

template <typename Key, typename Info>
class bi_ring // implemented as doubly linked list
{
private:
    struct Node
    {
        Key key;
        Info info;
        Node *next;
        Node *previous;
    };
    Node *start;
    

public:
    class iterator
    { /* … */
    };
    class const_iterator
    { /* … */
    };
    bi_ring();
    bi_ring(const bi_ring &src);
    ~bi_ring();
    bi_ring &operator=(const bi_ring &src);
    iterator push_front(const Key &key, const Info &info);
    iterator pop_front();
    iterator insert(iterator position, ...);
    iterator erase(iterator position);
    // what else can be useful in such a collection?
    // use examples of additional functions to guide you in the interface design
};