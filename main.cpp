#include <iostream>

using namespace std; 

int main(int argc, char** argv) {
	HTHPlus* cine = new HTHPlus();
	int opcion = menu();
	while (opcion != 8){
		switch (opcion){
			case 1:
				{
				string titulo = "", director = "", genero = ""; 
				cout << "-------AGREGAR------" <<endl; 
				
				cout << "-------FINAL AGREGAR------" <<endl; 
				break; 
				}
			case 2:
				{
				cout << "-------MODIFICAR------" <<endl; 
				
				cout << "-------FINAL MODIFICAR------" <<endl; 
				break; 
				}
			case 3: 
				{
				cout << "-------ELIMINAR------" <<endl; 
				
				cout << "-------FINAL ELIMINAR------" <<endl; 	
				break; 
				}
			case 4:
				{
				cout << "-------IMPRIMIR POR GENERO------" <<endl; 	
			
				cout << "-------FINAL IMPRIMIR POR GENERO------" <<endl; 	
				break; 
				}
			case 5:
				{
				string n = ""; 
				cout << "-------IMPRIMIR POR BUSQUEDA------" <<endl; 	
				
				cout << "-------FINAL POR BUSQUEDA------" <<endl; 	
				break; 
				}
			case 6:
				{
				cout << "-------IMPRIMIR POR VALORACION------" <<endl; 	
				
				cout << "-------FINAL IMPRIMIR POR VALORACION------" <<endl; 	
				break; 
				}
			case 7:
				{
				cout << "-------IMPRIMIR TODAS------" <<endl; 	
				
				cout << "-------FINAL IMPRIMIR TODAS------" <<endl; 	
				break; 
				}
		}//Fin del switch.
		cout <<endl; 
		opcion = menu(); 
	}//Fin del while.
	delete cine;
	return 0;
}

int menu(){
	int opcion = 0; 
	while (opcion != 8){
		cout << "--------MENU--------" <<endl;
		cout << " 1) Agregar pelicula. "<<endl;
		cout << " 2) Modificar pelicula. " <<endl; 
		cout << " 3) Eliminar pelicula. " <<endl; 
		cout << " 4) Imprimir por genero." <<endl; 
		cout << " 5) Imprimir por busqueda." <<endl; 
		cout << " 6) Imprimir por valoracion." <<endl;
		cout << " 7) Imprimir todas." <<endl;  
		cout << " 8) Salir." <<endl; 
		cout << "---------------------" <<endl; 
		cout << " Ingrese la opcion: " <<endl; 
		cin>> opcion; 
		cin.ignore();
		if (opcion == 8){
			cout << "Ha elegido salir del sistema. " <<endl; 
		}else if (opcion > 0 && opcion <= 7){
			break; 
		}
	}
	return opcion; 
}


