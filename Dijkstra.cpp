#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int dest;    // Destination vertex of the edge
    int weight;  // Weight of the edge
};

// Structure to represent a node in the priority queue
struct Node {
    int vertex;      // Vertex number
    int distance;    // Distance from the source vertex
    int predecessor; // Predecessor node in the shortest path
};

// Comparator for the priority queue
struct Comp {
    bool operator()(const Node &a, const Node &b) {
        return a.distance > b.distance;  // Comparison based on distance
    }
};

// Function to take input for the graph
vector<vector<Edge>> takeGraphInput(int &V) {
    int E;
    cout << "Enter number of vertices: ";
    cin >> V;

    // Check if number of vertices is valid
    if (V <= 0) {
        cerr << "Number of vertices must be positive." << endl;
        exit(1);
    }

    cout << "Enter number of edges: ";
    cin >> E;

    // Check if number of edges is valid
    if (E < 0) {
        cerr << "Number of edges must be non-negative." << endl;
        exit(1);
    }

    vector<vector<Edge>> graph(V + 1);  // Adjacency list representation of the graph

    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;

        src--;  // Decrement to adjust to 0-based indexing
        dest--;

        // Check if vertex indices are valid
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            cerr << "Invalid vertex index." << endl;
            exit(1);
        }

        // Add the edge to the graph
        graph[src + 1].push_back({dest + 1, weight});
    }

    return graph;
}

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<Edge>> &graph, int source) {
    int V = graph.size();

    priority_queue<Node, vector<Node>, Comp> pq;  // Priority queue for storing nodes
    vector<int> dist(V + 1, numeric_limits<int>::max());  // Distance array
    vector<int> predecessor(V + 1, -1);  // Predecessor array

    dist[source] = 0;  // Distance of source vertex is 0
    pq.push({source, 0, -1});  // Push source vertex into the priority queue

    while (!pq.empty()) {
        int u = pq.top().vertex;  // Get the vertex with the minimum distance
        int distance = pq.top().distance;
        int pred = pq.top().predecessor;
        pq.pop();

        // If the distance is greater than the current shortest distance, skip
        if (distance > dist[u]) continue;

        // Iterate through all the neighboring vertices of u
        for (const auto &edge : graph[u]) {
            int v = edge.dest;  // Destination vertex of the edge
            int weight = edge.weight;  // Weight of the edge

            // Relax the edge if a shorter path is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                predecessor[v] = u;  // Update predecessor
                pq.push({v, dist[v], u});  // Push the updated node into the priority queue
            }
        }
    }

    // Output shortest distances and paths
    cout << "Vertex\tDistance\tShortest Path\n";
    for (int i = 1; i < V; ++i) {
        cout << i << "\t" << dist[i] << "\t\t";
        if (dist[i] == numeric_limits<int>::max())
            cout << "Unreachable" << endl;
        else {
            stack<int> path;  // Stack to store the shortest path
            int current = i;
            while (current != -1) {
                path.push(current);  // Push vertices into the stack
                current = predecessor[current];  // Move to the predecessor
            }
            // Output the shortest path
            while (!path.empty()) {
                cout << path.top();
                path.pop();
                if (!path.empty())
                    cout << " -> ";
            }
            cout << endl;
        }
    }
}

// Main function
int main() {
    int V;
    vector<vector<Edge>> graph = takeGraphInput(V);  // Take input for the graph

    // Check if the graph is empty
    if (V == 0) {
        cerr << "Graph is empty." << endl;
        return 1;
    }

    // Check if the graph has only one vertex
    if (V == 1) {
        cout << "Graph has only one vertex." << endl;
        return 0;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    // Check if the source vertex index is valid
    if (source < 0 || source >= V) {
        cerr << "Invalid source vertex index." << endl;
        return 1;
    }

    // Perform Dijkstra's algorithm
    dijkstra(graph, source);

    return 0;
}
