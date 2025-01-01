#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int a[1001][1001];
vector<pair<int,int>> dscanh;
int n, m; // so lg dinh , so lg canh

//THAY DINH A B C D E F G = 1 2 3 4 5 6 7

//DUYET NEU SD MA TRAN KE 
void DFS2(int u){
    cout << u << " " ;
    visited[u] = true;
    //DUYET DS KE CUA DINH U : DUYET CAI DONG THU U TRONG MA TRAN KE A
    for(int i = 1 ; i <=n ; i++){
        if(a[u][i] == 1){
            if(!visited[i]){
                DFS2(i);
            }
        }
    }
}
//DUYET NEU SD DANH SACH KE
void DFS1(int u){
    cout << u << " " ;
    visited[u] = true;
    // duyet ds ke cua dinh u
    for(int v : ke[u]){
        if(!visited[v]){
            DFS1(v);
        }
    }
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " " ;
        for(int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i<m ; i++){
        int x, y; cin >> x >> y ;
        ke[x].push_back(y); //them dinh y vao ds ke cua x
        ke[y].push_back(x); //them dinh x vao ds ke cua y
    }
  //  DFS1(1);
    BFS(1);
    //NHAP DO THI SD MA TRAN KE
//     cin >> n >> m;
//     for(int i = 0 ; i < m ; i++){
//         int x, y ; cin >> x >> y ;
//         a[x][y] = 1;
//         a[y][x] = 1;
//     }
}