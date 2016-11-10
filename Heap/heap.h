#pragma once

#include <iostream>
#include <cassert>
#include <functional>

template<class Key>
class MinHeap {
private:
    std::function<bool(const Key&, const Key&)> _leq;

public:
    // initial the heap with the give function as <=
    MinHeap(std::function<bool(const Key&, const Key&)> leq):_leq(leq){}

    // insert a new element to the heap
    virtual void Insert(const Key&) = 0;

    // get the top of the heap
    virtual void Key Top() = 0;

    // get the top and delete it from the heap
    virtual void Key &&ExtractTop() = 0;

    // delete the heap of a certain element
    virtual void DecreaseKey(x, k) = 0;

public:
    // Merge two heaps to creat a new one
    static virtual MinHeap<Key> Union(MinHeap<Key> &h1, MinHeap<Key> &h2) = 0;
};

template<class Key>
class FibHeap {

};
