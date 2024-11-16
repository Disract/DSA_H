#ifndef GRAPHS_H
#define GRAPHS_H
typedef int** graph;
void bfs(graph arr,int v, int s);
void dfs(graph arr,int v, int s);
void addedge(graph arr,int u,int v);
graph createGraph(int v);
#endif