#include "Archivo.h"
#include <string>

Archivo::Archivo() : FileSystemNode(){
	
}

Archivo::Archivo(string n, string a, FileSystemNode* papa) : FileSystemNode(n, a, papa){
	
}

