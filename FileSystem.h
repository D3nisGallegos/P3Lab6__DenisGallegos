#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "FileSystemNode.h"
#include "Directorio.h"

class FileSystem{
	
	protected:
	Directorio* root; 
		
	public:
		FileSystem();
		FileSystem(Directorio* );
		Directorio* GETroot();
		~FileSystem();
};

#endif