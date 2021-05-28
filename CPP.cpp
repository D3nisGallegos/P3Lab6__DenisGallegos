#include "CPP.h"
#include <cstring>

CPP::CPP() : Archivo(){

}

CPP::CPP(string n, string a, FileSystemNode* papa, int x, int y) : Archivo(n, a, papa){
	lineas = x; 
	errores = y;
}

int CPP :: GETlineas(){
	return lineas;
}

int CPP :: GETerrores(){
	return errores;
}

string CPP :: toString(){
	return nombre; 
}

