// minimum spanning tree (prim's algorithm)
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

	int visited[nodes] = {0}, visited_n = 0, starting_node;

	cout<<"starting Node : ";
	cin>>starting_node;

	visited[starting_node]=1;
	visited_n++;

	while(visited_n<nodes){
  	int min_edge =999, min_node1 = -1, min_node2 = -1;
  	for(int i=0; i<nodes; i++){
    	if(visited[i]==1){
      	for(int j=0; j<nodes; j++){
        	if(visited[j]==0 && grp[i][j]<min_edge){
          	min_edge = grp[i][j];
          	min_node1 = i;
          	min_node2 = j;
        	}
      	}
    	}
  	}
  	cout<< min_node1 <<" "<< min_node2<<" "<<min_edge<<endl;
  	visited[min_node2]=1;
  	visited_n++;
	}
}


Enter nodes : 9
Enter edges : 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 8 6
6 7 1
7 8 7
starting Node : 1
