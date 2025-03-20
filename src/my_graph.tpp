#include "my_graph.h"

// Конструктор, который инициализирует граф с заданным количеством вершин
Graph::Graph(int vertices) {
    if (vertices <= 0) {
        std::cerr << "Количество вершин должно быть положительным." << std::endl;
        exit(EXIT_FAILURE);
    }
    this->V = vertices;
    adj.resize(vertices);
}

// Метод для добавления ребра между вершинами v и w
void Graph::addEdge(int v, int w) {
    if (v < 0 || v >= V || w < 0 || w >= V) {
        std::cerr << "Ошибка: недопустимые вершины " << v << " или " << w << "." << std::endl;
        return;
    }

    // Проверка на дублирование ребра
    for (int neighbor : adj[v]) {
        if (neighbor == w) {
            return; 
        }
    }

    // Добавление ребра в списки смежности
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Метод для выполнения обхода в ширину (BFS) от заданной вершины
std::vector<int> Graph::bfs(int startVertex) const {
    if (startVertex < 0 || startVertex >= V) {
        std::cerr << "Ошибка: StartVertex " << startVertex << " вне диапазона." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<int> distances(V, -1); // Вектор расстояний
    std::queue<int> q; // Очередь для BFS

    distances[startVertex] = 0; // Расстояние до стартовой вершины равно 0
    q.push(startVertex); // Добавление стартовой вершины в очередь

    // Основной цикл обхода
    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        // Обход всех соседей текущей вершины
        for (int neighbor : adj[currentVertex]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[currentVertex] + 1;
                q.push(neighbor);
            }
        }
    }

    return distances;
}

// Метод для вывода графа в консоль
void Graph::printGraph() const {
    for (int v = 0; v < V; ++v) {
        std::cout << "Вершина " << v << ":";
        for (int neighbor : adj[v]) {
            std::cout << " -> " << neighbor;
        }
        std::cout << std::endl;
    }
}