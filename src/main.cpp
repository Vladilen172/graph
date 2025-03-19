#include <fstream>
#include <sstream>
#include "my_graph.h"

/**
 * @brief Обрабатывает граф из файла.
 * @param filename Имя файла, содержащего описание графа.
 * 
 * Файл должен содержать количество вершин, количество ребер, 
 * список ребер и начальную вершину для обхода в ширину. 
 * В результате выводятся расстояния от начальной вершины 
 * до всех остальных вершин, а также структура графа.
 */
void processGraph(const std::string& filename);

int main(void) {
    processGraph("graph.txt");

    return 0;
}

void processGraph(const std::string& filename) {
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return;
    }

    int numVertices, numEdges;
    input >> numVertices; 
    input >> numEdges;    

    Graph g(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        input >> u >> v;
        g.addEdge(u, v);
    }

    int startVertex;
    input >> startVertex; 

    std::vector<int> distances = g.bfs(startVertex);

    for (int i = 0; i < numVertices; ++i) {
        std::cout << distances[i] << "\n";
    }

    g.printGraph();

    input.close(); 
}