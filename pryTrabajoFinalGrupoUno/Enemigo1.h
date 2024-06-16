#pragma once
#include "Enemigo.h"
class Enemigo1 : public Enemigo {
public:
	Enemigo1(int x_e1, int y_e1, System::Drawing::Bitmap^ img) {
		x = x_e1;
		y = y_e1;
		x = rand() % 700;
		y = rand() % 700;
		dx = dy = rand() % 2;
		ancho = img->Width / 78;//Cantidad de fotogramas horizontales
		alto = img->Height / 5;//Cantidad de fotogramas verticales
	};
	void eMostrar1(System::Drawing::Graphics^ g, System::Drawing::Bitmap^ img)
	{
		System::Drawing::Rectangle corte = System::Drawing::Rectangle(IDx * ancho, movimiento * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, System::Drawing::GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());

		if (movimiento >= eCaminarDerecha && movimiento <= eCaminarAbajo)
			// Cantidad de fotogramas en la imagen
			// Cantidad regular: 9
			// Fotogramas en "testing2_32_alt2": 27
			// Fotogramas en "testing2_32_alt3": 78
			IDx = (IDx + 1) % 78;
		else if (movimiento == eEliminado)
			// Cantidad de fotogramas en la imagen
			// Cantidad regular: 9
			// Fotogramas en "testing2_32_alt2": 27
			IDx = IDx + 1 % 27;
	}
	void eMover1(System::Drawing::Graphics^ g, int pX_j, int pY_j) {
		x_j = pX_j;
		y_j = pY_j;
		// Eje X
		if (x == x_j) {
			x += 0;
		}
		else if (x < x_j) {
			x += dx;
			IDx++;
			movimiento = eCaminarDerecha;
		}
		else if (x > x_j) {
			x -= dx;
			IDx++;
			movimiento = eCaminarIzquierda;
		}
		// Eje y
		if (y == y_j) {
			y += 0;
		}
		else if (y < y_j) {
			y += dy;
			IDx++;
			movimiento = eCaminarAbajo;
		}
		else if (y > y_j) {
			y -= dy;
			IDx++;
			movimiento = eCaminarArriba;
		}

		//if (dx < 0) {
		//	movimiento = eCaminarIzquierda;
		//}
		//else if (dx > 0) {
		//	movimiento = eCaminarDerecha;
		//}
		//else if (dy < 0) {
		//	movimiento = eCaminarArriba;
		//}
		//else if (dy > 0) {
		//	movimiento = eCaminarAbajo;
		//}
	}
};
class Enemigos1
{
	vector<Enemigo1*> enemigos1;
private:

public:
	Enemigos1(int x_e1, int y_e1, System::Drawing::Bitmap^ img, int cant) {
		for (int i = 0; i < cant; i++) {
			enemigos1.push_back(new Enemigo1(x_e1, y_e1, img));
		}
	};
	~Enemigos1() {
		for each (Enemigo1 * E1 in enemigos1) {
			delete E1;
		}
	};
	bool eColision(System::Drawing::Rectangle obj) {
		for each (Enemigo1 * E1 in enemigos1) {
			if (E1->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}
	void mover(System::Drawing::Graphics^ g, int pX_j, int pY_j) {
		for each (Enemigo1 * E1 in enemigos1)
			E1->eMover1(g, pX_j, pY_j);
	}
	void mostrar(System::Drawing::Graphics^ g, System::Drawing::Bitmap^ img) {
		for each (Enemigo1 * E1 in enemigos1)
			E1->eMostrar1(g, img);
	}
};