#include "Directorio.h"
#include <iostream>

using namespace std; 

Directorio::Directorio() : FileSystemNode(){
	
}

Directorio::Directorio(string n, string a, FileSystemNode* papa) : FileSystemNode(n, a, papa){
}

vector <FileSystemNode* > Directorio :: GETarchivos(){
	return archivos;
} 

void Directorio :: imprimirdirectorio(int espacios){
	/*
	if (profundidad == archivos.size()){
		
	}else {
		cout << archivos [profundidad]->toString();
		vector <FileSystemNode* > contenido = archivos [profundidad]->archivos; 
		if (contenido.size() > 0){
			imprimirdirectorio()
		}
	}
	*/
	for (int c = 0; c < archivos.size();c++){
		for (int j = 0; j < espacios * 6;j++){
			cout << " ";
		}
		cout << archivos [c]->toString(); 
		cout <<endl; 
		Directorio* actual;
		if (dynamic_cast < Directorio*> (archivos [c])){
			actual = archivos [c];
			actual->imprimirdirectorio(espacios + 1);
		}
		//archivos [c]->imprimirdirectorio(espacios + 1);
	}
}

void Directorio :: buscarporstring(string busqueda){
	for (int c = 0; c < archivos.size();c++){
		if (archivos[c]->nombre == busqueda){
			
		}
	}
}

void Directorio :: agregararchivo(FileSystemNode* archivo){
	archivos.push_back(archivo);
}

void Directorio :: agregardirectorio(FileSystemNode* directorio){
	archivos.push_back(directorio);
}


Directorio::~Directorio(){
	for(int c = 0; c < archivos.size(); c++) {
		if (archivos [c])
			delete archivos [c];   
	}
	archivos.clear();
}