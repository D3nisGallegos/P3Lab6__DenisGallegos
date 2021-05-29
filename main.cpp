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
				
				cout << "-------FINAL AGREGAR ARCHIVO------" <<endl; 
				break; 
				}
			case 3: 
				{
				cout << "-------AGREGAR DIRECTORIO------" <<endl; 
				
				cout << "-------FINAL AGREGAR DIRECTORIO------" <<endl; 	
				break; 
				}
			case 4:
				{
				cout << "-------IMPRIMIR POR NOMBRE------" <<endl; 	
			
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


