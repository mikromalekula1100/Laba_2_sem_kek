#include "node.h"

Node::Node(int value)
{
    this->value = value;
    next = nullptr;
}

void Node::print()
{
    cout<<value<<endl;
    cout<<next<<endl;
}

Node* Node::get_next()
{
    return next;
}

int Node::get_value()
{
    return value;
}

void Node::change_next(Node* i)
{
    next = i;
}
