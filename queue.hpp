#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

template <class Tip>
class Queue
{
    struct Node
    {
        Tip val;
        Node *pre;

        Node()
        {
            pre = NULL;
        }

        Node(Tip toInsert)
        {
            val = toInsert;
            pre = NULL;
        }
    };

    Node *beg, *end;

public:
    Queue()
    {
        beg = end = NULL;
    }

    Tip front()
    {
        if(beg != NULL)
            return beg->val;
    }

    bool empty()
    {
        return (beg==NULL);
    }

    void pop()
    {
        Node *p = beg;

        if(beg == NULL)
            return;

        if(beg == end)
            end = NULL;

        beg = beg->pre;

        delete p;
    }

    void push(Tip toInsert)
    {
        if(beg == NULL)
            beg = new Node(toInsert);
            else if(beg != NULL && end == NULL)
            {
                end = new Node(toInsert);
                beg->pre = end;
            }
                else
                {
                    end->pre = new Node(toInsert);
                    end = end->pre;
                }
    }
};

#endif // QUEUE_HPP_INCLUDED
