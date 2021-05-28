#include "Directorio.h"
#include "CPP.h"
#include "JPG.h"
#include "PPT.h"
#include <iostream>

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
		cout << archivos [c]->toString(); 
		cout <<endl; 
		Directorio* actual;
		CPP* actualcpp; 
		JPG* actualjpg; 
		PPT* actualppt; 
		if (dynamic_cast < Directorio*> (archivos [c])){
			actual = dynamic_cast < Directorio*> (archivos [c]);
			actual->imprimirdirectorio(espacios + 1);
		}else if (dynamic_cast < CPP*> (archivos [c])){
			actualcpp = dynamic_cast <CPP*> (archivos [c]);
			cout << actualcpp->toString() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -lineas de condigo: " <<actualcpp->GETlineas()+""<<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -errores: " <<actualcpp->GETerrores()+""<<endl;
		}else if (dynamic_cast < JPG*> (archivos [c])){
			actualjpg = dynamic_cast < JPG*> (archivos [c]);
			cout << actualjpg->toString() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Resolucion: " <<actualjpg->GETresolucion()  <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Largo: " <<actualjpg->GETlargo() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Ancho: " <<actualjpg->GETancho() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Flash: " <<actualjpg->GETflash() <<endl; 
		}else if (dynamic_cast < PPT*> (archivos [c])){
			actualppt = dynamic_cast < PPT*> (archivos [c]);
			actualppt->toString();
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Resolucion: " <<actualjpg->GETresolucion()  <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Largo: " <<actualjpg->GETlargo() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Ancho: " <<actualjpg->GETancho() <<endl;
			for (int j = 0; j < espacios * 6;j++){
				cout << " ";
			}
			cout << " -Flash: " <<actualjpg->GETflash() <<endl; 
		}
		//archivos [c]->imprimirdirectorio(espacios + 1);
	}
}

void Directorio :: buscarporstring(string busqueda){
	for (int c = 0; c < archivos.size();c++){
		Directorio* actual;
		CPP* actualcpp; 
		JPG* actualjpg; 
		PPT* actualppt; 
		bool v = false; 
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
				actualcpp->toString();
			}
		}else if (dynamic_cast < JPG*> (archivos [c])){
			actualjpg = dynamic_cast < JPG*> (archivos [c]);
			if (actualjpg->toString() == busqueda){
				v = true; 
				actualjpg->toString();
			}
		}else if (dynamic_cast < PPT*> (archivos [c])){
			actualppt = dynamic_cast < PPT*> (archivos [c]);
			if (actualppt->toString() == busqueda){
				v = true; 
				actualppt->toString();
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

string Directorio :: toString(){
	return toString();
}


Directorio::~Directorio(){
	for(int c = 0; c < archivos.size(); c++) {
		if (archivos [c])
			delete archivos [c];   
	}
	archivos.clear();
}