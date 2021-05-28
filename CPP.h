#ifndef CPP_H
#define CPP_H

#include "Archivo.h"

class CPP : public Archivo{
	
	protected:
	int lineas; 
	int errores; 
	
	public:
		CPP();
		CPP(string, string, FileSystemNode*, int, int);
		int GETlineas();
		int GETerrores();
		virtual string toString();
};

#endif