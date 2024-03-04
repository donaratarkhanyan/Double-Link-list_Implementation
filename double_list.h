#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

class d_list
{
public:
    d_list();
    d_list(const d_list& other);
    d_list(d_list&& other) noexcept;
    const d_list& operator=(const d_list& other);
    d_list& operator=(d_list&& other) noexcept;
    ~d_list();

public:
    void clear();
    bool empty();
    void push_back(int);
    void push_front(int);
    void display() const;
    void pop_back();
    void pop_front();
    size_t size();
    void insert(size_t, int);
    int get(size_t);
    void remove(int);
    int front();
    int back();
    void splice(size_t index, d_list& other);


    //friend bool operator== (const d_list&, const d_list&);
    //d_list& operator+ (d_list&, d_list&);
    //int operator[] (size_t ind);

private:
    struct Node {
        int data;
        Node* next;
        Node* previous;
        Node(int value);
    };

    Node* head;
    Node* tail;
};


#endif // DOUBLE_LIST_H
