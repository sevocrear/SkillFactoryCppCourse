#include "Graph.hpp"

Graph::Graph()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == v)
            return true;
    return false;
}

// Удаление вершины
void Graph::delVertex(int vnumber)
{
    // Ваш код должен быть здесь
    for (int i = vnumber; i < vertexCount; i++)
    {
        vertexes[i] = vertexes[i + 1];
    }
    vertexCount--;
    for (int j = 0; j < SIZE; j++)
        matrix[vnumber][j] = 0;
    for (int j = 0; j < SIZE; j++)
        matrix[j][vnumber] = 0;
}

// удаление ребра
void Graph::delEdge(int v1, int v2)
{
    // Ваш код должен быть здесь
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

// Алгоритм обхода в глубину
void Graph::depth(int start)
{
    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;     // инициализируем как непосещенные
    depthInner(start, visited); // запуск алгоритма

    std::cout << std::endl;
}

// Доп метод
void Graph::depthInner(int current, bool visited[])
{
    std::cout << "v" << current << " -> "; // вывод текущей
    visited[current] = true;               // помечаем как посещенную
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, i) && !visited[i])
            depthInner(i, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину
    }
}

// Алгоритм поиска всех путей от from к to узлу
int Graph::findPathCount(int from, int to)
{
    /// Method to find all possible paths from-to and count them
    // Total count of paths 
    int count = 0;
    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;     // инициализируем как непосещенные

        // For every adjacent vertex of current vertex 
    findPath(from, to, visited, count); 
    return count; 
}
void Graph::findPath(int from, int to, bool visited[], int& count) {
    if (from == to) {
        count++; 
        return;
    }
    visited[from] = true;   
    for (int v = 0; v < SIZE; v++)  {
        if (edgeExists(from, v) && !visited[v]) {
            findPath(v, to, visited, count);
        }
    }
    visited[from] = false;
}

// Алгоритм обхода смежного графа в ширину
void Graph::width(int start)
{
    int queue_to_visit[SIZE]; // очередь вершин для обхода
    int queueCount = 0;

    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    queue_to_visit[queueCount++] = start; // кладем в очередь начальную вершину
    while (queueCount > 0)
    {
        // взятие из очереди вершины
        int current = queue_to_visit[0];
        queueCount--;
        for (int i = 0; i < queueCount; i++)
        {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;
        std::cout << "v" << current << " -> ";
        // поиск смежных вершин и добавление их в очередь
        for (int i = 0; i < SIZE; i++)
        {
            bool alreadyAdded = false;
            for (int j = 0; j < queueCount; j++)
                if (queue_to_visit[j] == i)
                {
                    alreadyAdded = true;
                    break;
                }
            if (!alreadyAdded && edgeExists(current, i) && !visited[i])
                queue_to_visit[queueCount++] = i;
        }
    }
    std::cout << std::endl;
}