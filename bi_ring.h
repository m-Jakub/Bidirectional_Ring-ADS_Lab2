

template <typename Key, typename Info>
class Bi_ring // implemented as doubly linked list
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
    int size;

public:
    class Iterator
    {
    private:
        Node *owner;
        Iterator(Node *start);

        friend class Bi_ring<Key, Info>;

    public:

        Iterator();
        Iterator(const Iterator &src);
        ~Iterator();

        Iterator &operator=(const Iterator &src);

        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;

        Iterator &operator++();
        Iterator operator++(int);
        Iterator &operator--();
        Iterator operator--(int);
        Iterator operator+(int n) const;
        Iterator operator-(int n) const;
        Iterator &operator+=(int n);
        Iterator &operator-=(int n);

        Key &operator*() const;
        Key *operator->() const;

        bool empty() const { return owner == nullptr; }



    };
    class Const_iterator
    { /* … */
    };

    Bi_ring();
    Bi_ring(const Bi_ring &src);
    ~Bi_ring();

    Bi_ring &operator=(const Bi_ring &src);

    bool getInfo(Iterator position, Info &info);
    Iterator search(const Key &key, int which);

    int getSize() { return size; }
    bool empty() { return size == 0; }

    Iterator push_front(const Key &key, const Info &info);
    Iterator pop_front();
    Iterator insert(Iterator position, const Key &key, const Info &info); // inserts after the given position
    Iterator erase(Iterator position);
    void clear();

    void print();
    friend ostream &operator<<(ostream &os, const Ring<Key, Info> &ringToPrint);

    Iterator begin() { return Iterator(start); }
};