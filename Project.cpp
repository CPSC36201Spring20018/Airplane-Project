#define MAX_X_VALUE 10
#define MAX_Y_VALUE 10

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
struct Airport_Vertex{
  string name;
  int x;
  int y;
};
struct Edge{
  string ID;
  string airport_name_1;
  string airport_name_2;
};
class FAA{
public:
 void make_empty_graph();
 void add_vertex();
 void add_edge();
 void delete_vertex();
 void delete_edge();
 void disable_vertex();
 void disable_edge();
 void delete_path();
};
class Airline{
public:
 void create_path();
 void save_path();
};
void PrintMat(int **mat, int n)
{
	int i, j;

	cout<<"\n\n"<<setw(4)<<"";
	for(i = 0; i < n; i++)
		cout<<setw(3)<<"("<<i+1<<")";
	cout<<"\n\n";

	// Print 1 if the corresponding vertexes are connected otherwise 0.
	for(i = 0; i < n; i++)
	{
		cout<<setw(3)<<"("<<i+1<<")";
		for(j = 0; j < n; j++)
		{
			cout<<setw(4)<<mat[i][j];
		}
		cout<<"\n\n";
	}
}
int main()
{
	int i, v, j, v1, v2;
  char input[256];
  bool check = false;
	// take the input of the number of edges.
	//cout<<"Enter the number of vertexes of the graph: ";
	//cin>>v;


	// Dynamically declare graph.
	int **graph;
  if (MAX_X_VALUE > MAX_Y_VALUE){
    graph = new int*[MAX_X_VALUE];
    v = MAX_X_VALUE;
  }else{
    graph = new int*[MAX_Y_VALUE];
    v = MAX_Y_VALUE;
  }

  //Generates empty map
	for(i = 0; i < v; i++){
		graph[i] = new int[v];
		for(j = 0; j < v; j++){
      graph[i][j] = 0;
    }
	}
  //0 for vertex that doesn't exist, 1 for vertex that does exist
	// Take the input of the adjacent vertex pairs of the given graph.
  cout<<"\nInput number of verticies: ";
  while (scanf("%s", input) != EOF){
    check = true;
    for (int i = 0; i < strlen(input); ++i){
      if (!isdigit(input[i])){
        cout<<"\nError";
        check = false;
      }
    }
    if (check == true){
      int num = atoi(input);
      for (int i = 0; i < num; ++i){
    		cout<<"\nX: ";
    		cin>>v1;
    		cout<<"Y: ";
    		cin>>v2;
        if (graph[v1-1][v2-1] == 1){
          cout << "Error, vertex already exists" << endl;
        }else{
          graph[v1-1][v2-1] = 1;
        }
        PrintMat(graph, v);
      }
    }
    cout<<"\nInput number of verticies: ";
	}

	// Print the 2D array representation of the graph.

}
