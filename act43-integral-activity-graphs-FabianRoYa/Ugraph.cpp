#include "UGraph.h"
#include <iostream>   
#include <ostream>
   
template <class graph_t>
std::map<graph_t, std::set<graph_t>> UGraph<graph_t>::get_adjacency_list() const{
    std::map<graph_t, std::set<graph_t>> adjacency_list;
    for (auto &adjacent : adjacent_list){
        std::set<graph_t> set(adjacent.second.begin(), adjacent.second.end());
        adjacency_list.insert({adjacent.first, set});
    }
    return adjacency_list;
}

template <class graph_t>
std::map<graph_t, bool> UGraph<graph_t>::get_visited() const{
    return visited;
}

template <class graph_t>
std::map<graph_t, graph_t> UGraph<graph_t>::get_parent() const{
    return parent;
}

template <class graph_t>
std::map<graph_t, int> UGraph<graph_t>::get_distance() const{
    return distance;
}

template <class graph_t>
std::map<graph_t, int> UGraph<graph_t>::get_mnp() const
{
    return mnp;
}

template <class ostream_t>
std::ostream &operator<<(std::ostream &os, const UGraph<ostream_t> &graph){
    for (auto &adjacent : graph.adjacent_list){
        os << adjacent.first << " -> ";

        for (auto &vertex : adjacent.second)
            os << vertex << " ";

        os << std::endl;
    }
    return os;
}

template <class graph_t>
void UGraph<graph_t>::add_edge(const graph_t &vertex1,
                               const graph_t &vertex2){
    adjacent_list[vertex1].push_back(vertex2);
    adjacent_list[vertex2].push_back(vertex1);
}

template <class graph_t>
void UGraph<graph_t>::remove_edge(const graph_t &vertex1,
                                  const graph_t &vertex2){
    adjacent_list[vertex1].erase(vertex2);
    adjacent_list[vertex2].erase(vertex1);
}

template <class graph_t>
void UGraph<graph_t>::add_vertex(const graph_t &vertex){
    adjacent_list[vertex];
}

template <class graph_t>
void UGraph<graph_t>::remove_vertex(const graph_t &vertex){
    for (auto &adjacent : adjacent_list)
        adjacent.second.erase(vertex);

    adjacent_list.erase(vertex);
}

template <class graph_t>
void UGraph<graph_t>::reset(){
    this->distance.clear();
    this->parent.clear();
    this->visited.clear();
}

template <class graph_t>
void UGraph<graph_t>::bfs(const graph_t &start){
    std::queue<graph_t> queue;

    queue.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!queue.empty()){
        graph_t vertex = queue.front();
        queue.pop();

        for (auto &adjacent : adjacent_list[vertex]){
            if (!visited[adjacent]){
                queue.push(adjacent);
                visited[adjacent] = true;
                distance[adjacent] = distance[vertex] + 1;
                parent[adjacent] = vertex;
            } 
        }     
    }        
}