#include <stdio.h>
#include "graph.h"

int main()
{
	graph gra;
	graph* g = &gra;
	read_graph(g, true);
	//bfs(g, 1);
	//dfs_simple(g, 3);
	dfs_complex(g, 1);
}