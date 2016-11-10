#pragma once

#include <iostream>
#include <cassert>
#include <vector>

template<class V, class E>
class LinkGraph {
protected:
    vector<V> m_vertex;
    vector<vector<E>> m_edge;

public:
    LinkGraph();
    ~LinkGraph();

    void AddVertex(V v);
    void AddEdge(V v1, V v2);
};