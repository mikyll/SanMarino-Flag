#include "Figure.h"

void createFigureVAO(Figure* fig)
{
	glGenVertexArrays(1, &fig->VAO);
	glBindVertexArray(fig->VAO);
	// Genero, rendo attivo, riempio il VBO della geometria dei vertici
	glGenBuffers(1, &fig->VBO_Geom);
	glBindBuffer(GL_ARRAY_BUFFER, fig->VBO_Geom);
	glBufferData(GL_ARRAY_BUFFER, fig->vertices.size() * sizeof(Point3D), fig->vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	// Genero, rendo attivo, riempio il VBO dei colori
	glGenBuffers(1, &fig->VBO_Col);
	glBindBuffer(GL_ARRAY_BUFFER, fig->VBO_Col);
	glBufferData(GL_ARRAY_BUFFER, fig->colors.size() * sizeof(ColorRGBA), fig->colors.data(), GL_STATIC_DRAW);
	// Adesso carico il VBO dei colori nel layer 2
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);
}

void drawFigure(Figure fig)
{
	glBindVertexArray(fig.VAO);
	glDrawArrays(fig.drawMode, 0, fig.vertices.size());
	glBindVertexArray(0);
}