#include <iostream>
#include <cassert>
using namespace std;



template<typename T>
class Node
{
    public:
    T val;
    Node<T>* down = nullptr;

    Node(T x){
        val = x;
    }
    // Your code here

};

template<typename T>
class Stack
{
   public:
    Node<T>* top=nullptr;
    Stack (){
        top = nullptr;
    }
    Stack(T x){
        top = new Node(x);
    }

    bool isEmpty(){
            if(top==nullptr) return true;
            return false;
    }

       void push(T x){
            Node<T>* help = new Node(x);
            help->down = top;
            top = help;
       }

       T pop(){
        assert(top != nullptr);
            T a = top->val;
            Node<T>* help = top;
            top = top->down;
            delete(help);
            return a;
       }

       T peek(){
        assert(top != nullptr);
            return top->val;
       }
    // Your code here
};