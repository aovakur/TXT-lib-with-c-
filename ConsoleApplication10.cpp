#include "stdafx.h"
#include "TXLib.h"

class Circle
{
public:
	Circle(int x, int y, int v, int dx, int dy, int r)
	{
		xCoord = x;
		yCoord = y;
		speed = v;
		dirX = dx;
		dirY = dy;
		rad = r;
	}

	void Move();
	void Draw();

private:
	int x;
	int y;
	int s;
	int v;
	int dx;
	int dy;
	int r;
	int xCoord;
	int yCoord;
	int speed;
	int dirX;
	int dirY;
	int rad;
};

void Circle::Draw()
{
	txSetColor(TX_WHITE);
	txSetFillColor(TX_BLACK);
	txCircle(xCoord, yCoord, rad);
}

void Circle::Move()
{
	xCoord += dirX * speed;
	yCoord += dirY * speed;

	if (xCoord - rad < 0 || xCoord + rad > 500)
	{
		dirX = -dirX;
	}

	if (yCoord - rad <=0 || yCoord + rad >500)
	{
		dirY = -dirY;
	}

	Draw();
	
}

int main()
{
	txCreateWindow(500, 500);
	Circle A(300, 300, 10, 1, 1, 20);
	Circle C(300, 100, 5, 1, 1, 20);
	Circle D(50, 100, 5, 1, 1, 20);

	while (true)
	{
		txClear();
		A.Move();
		C.Move();
		D.Move();
		txSleep(100);
	}
}
