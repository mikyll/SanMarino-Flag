#include "Commons.h"

static unsigned int programId;
static glm::mat4 Projection;
static unsigned int MatProj, MatModel;

static void initShader()
{
	GLenum ErrorCheckValue = glGetError();

	char* vertexShader = (char*)"resources/shaders/vertexShader_C_M.glsl";
	char* fragmentShader = (char*)"resources/shaders/fragmentShader_C_M.glsl";

	programId = ShaderMaker::createProgram(vertexShader, fragmentShader);
	glUseProgram(programId);
}

static void init()
{
	Projection = glm::ortho(0.0f, float(WINDOW_WIDTH), 0.0f, float(WINDOW_HEIGHT));
	MatProj = glGetUniformLocation(programId, "Projection");
	MatModel = glGetUniformLocation(programId, "Model");

	buildFlag();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

static void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUniformMatrix4fv(MatProj, 1, GL_FALSE, value_ptr(Projection));

	glm::mat4 modelMatrix = glm::mat4(1.0);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(modelMatrix));

	drawFlag();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 0);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("San Marino Flag");

	glutDisplayFunc(drawScene);

	glewExperimental = GL_TRUE;
	glewInit();

	initShader();
	init();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutMainLoop();

	return 0;
}