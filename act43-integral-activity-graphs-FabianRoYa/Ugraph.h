#ifndef UGRAPH_H
#define UGRAPH_H

#include <vector>
#include <set>
#include <queue>
#include <map>   

template <class graph_t>
class UGraph{
public:
    UGraph() = default;
    ~UGraph() = default;

    std::map<graph_t, std::set<graph_t>> get_adjacency_list() const;
    std::map<graph_t, bool> get_visited() const;
    std::map<graph_t, graph_t> get_parent() const;
    std::map<graph_t, int> get_distance() const;
    std::map<graph_t, int> get_mnp() const;

    template <class ostream_t>
    friend std::ostream &operator<<(std::ostream &os,
                                    const UGraph<ostream_t> &graph);

    void add_edge(const graph_t &, const graph_t &);
    void remove_edge(const graph_t &, const graph_t &);
    void add_vertex(const graph_t &);
    void remove_vertex(const graph_t &);
    void reset();

    void bfs(const graph_t &);

private:
    std::map<graph_t, std::vector<graph_t>> adjacent_list;
    std::map<graph_t, bool> visited;
    std::map<graph_t, graph_t> parent;
    std::map<graph_t, int> distance;
    std::map<graph_t, int> mnp;
};

#endif 