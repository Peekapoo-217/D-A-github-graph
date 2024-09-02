#include <bits/stdc++.h>
#include <vector>

using namespace std;

/*
ma tran ke
*/
#define MAX_VERTICES 100
#define INF 100

struct AdjMatrixGraph{
    int numVertices; // so dinh
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];// ma tran ke
};

void readGraphFromFile(string filename, AdjMatrixGraph &graph){
	ifstream file(filename);//Mo tep de doc
	
	file>>graph.numVertices;//Doc so dinh tu tep
	
	//Doc ma tran tu tep va luu vao cau truc do thi
	for(int i = 0; i < graph.numVertices; ++i){
		for(int j = 0 ; j < graph.numVertices; ++j){
			file>>graph.adjMatrix[i][j];
		}
	}
		file.close();//Dong tep sau khi doc 
		
}

void printGraph(AdjMatrixGraph graph){
	cout<<"So luong dinh: "<< graph.numVertices << endl;
	for(int i = 0 ; i < graph.numVertices ; ++i){
		for(int j = 0; j < graph.numVertices; ++j){
			cout<<graph.adjMatrix[i][j]<< " ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//liet ke sinh vien cung tinh voi sinh vien k
void LietKeSinhVienCungTinh(AdjMatrixGraph &graph, int student){
	cout<<endl;
	cout<<"Sinh vien "<< student<<" cung tinh voi sinh vien: ";
	for(int i = 0; i < graph.numVertices; ++i){
		if(graph.adjMatrix[student][i] == 1 || graph.adjMatrix[i][student] == 1){
			cout<<i<<" ";	
		}
	}
	cout<<endl;
}



//tim sinh vien cung t?nh
vector<int> findSameProvince(AdjMatrixGraph &graph, int student){
	vector<int> sameProvinceStudent;
	for(int i = 0 ; i < graph.numVertices; ++i){
		if(graph.adjMatrix[student][i] == 1){
			sameProvinceStudent.push_back(i);
		}
	}
	return sameProvinceStudent;	
}

//sinh vien trong lop co bao nhieu tinh, moi tinh gom nhung sinh vien nao
void getProvince(AdjMatrixGraph &graph){
	for(int i = 0 ; i< graph.numVertices; ++i){
		cout<<endl;
		cout<<"Tinh "<<i<<" gom sinh vien: ";
		for(int j = 0 ; j < graph.numVertices; ++j){
			if(graph.adjMatrix[i][j] == 1){
				cout<<j<<" ";
			}
		}
	}
	cout<<endl;
}

//demcanh
int demcanh(AdjMatrixGraph &graph){
	int cnt = 0;
	for (int i = 0; i < graph.numVertices; ++i){
        for (int j = 0; j < graph.numVertices; ++j){
            if (graph.adjMatrix[i][j] == 1) {
                ++cnt;
            }
        }
    }
	//vo huong nen nhan 2 em khong biet dung hay sai a
    return cnt * 2;
}

//tinh so canh vao
int* calculateInDegree(AdjMatrixGraph &graph) {
    int* dinhVao = new int[graph.numVertices];
    
    for (int i = 0; i < graph.numVertices; ++i) {
        dinhVao[i] = 0; // Kh?i t?o gi� tr? 0 cho m?i d?nh
        for (int j = 0; j < graph.numVertices; ++j) {
            if (graph.adjMatrix[i][j] == 1) {
                dinhVao[i]++;
            }
        }
    }
    return dinhVao;
}



int main(){
	AdjMatrixGraph graph;
	readGraphFromFile("bt2.txt", graph);
	printGraph(graph);

	
	int student = 0;
	vector<int>sameProvinceStudents = findSameProvince(graph, student);
	for(int i = 0; i<sameProvinceStudents.size(); ++i){
		cout<<sameProvinceStudents[i]<<" ";
	}
	cout<<endl;
	
	cout<<"Tong so tinh trong lop: "<<graph.numVertices<<endl;
	getProvince(graph);
	

	int check = 2;
	LietKeSinhVienCungTinh(graph, check);
	
	
	int cnt = demcanh(graph);
	cout<<"\nTong so canh: "<<cnt<<endl;
	
	
	int dinhVao[MAX_VERTICES];
	calculateInDegree(graph);
	cout<<"\nSo luong canh vao cua moi dinh: \n";
	for(int i = 0 ; i < graph.numVertices; ++i){

		cout<<"Dinh "<<i<<": "<< dinhVao[i] << "canh "<<endl;
	}
	
	return 0;
}

