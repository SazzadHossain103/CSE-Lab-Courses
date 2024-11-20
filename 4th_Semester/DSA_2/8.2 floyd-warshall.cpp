//floyd-warshall algorithm (kono node e jawar sorted path ber kora hoy)
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
            grp[i][j]=(i==j)? 0: -1;
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

    for(int k=0; k<nodes; k++){
        for(int i=0; i<nodes; i++){
            for(int j=0; j<nodes; j++){
                if(grp[i][k]==-1 || grp[k][j]==-1)continue;
                int w = grp[i][k]+grp[k][j];
                if(grp[i][j]==-1 || grp[i][j]>w){
                    grp[i][j]=w;
                }
            }
        }
    }
    cout<<"Adjacency Matrix update :"<<endl;
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            cout<<grp[i][j]<<" ";
        }
        cout<<endl;
    }
}


//Enter nodes : 5
//Enter edges : 7
//0 1 3
//0 4 8
//0 3 7
//1 2 1
//1 3 4
//2 3 2
//3 4 3
