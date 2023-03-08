// By: Gonçalo Leão

#include "exercises.h"

bool IntroGraph::isDAG() const {
    int flag0 = 0;
    int counter = 0;

    for(auto &v : vertexSet) {
        v->setIndegree(v->getIncoming().size());
        if(v->getIncoming().empty()) flag0 = 1;
    }
    if(flag0==0) return false;

    while(counter!=vertexSet.size()){
        int testloop = 0;
        for(auto it = this->vertexSet.begin(); it!=this->vertexSet.end();it++) {
            auto v = *it;
            if (v->getIndegree() == 0 and !v->isVisited()) {
                counter++;
                v->setVisited(true);
                testloop = 1;
                for (auto &e: v->getAdj())
                    e->getDest()->setIndegree(e->getDest()->getIndegree() - 1);
            }
        }
        if(testloop==0) return false;
    }
    return true;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex5, test_isDAG) {
    IntroGraph myGraph;

    for(unsigned int i = 0; i < 6; i++) {
        myGraph.addVertex(i);
    }

    myGraph.addEdge(1, 2, 0);
    myGraph.addEdge(2, 5, 0);
    myGraph.addEdge(5, 4, 0);
    myGraph.addEdge(3, 1, 0);
    myGraph.addEdge(0, 4, 0);

    EXPECT_EQ(myGraph.isDAG(), true);

    myGraph.addEdge(4, 1, 0);

    EXPECT_EQ(myGraph.isDAG(), false);
}