#include "FileSystem.h"
#include <vector>
#include <string>

FileSystem::FileSystem(){

}

FileSystem::FileSystem(Directorio* dir){
	root = dir;
}

Directorio* FileSystem :: GETroot(){
	return root;
}

FileSystem::~FileSystem(){
	delete root; 
}