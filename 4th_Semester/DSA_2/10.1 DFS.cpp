//graph-DFS

#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter number of nodes : ";
    int n; cin>>n;

    vector<int> graph[n];

    cout<<"Enter edges : ";
    int e; cin>>e;

    for(int i=0; i<e; i++)
    {
        int nd1,nd2;
        cin>>nd1>>nd2;
        graph[nd1].push_back(nd2);
        graph[nd2].push_back(nd1);
    }
    cout<<"Adjacency list :"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<" : ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

//    DFS
    stack<int>st;
    int visited[n] = {0};
    st.push(0);
    while(!st.empty()){
        int node = st.top();
        if(visited[node]==1){
            st.pop();
            continue;
        }
        cout<<st.top()<<" ";

        st.pop();
        visited[node]=1;
        for(int j=0; j<graph[node].size(); j++)
        {
            int adj_node = graph[node][j];
            if(visited[adj_node]==0){
                st.push(adj_node);
            }
        }
    }


}
//node = 7
//edge = 7
//0 1
//0 3
//0 2
//2 3
//2 4
//4 5
//3 6
