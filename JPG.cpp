#include "JPG.h"

JPG::JPG() : Archivo(){

}

JPG::JPG(string n, string a, FileSystemNode* papa, bool conflash, string resol, double larg, double anch) : Archivo(n, a, papa){
	flash = conflash;
	resolucion = resol;
	largo = larg;
	ancho = anch;
}

string JPG :: GETresolucion(){
	return resolucion;
}

double JPG :: GETlargo(){
	return largo;
}

double JPG :: GETancho(){
	return ancho;
}

bool JPG :: GETflash(){
	return flash;
}

string JPG :: toString(){
	return nombre;
}

