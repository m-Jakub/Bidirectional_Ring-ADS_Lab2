

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

    class iterator_base // Base class for iterator and const_iterator
    {
    protected:
        Node *owner;
        explicit iterator_base(Node *start) : owner(start) {} // Explicit keyword prevents implicit conversion from Node* to iterator_base, like e.g. iterator_base it = start; - will not compile

    public:
        iterator_base() : owner(nullptr) {}
        iterator_base(const iterator_base &src) : owner(src.owner) {}
        ~iterator_base() = default;

        bool operator==(const iterator_base &other) const { return owner == other.owner; }
        bool operator!=(const iterator_base &other) const { return owner != other.owner; }

        iterator_base &operator++()
        {
            owner = owner->next;
            return *this;
        }
        iterator_base operator++(int)
        {
            iterator_base temp = *this;
            owner = owner->next;
            return temp;
        }
        iterator_base &operator--()
        {
            owner = owner->previous;
            return *this;
        }
        iterator_base operator--(int)
        {
            iterator_base temp = *this;
            owner = owner->previous;
            return temp;
        }
        iterator_base operator+(int n) const
        {
            iterator_base temp = *this;
            for (int i = 0; i < n; i++)
            {
                temp.owner = temp.owner->next;
            }
            return temp;
        }
        iterator_base operator-(int n) const
        {
            iterator_base temp = *this;
            for (int i = 0; i < n; i++)
            {
                temp.owner = temp.owner->previous;
            }
            return temp;
        }
        iterator_base &operator+=(int n)
        {
            for (int i = 0; i < n; i++)
            {
                owner = owner->next;
            }
            return *this;
        }
        iterator_base &operator-=(int n)
        {
            for (int i = 0; i < n; i++)
            {
                owner = owner->previous;
            }
            return *this;
        }
    };

