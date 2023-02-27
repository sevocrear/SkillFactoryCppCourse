#pragma once
#include <iostream>
#define SIZE 10

class Graph {
    public:
        Graph();
        // добавление вершины
        void addVertex(int vnumber);
        // добавление ребра
        void addEdge(int v1, int v2, int weight);
        // удаление вершины
        void delVertex(int vnumber);
        // удаление ребра
        void delEdge(int v1, int v2);
        
        void depth(int start);
        void width(int start);
        void depthInner(int current, bool visited[]);
        void findPath(int from, int to, bool visited[], int& count);
        int findPathCount(int from, int to);
    private:
        bool edgeExists(int v1, int v2);
        bool vertexExists(int v);

        int matrix[SIZE][SIZE]; // матрица смежности
         
        int vertexes[SIZE]; // хранилище вершин
        int vertexCount; // количество добавленных вершин
};