#pragma once

class TCalendario {

	private:
	
	int _dia;
	int _mes;
	int _anyo;

	char* _mensaje;


	public:
	
	//Constructor por defecto: inicializa dia, mes y anyo a 1/1/1900 y mensaje a NULL
	inline TCalendario ();
	//Constructor que inicializa calendario con parámetros pasados
	TCalendario (int, int, int, char*);
	//Constructor copia
	inline TCalendario (TCalendario &);
	//Destructor
	inline ~TCalendario ();
	// Sobrecarga del operador asignación
	// TCalendario & operator = (TCalendario &);
	
	// Sobrecarga del operador igualdad;
	bool operator == (const TCalendario &);
	// Sobrecarga del operador desigualdad;
	// bool operator != (TCalendario &);
	// Sobrecarga del operador >; (ver ACLARACIÓN sobre ORDENACIÓN)
	bool operator > (const TCalendario &);	
	// Sobrecarga del operador <; (ver ACLARACIÓN sobre ORDENACIÓN)
	bool operator < (const TCalendario &);
	
	// Devuelve el día del calendario;
	int Dia()  const {return _dia;};
	// Devuelve el mes del calendario;
	int Mes()  const {return _mes;};
	// Devuelve el año del calendario;
	int Anyo() const {return _anyo;};
	// Devuelve el mensaje del calendario;
	char* Mensaje() const {return _mensaje;};

	
	// Sobrecarga del operador salida
	//friend ostream & operator << (ostream &, TCalendario &);
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
