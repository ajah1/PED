#pragma once

#include "tcalendario.h"

#include <iostream>

class TVectorCalendario {

	private:

	TCalendario* _c;
	TCalendario _error;
	
	int _tamano;
		

	public:
	
	// Constructor por defecto
	inline TVectorCalendario();
	// Constructor a partir de un tamaño
	inline TVectorCalendario(int);
	// Constructor de copia
	TVectorCalendario(TVectorCalendario &);
	// Destructor
	inline ~TVectorCalendario();
	// Sobrecarga del operador asignación
	TVectorCalendario & operator=(TVectorCalendario &);
	
	// Sobrecarga del operador igualdad
	bool operator==(TVectorCalendario &);
	// Sobrecarga del operador desigualdad
	bool operator!=(TVectorCalendario &);
	
	// Sobrecarga del operador corchete (parte IZQUIERDA)
	TCalendario & operator[](int);
	// Sobrecarga del operador corchete (parte DERECHA)
	TCalendario operator[](int) const;
	
	// Tamaño del vector (posiciones TOTALES)
	int Tamano();
	// Cantidad de posiciones OCUPADAS (no vacías) en el vector
	int Ocupadas();
	
	// Devuelve true si existe el calendario en el vector
	bool ExisteCal(TCalendario &);
	// Mostrar mensajes de TCalendario, de fecha IGUAL O POSTERIOR a la pasada
	void MostrarMensajes(int,int,int);
	// REDIMENSIONAR el vectorde TCalendario
	bool Redimensionar(int);
	
	// Sobrecarga del operador salida
	friend std::ostream& operator<<(std::ostream&, TVectorCalendario&);
	
	
}

TVectorCalendario::TVectorCalendario () :
	_tamano(0),
	_c(nullptr)
{}

TVectorCalendario::TVectorCalendario (int size)
{
	if (size == 0)
	{
		_tamano = 0;
		_c = nullptr;
	}
	else
	{
		_tamano = size;
		_c = new TCalendario[size];
	}
}

TVectorCalendario::~TVectorCalendario ()
{
	_tamano = 0;

	if (_c != nullptr)
	{
		delete[] _c;
		_c = nullptr;
	}
}






















