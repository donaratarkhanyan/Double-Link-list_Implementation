#include <iostream>
#include "double_list.h"

d_list::Node::Node(int value)
    : next {nullptr}
    , previous {nullptr}
    , data {value}
{}

d_list::d_list() 
    : head {nullptr}
    , tail {nullptr}
{}

d_list::d_list(const d_list& other)
    :head {nullptr}
    ,tail {nullptr}
{   
    Node* otherNode = other.head;
    Node* otherNext = nullptr;
    while(otherNode != nullptr) {
        Node* newNode = new Node(otherNode -> data);
        if(otherNext == nullptr){
            head = newNode;
        }
        else{
            newNode -> previous = otherNext;
            otherNext -> next = newNode;
        }
        otherNext = newNode;
        otherNode = otherNode -> next;
    }
    tail = otherNext;
}

d_list::d_list(d_list&& other) noexcept 
    : head {other.head}
    , tail {other.tail}
{
    other.head = nullptr;
    other.tail = nullptr;
}

const d_list& d_list::operator= (const d_list& other) 
{
    if(this != &other) {
        clear();
        Node* otherNode = other.head;
        Node* otherNext = nullptr;
        while(otherNode != nullptr) {
            Node* newNode = new Node(otherNode -> data);
            if(otherNext == nullptr){
                head = newNode;
            }
            else{
                newNode -> previous = otherNext;
                otherNext -> next = newNode;
            }
            otherNext = newNode;
            otherNode = otherNode -> next;
        }
        tail = otherNext;
    }
    return *this;
}

d_list& d_list::operator= (d_list&& other) noexcept
{   
    if(this != &other) {
        clear();
        
        head = other.head;
        tail = other.tail;
        
        other.head = nullptr;
        other.tail = nullptr;

    }
    return *this;
}

d_list::~d_list() 
{   
    clear();
}

void d_list::clear()
{
    Node* current = head;
    Node* nextNode = nullptr;
    while(current) {
        nextNode = current -> next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

bool d_list::empty()
{
    if(head){
        return  false;
    }
    return true;
}

void d_list::push_back(int val) 
{
    Node* tmp = new Node (val);
    if(!head){
        head = tmp;
        tail = tmp;
    } 
    else {
        tail -> next = tmp;
        tmp -> previous = tail;
        tail = tmp;
    }
}

void d_list::push_front(int val)
{
    Node* tmp = new Node (val);
    if(!head){
        head = tmp;
        tail = tmp;
    }
    else {
        tmp -> next = head;
        head -> previous = tmp;
        head = tmp;
    }
}

void d_list::display () const{
    if(!head){
        std::cout << "Empty list" << std::endl;
    }
    Node* current = head;
    while(current) {
        std::cout << current -> data << " ";
        current = current -> next;
    }
}

void d_list::pop_back(){
    if(!tail) {
        return;
    }
    if(tail){
        Node* tmp = tail -> previous;
        delete tail;
        tail = tmp;
        tail -> next = nullptr;
    }

}

void d_list::pop_front()
{
    if(!head) {
        return;
    }
    if(head){
        head = head -> next;
        delete head -> previous;
        head -> previous = nullptr;
    }
}

size_t d_list::size(){
    size_t count = 0;
    if(head == nullptr){
        return 0;
    }
    Node* current = head;
    while(current){
        ++count;
        current = current -> next;
    }
    return count;
}

void d_list::insert(size_t index, int val){
    size_t s = size();
    if(s < index){
        throw std::invalid_argument("Out of range");
    }

    Node* tmp = new Node (val);
    if(index == 0){
        tmp -> next = head;
        head -> previous = tmp;
        head = tmp;
        return;
    }

    Node* current = head;
    for(int i = 0; i < index - 1; ++i){
        current = current -> next;
    }
    tmp -> next = current -> next;
    current -> next = tmp;
    tmp -> previous = current;
    current = current -> next -> next;
    if (current != nullptr) {
        current -> previous = tmp;
    }
}

int d_list::get(size_t index) {
    size_t s = size();
    if(s < index){
        throw std::invalid_argument("Out of range");
    }
    Node* current = head;
    for(size_t i = 0; i < index; ++i) {
        current = current -> next;
    }
    return current -> data;
}

int d_list::front(){ 
    return head -> data;
}

int d_list::back(){
    return tail -> data;
}

void d_list::remove(int val){
    Node* current = head;
    while(current){
    if(current -> data == val){
        if(current == head){
            pop_front();
        }
        else if(current == tail){
            pop_back();
        }
        else{
            current -> previous -> next = current -> next;
            current -> next -> previous = current -> previous;
            delete current ;
        }
    }
    current = current -> next;
    }
}

void d_list::splice(size_t index, d_list& other) 
{
    size_t s = size();
    if (s + 1 < index) {
        std::cout << "Out of rang!!!" << std::endl;
        return;
    }
    if(index == 0){
        other.tail -> next = head;
        head -> previous = other.tail;
        head = other.head; 
    }else if (index == s){
        tail -> next = head;
        other.head -> previous = tail;
        tail = other.tail;
    }else {
        Node* current = head;
        for(size_t i = 0; i < index; ++i){
            current = current -> next;
        }
        current -> next -> previous = other.tail;
        other.tail -> next = current -> next;
        current -> next = other.head;
        other.head -> previous = current;
    }
}

    
    

    







