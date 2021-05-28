#ifndef FILESYSTEMNODE_H
#define FILESYSTEMNODE_H
#include <string>

using namespace std; 

class FileSystemNode {
	
	protected: 
	FileSystemNode* padre; 
	string nombre; 
	string autor; 
	
	public:
		FileSystemNode();
		FileSystemNode(string, string, FileSystemNode* );
		virtual string toString() = 0; 
		~FileSystemNode();
	
};

#endif