#include <iostream>
#include <queue>
using namespace std;

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,1},
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,1,0,0,0}
};

bool visited[5];

void DFS(int node){
    visited[node] = true;
    cout << node << " ";

    for(int i = 0; i < 5; i++){
        if(graph[node][i] == 1 && !visited[i]){
            DFS(i);
        }
    }
}

void BFS(int start){
    queue<int> q;

    for(int i=0;i<5;i++)
        visited[i] = false;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int i = 0; i < 5; i++){
            if(graph[node][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){

    cout << "DFS: ";
    for(int i=0;i<5;i++)
        visited[i] = false;
    DFS(0);

    cout << endl;

    cout << "BFS: ";
    BFS(0);

    return 0;
}