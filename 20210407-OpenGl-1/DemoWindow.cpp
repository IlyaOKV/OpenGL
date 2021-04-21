/*
 * DemoWindow.cpp
 *
 *  Created on: 13 ���. 2021 �.
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
	glMatrixMode(GL_PROJECTION); // ������������� ������� ��������
	gluPerspective (45.0, double(width()) / double(height()), 0.1, 20.0);
	/*                ^ ���� ������ �� ���������
	 *                         ^ ����������� ������ ������
	 * 															^ ���������� �� ������� ��������� ���������
	 * 																^ ���������� �� ������� ��������� ���������
	 */
	glMatrixMode(GL_MODELVIEW);
	// glPointSize(16.0f); ������ �����
	// glLineWidth(10.0f); ������ �����
}

void DemoWindow::render() {
	glClear(GL_COLOR_BUFFER_BIT); // �������

	glLoadIdentity(); // ������� ������ ���� = ���������

	gluLookAt(3.0, 4.0, 2.0,  // ���������� ������
			  0.0, 0.0, 0.0,  // ���������� ������
			  0.0, 0.0, 1.0); // ����������� �����, ����������=������
	glRotated(_cube_angle, 0.0, 0.0, 1.0);



	//glBegin(GL_TRIANGLES); �����������
	//glBegin(GL_POINTS); �����
	//glBegin(GL_LINES); �����
	//glBegin(GL_LINE_STRIP); �������
	//glBegin(GL_LINE_LOOP); ������� ���������

	/* glVertex???
	 *         ^ ���������� ��������� (2,3 ��� 4)
	 *          ^ ��� �������� ��������� (d-double, f- float, i - int, s - short)
	 *           ^ ���� ����� v, �� �� ������
	*/
	/* ������� �������
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

	//���
	glBegin(GL_QUADS);
	glColor3d(1.0, 0.0, 0.0); // ������ ����� (�������)
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);

	glColor3d(0.0, 1.0, 1.0); // ������� ����� (���������)
	glVertex3d(-1.0, -1.0, 1.0);
	glVertex3d(1.0, -1.0, 1.0);
	glVertex3d(1.0, 1.0, 1.0);
	glVertex3d(-1.0, 1.0, 1.0);

    /*TODO:������� ��� ��������������� ������
     *  - �������� ���������� ����� ����
     *  - �������, ������ ��� � ������� ���� ������������ �����������
     *  - ��������� ���������, ����� ��� ����� ��������� ������������ (�������� 1,�������� 1)
     *  - ����������� � ��������� ����������������:
     *  		~ ������������ �������;
     *  		~  �������;
     *  		~  ���������������.
     *  - ����������� � ��������� glPushMatrix() � glPopMatrix()
     *  - ��������� �� ������� ���������:
     *          +-+
     *          |X|
     *        +-+ +-+
     *        |X| |X|
     *      +-+ +-+ +-+
     *      |X| |X| |X|
     *      +-+ +-+ +-+
     */
	glEnd();
}

void DemoWindow::update() {
	//������� ����
	_cube_angle += 0.01;
	if (_cube_angle >= 360.0)
		_cube_angle -= 360.0;
}
