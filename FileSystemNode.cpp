#include "FileSystemNode.h"
#include <iostream>


FileSystemNode::FileSystemNode() {
	nombre = "";
	autor = "";
	padre = NULL;
}

FileSystemNode::FileSystemNode(string n, string a, FileSystemNode* papa) {
	nombre = n;
	autor = a;
	padre = papa;
}


string FileSystemNode :: toString(){
	return "Nombre: "+nombre+" Autor: "+autor+" Padre: "+padre->nombre;	
}


FileSystemNode::~FileSystemNode(){
	delete padre; 
	nombre = ""; 
	autor = "";
}