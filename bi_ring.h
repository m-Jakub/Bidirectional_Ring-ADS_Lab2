

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
    Node *start; // front

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
    iterator insertAtPos(iterator position, const Key &key, const Info &info);
    iterator eraseAtPos(iterator position);
    iterator searchKey(const Key &key);
    // bool addAtPos(const Key &key, const Info &info, int which);
    // bool removeByKey(const Key &key, int which);
    // bool getInfo(const Key &key, const Info &info, int which);
    Iterator search(const Key &key, const Info &info, int which);
    int getSize();
    // what else can be useful in such a collection?
    // use examples of additional functions to guide you in the interface design
};