#ifndef STACK_H
#define STACK_H

template<class T>
class Stack
{
    struct Node
    {
        T mValue;
        Node *mNext;
    };
    Node *mTop;
    int mSize;

public:
    Stack() { mTop = NULL; mSize = 0; }

    bool push(T value)
    {
        Node *mNewEntry = new Node;
        mNewEntry->mValue = value;
        mNewEntry->mNext = mTop;
        mTop = mNewEntry;
        mSize++;
        return true;
    }

    bool pop()
    {
        if (mTop)
        {
            Node *aux = mTop;
            mTop = mTop->mNext;
            delete aux;
            mSize--;
            return true;
        }

        return false;
    }

    T top()
    {
        if (mTop)
            return mTop->mValue;
    }

    int getSize() { return mSize; }

    bool isEmpty() { return !mSize; }
};

#endif // STACK_H
