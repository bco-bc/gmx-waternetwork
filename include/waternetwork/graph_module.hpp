/*
 *  Class for finding point inside the Alpha Shape Surface
 *  Pierre Leprovost, University of Oulu, Biocenter Oulu
 *  1/11/2015
 */

/*! \file
 * \brief
 * Declares FindElementInsideAlphaShape.
 *
 * \author Pierre Leprovost <leprovost.pierre@gmail.com>
 */

#ifndef GRAPHMODULE_HPP
#define GRAPHMODULE_HPP

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/graph_traits.hpp>

#include <boost/range/iterator_range.hpp>
/*
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/graph/subgraph.hpp>
#include <boost/graph/graph_utility.hpp> 
*/

#include <boost/graph/boykov_kolmogorov_max_flow.hpp>

#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graphml.hpp>

#include <fstream>
#include <iostream>

typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> Traits;

struct VertexProperties {
    int id = 0;
};

struct EdgeProperties {
    long weight;
    long capacity;
    long residual_capacity;
    Traits::edge_descriptor reverse;
};

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
			      boost::no_property,
			      boost::property<boost::edge_index_t, std::size_t> > Graph;

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
			      VertexProperties, EdgeProperties> graph_t;

// Descriptors
using vertex_descriptor = boost::graph_traits<Graph>::vertex_descriptor;
using edge_descriptor = boost::graph_traits<Graph>::edge_descriptor;

// Iterators
// using vertex_iterator =  boost::graph_traits<Graph>::vertex_iterator;
// using edge_iterator = boost::graph_traits<Graph>::edge_iterator;

class GraphModule
{
public:
    GraphModule();
    void set_nodes(int n);
    bool add_bidirectional_edge(int, int, const EdgeProperties&);
    
private:
    Graph g_;
};


#endif
