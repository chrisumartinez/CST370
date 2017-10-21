//============================================================================
// Name        : adj_matrix.cpp
// Author      : Christian Martinez
// Student ID  : 7354
// Date        : 2/07/2017
// Description : Matrix of the
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
/*
 * Functions
 */
void getInput();
void stringSplit(string);
/*
 * Variables
 */
int vertexInput;
int edgeInput;
int strSplit[1];


int main() {
	getInput();
	return 0;
}
void getInput(){
	//prompt input from user
	string filePath = "";
	cout << "Enter File Path: " << endl;
	cin >> filePath;

	//open file, getLine for vertex and edge
	ifstream inFile;
	inFile.open(filePath.c_str());
	string strVertices, strEdges;

	//get vertices
	getline(inFile, strVertices);
	int vertices = atoi(strVertices.c_str());
	cout << "Number of Vertices: " << vertices << endl;

	//get edges
	getline(inFile, strEdges);
	int edges = atoi(strEdges.c_str());
	cout << "Number of Edges: " << edges << endl;

	//create the matrix
	int matrix[vertices][vertices];

	//initialize the contents to 0
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			matrix[i][j] = 0;
		}
	}

	//Traverse through text file
	string edgeData;
	while(!inFile.eof()){
		getline(inFile, edgeData);
		stringSplit(edgeData);
		matrix[strSplit[0]][strSplit[1]] = 1;
	}

	//print out the matrix
	cout << "Adjacency Matrix: " << endl;
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

/*
 * splits the string into 2 values. Stored into the strSplit Array.
 */
void stringSplit(string str){
	stringstream ss(str);
	string token;
	char delimiter = ' ';
	getline(ss, token, delimiter);
	int val = atoi(token.c_str());
	strSplit[0] = val;
	getline(ss, token, delimiter);
	val = atoi(token.c_str());
	strSplit[1] = val;
}
