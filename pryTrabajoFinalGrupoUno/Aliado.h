#pragma once
#include "Personaje.h"
// Segun los requisitos del hito 2, el aliiado debe aparecer invisible
// el jugador puede presionar la barra de espacio para revelar al aliado
enum SpriteAliado {
	aCaminarDerecha,
	aCaminarIzquierda,
	aCaminarArriba,
	aCaminarAbajo
};
class Aliado: public Personaje
{
private:
	SpriteAliado movimiento;
public:
	Aliado(int x_a, int y_a, System::Drawing::Bitmap^ img) {
		x = x_a;
		y = y_a;
		dx = dy = 0;
		ancho = img->Width / 27;//Cantidad de fotogramas horizontales
		alto = img->Height / 5;//Cantidad de fotogramas verticales
		movimiento = aCaminarAbajo;
	};
	void aMostrar(System::Drawing::Graphics^ g, System::Drawing::Bitmap^ img) {
		System::Drawing::Rectangle corte = System::Drawing::Rectangle(IDx * ancho, movimiento * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, System::Drawing::GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());

		if (movimiento >= eCaminarDerecha && movimiento <= eCaminarAbajo) {
			// Cantidad de fotogramas en la imagen
			// Cantidad regular: 9
			// Fotogramas en "testing5_32_alt2": 27
			IDx = (IDx + 1) % 27;
		}
	}
	void aMover(System::Drawing::Graphics^ g) {
		if (x == 120 && y == 120) {
			dx = 8; dy = 0;
		}
		if (x == 200 && y == 120) {
			dx = 0; dy = 8; 
		}
		if (x == 200 && y == 140) {
			dx = -8; dy = 0; 
		}
		if (x == 140 && y == 180) {
			dx = 0; dy = -8; 
		}

		if (dx < 0) {
			movimiento = aCaminarIzquierda;
		}
		else if (dx > 0) {
			movimiento = aCaminarDerecha;
		}
		else if (dy < 0) {
			movimiento = aCaminarArriba;
		}
		else if (dy > 0) {
			movimiento = aCaminarAbajo;
		}

		x += dx;
		y += dy;
	}
};
class Aliados {
	vector<Aliado*> aliados;
public:
	Aliados(int x_a, int y_a, System::Drawing::Bitmap^ img, int cant) {
		for (int i = 0; i < cant; i++) {
			aliados.push_back(new Aliado(x_a, y_a, img));
		}
	};
	~Aliados() {
		for each (Aliado * A in aliados) {
			delete A;
		}
	};
	bool aColision(System::Drawing::Rectangle obj) {
		for each (Aliado * A in aliados) {
			if (A->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}
	void mover(System::Drawing::Graphics^ g) {
		for each (Aliado * A in aliados)
			A->aMover(g);
	}
	void mostrar(System::Drawing::Graphics^ g, System::Drawing::Bitmap^ img) {
		for each (Aliado * A in aliados)
			A->aMostrar(g, img);
	}
};