#pragma once

#include <iostream>
#include <inttypes.h>

class TCalendario {

	friend 
	std::ostream & operator << (std::ostream &, const TCalendario &);

private:

    int _dia;
    int _mes;
    int _anyo;

    char* _mensaje;


public:

    inline TCalendario ();
    TCalendario (const int, const int, const int, const char*);
    TCalendario (const TCalendario &);
    inline ~TCalendario ();
    TCalendario & operator = (const TCalendario&);

    bool ModFecha (int, int, int);
    bool ModMensaje (char *);

    bool operator == (const TCalendario &) const;
    bool operator != (const TCalendario &) const;
    bool operator > (const TCalendario &) const;
    bool operator < (const TCalendario &) const;

    TCalendario operator--(int);
    TCalendario & operator--();
    
    TCalendario operator+(int) const;
    TCalendario operator-(int) const;
    
    TCalendario operator++(const int);
    TCalendario & operator++();

    int Dia()  const {return _dia;};
    int Mes()  const {return _mes;};
    int Anyo() const {return _anyo;};
    char* Mensaje() const {return _mensaje;};
	
	// establece una fecha a la minim
	void Vacio ();
	
    // dias que tiene el mes
    int8_t diasMes (const int);
    // devuelve true si la fecha es correcta
    bool comprobarFecha (const int, const int, const int);
    // devuelve 1 si el mesanje es mayor
    bool mayorMensaje (const char*, const char*) const;
    // devuelve 1 si la fecha es mayor
    bool mayorFecha (const TCalendario&, const TCalendario&) const;
};

TCalendario::TCalendario () :
	_dia(1),
	_mes(1), 
	_anyo(1900),
	_mensaje(nullptr)
{}

TCalendario::~TCalendario ()
{
	_dia = 1;
	_mes = 1;
	_anyo = 1900;
	_mensaje = nullptr;
}
