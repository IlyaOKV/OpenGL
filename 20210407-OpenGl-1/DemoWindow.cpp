/*
 * DemoWindow.cpp
 *
 *  Created on: 13 апр. 2021 г.
 *      Author: grtq
 */

#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width,height)
{
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl() {
	glClearColor(0.2f, 0.4f, 0.7f, 1.0);
	glMatrixMode(GL_PROJECTION); // использование матрицы проекции
	gluPerspective (45.0, double(width()) / double(height()), 0.1, 20.0);
	/*                ^ угол обзора по вертикали
	 *                         ^ соотношение сторон экрана
	 * 															^ расстояние до ближней плоскости отсечения
	 * 																^ расстояние до дальней плоскости отсечения
	 */
	glMatrixMode(GL_MODELVIEW);
	// glPointSize(16.0f); размер точки
	// glLineWidth(10.0f); ширина линии
	glEnable(GL_DEPTH_TEST); //включение теста глубины
}

void CubeRender(){
	//Куб
		glBegin(GL_QUADS);
		glColor3d(1.0, 0.0, 0.0); // Нижняя грань (красная)
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);

		glColor3d(0.0, 1.0, 1.0); // Верхняя грань (бирюзовая)
		glVertex3d(-1.0, -1.0, 1.0);
		glVertex3d(1.0, -1.0, 1.0);
		glVertex3d(1.0, 1.0, 1.0);
		glVertex3d(-1.0, 1.0, 1.0);

		glColor3d(0.0, 1.0, 0.0); // Боковая грань (зеленая)
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(1.0, -1.0, 1.0);
		glVertex3d(1.0, 1.0, 1.0);

		glColor3d(1.0, 1.0, 0.0); // Боковая грань (желтая)
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, 1.0);
		glVertex3d(1.0, -1.0, 1.0);

		glColor3d(0.7, 0.5, 0.0); // Боковая грань (коричневая)
		glVertex3d(-1.0, -1.0, -1.0);
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(-1.0, 1.0, 1.0);
		glVertex3d(-1.0, -1.0, 1.0);

		glColor3d(0.0, 0.5, 0.2); // Боковая грань (темно-зеленая)
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, 1.0);
		glVertex3d(-1.0, 1.0, 1.0);
		glEnd();
}

void DemoWindow::render() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Очистка + очистка буфера глубины от старых значений

	glLoadIdentity(); // Матрица модель вида = единичная

	gluLookAt(3.0, 4.0, 2.0,  // Координаты камеры
			  0.0, 0.0, 0.0,  // Координаты центра
			  0.0, 0.0, 1.0); // Направление вверх, МодельВида=Камера
	glRotated(_cube_angle, 0.0, 0.0, 1.0);
	glPushMatrix (); //сохраненение ^ матрицы в стек
	//glScaled(0.5, 0.5, 0.5); // преобразовали матрицу
	//glPopMatrix (); //но взяли из стека сохраненную матрицу
	//glRotated(_cube_angle, 0.0, 0.0, 1.0); //преобразование поворот (на угл, вокруг (x, y, z) - ось вращения)
	//glTranslated (0.7, 0.0, 0.0); //преобразование параллельный перенос - прибавление к координатам вершин заданных параметров
	//glScaled(_cube_scale,_cube_scale,_cube_scale); //преобразование масштаб - сжатие или растяжение вдоль вектора, умножение
												   //координат вершин на значение заданных параметров

	//glBegin(GL_TRIANGLES); треугольник
	//glBegin(GL_POINTS); точки
	//glBegin(GL_LINES); линия
	//glBegin(GL_LINE_STRIP); ломаная
	//glBegin(GL_LINE_LOOP); ломаная замкнутая

	/* glVertex???
	 *         ^ количество координат (2,3 или 4)
	 *          ^ тип значений координат (d-double, f- float, i - int, s - short)
	 *           ^ если здесь v, то это массив
	*/
	/* Плоский квадрат
	glBegin(GL_QUADS);
	glColor3d(1.0, 0.0, 0.0);
	glVertex2d(-0.8,0.8);
	glColor3d(0.0, 1.0, 0.0);
	glVertex2d(0.8,0.8);
	glColor3d(0.0, 1.0, 1.0);
	glVertex2d(0.8,-0.8);
	glColor3d(0.0, 0.0, 1.0);
	glVertex2d(-0.8,-0.8);
	glEnd();
	*/

	glScaled(0.2, 0.2, 0.2);
	CubeRender();

	glPopMatrix ();
	glScaled(0.2, 0.2, 0.2);
	glTranslated (2.0, 0, 2.0);
	CubeRender();

	glTranslated (2.0, 0, -2.0);
	CubeRender();

	glTranslated (-2.0, 0, -2.0);
	CubeRender();

	glTranslated (4.0, 0, 0);
	CubeRender();

	glTranslated (-8.0, 0, 0);
	CubeRender();

    /*TODO:задание для самостоятельной работы
     *  - Добавить оставшиеся грани куба +
     *  - Выясниь, почему куб в текущем виде отображается неправильно +
     *  - Исправить программу, чтобы куб начал правильно отображаться +
     *  - Разобраться с основными преобразованиями:
     *  		~ параллельный перенос; +
     *  		~ поворот; +
     *  		~ масштабирование. +
     *  - Разобарться с функциями glPushMatrix() и glPopMatrix() +
     *  - Построить из кубиков пирамидку: +
     *          +-+
     *          |X|
     *        +-+ +-+
     *        |X| |X|
     *      +-+ +-+ +-+
     *      |X| |X| |X|
     *      +-+ +-+ +-+
     */

}

void DemoWindow::update() {
	_cube_angle += 0.01; //поворот куба
	//_cube_scale -= 0.00001; //уменьшение масштаба куба
	//if (_cube_scale <= 0.2) // если масштаб равен 0.2
	//	_cube_scale += 1; // вернуть значение в 1
	if (_cube_angle >= 360.0) // если угл поворота равен 360 градусов
		_cube_angle -= 360.0; // вернуть значение в 0 градусов
}
