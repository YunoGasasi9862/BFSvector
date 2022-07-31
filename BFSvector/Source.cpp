#include <iostream>
#include <vector>
#include <queue>
#define VERTICES 5
void AddnewEdge(std::vector<int> adjacencylist[], int a, int b)  //a and b are values
//adjacency list is the list that the values will be added to
{
	adjacencylist[a].push_back(b);
	adjacencylist[b].push_back(a);

}

void bfs(std::vector<int> adj[], int src, std::vector<int>& finalan, std::vector<bool>& visited) //DONT CREATE A COPY
{
	
	std::queue<int> queue;
	queue.push(src);
	visited[src] = true;

	while (!queue.empty())
	{
		src = queue.front();
		finalan.push_back(src); //pushes into the vector
		queue.pop();


		for (int i = 0; i < adj[src].size(); i++)  //adj[src]->size() gives us the size of the vector in that particular row
			//if src is 0, so it's going to give the size of all the nodes attached to zero
		{
			int check = adj[src].at(i); //you can use at 
			//also this check is used to traverse the adjaceny list of that particular src (source)
			if (!visited[check])
			{
				visited[check] = true;
				queue.push(check);
			}
		}
	}

}

std::vector<int> bfsOfGraph(int V, std::vector<int> adj[]) {
	
	std::vector<int> answer;
	std::vector<bool> visited(V, false); //initializing all of them to false
	
	bfs(adj, 0, answer, visited); //std::vector<bool> visited(V, false)
	//initializes 5 slots with false


	return answer;

	

}

int main(void)
{
	std::vector<int> adj[VERTICES];  //this is how you create adjaceny list in C++
	
	AddnewEdge(adj, 0, 1);
	AddnewEdge(adj, 0, 2);
	AddnewEdge(adj, 0, 3);
	AddnewEdge(adj, 2,4);

	std::vector<int> answer = bfsOfGraph(5, adj);


	return 0;
}