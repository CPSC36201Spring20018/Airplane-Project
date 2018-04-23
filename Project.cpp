#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <vector>
using namespace std;
/*
2D array
[00 01 02 03
 10 11 12 13
 20 21 22 23
 30 31 32 33]
transform to 1D array
[0 1 2 3
 4 5 6 7
 8 9 10 11
 12 13 14 15]
*/
#define MAX_X_VALUE 9
#define MAX_Y_VALUE 9
struct node{
	int x1, y1, pos;
  string name;
	node *next;
  bool check_disable = false;
};
class List{
private:
  node *head, *tail;
public:
  List();
  void create_node(int new_x1, int new_y1, string new_name);
  void display();
  void insert_position(int pos, int new_x1, int new_y1, string new_name);
  void delete_position(int x, int y);
  bool find_node(int x, int y);
  int find_pos(int x, int y);
};
List::List(){
  head=NULL;
  tail=NULL;
}
void List::create_node(int new_x1, int new_y1, string new_name){
    node *temp=new node;
    temp->x1 = new_x1;
    temp->y1 = new_y1;
    temp->name = new_name;
    temp->next=NULL;
    if(head==NULL){
      head=temp;
      tail=temp;
      temp=NULL;
    }
    else{
      tail->next=temp;
      tail=temp;
    }
}
void List::display(){
    node *temp=new node;
    temp=head;
    while(temp!=NULL){
			if (temp->name != ""){
				cout << temp->name << " " << "(" << temp->x1  << "," << temp->y1 << ")" << endl;
			}

      temp=temp->next;
    }
}
void List::insert_position(int pos, int new_x1, int new_y1, string new_name){
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;++i){
      pre=cur;
      cur=cur->next;
    }
    temp->x1 = new_x1;
    temp->y1 = new_y1;
    temp->name = new_name;
    pre->next=temp;
    temp->next=cur;
}
void List::delete_position(int x, int y){
  node *current=new node;
  node *previous=new node;
  current=head;
  int count = 0;
  while ((current->next != NULL) && (current->x1 != x && current->y1 != y)){
    cout << count << endl;
    ++count;
    previous=current;
    current=current->next;
  }
  delete(current);

}
bool List::find_node(int x, int y){
    node *temp = new node;
    temp = head;
    while(temp!=NULL){
      if (x == temp->x1 && y == temp->y1){
        //cout << temp->name << " " << "(" << temp->x1  << "," << temp->y1 << ")" << endl;
        return true;
      }
      temp=temp->next;
    }
    return false;
}
int List::find_pos(int x, int y){
  node *temp = new node;
  temp = head;
  int i = 0;
  while(temp!=NULL){
    if (x == temp->x1 && y == temp->y1){
      cout << i << endl;
      return i;
    }
    ++i;
    temp=temp->next;
  }
  return -1;
}
class Airport: public List{
public:
 Airport();
 void make_empty_graph();
 void add_vertex();
 void add_edge();
 void delete_vertex(int x1, int y1);
 void delete_edge();
 void disable_vertex(int x1, int y1);
 void enable_edge();
 void enable_vertex(int x1, int y1);
 void disable_edge();
 void delete_path();
 void create_path();
 void save_path();
 void print_array();
 void print_existing_graph();
 void generate_distance(int x1, int x2, int y1, int y2);

