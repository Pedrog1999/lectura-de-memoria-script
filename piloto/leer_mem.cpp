#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

HWND hwnd;
DWORD pid;
HANDLE hp;

uintptr_t NICK = 0x04FA33F9;

int main()
{
	hwnd = FindWindow (0, L"Counter-Strike");
	GetWindowThreadProcessId (hwnd, &pid);
	// acá se puede hacer un cout << el pid es << pid << endl;
	// se puede comprobar desde el administrador de tareas;

	hp = OpenProcess(PROCESS_ALL_ACCESS, true, pid);

	// acá ya se precisa de un ejecutable que permita traer datos de memoria, yo uso Cheat Engine;
	// buscamos un string que puede ser el nombre (IdUsuario);
	// buscamos la dirección de memoria que contenga ese texto;
	// lo mejor es hacerlo en una dirección estática, pero para probar con una dinámica es válido;
	// en este punto creamos la variable global que nos va a permitir guardar el dato de esa dirección de memoria;
	// uintptr_t NICK = 0x con el "0x" luego de la variable, damos a entender que lo que le sigue, es una direccion de memoria;

	char buffer_txt[255];

	ReadProcessMemory(hp, (LPBYTE)(NICK), &buffer_txt, sizeof(buffer_txt), 0); //acá la funcion ReadProcessMemory lee el contenido de NICK y con & lo guardamos en buffer_txt y con sizeoff le pasamos el tamaño;
	cout << "Mi nick:" << buffer_txt << endl; // aca lo mostramos por pantalla;
}