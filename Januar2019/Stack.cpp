#include "Stack.h"

Stack::Stack(int stacksize)
    :   stacksize_(stacksize > 0 ? stacksize : 10)
{
    dataPtr_ = new int [stacksize];
    stacktop_ = 0;
}

Stack::~Stack()
{
    delete dataPtr_;
}

int Stack::pop()
{
    if (stacktop_ > 0) {
        stacktop_--;
        return dataPtr_[stacktop_];
    }
    else {
        throw StackPopException();
        return 0;
    }
}

Stack& Stack::operator+=(int element)
{
    if (stacktop_ < stacksize_) {
        dataPtr_[stacktop_] = element;
        stacktop_++;
    }
    return *this;
}

bool Stack::isEmpty() const
{
    return (stacktop_ == 0 ? true : false);
}

bool Stack::isFull() const
{
    return (stacktop_ == stacksize_ ? true : false);
}
