#include <gtest/gtest.h>
#include "../src/my_graph.h"

// Тестовый случай для класса Graph
class GraphTest : public ::testing::Test {
protected:
    void SetUp() override {
        g = new Graph(6); 
        g->addEdge(0, 1);
        g->addEdge(0, 2);
        g->addEdge(1, 3);
        g->addEdge(1, 4);
        g->addEdge(2, 5);
    }

    void TearDown() override {
        delete g;
    }

    Graph* g;
};

TEST_F(GraphTest, ConstructorValid) {
    EXPECT_NO_FATAL_FAILURE(Graph(5)); 
}

TEST_F(GraphTest, ConstructorInvalid) {
    EXPECT_EXIT(Graph(-1), ::testing::ExitedWithCode(1), "Количество вершин должно быть положительным.");
}

TEST_F(GraphTest, AddEdgeValid) {
    g->addEdge(2, 3); 
    std::vector<int> distances = g->bfs(0);
    EXPECT_EQ(distances[3], 2); 
}

TEST_F(GraphTest, AddEdgeDuplicate) {
    g->addEdge(0, 1); 
    std::vector<int> distances = g->bfs(0);
    EXPECT_EQ(distances[1], 1); 
}

// Тест BFS
TEST_F(GraphTest, BfsDistances) {
    std::vector<int> distances = g->bfs(0);
    EXPECT_EQ(distances[0], 0); // Расстояние до самой себя
    EXPECT_EQ(distances[1], 1); // Расстояние до вершины 1
    EXPECT_EQ(distances[2], 1); // Расстояние до вершины 2
    EXPECT_EQ(distances[3], 2); // Расстояние до вершины 3
    EXPECT_EQ(distances[4], 2); // Расстояние до вершины 4
    EXPECT_EQ(distances[5], 2); // Расстояние до вершины 5
}

TEST_F(GraphTest, BfsInvalidStartVertex) {
    EXPECT_EXIT(g->bfs(10), ::testing::ExitedWithCode(1), "Ошибка: StartVertex 10 вне диапазона.");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
