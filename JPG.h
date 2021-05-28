#ifndef JPG_H
#define JPG_H

#include "Archivo.h"

class JPG : public Archivo{
	
	protected:
	bool flash; 
	string resolucion; 
	double largo; 
	double ancho; 
	
	public:
		JPG();
		JPG(string, string, FileSystemNode*, bool, string, double, double);
		bool GETflash();
		string GETresolucion();
		double GETlargo();
		double GETancho();
		virtual string toString();
		

};

#endif