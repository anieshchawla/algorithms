//Breadth First Search: Shortest Reach
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
    ~Graph(){};
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V+1];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    int visited[V+1],count;
    for(int i = 1; i <= V; i++)
        visited[i] = -1;
 
    // Create a queue for BFS
    list<int> queue;
    list<int>count_que;
 
    // Mark the current node as visited and enqueue it
    visited[s] = 0;
    queue.push_back(s);
    count_que.push_back(0);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        //cout << s << " ";
        queue.pop_front();
        count = count_que.front();
        count_que.pop_front();
        count++;
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            //cout<<"visited[*i] "<<visited[*i]<<endl;

            if(visited[*i] == -1)
            {
                visited[*i] = count;
                //cout<<"count is "<<count<<endl;
                queue.push_back(*i);
                count_que.push_back(count);
            }
        }
        //count++;
    }
    for(int i = 1; i <= V; i++){
        if(visited[i]>0) cout<<visited[i]*6<<" ";
        else if(visited[i]<0) cout<<visited[i]<<" ";
    }
    cout<<endl;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test;
    cin>>test;
    while(test){
        int n,m;
        cin>>n>>m;
        Graph g(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            g.addEdge(x,y);
        }
        int starting_node;
        cin>>starting_node;
        g.BFS(starting_node);
        test--;
    }   
    return 0;
}