#include "Flag.h"

static std::vector<Figure> flag;

static void createBackground()
{
	// Bottom part
	Figure figBackgroundBottom = {};
	figBackgroundBottom.drawMode = GL_TRIANGLE_FAN;
	figBackgroundBottom.vertices.push_back({ 0.0f, 0.0f, 0.0f });
	figBackgroundBottom.vertices.push_back({ 0.0f, WINDOW_HEIGHT / 2, 0.0f });
	figBackgroundBottom.vertices.push_back({ WINDOW_WIDTH, WINDOW_HEIGHT / 2, 0.0f });

	figBackgroundBottom.vertices.push_back({ WINDOW_WIDTH, WINDOW_HEIGHT / 2, 0.0f });
	figBackgroundBottom.vertices.push_back({ WINDOW_WIDTH, 0.0f, 0.0f });
	figBackgroundBottom.vertices.push_back({ 0.0f, 0.0f, 0.0f });
	for (int i = 0; i < figBackgroundBottom.vertices.size(); i++)
	{
		figBackgroundBottom.colors.push_back(COLOR_LIGHT_BLUE);
	}
	createFigureVAO(&figBackgroundBottom);
	flag.push_back(figBackgroundBottom);

	// Top part
	Figure figBackgroundTop = {};
	figBackgroundTop.drawMode = GL_TRIANGLE_FAN;
	figBackgroundTop.vertices.push_back({ 0.0f, WINDOW_HEIGHT / 2, 0.0f });
	figBackgroundTop.vertices.push_back({ 0.0f, WINDOW_HEIGHT, 0.0f });
	figBackgroundTop.vertices.push_back({ WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f });

	figBackgroundTop.vertices.push_back({ WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f });
	figBackgroundTop.vertices.push_back({ WINDOW_WIDTH, WINDOW_HEIGHT / 2, 0.0f });
	figBackgroundTop.vertices.push_back({ 0.0f, WINDOW_HEIGHT / 2, 0.0f });
	for (int i = 0; i < figBackgroundTop.vertices.size(); i++)
	{
		figBackgroundTop.colors.push_back(COLOR_PURE_WHITE);
	}
	createFigureVAO(&figBackgroundTop);
	flag.push_back(figBackgroundTop);
}

void buildFlag()
{
	// background
	createBackground();
}

void drawFlag()
{
	for (int i = 0; i < flag.size(); i++)
	{
		drawFigure(flag.at(i));
	}
}