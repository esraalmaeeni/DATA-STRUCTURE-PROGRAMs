#include <iostream>
#include <vector>

using namespace std;

// Define a structure for graph nodes
struct Node {
    int value;
    Node(int val) : value(val) {}
};

// Define a graph class using an adjacency list
class Graph {
public:
    vector<Node*> nodes;
    vector<vector<int>> adjacencyList;

    // Constructor to initialize the graph
    Graph(int n) {
        adjacencyList.resize(n);
        for (int i = 0; i < n; ++i) {
            nodes.push_back(new Node(i));
        }
    }

    // Function to add an edge between two nodes
    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from); // For undirected graph
    }
};

int main() {
    // Create a graph with 5 nodes
    Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // Print the adjacency list
    for (int i = 0; i < graph.nodes.size(); ++i) {
        cout << "Adjacent nodes to Node " << i << ": ";
        for (int neighbor : graph.adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
