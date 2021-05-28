#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "FileSystemNode.h"

class Archivo : public FileSystemNode{
	
	public:
		Archivo();
		virtual string toString() = 0;
};

#endif