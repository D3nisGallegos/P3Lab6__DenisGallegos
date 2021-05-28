#ifndef PPT_H
#define PPT_H

#include "Archivo.h"

class PPT : public Archivo{
	
	protected:
	string titulo; 
	int slides; 
	int plantilla; 
	bool animaciones;
		
	public:
		PPT();
		PPT(string, string, FileSystemNode*, string, int, int, bool);
		string GETtitulo();
		int GETslides();
		int GETplantillas();
		bool GETanimaciones(); 
		virtual string toString();
};

#endif