public:
    class iterator : public iterator_base
    {
    private:
        iterator(Node *start) : iterator_base(start) {}

        friend class bi_ring<Key, Info>;

    public:
        iterator() : iterator_base() {}
        iterator(const iterator &src) : iterator_base(src.owner) {}
        iterator(const const_iterator &src) : iterator_base(src.owner) {} // you can construct iterator from const_iterator and vice versa
        ~iterator() = default;

        iterator &operator=(const iterator &src)
        {
            owner = src.owner;
            return *this;
        }
        iterator &operator=(const const_iterator &src)
        {
            owner = src.owner;
            return *this;
        }

        Node &operator*() const { return *owner; }
        Node *operator->() const { return owner; }
    };

    class const_iterator
    {
    private:
        const Node *owner;
        explicit const_iterator(const Node *start) : owner(start) {}

        friend class bi_ring<Key, Info>;

    public:
        const_iterator() : owner(nullptr) {}
        const_iterator(const const_iterator &src) : owner(src.owner) {}
        const_iterator(const iterator &src) : owner(src.owner) {}
        ~const_iterator() = default;

        const_iterator &operator=(const const_iterator &src)
        {
            owner = src.owner;
            return *this;
        }
        const_iterator &operator=(const iterator &src)
        {
            owner = src.owner;
            return *this;
        }

        const Node &operator*() const { return *owner; }
        const Node *operator->() const { return owner; }
    };

    bi_ring()
    {
        start = nullptr;
        size = 0;
    };
    bi_ring(const bi_ring &src)
    {
        if (src.start == nullptr)
        {
            start = nullptr;
            size = 0;
        }
        else
        {
            Node *temp = src.start;
            while (temp != src.start)
            {
                push_back(temp->key, temp->info);
                temp = temp->next;
            }
            size = src.size;
        }
    }
    ~bi_ring() { clear(); }

    bi_ring &operator=(const bi_ring &src)
    {
        if (this == &src)
            return *this;

        else
        {
            clear();
            if (src.start == nullptr)
            {
                start = nullptr;
                size = 0;
            }
            else
            {
                Node *temp = src.start;
                while (temp != src.start)
                {
                    push_back(temp->key, temp->info);
                    temp = temp->next;
                }
                size = src.size;
            }
            return *this;
        }
    }

    bool getInfo(iterator position, Info &info) const
    {
        if (position == iterator())
            return false;

        else
        {
            info = position->info;
            return true;
        }
    }
    iterator search(const Key &key, int which)
    {
        if (start == nullptr)
            return iterator();

        else
        {
            Node *temp = start;
            for (int i = 0; i < which; i++)
            {
                if (temp->key == key)
                    return iterator(temp);

                else
                    temp = temp->next;
            }
            return iterator();
        }
    }

    int getSize() const { return size; }
    bool isEmpty() { return size == 0; }

    iterator push_front(const Key &key, const Info &info)
    {
        if (start == nullptr)
        {
            start = new Node;
            start->key = key;
            start->info = info;
            start->next = start;
            start->previous = start;
        }
        else
        {
            Node *newNode = new Node;
            newNode->key = key;
            newNode->info = info;
            newNode->next = start;
            newNode->previous = start->previous;
            start->previous->next = newNode;
            start->previous = newNode;
            start = newNode;
        }
        size++;
        return iterator(start);
    }
    iterator push_back(const Key &key, const Info &info)
    {
        if (start == nullptr)
        {
            start = new Node;
            start->key = key;
            start->info = info;
            start->next = start;
            start->previous = start;
        }
        else
        {
            Node *newNode = new Node;
            newNode->key = key;
            newNode->info = info;
            newNode->next = start;
            newNode->previous = start->previous;
            start->previous->next = newNode;
            start->previous = newNode;
        }
        size++;
        return iterator(start->previous);
    }
    iterator pop_front()
    {
        if (start == nullptr)
        {
            return iterator();
        }
        else if (start->next == start)
        {
            delete start;
            size--;
            start = nullptr;
            return iterator();
        }
        else
        {
            Node *temp = start;
            start->previous->next = start->next;
            start->next->previous = start->previous;
            start = start->next;
            delete temp;
            size--;
            return iterator(start);
        }
    }
    iterator pop_back()
    {
        if (start == nullptr)
        {
            return iterator();
        }
        else if (start->next == start)
        {
            delete start;
            size--;
            start = nullptr;
            return iterator();
        }
        else
        {
            Node *temp = start->previous;
            start->previous->previous->next = start;
            start->previous = start->previous->previous;
            delete temp;
            size--;
            return iterator(start->previous);
        }
    }
    iterator insert(iterator position, const Key &key, const Info &info) // inserts after the given position
    {
        if (position == iterator())
            return iterator();

        else
        {
            Node *newNode = new Node;
            newNode->key = key;
            newNode->info = info;
            newNode->next = position->next;
            newNode->previous = position->next->previous;
            position->next->previous = newNode;
            position->next = newNode;
            size++;
            return iterator(newNode);
        }
    }
    iterator erase(iterator position)
    {
        if (position == iterator())
            return iterator();

        else
        {
            Node *temp = position->next;
            position->previous->next = position->next;
            position->next->previous = position->previous;
            delete position;
            size--;
            return iterator(temp);
        }
    }
    void clear()
    {
        if (start == nullptr)
            return;

        else
        {
            Node *temp = start;
            while (temp->next != start)
            {
                temp = temp->next;
                delete temp->previous;
            }
            delete temp;
            start = nullptr;
            size = 0;
        }
    }

    void print()
    {
        if (start == nullptr)
            return;

        else
        {
            Node *temp = start;
            while (temp->next != start)
            {
                cout << temp->key << " " << temp->info << endl;
                temp = temp->next;
            }
            cout << temp->key << " " << temp->info << endl;
        }
    }
    friend ostream &operator<<(ostream &os, const Ring<Key, Info> &ring)
    {
        if (ring.start == nullptr)
            return os;

        else
        {
            Node *temp = ring.start;
            while (temp->next != ring.start)
            {
                os << temp->key << " " << temp->info << endl;
                temp = temp->next;
            }
            os << temp->key << " " << temp->info << endl;
            return os;
        }
    }

    iterator begin() const { return iterator(start); }
};

