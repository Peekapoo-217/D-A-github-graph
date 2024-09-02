#include <bits/stdc++.h>

using namespace std;

/*
Danh sach ke
*/
#define MAX_VERTICES 100
#define INF 100


struct AdjList{
	int adjVertex;
	float weight;
	AdjList * next;
};

struct AdjListGraph{
	int numVertices;
	AdjList * adjList[MAX_VERTICES];
};

void readGraphFromFile(AdjListGraph &graph, string filename){
	ifstream file(filename);
	file>>graph.numVertices;
	
	for(int i = 0 ; i< graph.numVertices; ++i){
		graph.adjList[i] = nullptr;
		for(int j = 0; j < graph.numVertices; ++j){
			float weight;
			file>>weight;
			if(weight != INF){
				AdjList * newNode = new AdjList;
				newNode-> adjVertex = j;
				newNode-> weight = weight;
				newNode-> next = graph.adjList[i];
				graph.adjList[i] = newNode;
			}
		}
	}
	file.close();		
}

void printGraph(AdjListGraph graph){
	cout<<"So dinh: "<< graph.numVertices<<endl;
	for(int i = 0 ;i < graph.numVertices; ++i){
		cout<<"adjList[" << i<<"]: ";
		for(AdjList * p = graph.adjList[i]; p != nullptr; p = p->next){
			cout<<p->adjVertex << "("<< p->weight << ")";		
		}
		cout<<endl; 
	}
	cout<<endl;
}

//sinh vien x va y co cung tinh khong
bool sameProvince(AdjListGraph & graph, int x, int y){
	if(x < 0 || x >= graph.numVertices || y<0 || y >= graph.numVertices){
		return false;
	}
	
	for(AdjList * p = graph.adjList[x]; p != nullptr; p = p->next){
		if(p->adjVertex == y){
			return true;
		}
	}
	return false;
}


//liet ke sinh vien khong cung tinh voi x
// Liet ke sinh vien khong cung tinh voi x
void listStudentsNotInSameProvince(AdjListGraph &graph, int x) {
    if (x < 0 || x >= graph.numVertices) {
        cout << "Sinh vien " << x << " khong ton tai trong do thi." << endl;
        return;
    }

    cout << "Sinh vien khong cung tinh voi sinh vien " << x << ": ";
    for (int i = 0; i < graph.numVertices; ++i) {
        if (i != x) {
            bool sameProvince = false;
            for (AdjList *p = graph.adjList[x]; p != nullptr; p = p->next) {
                if (p->adjVertex == i) {
                    sameProvince = true;
                    break;
                }
            }
            if (!sameProvince) {
                cout << i << " ";
            }
        }
    }
    cout << endl;
}

int main(){
	AdjListGraph graph;
	readGraphFromFile(graph, "bt2.txt");
	printGraph(graph);

	
	int a,b;
	cin>>a>>b;
	if(sameProvince(graph, a, b)){
		cout<<"Cung tinh";
	}
	else{
		cout<<"Khac tinh";
	}

	int x;
	cout<<"\n\nNhap so hieu sinh vien x:";
	cin>>x;
	listStudentsNotInSameProvince(graph,x);
	

	return 0;
}

