#include<bits/stdc++.h>

using namespace std;


//Time complexity: Inserting and deleting an edge take O(1) time 
//Space Complexity: O(V^2)
int vertArr[20][20]; 
int count = 0; //the adjacency matrix initially 0

//function allow u to add edge
void add_edge(vector<int> adj[], int u, int v) {
    vertArr[u][v] =  vertArr[v][u] = 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Use to print Matrix
void displayMatrix(vector<int> adj[], int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}

// DFS algorithms:
    //Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
    //Space Complexity: O(V), since an extra visited array of size V is required.

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vector<int> adj[], vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i <adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}
 
// unvisited vertices.
void DFS(vector<int> adj[], int v) {
    vector<bool> visited(v, false);
    for (int u = 0; u < v; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}

//Time Complexity : O(V + E) 
//Auxiliary Space: O(V)
bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[]) {
    list<int> queue;
    bool visited[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
 
                // We stop BFS when we find destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
    return false;
}
 
void printShortestDistance(vector<int> adj[], int s, int dest, int v) {
    int pred[v], dist[v];
 
    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "\n\nGiven source and destination are not connected";
        return;
    }
 
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    cout << "\nShortest path length is: "
         << dist[dest];
 
    cout << "\nPath is: ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

void showMenu(){
	cout << "\n";
    cout << "\n1. Reads the exist graph\n";
    cout << "2. Graph to adj matrix \n";
    cout << "3. DFS search \n";
    cout << "4. Print the shortest path between 2 points \n";
    cout << "5. Exit\n";
}

int main() {
    int v = 5, choose;
    vector<int> adj[v];
    do{
    	showMenu();
    	cout << "Your choice: ";
        cin >> choose;
    	switch(choose){
    		case 1: {
				    add_edge(adj, 0, 1);
				    add_edge(adj, 0, 2);
				    add_edge(adj, 1, 2);
				    add_edge(adj, 1, 3);
				    add_edge(adj, 2, 3);
				    add_edge(adj, 2, 4);
				    add_edge(adj, 3, 4);
    				break;
				}
    			
    		case 2: {
                    ofstream file("outputfile.txt");
                    cout << "Graph to adj matrix: \n\n";
    				displayMatrix(adj, v);
                    file.close();
    				break;
				}
    		case 3: {
    				cout << "\nGraph implementation using STL | Set 1 (DFS of Unweighted and Undirected): \n";
	    			DFS(adj, v);
	    			break;
				}
    		case 4: {
    				int source = 1, dest = 4;
	    			printShortestDistance(adj, source, dest, v);
	    			break;
				}
    		case 5:
    			break;
    		default:
    			cout << "Please choose again!!!";
    			break;
		}
    }while(choose!=5);
}

