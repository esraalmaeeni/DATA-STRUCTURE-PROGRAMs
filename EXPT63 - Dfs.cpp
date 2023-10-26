#include <iostream>
#include <vector>
#include <stack>

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

    // Function to perform DFS
    void dfs(int startVertex) {
        // Create a boolean array to keep track of visited vertices
        vector<bool> visited(vertices, false);

        // Create a stack for DFS
        stack<int> s;

        // Push the starting vertex onto the stack
        s.push(startVertex);

        cout << "Depth-First Traversal starting from vertex " << startVertex << ": ";

        while (!s.empty()) {
            // Pop a vertex from the stack
            int currentVertex = s.top();
            s.pop();

            // If this vertex is not visited, mark it as visited and process it
            if (!visited[currentVertex]) {
                visited[currentVertex] = true;
                cout << currentVertex << " ";

                // Get all adjacent vertices of the current vertex
                for (int neighbor : adjacencyList[currentVertex]) {
                    // If an adjacent vertex is not visited, push it onto the stack
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }

        cout << endl;
    }
};

int main() {
    // Create a graph with 7 vertices
    Graph graph(7);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 6);

    // Perform DFS starting from vertex 0
    graph.dfs(0);

    return 0;
}
