#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a graph class using an adjacency list
class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    // Constructor to initialize the graph
    Graph(int n) : vertices(n) {
        adjacencyList.resize(n);
    }

    // Function to add an edge between two vertices
    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
    }

    // Function to perform BFS
    void bfs(int startVertex) {
        // Create a boolean array to keep track of visited vertices
        vector<bool> visited(vertices, false);

        // Create a queue for BFS
        queue<int> q;

        // Mark the starting vertex as visited and enqueue it
        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth-First Traversal starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            // Dequeue a vertex from the queue and print it
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    // Mark the adjacent vertex as visited and enqueue it
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    // Perform BFS starting from vertex 0
    graph.bfs(0);

    return 0;
}
