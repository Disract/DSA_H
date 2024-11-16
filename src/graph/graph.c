#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bfs(graph arr,int v, int s){
    int q[100],front=-1,rear=-1;
    bool varr[100]={false};

    varr[s]=true;
    q[++rear]=s;
    while(front<rear){
        int curr = q[++front];
        printf("%d ",curr);
        for(int i=0;i<v;i++){
            if(!varr[i] && arr[curr][i]==1){
                varr[i] = true;
                q[++rear] = i;
            }
        }
    }

}

void dfs(graph arr, int v, int r) {
    int s[100], top = -1;
    bool varr[100] = {false};
    
    varr[r] = true;
    s[++top] = r;
    
    while(top != -1) {
        int curr = s[top];
        bool foundUnvisited = false;
        
        for(int i = 0; i < v; i++) {
            if(arr[curr][i] == 1 && !varr[i]) {
                varr[i] = true;
                s[++top] = i;
                foundUnvisited = true;
                break; 
            }
        }
        
        if(!foundUnvisited) {
            printf("%d ", curr);
            top--;
        }
    }
}

void addedge(graph arr,int u,int v){
    arr[u][v] = 1;
    arr[v][u] = 1;
}

graph createGraph(int v){
    int** arr = (int**)malloc(v*sizeof(int*));
    for(int i=0;i<v;i++){
        arr[i] = (int*)malloc(v*sizeof(int*));
    }

    for(int j=0;j<v;j++){
        for(int k=0;k<v;k++){
            arr[j][k] = 0;
        }
    }

    return arr;
}

