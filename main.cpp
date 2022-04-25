/*  Author: Riley Than
*   Date: 4/24/2002
*   Professor: Syrotiuk
*   Class: CSE310
*   Description: Make a program that parses commands and display things
*/

#include <stdio.h>
#include <iostream> //basic libraries
#include <fstream>
#include <string>

using namespace std;

#include "graph.h" //modules
#include "floyd_warshall.h"
#include "dfs.h"

int* firstVertexArray = NULL;
int* trueVertexArray = NULL;
int fillVertexArray(vertex* arr1, vertex* arr2, int firstYear, int secondYear, std::string fileName);
struct vertex {
  int num;
  int year; 
  struct edge* edges;
};
struct edge {
  int point; 
  struct edge* next;
};

int main(int argc, char** argv){
    std::string edges = argv[1];
    std::string dates = argv[2];
    std::string commands = argv[3];

    ifstream commandFile;
    commandFile.open(commands);
    std::string commandLine;
    for(commandLine; getline(commandFile, commandLine);){//loop until there is nothing
        cout << "Command: " << commandLine << endl << endl;

        int pos = 0;
        while (commandLine[pos] != ' '){
            pos++;
        }

        std::string queryName = commandLine.substr(0,pos);
        commandLine.erase(0, pos+1);

        if(queryName == "start-graph"){
            pos = 0;
            while(commandLine[pos] != ' '){
                pos++;
            }
            std::string firstYearString = commandLine.substr(0,pos);
            commandLine.erase(0,pos+1);

            std::string secondYearString = commandLine;

            int firstYear = stoi(firstYearString);
            int secondYear = stoi(secondYearString);

            //other modular shit goes here
            
            if(firstVertexArray == NULL && trueVertexArray == NULL){
                vertexArray = new vertexArray[10000];
                int arrSize = fillVertexArray(firstVertexArray, trueVertexArray, firstYear, secondYear, dates);
            }

            cout << "The graph G for the years " << firstYear << "-" << secondYear << " has:" << endl;
            cout << '\t' << "|V| = " << endl;
            cout << '\t' << "|E| = " << endl;
        } else if(queryName =="out-degree"){
            cout << "The out-degre distribution is: " << endl;
        } else if(queryName == "diameter") {
            cout << "the graph G has diameter " << endl;
        } else if(queryName = "scc"){
            cout << "The graph G has " << " strongly connected components: " << endl;
            cout << '\t' << "Size : Number" << endl;
        } else if(queryName == "end-graph"){
            
        } else{
            //abort
        }
    }
    commandFile.close();

    return 0;
}

int fillVertexArray(vertex* arr1, vertex* arr2, int firstYear, int secondYear, std::string fileName){
    ifstream datesFile;
    datesFile.open(fileName);

    int size = 0;
    std::string line;
    int arrayPos = 0;

    for(line; getline(datesFile, line);){
        int pos = 0;
        while(line[pos] != '\t'){
            pos++;
        }
        std::string numberString = line.substr(0,pos);
        line.erase(0,pos+1);

        std::string yearString = line; //parse each line
        int yearInt = stoi(yearString); //convert year to int

        if(yearInt >= firstYear && yearInt <= secondYear){ //compare
            int number = stoi(numberString);
            struct vertex obj;
            obj.num = number;
            obj.year = yearInt;
            obj.edge = NULL;
            arr1[arrayPos] = obj;
            size++;
        }
    }
        arr2 = new arr2[size]; //declare size

        for(int i=0; i < size; i++){ //fill 2nd array with 1st array's contents
            arr2[i] = arr1[i];
        }
    datesFile.close();
}