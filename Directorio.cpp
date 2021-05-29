#include "Directorio.h"
#include "CPP.h"
#include "JPG.h"
#include "PPT.h"
#include <iostream>
#include <string>

using namespace std; 

Directorio::Directorio() : FileSystemNode(){
	
}

Directorio::Directorio(string n, string a, FileSystemNode* papa) : FileSystemNode(n, a, papa){
}

vector <FileSystemNode* > Directorio :: GETarchivos(){
	return archivos;
} 

void Directorio :: imprimirdirectorio(int espacios){
	for (int c = 0; c < archivos.size();c++){
		for (int j = 0; j < espacios * 6;j++){
			cout << " ";
		} 
		Directorio* actual;
		CPP* actualcpp; 
		JPG* actualjpg; 
		PPT* actualppt; 
		//bool v = false; 
		if (dynamic_cast < Directorio*> (archivos [c])){
			actual = dynamic_cast < Directorio*> (archivos [c]);
			//v = true;
			cout << actual->toString();
			cout <<endl;
			//espacios++;
			actual->imprimirdirectorio(espacios += 1);
			espacios--;
		}else if (dynamic_cast < CPP*> (archivos [c])){
			actualcpp = dynamic_cast <CPP*> (archivos [c]);
			cout << actualcpp->toString() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			//string n = to_string(valoracion);
			cout << " -lineas de condigo: " << to_string(actualcpp->GETlineas())+""<<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -errores: " << to_string(actualcpp->GETerrores())+""<<endl;
		}else if (dynamic_cast < JPG*> (archivos [c])){
			actualjpg = dynamic_cast < JPG*> (archivos [c]);
			cout << actualjpg->toString() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Resolucion: " << actualjpg->GETresolucion()  <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Largo: " << to_string(actualjpg->GETlargo()) <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Ancho: " << to_string(actualjpg->GETancho()) <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Flash: " << actualjpg->GETflash() <<endl; 
		}else if (dynamic_cast < PPT*> (archivos [c])){
			actualppt = dynamic_cast < PPT*> (archivos [c]);
			cout << actualppt->toString() << endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Animaciones: " << actualppt->GETanimaciones() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Slides: " << to_string(actualppt->GETslides()) <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Plantilla: " << to_string(actualppt->GETplantillas()) <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Titulo: " <<actualppt->GETtitulo() <<endl; 
		}
		//archivos [c]->imprimirdirectorio(espacios + 1);
		//if (v == true){
		//}
	}
}

void Directorio :: buscarporstring(string busqueda){
	bool v = false; 
	for (int c = 0; c < archivos.size();c++){
		Directorio* actual;
		CPP* actualcpp; 
		JPG* actualjpg; 
		PPT* actualppt; 
		if (dynamic_cast < Directorio*> (archivos [c])){
			actual = dynamic_cast < Directorio*> (archivos [c]);
			if (actual->nombre == busqueda){
				v = true; 
				actual->imprimirdirectorio(0);
			}
			//actual->imprimirdirectorio(espacios + 1);
		}else if (dynamic_cast < CPP*> (archivos [c])){
			actualcpp = dynamic_cast < CPP*> (archivos [c]);
			if (actualcpp->toString() == busqueda){
				v = true; 
				cout << actualcpp->toString() <<endl;
				cout << " -lineas de condigo: " << to_string(actualcpp->GETlineas())+""<<endl;
				cout << " -errores: " << to_string(actualcpp->GETerrores())+""<<endl;
			}
		}else if (dynamic_cast < JPG*> (archivos [c])){
			actualjpg = dynamic_cast < JPG*> (archivos [c]);
			if (actualjpg->toString() == busqueda){
				v = true; 
				cout << actualjpg->toString() <<endl;
			
			cout << " -Resolucion: " << actualjpg->GETresolucion()  <<endl;
			
			cout << " -Largo: " << to_string(actualjpg->GETlargo()) <<endl;
			
			cout << " -Ancho: " << to_string(actualjpg->GETancho()) <<endl;
			
			cout << " -Flash: " << actualjpg->GETflash() <<endl; 
			}
		}else if (dynamic_cast < PPT*> (archivos [c])){
			actualppt = dynamic_cast < PPT*> (archivos [c]);
			if (actualppt->toString() == busqueda){
				v = true; 
				cout << actualppt->toString() << endl;
			
			cout << " -Animaciones: " << actualppt->GETanimaciones() <<endl;
			
			cout << " -Slides: " << to_string(actualppt->GETslides()) <<endl;
			
			cout << " -Plantilla: " << to_string(actualppt->GETplantillas()) <<endl;
			
			cout << " -Titulo: " <<actualppt->GETtitulo() <<endl; 
			}
		}
	}
	if (v == false){
		cout << "No se han encontrado coincidencias. " <<endl;
	}
}

void Directorio :: agregararchivo(FileSystemNode* archivo){
	archivos.push_back(archivo);
}

void Directorio :: agregardirectorio(FileSystemNode* directorio){
	archivos.push_back(directorio);
}

string Directorio :: GETnombre(){
	return nombre;
}

string Directorio :: toString(){
	return "DIRECTORIO: "+nombre+" AUTOR: "+autor;
}


Directorio::~Directorio(){
	for(int c = 0; c < archivos.size(); c++) {
		if (archivos [c])
			delete archivos [c];   
	}
	archivos.clear();
}