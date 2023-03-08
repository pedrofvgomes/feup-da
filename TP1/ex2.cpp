// By: Gonçalo Leão

#include "exercises.h"

#include "TestAux.h"

/* a)
 * A-B-E-F-C-G-D
 */

std::vector<int> IntroGraph::dfs(const int & source) const {
    std::vector<int> res;

    std::stack<int> s;
    s.push(source);
    while(!s.empty()){
       auto v = findVertex(s.top());
       s.pop();
       if(!v->isVisited()){
           res.push_back(v->getId());
           v->setVisited(true);
       }

       auto adj = v->getAdj();

       for(auto it = adj.rbegin(); it!= adj.rend(); it++){
           auto e = *it;
           if(!e->getDest()->isVisited())
               s.push(e->getDest()->getId());
       }
    }

    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, test_dfs) {
    IntroGraph graph;
    createNetwork(graph);
    std::vector<int> vs = graph.dfs(1);

    unsigned int ids[] = {1, 2, 5, 6, 3, 7, 4};
    EXPECT_EQ(vs.size(), 7);
    for (unsigned int i = 0; i < vs.size(); i++) {
        EXPECT_EQ(vs[i], ids[i]);
    }
}