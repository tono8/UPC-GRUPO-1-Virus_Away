#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	//Indice de direccion
	int IDx;//se declara para mostrar fotogramas de acuerdo al indice
public:
	Entidad() {
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	};
	void setDX(int value)
	{
		dx = value;
	}
	void setDY(int value)
	{
		dy = value;
	}
	System::Drawing::Rectangle Area()
	{
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}
	System::Drawing::Rectangle NextArea()
	{
		return System::Drawing::Rectangle(x + dx, y + dy, ancho, alto);
	}
	virtual void mover(System::Drawing::Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void mostrar(System::Drawing::Graphics^ g, System::Drawing::Bitmap^ img)
	{
		g->FillRectangle(System::Drawing::Brushes::Black, Area());
	}
};