 //convert 2D index to 1D index for position
 int get_1D_index(int x1,int y1);
 void print_linked_list();
private:
  string name, input;
  bool check, check_linked_list;
	int x1, x2, y1, y2, v, num_objects, v1, v2, distance, num_of_verticies, graph_edge[MAX_X_VALUE][MAX_Y_VALUE], graph[MAX_X_VALUE][MAX_Y_VALUE];
	string graph_name[MAX_X_VALUE][MAX_Y_VALUE];
  vector<List> objs;
};
Airport::Airport(){
  num_of_verticies = 0;
  num_objects = 1;
  check_linked_list = false;
  objs.resize(num_objects);
}
void Airport::make_empty_graph(){

  // Dynamically declare graph.
  num_of_verticies = 0;
  //Generates empty map
	for(int i = 0; i < MAX_X_VALUE; ++i){
		for(int j = 0; j < MAX_Y_VALUE; j++){
      graph[i][j] = 0;
      graph_edge[i][j] = 0;
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
				cout << "name: ";
				cin >> name;
        //checks that new coordinates are unique.
        if (graph[v1][v2] == 1){
          cout << "Error, vertex already exists" << endl;
        }
        else{
          num_of_verticies++;
          graph[v1][v2] = 1;
					graph_name[v1][v2] = name;
          print_array();
        }
      }
    }
    //cout<<"\nInput number of verticies: ";
	}
}
void Airport::add_edge(){
  if (num_of_verticies < 2){
    cout << "Not enough vertices to make an edge" << endl;
  }
  else{
    print_existing_graph();
    cout << "Input first vertex: " << endl;
    cout << "X1: ";
    cin >> x1;
    cout << "Y1: ";
    cin >> y1;
    cout << "Input second vertex: " << endl;
    cout << "X2: ";
    cin >> x2;
    cout << "Y2: ";
    cin >> y2;
    //checking to insure vertex exist in graph and that they are not the same vertex
    if (graph[x1][y1] == 1 && graph[x2][y2] == 1 && (x1 != x2 || y1 != y2)){
      if (num_objects == 1){
        objs[0].create_node(x1,y1,graph_name[x1][y1]);
        objs[0].create_node(x2,y2,graph_name[x2][y2]);
        /*
        objs[0].find_node(x1,y1);
        generate_distance(x1,x2,y1,y2);
        objs[0].display();
        */
        num_objects++;
        objs.resize(num_objects);
      }
      else{
        //if node already exist in one linked list, adds the other to said linked list
        check_linked_list = false;
        for (int i = 0; i < num_objects; ++i){
          if (objs[i].find_node(x1,y1) == true){
            if (objs[i].find_node(x2,y2) == false){
              objs[i].create_node(x2,y2,graph_name[x2][y2]);
            }
            check_linked_list = true;
          }
          if (objs[i].find_node(x2,y2) == true){
            if (objs[i].find_node(x1,y1) == false){
              objs[i].create_node(x1,y1,graph_name[x1][y1]);
            }
            check_linked_list = true;
          }
        }
        //if no new nodes already connected by
        if (check_linked_list == false){
          objs[num_objects-1].create_node(x1,y1,graph_name[x1][y1]);
          objs[num_objects-1].create_node(x2,y2,graph_name[x2][y2]);
          num_objects++;
          objs.resize(num_objects);
        }
      }

    }
    else{
      cout << "Invaild input" << endl;
    }
  }
}
void Airport::delete_vertex(int x1, int y1){
  for(int i = 0; i < num_objects; ++i){
    if (objs[i].find_node(x1,y1) == true){
			objs.size();
      objs[i].delete_position(x1,y1);
			graph[x1][y1] = 0;
			graph_name[v1][v2] = "";
    }
  }
}
void Airport::print_array(){
  cout << endl;
  cout << "Here is the graph. 0 represents no node, 1 represents node" << endl;
  for(int i = 0; i < MAX_X_VALUE; ++i){
		for(int j = 0; j < MAX_Y_VALUE; j++){
      cout << graph[i][j];
    }
    cout << endl;
  }

}
void Airport::print_existing_graph(){
  cout << "Here are all the existing vertices" << endl;
	for (int i = 0; i < MAX_X_VALUE; ++i){
		for (int j = 0; j < MAX_Y_VALUE; ++j){
			if (graph[i][j] == 1){
				cout << i<< "," << j << " " << graph_name[i][j] << endl;
			}
		}
	}
}
void Airport::generate_distance(int x1, int x2, int y1, int y2){
  if (abs(x1 - x2) > abs(y1 - y2)){
    distance = abs(x1 - x2);
  }
  else{
    distance = abs(y1 - y2);
  }
  cout << "distance: " << distance << endl;
}
int Airport::get_1D_index(int x1, int y1){
  return (x1*MAX_Y_VALUE+y1);
}
void Airport::print_linked_list(){
  cout<<"\n--------------------------------------------------\n";
  cout<<"---------------Displaying All Graphs---------------";
  cout<<"\n--------------------------------------------------\n";
  for (int i = 0; i < num_objects-1; ++i){
    objs[i].display();
    cout << endl;
  }
}
int main(){

  Airport F;
  F.make_empty_graph();
  F.add_vertex();
	F.add_edge();
  F.add_edge();
  F.print_linked_list();
  F.delete_vertex(1,1);
  F.print_linked_list();
}
