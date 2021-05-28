#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include <string>
#include <vector>
#include "FileSystemNode.h"

using namespace std; 

class Directorio : public FileSystemNode {
	
	protected: 
	vector <FileSystemNode* > archivos;
	
	
	public:
		Directorio();
		Directorio(string, string, FileSystemNode*);
		vector <FileSystemNode* > GETarchivos();
		void agregararchivo(FileSystemNode* );
		void agregardirectorio(FileSystemNode* );
		void imprimirdirectorio(int );
		void buscarporstring(string );
		~Directorio();
};

#endif