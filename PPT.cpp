#include "PPT.h"

PPT::PPT() : Archivo(){

}

PPT:: PPT(string n, string a, FileSystemNode* papa, string tit, int sli, int plant, bool anim) : Archivo(n, a, papa){
	titulo = tit;
	slides = sli;
	plantilla = plant;
	animaciones = anim;
}

string PPT :: GETtitulo(){
	return titulo;
}

int PPT :: GETslides(){
	return slides;
}

int PPT :: GETplantillas(){
	return plantilla;
}

bool PPT :: GETanimaciones(){
	return animaciones;
}

string PPT :: toString(){
	return nombre;
}