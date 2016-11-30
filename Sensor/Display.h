#pragma once

typedef struct Vector2 {
	float x;
	float y;
}Vector2;


typedef struct Vector3 {
	float x;
	float y;
	float z;
}Vector3;


typedef struct Color {
	float r;
	float g;
	float b;
	float a;
	Color(float r, float g, float b, float a):
		r(r),g(g), b(b),a(a)	
	{}

	Color(unsigned int hex) :
		r((hex&0x000000ff)/255.0f),
		g(((hex>>8)&0x000000ff)/255.0f),
		b(((hex >> 16) & 0x000000ff) / 255.0f),
		a(((hex >> 24) & 0x000000ff) / 255.0f)

	{}
	
}Color;


class Display
{
protected:
	const char* windowName;
	int width;
	int height;

public:
	Display();
	~Display();
	static int init();
	void drawPoints(Vector2* vertices, int count, float size);
	void drawLines(Vector2* vertices, int count);
	void drawText(Vector2* position, const char* text, int length);

	static void setBackgroundColor(Color color);
	static void setForegroundColor(Color color);

	virtual void run();
	virtual void onRender();
};

