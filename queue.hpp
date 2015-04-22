#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

template <class Tip>
class Queue
{
    struct Node
    {
        Tip val;
        Node *next;
    }start;
};

#endif // QUEUE_HPP_INCLUDED
