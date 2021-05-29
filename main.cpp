#include <iostream>
#include "FileSystemNode.h"
#include "FileSystem.h"
#include "Directorio.h"
#include "Archivo.h"
#include "CPP.h"
#include "JPG.h"
#include "PPT.h"
#include <string>
#include <cstring>
#include <vector>

using namespace std; 

int menu();

int main(int argc, char** argv) {
	FileSystem* fs = new FileSystem(new Directorio("ROOT", "Denis", NULL));
	Directorio* carpeta1 = new Directorio("Carpeta1", "Denis", fs->GETroot());
	Directorio* carpeta2 = new Directorio("Carpeta2", "Denis", carpeta1);
	Directorio* carpeta3 = new Directorio("Carpeta3", "Denis", carpeta2);
	fs->GETroot()->agregardirectorio(carpeta1);
	carpeta1->agregardirectorio(carpeta2);
	carpeta2->agregardirectorio(carpeta3);
	
	carpeta1->agregararchivo(new CPP("ArchivoCPP1", "DenisELprogramador", carpeta1, 300, 0));
	carpeta1->agregararchivo(new JPG("ArchivoJPG1", "DenisELgrafico", carpeta1, true, "1920x1080", 1920, 1080));
	carpeta1->agregararchivo(new PPT("ArchivoPPT1", "DenisELlicensiado", carpeta1, "tarea1", 5, 10, false));
	
	carpeta2->agregararchivo(new CPP("ArchivoCPP2", "DenisELprogramador", carpeta2, 600, 0));
	carpeta2->agregararchivo(new JPG("ArchivoJPG2", "DenisELgrafico", carpeta2, true, "1920x1080", 1920, 1080));
	carpeta2->agregararchivo(new PPT("ArchivoPPT2", "DenisELlicensiado", carpeta2, "tarea2", 5, 10, false));
	
	carpeta3->agregararchivo(new CPP("ArchivoCPP3", "DenisELprogramador", carpeta3, 1000, 0));
	carpeta3->agregararchivo(new JPG("ArchivoJPG3", "DenisELgrafico", carpeta3, true, "1920x1080", 1920, 1080));
	carpeta3->agregararchivo(new PPT("ArchivoPPT3", "DenisELlicensiado", carpeta3, "tarea3", 5, 10, false));
	int opcion = menu();
	while (opcion != 5){
		switch (opcion){
			case 1:
				{
				string titulo = "", director = "", genero = ""; 
				cout << "-------IMPRIMIR FILE SYSTEM------" <<endl; 
				fs->GETroot()->imprimirdirectorio(0);
				cout << "-------FINAL IMPRIMIR FILE SYSTEM------" <<endl; 
				break; 
				}
			case 2:
				{
				cout << "-------AGREGAR ARCHIVO------" <<endl; 
				int opcion2 = 0; 
				while (opcion2 != 4){
					cout << "--------MENU--------" <<endl;
					cout << " 1) Agregar CPP. "<<endl;
					cout << " 2) Agregar JPG. " <<endl; 
					cout << " 3) Agregar PPT. " <<endl; 
					cout << " 4) Salir." <<endl; 
					cout << "---------------------" <<endl; 
					cout << " Ingrese la opcion: " <<endl; 
					cin>> opcion2; 
					cin.ignore();
					if (opcion2 == 4){
						cout << "Ha elegido salir del menu. " <<endl; 
					}else if (opcion2 > 0 && opcion2 <4){
						break; 
					}
				}
				string autor = "";
				string titulo = "";
				cout << "Ingrese el autor del archivo: " <<endl; 
				getline(cin, autor); 
				cout << "Ingrese el titulo del archivo: " <<endl; 
				getline(cin, titulo);
				switch (opcion2){
						case 1:
							{
							int lineas; 
							int errores; 
							bool validar = false; 
							while (validar == false){
								cout << "Ingrese la cantidad de lineas: " <<endl; 
								cin >> lineas; 
								cin.ignore();
								cout << "Ingrese la cantidad de errores: " <<endl; 
								cin >> errores; 
								cin.ignore();
								if (lineas > 0 && errores >= 0){
									validar = true;
								}else {
									cout << "datos invalidos." <<endl;
								}
							}
							fs->GETroot()->agregararchivo(new CPP(titulo, autor, fs->GETroot(), lineas, errores));
							break;	
							}
						case 2:
							{
							double largo; 
							double ancho; 
							int flash; 
							string resolucion = "";
							bool validar = false; 
							while (validar == false){
								cout << "Ingrese si tiene flash (1/0): " <<endl; 
								cin >> flash;
								cin.ignore();
								cout << "Ingrese la resolucion: " <<endl; 
								getline(cin, resolucion);
								cout << "Ingrese el largo: " <<endl; 
								cin >> largo; 
								cin.ignore();
								cout << "Ingrese el ancho: " <<endl; 
								cin >> ancho; 
								cin.ignore();
								if (largo > 0 && ancho > 0 && (flash == 0 || flash == 1)){
									validar = true;
								}else {
									cout << "datos invalidos." <<endl;
								}
							}
							if (flash = 0){
								validar = false; 
							}else {
								validar = true; 
							}
							fs->GETroot()->agregararchivo(new JPG(titulo, autor, fs->GETroot(), validar, resolucion, largo, ancho));
							break; 	
							}	
						case 3:
							{
							double plantilla; 
							double slides; 
							int flash; 
							string titulo = "";
							bool validar = false; 
							while (validar == false){
								cout << "Ingrese si tiene animaciones (1/0): " <<endl; 
								cin >> flash;
								cin.ignore();
								cout << "Ingrese el titulo: " <<endl; 
								getline(cin, titulo);
								cout << "Ingrese la plantilla: " <<endl; 
								cin >> plantilla; 
								cin.ignore();
								cout << "Ingrese las slides: " <<endl; 
								cin >> slides; 
								cin.ignore();
								if (slides > 0 && plantilla > 0 && (flash == 0 || flash == 1)){
									validar = true;
								}else {
									cout << "datos invalidos." <<endl;
								}
							}
							if (flash = 0){
								validar = false; 
							}else {
								validar = true; 
							}
							fs->GETroot()->agregararchivo(new PPT(titulo, autor, fs->GETroot(), titulo, slides, plantilla, validar));
							break;
							}
				}//Fin del switch
				cout << "-------FINAL AGREGAR ARCHIVO------" <<endl; 
				break; 
				}
			case 3: 
				{
					string autor = "";
					string titulo = "";
				cout << "-------AGREGAR DIRECTORIO------" <<endl; 
				cout << "Ingrese el autor del directorio: " <<endl; 
				getline(cin, autor); 
				cout << "Ingrese el nombre del titulo: " <<endl; 
				getline(cin, titulo);
				fs->GETroot()->agregardirectorio(new Directorio(titulo, autor, fs->GETroot()));
				cout << "-------FINAL AGREGAR DIRECTORIO------" <<endl; 	
				break; 
				}
			case 4:
				{
				string buscar = "";
				cout << "-------IMPRIMIR POR NOMBRE------" <<endl; 	
				cout << "Ingrese el nombre de busqueda: " <<endl; 
				getline(cin, buscar);
				fs->GETroot()->buscarporstring(buscar);
				cout << "-------FINAL IMPRIMIR POR NOMBRE------" <<endl; 	
				break; 
				}
		}//Fin del switch.
		cout <<endl; 
		opcion = menu(); 
	}//Fin del while.
	return 0;
}

int menu(){
	int opcion = 0; 
	while (opcion != 5){
		cout << "--------MENU--------" <<endl;
		cout << " 1) Imprimir FileSystem. "<<endl;
		cout << " 2) Agregar archivo. " <<endl; 
		cout << " 3) Agregar directorio. " <<endl; 
		cout << " 4) Imprimir por nombre." <<endl; 
		cout << " 5) Salir." <<endl; 
		cout << "---------------------" <<endl; 
		cout << " Ingrese la opcion: " <<endl; 
		cin>> opcion; 
		cin.ignore();
		if (opcion == 5){
			cout << "Ha elegido salir del sistema. " <<endl; 
		}else if (opcion > 0 && opcion <5){
			break; 
		}
	}
	return opcion; 
}


