#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Function prototype
void dijkstra(const std::vector<std::vector<int>>& graph, int size, int src);

// Utility function to find the vertex with minimum distance value
int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet);

// Function that implements Dijkstra's algorithm
void dijkstra(const std::vector<std::vector<int>>& graph, int size, int src) {
    std::vector<int> dist(size, INT_MAX);
    std::vector<bool> sptSet(size, false);

    dist[src] = 0;

    for (int count = 0; count < size - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < size; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output the distances
    for (int i = 0; i < size; i++) {
        std::cout << "Shortest distance from vertex " << src << " to vertex " << i << " is: " << dist[i] << std::endl;
    }
}

// Utility function to find the vertex with minimum distance value
int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet) {
    int min = INT_MAX, min_index;
    for (size_t v = 0; v < dist.size(); v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Driver code
int main() {
    int n;
    std::cout << "Enter the size of the matrix: ";
    std::cin >> n;
    if(n<=0) {
        std::cerr << "Error: Matrix size must be positive." << std::endl; // Exit if matrix size is non-positive
        exit(1);
    }

    std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n));
    int edgesCount = 0;

    std::cout << "Enter the matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> adjacencyMatrix[i][j];
            if(adjacencyMatrix[i][j]<0) {
                std::cerr << "Error: Negative weight entered." << std::endl; // Exit if negative weight is entered
                exit(1);
            }
            if(i==j&&adjacencyMatrix[i][j]!=0) {
                std::cerr << "Error: Non-zero diagonal entry." << std::endl; // Exit if non-zero diagonal entry
                exit(1);
            }
            if (adjacencyMatrix[i][j] != 0) {
                ++edgesCount; // Add edge to count if non-zero weight is entered
            }
        }
    }

    if (edgesCount != n * (n - 1)) {
        std::cerr << "Error: Too few or too many edges entered." << std::endl;
        return 1; // Exit if incorrect number of edges entered
    }

    int sourceVertex;
    std::cout << "Enter the source vertex: ";
    std::cin >> sourceVertex;
    if (cin.fail() || cin.peek() != '\n') {
        std::cerr << "Error: Expected a single integer for the source vertex." << std::endl;
        return 1; // Exit if invalid input for source vertex
    }

    dijkstra(adjacencyMatrix, n, sourceVertex);

    return 0;
}

