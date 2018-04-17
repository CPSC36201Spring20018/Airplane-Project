#define MAX_X_VALUE 10
#define MAX_Y_VALUE 10

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
// Print the 2D array representation of the graph.

class Airport{
public:
 void make_empty_graph();
 void add_vertex();
 void add_edge();
 void delete_vertex();
 void delete_edge();
 void disable_vertex();
 void disable_edge();
 void delete_path();
 void create_path();
 void save_path();
 void print_array(int **mat, int n);
 void print_existing_graph();
private:
  string name, input;
  bool check;
	int i, v, j, v1, v2, distance;
	int **graph;
	string graph_name[MAX_X_VALUE][MAX_Y_VALUE];
};
void Airport::make_empty_graph(){

  // Dynamically declare graph.

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
			graph_name[i][j] = "";
    }
	}
}
void Airport::add_vertex(){
  //0 for vertex that doesn't exist, 1 for vertex that does exist
	// Take the input of the adjacent vertex pairs of the given graph.
	input.clear();
  while (input != "q"){
		cout<<"\nInput number of verticies: ";
		cin >> input;
    check = true;
    for (int i = 0; i < input.length(); ++i){
      if (!isdigit(input[i])){
        //cout << "\nError";
        check = false;
      }
    }
    if (check == true && input != "q"){
      int num = stoi(input);
      for (int i = 0; i < num; ++i){
        cout << "\nInput coordinates: ";
    		cout << "\nX: ";
    		cin >> v2;
    		cout << "Y: ";
    		cin >> v1;
				cout << "\nname: ";
				cin >> name;
        //checks that new coordinates are unique.
        if (graph[v1-1][v2-1] == 1){
          cout << "Error, vertex already exists" << endl;
        }else{
          graph[v1-1][v2-1] = 1;
					graph_name[v1-1][v2-1] = name;
        }
        print_array(graph, v);
      }
    }
    //cout<<"\nInput number of verticies: ";
	}
}
void Airport::add_edge(){

}
void Airport::print_array(int **mat, int n){
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
void Airport::print_existing_graph(){
	for (int i = 0; i < MAX_X_VALUE; ++i){
		for (int j = 0; j < MAX_Y_VALUE; ++j){
			if (graph[i][j] == 1){
				cout << i+1 << "," << j+1 << " " << name << endl;
			}
		}
	}
}
int main(){
  Airport F;
  F.make_empty_graph();
  F.add_vertex();
	F.print_existing_graph();
}
