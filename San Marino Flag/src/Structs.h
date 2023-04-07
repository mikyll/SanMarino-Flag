#pragma once

#include "Commons.h"

typedef struct {
	float x, y, z;
} Point3D;

typedef struct {
	float r, g, b, a;
} ColorRGBA;

typedef struct {
	int id;
	GLuint VAO;
	GLuint VBO_Geom;
	GLuint VBO_Col;
	std::vector<Point3D> vertices;
	std::vector<ColorRGBA> colors;
	int drawMode;
	float sizePoints;
	float widthLines;
} Figure;