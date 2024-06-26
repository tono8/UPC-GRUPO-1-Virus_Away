#pragma once
#include "Enemigo.h"
enum SpriteEnemigo1 {
	eMovimiento1,
	eEliminado1
};
class Enemigo1 : public Enemigo {
public:
	SpriteEnemigo1 movimiento1;
	Enemigo1(System::Drawing::Bitmap^ img) {
		x = rand() % 700;
		y = rand() % 700;
		// dx = dy = rand() % (50 - 0,2 + 1) + 0.8;
		dx = dy = 2;
		ancho = img->Width / 31;//Cantidad de fotogramas horizontales
		alto = img->Height / 2;//Cantidad de fotogramas 
		movimiento1 = eMovimiento1;
	};
	SpriteEnemigo1 getMovimiento() {
		return movimiento1;
	}
	void setMovimiento(SpriteEnemigo1 value) {
		movimiento1 = value;
	}
	void eMostrar1(System::Drawing::Graphics^ g, System::Drawing::Bitmap^ img)
	{
		System::Drawing::Rectangle corte = System::Drawing::Rectangle(IDx * ancho, movimiento1 * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, System::Drawing::GraphicsUnit::Pixel);
		//g->DrawRectangle(System::Drawing::Pens::Black, Area());
		g->DrawRectangle(System::Drawing::Pens::Magenta, Hitbox());

		if (movimiento1 == eMovimiento1) {
			// Cantidad de fotogramas en la imagen
			// Cantidad regular: 9
			// Fotogramas en "testing2_32_alt2": 27
			// Fotogramas en "testing2_32_alt3": 78
			// Fotogramas en "testing2_64_alt3": 78
			// Fotogramas en "enemigo1_v1_64_alt1": 3
			// Fotogramas en "enemigo1_v2_64": 31
			// Fotogramas en "enemigo1_v4_64": 31
			IDx = (IDx + 1) % 31;
		}
		else if (movimiento1 == eEliminado1) {
			// Cantidad de fotogramas en la imagen
			// Cantidad regular: 9
			// Fotogramas en "testing2_32_alt2": 27
			// Fotogramas en "testing2_64_alt3": 27
			// Fotogramas en "enemigo1_v1_64_alt1": 4
			// Fotogramas en "enemigo1_v2_64": 12
			// Fotogramas en "enemigo1_v4_64": 27
			//IDx = IDx + 1 % 27;
			IDx;
		}
	}
	void eMover1(System::Drawing::Graphics^ g, int pX_j, int pY_j) {
		// Algoritmo para perseguir al jugador
		// Se obtiene la posicion del jugador
		// ## Obtenido gracias al taller de asesoria #13
		x_j = pX_j;
		y_j = pY_j;
		// Moviendo el enemigo atravez el
		// Eje X
		if (x == x_j) {
			x += 0;
		}
		else if (x < x_j) {
			x += dx;
		}
		else if (x > x_j) {
			x -= dx;
		}
		// Moviendo el enemigo atravez el
		// Eje y
		if (y == y_j) {
			y += 0;
		}
		else if (y < y_j) {
			y += dy;
		}
		else if (y > y_j) {
			y -= dy;
		}
	}
};
class Enemigos1
{
	vector<Enemigo1*> enemigos1;
private:

public:
	Enemigos1(System::Drawing::Bitmap^ img, int cant) {
		for (int i = 0; i < cant; i++) {
			enemigos1.push_back(new Enemigo1(img));
		}
	};
	int eSize() {
		return enemigos1.size();
	}
	Enemigo1* getP(int posicion) {
		return enemigos1[posicion];
	}
	~Enemigos1() {
		for each (Enemigo1 * E1 in enemigos1) {
			delete E1;
		}
	};
	void eEliminar(int posicion) {
		enemigos1.erase(enemigos1.begin() + posicion);
	}
	void eLimpiar(System::Drawing::Rectangle rectangulo) { // Se llama limpiar por el contexto de la historia del juego
		for (int i = 0; i < enemigos1.size(); i++)
		{
			Enemigo1* E1 = enemigos1[i];
			if (E1->Hitbox().IntersectsWith(rectangulo)) {
				E1->setDX(0);
				E1->setDY(0);
				E1->setMovimiento(eEliminado1);
			}
		}
	}
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