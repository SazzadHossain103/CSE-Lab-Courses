#include<bits/stdc++.h>
using namespace std;

//#include <iostream>
//#include <vector>

class DisjointSet {
private:
    std::vector<int> parent;

public:
    // Constructor to create sets
    DisjointSet(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;  // Initialize each element as its own parent (representative)
        }
    }

    // Find operation to determine the representative of a set
    int Find(int x) {
        if (parent[x] == x) {
            return x;  // x is the representative of its set
        }
        return Find(parent[x]);  // Recursively find the representative
    }

    // Union operation to merge two sets
    void Union(int x, int y) {
        int root_x = Find(x);  // Find the representative of set containing x
        int root_y = Find(y);  // Find the representative of set containing y

        if (root_x != root_y) {
            parent[root_x] = root_y;  // Make root_y the parent of root_x
        }
    }
};

int main() {
    int num_elements = 6;
    DisjointSet ds(num_elements);

    ds.Union(0, 1);
    ds.Union(1, 2);
    ds.Union(3, 4);

    // Check if elements belong to the same set
    if (ds.Find(0) == ds.Find(2)) {
        std::cout << "0 and 2 are in the same set." << std::endl;
    } else {
        std::cout << "0 and 2 are in different sets." << std::endl;
    }

    if (ds.Find(3) == ds.Find(5)) {
        std::cout << "3 and 5 are in the same set." << std::endl;
    } else {
        std::cout << "3 and 5 are in different sets." << std::endl;
    }

    // Perform additional Union operations
    ds.Union(2, 3);

    if (ds.Find(0) == ds.Find(5)) {
        std::cout << "0 and 5 are in the same set." << std::endl;
    } else {
        std::cout << "0 and 5 are in different sets." << std::endl;
    }

    return 0;
}
