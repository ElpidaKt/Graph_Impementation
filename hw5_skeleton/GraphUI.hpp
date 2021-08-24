
#ifndef _GRAPH_UI_
#define _GRAPH_UI_
#include <iostream>
#include"Graph.hpp"
#include <list> 
#include<iterator>  
#include<vector>  
#include <stdio.h>
#include <stdlib.h>

template <typename T>
int graphUI() {
  
  string option, line;
  int distance;
  bool digraph = false;
  
  cin >> option;
  if(!option.compare("digraph"))
    digraph = true;
  Graph<T> g(digraph);
  
  while(true) {
    
    std::stringstream stream;
    cin >> option;
    
    if(!option.compare("av")) {
      getline(std::cin, line);
      stream << line;
      T vtx(stream);
      if(g.addVtx(vtx))
        cout << "av " << vtx << " OK\n";
      else
        cout << "av " << vtx << " NOK\n";
    }
    else if(!option.compare("rv")) {

    }
    else if(!option.compare("ae")) {
      
    }
    else if(!option.compare("re")) {

    }
    else if(!option.compare("dot")) {
      
    }
    else if(!option.compare("bfs")) {
      
      cout << "\n----- BFS Traversal -----\n";
      
      cout << "\n-------------------------\n";
    }
    else if(!option.compare("dfs")) {
      
      cout << "\n----- DFS Traversal -----\n";
      
      cout << "\n-------------------------\n";
    }
    else if(!option.compare("dijkstra")) {
      getline(std::cin, line);
      stream << line;
      T from(stream);
      T to(stream);

      cout << "Dijkstra (" << from << " - " << to <<"): ";
      
    }
    else if(!option.compare("mst")) {

      cout << "\n--- Min Spanning Tree ---\n";
      //cout << "MST Cost: " << sum << endl;
    }
    else if(!option.compare("q")) {
      cerr << "bye bye...\n";
      return 0;
    }
    else if(!option.compare("#")) {
      string line;
      getline(cin,line);
      cerr << "Skipping line: " << line << endl;
    }
    else {
      cout << "INPUT ERROR\n";
      return -1;
    }
  }
  return -1;  
}

#endif

using namespace std;

template <typename T>
Graph<T>::Graph(bool isDirectedGraph){
    this->isDirectedGraph = isDirectedGraph;
}

template <typename T>
bool Graph<T>::contains(const T& info){
  typename vector<Node<T>>::iterator it;

  for (it=this->vertices.begin(); it != this->vertices.end(); ++it){
    if((*it).content == info){
      return true;
    }
  }
  return false;
}

template <typename T>
bool Graph<T>::addVtx(const T& info){

  Node<T> cur_node;
    
    
  if(contains(info)){
    return false;
  }

  cur_node.content = info;
  cur_node.visited = false;
  
  vertices.push_back(cur_node);
  
  return true;
}

template <typename T>
bool Graph<T>::rmvVtx(const T& info){

    
    if(!contains(info)){
        return false;
    }

    
    typename vector<Node<T>>::iterator it;

    for (it=this->vertices.begin(); it != this->vertices.end(); ++it){
        if((*it).content == info){
            
            // Remove Edges
            typename vector<Edge<T>>::iterator it1;

            for (it1=this->adjacency.begin(); it1 != this->adjacency.end(); ++it1){
                if((*it1).from == (*it).info || (*it1).to == (*it).info){
                    adjacency.erase(it1);
                }
            }
                    
            // delete node
            vertices.erase(it);
    
        }
    }
    
    return true;

}
template <typename T>
bool Graph<T>::addEdg(const T& from, const T& to, int cost){
 
    Edge<T> cur_edge, inverted_cur_edge;
    
    typename vector<Edge<T>>::iterator it;
    for (it=this->adjacency.begin(); it != this->adjacency.end(); ++it){
        if((*it).from == from && (*it).to == to){ // directed
            return false;
        }
    }
    
    cur_edge = Edge<T>(from, to, cost);
    this->adjacency.push_back(cur_edge);
    
    if(this->isDirectedGraph == false){ // Undirected
        inverted_cur_edge = Edge<T>(to, from, cost);
        this->adjacency.push_back(inverted_cur_edge);
    }
    
}

template <typename T>
bool Graph<T>::rmvEdg(const T& from, const T& to){
 
    Edge<T> cur_edge, inverted_cur_edge;
    
    typename vector<Edge<T>>::iterator it;
    for (it=this->adjacency.begin(); it != this->adjacency.end(); ++it){
        if((*it).from == from && (*it).to == to){ // directed
            return false;
        }
    }
    
    cur_edge = Edge<T>(from, to, cost);
    this->adjacency.push_back(cur_edge);
    
    if(this->isDirectedGraph == false){ // Undirected
        inverted_cur_edge = Edge<T>(to, from, cost);
        this->adjacency.push_back(inverted_cur_edge);
    }
    
}



/*
template <typename T>
void Graph<T>::RefreshAdjacencyMatrix(int position){
  
  int i;
  int n = position;
  const m = position;
  
  adjacency = new int [n][m];
  //(int *)malloc(position * position * sizeof(int)); 

  for (i = 0; i < position; i++) {
        adjacency[i][position - 1] = 0;
        adjacency[position - 1][i] = 0;
    }
}
*/

/*
template <typename T>
Node* Graph<T>::Adjnode(int distance, Node *head){

    Node *cur_node = new Node;
    cur_node->weight = distance;
    cur_node->next = head;
    
    return cur_node;
}
 */   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
