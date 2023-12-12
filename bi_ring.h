

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
    int size;

public:
    class iterator
    {
    private:
        Node *owner;
        iterator(Node *start);

        friend class bi_ring<Key, Info>;

    public:
        iterator();
        iterator(const iterator &src);
        ~iterator();

        iterator &operator=(const iterator &src);

        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;

        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        iterator operator+(int n) const;
        iterator operator-(int n) const;
        iterator &operator+=(int n);
        iterator &operator-=(int n);

        Node &operator*() const;
        Node *operator->() const;
    };
    class const_iterator
    {
    private:
        Node *owner;
        const_iterator(Node *start);

        friend class bi_ring<Key, Info>;

    public:
        const_iterator();
        const_iterator(const const_iterator &src);
        ~const_iterator();

        const_iterator &operator=(const const_iterator &src);

        bool operator==(const const_iterator &other) const;
        bool operator!=(const const_iterator &other) const;

        const_iterator &operator++();
        const_iterator operator++(int);
        const_iterator &operator--();
        const_iterator operator--(int);
        const_iterator operator+(int n) const;
        const_iterator operator-(int n) const;
        const_iterator &operator+=(int n);
        const_iterator &operator-=(int n);

        const Node &operator*() const;
        const Node *operator->() const;
    };

    bi_ring();
    bi_ring(const bi_ring &src);
    ~bi_ring();

    bi_ring &operator=(const bi_ring &src);

    bool getInfo(iterator position, Info &info);
    iterator search(const Key &key, int which);

    int size() const { return size; }
    bool empty() { return size == 0; }

    iterator push_front(const Key &key, const Info &info);
    iterator pop_front();
    iterator insert(iterator position, const Key &key, const Info &info); // inserts after the given position
    iterator erase(iterator position);
    void clear();

    void print();
    friend ostream &operator<<(ostream &os, const Ring<Key, Info> &ringToPrint);

    iterator begin() const { return iterator(start); }
};