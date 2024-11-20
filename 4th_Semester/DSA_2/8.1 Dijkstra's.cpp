//Dijkstra's shorted path algorithm
// (single source shortest path)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter nodes : ";
    int nodes; cin>>nodes;
    int grp[nodes][nodes];

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            grp[i][j]=(i==j)? 0: 9999;
        }
    }
    cout<<"Enter edges : ";
    int edges; cin>>edges;
    for(int i=0; i<edges; i++)
    {
        int nd1,nd2,wight;
        cin>>nd1>>nd2>>wight;
        grp[nd1][nd2]=wight;
        grp[nd2][nd1]=wight;
    }
    cout<<"Adjacency Matrix :"<<endl;
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            cout<<grp[i][j]<<" ";
        }
        cout<<endl;
    }

    queue<int>q;
    int shortest_path[nodes];
    for(int i=0; i<nodes; i++){
        shortest_path[i]=9999;
    }
    cout<<"Enter source : ";
    int source ; cin>>source;
    q.push(source);
    shortest_path[source]=0;
    int visited[nodes]={0}, visited_n =0;
    while(visited_n < nodes){
        int node =q.front();
        q.pop();
        if(visited[node]==1) continue;
        for(int i=0; i<nodes; i++){
            int adj_weight= grp[node][i];
            if(adj_weight==-1)continue;
            int adj_path = shortest_path[node]+adj_weight;
            shortest_path[i] = min(shortest_path[i],adj_path);
            q.push(i);
        }
        visited[node]=1;
        visited_n++;
    }
    for(int i=0; i<nodes; i++){
        cout<<shortest_path[i]<<" " ;
    }
}

