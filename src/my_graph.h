#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>

/**
 * @class Graph
 * @brief Класс для представления неориентированного графа с помощью списков смежности.
 */
class Graph {
private:
    int V;  ///< Количество вершин в графе.
    std::vector<std::list<int>> adj; ///< Список смежности для хранения графа.
    
public:
    /**
     * @brief Конструктор по умолчанию.
     * Создает пустой граф без вершин.
     */
    Graph() = default;

    /**
     * @brief Конструктор класса Graph.
     * @param vertices Количество вершин в графе.
     * 
     * Инициализирует граф с заданным количеством вершин.
     */
    Graph(int vertices);

    /**
     * @brief Добавляет ребро между двумя вершинами.
     * @param v Первая вершина.
     * @param w Вторая вершина.
     * 
     * Добавляет ребро между вершинами v и w. Если одно из значений неверно (меньше 0 
     * или больше или равно количеству вершин), выводится сообщение об ошибке.
     */
    void addEdge(int v, int w);

    /**
     * @brief Выполняет обход графа в ширину (BFS) от заданной вершины.
     * @param startVertex Вершина, с которой начинается обход.
     * @return Вектор расстояний от startVertex до всех остальных вершин.
     * 
     * Расстояние до каждой вершины возвращается в виде вектора, где значения являются
     * расстояниями от startVertex. Неподключенные вершины получают значение -1.
     */
    std::vector<int> bfs(int startVertex) const;

    /**
     * @brief Выводит граф в консоль.
     * 
     * Для отладки и визуализации структуры графа. Каждый узел и его соседние вершины
     * выводятся в формате: "Вершина X: -> Y".
     */
    void printGraph() const;
};

#include "my_graph.tpp"

#endif
