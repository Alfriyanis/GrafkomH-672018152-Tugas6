#include <iostream>
#include <GL/freeglut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);                                                        //Bagian belakang
    glVertex3f(-53.0, -20.0, -60.0);                    //titik bawah kiri
    glVertex3f(-53.0, 25.0, -60.0);                     //titik atas kiri
    glVertex3f(-5.0, 65.0, -60.0);                      //titik tengah atas
    glVertex3f(45.0, 25.0, -60.0);                      //titik atas kanan
    glVertex3f(45.0, -20.0, -60.0);                     //titik bawah kanan
    glEnd();

    // Bawah                                                                    //lantai
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-53.0, -20.0, 53.0);             ///depan kiri
    glVertex3f(45.0, -20.0, 53.0);              ///depan kanan
    glVertex3f(45.0, -20.0, -60.0);             ///kanan belakang
    glVertex3f(-53.0, -20.0, -60.0);           ///kanan kiri
    //
    glVertex3f(-53.0, -20.0, 60.0);             ///depan kiri
    glVertex3f(1.0, -20.0, 60.0);              ///depan kanan
    glVertex3f(1.0, -20.0, 52.0);             ///kanan belakang
    glVertex3f(-53.0, -20.0, 52.0);           ///kanan kiri
    glEnd();


    glColor3f(0.2, 0.2, 0.2);                                                  //atap kiri
    glBegin(GL_POLYGON);
    glVertex3f(-60.0, 20.0, -65.0);
    glVertex3f(-60.0, 20.0, 50.0);
    glVertex3f(-5.0, 65.0, 50.0);
    glVertex3f(-5.0, 65.0, -65.0);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);                                                  //atap kanan
    glBegin(GL_POLYGON);
    glVertex3f(52.0, 20.0, -65.0);
    glVertex3f(52.0, 20.0, 50.0);
    glVertex3f(-5.0, 65.0, 50.0);
    glVertex3f(-5.0, 65.0, -65.0);
    glEnd();


    glColor3f(1.2, 128.2, 0.2);
    glBegin(GL_POLYGON);                                                        //bagian dinding depan
    glVertex3f(-5.0, -20.0, 42.0);                     //titik kiri bawah
    glVertex3f(45.0, -20.0, 42.0);                      //titik kanan bawah
    glVertex3f(45.0, 25.0, 42.0);  glVertex3f(-5.0, 25.0, 42.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-47.2, 24.7, 30.3);
    glVertex3f(-7.8, 24.7, 30.3);
    glVertex3f(-29.0, 39, 30.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(20.0, -5.0, 42.3);  glVertex3f(40.0, -5.0, 42.3);
    glVertex3f(40.0, 18.0, 42.3);  glVertex3f(20.0, 18.0, 42.3);
    glEnd();

    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(20.0, 14.0, 42.4);  glVertex3f(40.0, 14.0, 42.4);
    glVertex3f(40.0, 17.0, 42.4);  glVertex3f(20.0, 17.0, 42.4);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(20.0, -5.0, 42.5);  glVertex3f(40.0, -5.0, 42.5);
    glVertex3f(40.0, 18, 42.5);    glVertex3f(20.0, 18, 42.5);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(27, -5.0, 42.5);     glVertex3f(27, 18, 42.5);
    glVertex3f(20.0, 13.0, 42.5);   glVertex3f(40.0, 13.0, 42.5);
    glVertex3f(20.0, 9.0, 42.5);   glVertex3f(27.0, 9.0, 42.5);
    glVertex3f(20.0, 6.0, 42.5);   glVertex3f(27.0, 6.0, 42.5);
    glVertex3f(20.0, 3.0, 42.5);   glVertex3f(27.0, 3.0, 42.5);
    glVertex3f(20.0, 0.0, 42.5);   glVertex3f(27.0, 0.0, 42.5);
    glEnd();


    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex3f(-5.0, 25.0, 30.0);  glVertex3f(-5.0, 25.0, 42.0);
    glVertex3f(-5.0, 65.0, 42.0);   glVertex3f(-5.0, 65.0, 30.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(-5.0, -20.0, 30.0);  glVertex3f(-5.0, -20.0, 42.0);
    glVertex3f(-5.0, 25.0, 42.0);   glVertex3f(-5.0, 25.0, 30.0);
    glEnd();

    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_TRIANGLES);
    glVertex3f(-53.0, 25.0, 30.0);
    glVertex3f(-5.0, 25.0, 30.0);
    glVertex3f(-5.0, 65.0, 30.0);
    glEnd();

    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex3f(-5.0, 25.0, 42.0);
    glVertex3f(-5.0, 65.0, 42.0);
    glVertex3f(45.0, 25.0, 42.0);
    glEnd();

    glColor3f(1.0, 128.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-53.0, -20.0, 30.0); glVertex3f(-5.0, -20.0, 30.0);
    glVertex3f(-5.0, 25.0, 30.0);   glVertex3f(-53.0, 25.0, 30.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);                    //JENDELA
    glVertex3f(-48.0, -5.0, 30.3);   glVertex3f(-25.0, -5.0, 30.3);
    glVertex3f(-25.0, 18.0, 30.3);   glVertex3f(-48.0, 18.0, 30.3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-39.0, -5.0, 30.5);  glVertex3f(-39.0, 18.0, 30.5);
    glVertex3f(-34.0, -5.0, 30.5);  glVertex3f(-34.0, 18.0, 30.5);
    glVertex3f(-39.0, -1.0, 30.5);  glVertex3f(-34.0, -1.0, 30.5);
    glVertex3f(-39.0, 2.0, 30.5);  glVertex3f(-34.0, 2.0, 30.5);
    glVertex3f(-39.0, 5.0, 30.5);  glVertex3f(-34.0, 5.0, 30.5);
    glVertex3f(-39.0, 9.0, 30.5);  glVertex3f(-34.0, 9.0, 30.5);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-48.0, -5.0, 30.5);    glVertex3f(-25.0, -5.0, 30.5);
    glVertex3f(-25.0, 18.0, 30.5);    glVertex3f(-48.0, 18.0, 30.5);
    glEnd();

    glColor3f(1.1, 128.1, 128.1);
    glBegin(GL_POLYGON);                    //PINTUDASAR
    glVertex3f(-25.0, -20.0, 30.2);
    glVertex3f(-8.0, -20.0, 30.2);
    glVertex3f(-8.0, 18.0, 30.2);
    glVertex3f(-25.0, 18.0, 30.2);
    glEnd();

    glColor3f(0.2, 128.2, 0.2);
    glBegin(GL_POLYGON);                    //PINTU
    glVertex3f(-25.0, -20.0, 30.3);
    glVertex3f(-8.0, -20.0, 30.3);
    glVertex3f(-8.0, 13.0, 30.3);
    glVertex3f(-25.0, 13.0, 30.3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-24.0, -3.0, 30.5); glVertex3f(-22.0, -5.0, 30.5);
    glVertex3f(-25.0, 4.0, 30.5); glVertex3f(-8.0, 4.0, 30.5);
    glVertex3f(-25.0, -6.0, 30.5); glVertex3f(-8.0, -6.0, 30.5);
    glVertex3f(-16.0, 13.0, 30.5); glVertex3f(-16, -19.0, 30.5);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-25.0, -19.5, 30.5);  glVertex3f(-8.0, -19.5, 30.5);
    glVertex3f(-8.0, 18.0, 30.5);    glVertex3f(-25.0, 18.0, 30.5);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-48.0, 13.0, 30.5); glVertex3f(-8.0, 13.0, 30.5);
    glEnd();

    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(-48.0, 14.0, 30.5);   glVertex3f(-8.0, 14.0, 30.5);
    glVertex3f(-8.0, 17.0, 30.5);    glVertex3f(-48.0, 17.0, 30.5);
    glEnd();

    //teras
    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                                ///pilar 1 kiri
    glVertex3f(-53.0, -20.0, 56.0);                      //bagian dinding kiri           
    glVertex3f(-53.0, -20.0, 60.0);                      //titik kanan bawah
    glVertex3f(-53.0, 20.0, 60.0);
    glVertex3f(-53.0, 20.0, 56.0);
    glEnd();

    glColor3f(1.0, 128.0, 0.0);
    glBegin(GL_POLYGON);                                                ///pilar 1 kanan
    glVertex3f(-49.0, -20.0, 56.0);                      //bagian dinding kiri           
    glVertex3f(-49.0, -20.0, 60.0);                      //titik kanan bawah
    glVertex3f(-49.0, 20.0, 60.0);
    glVertex3f(-49.0, 20.0, 56.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                                ///pilar 1 belakang
    glVertex3f(-53.0, -20.0, 56.0);                      //bagian dinding kiri           
    glVertex3f(-49.0, -20.0, 56.0);                      //titik kanan bawah
    glVertex3f(-49.0, 20.0, 56.0);
    glVertex3f(-53.0, 20.0, 56.0);
    glEnd();

    glColor3f(1.2, 128.2, 0.2);
    glBegin(GL_POLYGON);                                                ///pilar 1 depan
    glVertex3f(-53.0, -20.0, 60.0);                      //bagian dinding kiri           
    glVertex3f(-49.0, -20.0, 60.0);                      //titik kanan bawah
    glVertex3f(-49.0, 20.0, 60.0);
    glVertex3f(-53.0, 20.0, 60.0);
    glEnd();



    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                                ///pilar 2 kiri
    glVertex3f(-5.0, -20.0, 56.0);                      //bagian dinding kiri           
    glVertex3f(-5.0, -20.0, 60.0);                      //titik kanan bawah
    glVertex3f(-5.0, 20.0, 60.0);
    glVertex3f(-5.0, 20.0, 56.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                                ///pilar 2 kanan
    glVertex3f(-1.0, -20.0, 56.0);                      //bagian dinding kiri           
    glVertex3f(-1.0, -20.0, 60.0);                      //titik kanan bawah
    glVertex3f(-1.0, 20.0, 60.0);
    glVertex3f(-1.0, 20.0, 56.0);
    glEnd();


    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                                ///pilar 2 belakang
    glVertex3f(-5.0, -20.0, 56.0);                      //bagian dinding kiri           
    glVertex3f(-1.0, -20.0, 56.0);                      //titik kanan bawah
    glVertex3f(-1.0, 20.0, 56.0);
    glVertex3f(-5.0, 20.0, 56.0);
    glEnd();

    glColor3f(1.2, 128.2, 0.2);
    glBegin(GL_POLYGON);                                                ///pilar 2 depan
    glVertex3f(-5.0, -20.0, 60.0);                      //bagian dinding kiri           
    glVertex3f(-1.0, -20.0, 60.0);                      //titik kanan bawah
    glVertex3f(-1.0, 20.0, 60.0);
    glVertex3f(-5.0, 20.0, 60.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);                                         ///melintang 1
    glBegin(GL_POLYGON);                                            //kiri
    glVertex3f(-52.7, 20, 30.0);      glVertex3f(-52.7, 20, 65.0);
    glVertex3f(-52.7, 17.0, 65.0);    glVertex3f(-52.7, 17.0, 30.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);                                         ///melintang 1
    glBegin(GL_POLYGON);                                            //kanan
    glVertex3f(-49.3, 20.0, 30.0);    glVertex3f(-49.3, 20.0, 65.0);
    glVertex3f(-49.3, 17.0, 65.0);    glVertex3f(-49.3, 17.0, 30.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);                                         ///melintang 1
    glBegin(GL_POLYGON);                                            //bawah
    glVertex3f(-52.7, 17.0, 65.0);    glVertex3f(-49.3, 17.0, 65.0);
    glVertex3f(-49.3, 17.0, 30.0);    glVertex3f(-52.7, 17.0, 30.0);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);                                       ///melintang 1
    glBegin(GL_POLYGON);                                            //atas
    glVertex3f(-52.7, 20.0, 65.0);    glVertex3f(-49.3, 20.0, 65.0);
    glVertex3f(-49.3, 20.0, 30.0);    glVertex3f(-52.7, 20.0, 30.0);
    glEnd();

    glColor3f(1.2, 128.2, 0.2);                                       ///melintang 1
    glBegin(GL_POLYGON);                                            //tutup
    glVertex3f(-52.7, 20, 65.0);    glVertex3f(-49.3, 20.0, 65.0);
    glVertex3f(-49.3, 17.0, 65.0);  glVertex3f(-52.7, 17.0, 65.0);
    glEnd();


    glColor3f(0.2, 0.2, 0.2);                                         ///atapkecil 1
    glBegin(GL_POLYGON);                                            //kiri
    glVertex3f(-60.0, 15, 30.0);    glVertex3f(-60.0, 15, 65.0);
    glVertex3f(-29, 39.0, 65.0);     glVertex3f(-29, 39.0, 30.0);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);                                         ///atapkecil 1
    glBegin(GL_POLYGON);                                            //kanan
    glVertex3f(-29, 39.0, 30.0);   glVertex3f(-29, 39.0, 65.0);
    glVertex3f(4, 16.75, 65.0);    glVertex3f(4, 16.75, 30.0);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);                                         ///atapkecil 2
    glBegin(GL_POLYGON);                                            //depan
    glVertex3f(3, 25.0, 42.0);    glVertex3f(3, 15, 55.0);
    glVertex3f(45, 15.0, 55.0);   glVertex3f(45, 25.0, 42.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                            //melintang kecil kiri
    glVertex3f(4, 10, 42.0);      glVertex3f(4, 19, 49.5);
    glVertex3f(4, 17.0, 52.0);    glVertex3f(4, 12.0, 42.0);
    glEnd();
    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                            //melintang kecil kanan
    glVertex3f(44, 10, 42.0);      glVertex3f(44, 19, 49.5);
    glVertex3f(44, 17.0, 52.0);    glVertex3f(44, 12.0, 42.0);
    glEnd();


    glColor3f(1.0, 128.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-53.0, 18.0, 59.0);
    glVertex3f(-53.0, 20.0, 59.0);
    glVertex3f(-29.0, 39, 59.0);
    glVertex3f(-1.0, 20.0, 59.0);
    glVertex3f(-1.0, 18.0, 59.0);
    glEnd();

    glColor3f(1.0, 128.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-53.0, 18.0, 56.0);
    glVertex3f(-53.0, 20.0, 56.0);
    glVertex3f(-29.0, 39, 56.0);
    glVertex3f(-1.0, 20.0, 56.0);
    glVertex3f(-1.0, 18.0, 56.0);
    glEnd();


    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(-53.0, 18.0, 59.0);
    glVertex3f(-1.0, 18.0, 59.0);
    glVertex3f(-1.0, 18.0, 56.0);
    glVertex3f(-53.0, 18.0, 56.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);                                         ///melintang 2
    glBegin(GL_POLYGON);                                            //kiri
    glVertex3f(-4.7, 20, 30.0);      glVertex3f(-4.7, 20, 65.0);
    glVertex3f(-4.7, 17.0, 65.0);    glVertex3f(-4.7, 17.0, 30.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);                                         ///melintang 2
    glBegin(GL_POLYGON);                                            //kanan
    glVertex3f(-1.3, 20.0, 30.0);    glVertex3f(-1.3, 20.0, 65.0);
    glVertex3f(-1.3, 17.0, 65.0);    glVertex3f(-1.3, 17.0, 30.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);                                         ///melintang 2
    glBegin(GL_POLYGON);                                            //bawah
    glVertex3f(-4.7, 17.0, 65.0);    glVertex3f(-1.3, 17.0, 65.0);
    glVertex3f(-1.3, 17.0, 30.0);    glVertex3f(-4.7, 17.0, 30.0);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);                                       ///melintang 2
    glBegin(GL_POLYGON);                                            //atas
    glVertex3f(-4.7, 20.0, 65.0);    glVertex3f(-1.3, 20.0, 65.0);
    glVertex3f(-1.3, 20.0, 30.0);    glVertex3f(-4.7, 20.0, 30.0);
    glEnd();

    glColor3f(1.2, 128.2, 0.2);                                       ///melintang 2
    glBegin(GL_POLYGON);                                            //tutup
    glVertex3f(-4.7, 20, 65.0);    glVertex3f(-1.3, 20.0, 65.0);
    glVertex3f(-1.3, 17.0, 65.0);  glVertex3f(-4.7, 17.0, 65.0);
    glEnd();


    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                                        //bagian dinding kiri
    glVertex3f(-53.0, -20.0, -60.0);                     //titik kiri bawah             
    glVertex3f(-53.0, -20.0, 60.0);                      //titik kanan bawah
    glVertex3f(-53.0, -8.0, 60.0);
    glVertex3f(-53.0, -8.0, 30.0);
    glVertex3f(-53.0, 25.0, 30.0);
    glVertex3f(-53.0, 25.0, -60.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(-49.0, -20, 30.0);    glVertex3f(-49.0, -20, 56.0);
    glVertex3f(-49.0, -8.0, 56.0);   glVertex3f(-49.0, -8.0, 30.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(-53.0, -8.0, 56.0);    glVertex3f(-49.0, -8.0, 56.0);
    glVertex3f(-49.0, -8.0, 30.0);    glVertex3f(-53.0, -8.0, 30.0);

    glEnd();

    glColor3f(1.1, 128.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(-53.0, -20.0, -60.0);
    glVertex3f(-53.0, -20.0, 60.0);
    glVertex3f(-53.0, -8.0, 60.0);
    glVertex3f(-53.0, -8.0, 30.0);
    glVertex3f(-53.0, 25.0, 30.0);
    glVertex3f(-53.0, 25.0, -60.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);                                                //Jendela2
    glVertex3f(-53.3, -10.0, -25.0); glVertex3f(-53.3, -10.0, 5.0);
    glVertex3f(-53.3, 15.0, 5.0);    glVertex3f(-53.3, 15.0, -25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-53.5, 11.0, -25.0); glVertex3f(-53.5, 11.0, 5.0);
    glVertex3f(-53.5, 14.0, 5.0);   glVertex3f(-53.5, 14.0, -25.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-53.5, -10.0, -25.0); glVertex3f(-53.5, -10.0, 5.0);
    glVertex3f(-53.5, 15.0, 5.0);    glVertex3f(-53.5, 15.0, -25.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-53.5, 10.0, -25.0);  glVertex3f(-53.5, 10.0, 5.0);
    glVertex3f(-53.5, -10.0, -15.0); glVertex3f(-53.5, 10.0, -15.0);
    glVertex3f(-53.5, -10.0, -5.0);  glVertex3f(-53.5, 10.0, -5.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);                                                        //bagian dinding kanan
    glVertex3f(45.0, -20.0, -60.0);                     //titik kiri bawah             
    glVertex3f(45.0, -20.0, 53.0);                      //titik kanan bawah
    glVertex3f(45.0, -8.0, 53.0);   glVertex3f(45.0, -8.0, 42.0);
    glVertex3f(45.0, 25.0, 42.0);   glVertex3f(45.0, 25.0, -60.0);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(43.0, -20.0, 42.0); glVertex3f(43.0, -20.0, 53.0);
    glVertex3f(43.0, -8.0, 53.0);  glVertex3f(43.0, -8.0, 42.0);
    glEnd();

    glColor3f(1.0, 128.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(43.0, -20.0, 53.0);  glVertex3f(45.0, -20.0, 53.0);
    glVertex3f(45.0, -8.0, 53.0);   glVertex3f(43.0, -8.0, 53.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(43.0, -8.0, 53.0);   glVertex3f(45.0, -8.0, 53.0);
    glVertex3f(45.0, -8.0, 42.0);   glVertex3f(43.0, -8.0, 42.0);
    glEnd();


    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);                                                 //Jendela1
    glVertex3f(45.3, -10.0, -50.0); glVertex3f(45.3, -10.0, -40.0);
    glVertex3f(45.3, 10.0, -40.0);  glVertex3f(45.3, 10.0, -50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(45.5, -10.0, -50.0); glVertex3f(45.5, -10.0, -40.0);
    glVertex3f(45.5, 10.0, -40.0); glVertex3f(45.5, 10.0, -50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(45.5, 0.0, -50.0);   glVertex3f(45.5, 0.0, -40.0);
    glVertex3f(45.5, -10.0, -45.0); glVertex3f(45.5, 10.0, -45.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);                                                //Jendela2
    glVertex3f(45.3, -10.0, -25.0); glVertex3f(45.3, -10.0, 5.0);
    glVertex3f(45.3, 15.0, 5.0);    glVertex3f(45.3, 15.0, -25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(45.5, 11.0, -25.0); glVertex3f(45.5, 11.0, 5.0);
    glVertex3f(45.5, 14.0, 5.0);   glVertex3f(45.5, 14.0, -25.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(45.5, -10.0, -25.0); glVertex3f(45.5, -10.0, 5.0);
    glVertex3f(45.5, 15.0, 5.0);    glVertex3f(45.5, 15.0, -25.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(45.5, 10.0, -25.0);  glVertex3f(45.5, 10.0, 5.0);
    glVertex3f(45.5, -10.0, -15.0); glVertex3f(45.5, 10.0, -15.0);
    glVertex3f(45.5, -10.0, -5.0);  glVertex3f(45.5, 10.0, -5.0);
    glEnd();

    ////////////////////////////object dalam rumah
     //tempat tidur
    glColor3f(1.4, 1.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(-40.0, -20.0, -55.0);    glVertex3f(-20.0, -20.0, -55.0);
    glVertex3f(-20.0, -15.0, -55.0);    glVertex3f(-40.0, -15.0, -55.0);
    glEnd();

    glColor3f(1.4, 1.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(-40.0, -20.0, -20.0);    glVertex3f(-20.0, -20.0, -20.0);
    glVertex3f(-20.0, -15.0, -20.0);    glVertex3f(-40.0, -15.0, -20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-40.0, -20.0, -55.0);    glVertex3f(-40.0, -20.0, -20.0);
    glVertex3f(-40.0, -15.0, -20.0);    glVertex3f(-40.0, -15.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-20.0, -20.0, -55.0);    glVertex3f(-20.0, -20.0, -20.0);
    glVertex3f(-20.0, -15.0, -20.0);    glVertex3f(-20.0, -15.0, -55.0);
    glEnd();

    glColor3f(1.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(-40.0, -15.0, -20.0);    glVertex3f(-20.0, -15.0, -20.0);
    glVertex3f(-20.0, -15.0, -55.0);    glVertex3f(-40.0, -15.0, -55.0);
    glEnd();

    //bantal
    glColor3f(1.4, 1.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(-34.0, -15.0, -52.0);    glVertex3f(-26.0, -15.0, -52.0);
    glVertex3f(-26.0, -13.0, -52.0);    glVertex3f(-34.0, -13.0, -52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-34.0, -15.0, -47.0);    glVertex3f(-26.0, -15.0, -47.0);
    glVertex3f(-26.0, -13.0, -47.0);    glVertex3f(-34.0, -13.0, -47.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-34.0, -15.0, -52.0);    glVertex3f(-34.0, -15.0, -47.0);
    glVertex3f(-34.0, -13.0, -47.0);    glVertex3f(-34.0, -13.0, -52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-26.0, -15.0, -52.0);    glVertex3f(-26.0, -15.0, -47.0);
    glVertex3f(-26.0, -13.0, -47.0);    glVertex3f(-26.0, -13.0, -52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-34.0, -13.0, -47.0);    glVertex3f(-26.0, -13.0, -47.0);
    glVertex3f(-26.0, -13.0, -52.0);    glVertex3f(-34.0, -13.0, -52.0);
    glEnd();

    //lampu kamar
    glBegin(GL_POLYGON);
    glVertex3f(-47.0, -20.0, -47.0);    glVertex3f(-46.0, -20.0, -47.0);
    glVertex3f(-46.0, 10.0, -47.0);     glVertex3f(-47.0, 10.0, -47.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-47.0, -20.0, -47.0);    glVertex3f(-47.0, -20.0, -46.0);
    glVertex3f(-47.0, 10.0, -46.0);     glVertex3f(-47.0, 10.0, -47.0);
    glEnd();

    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -20.0, -48.0);    glVertex3f(-43.0, -20.0, -48.0);
    glVertex3f(-43.0, -18.0, -48.0);    glVertex3f(-50.0, -18.0, -48.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -20.0, -45.0);    glVertex3f(-43.0, -20.0, -45.0);
    glVertex3f(-43.0, -18.0, -45.0);    glVertex3f(-50.0, -18.0, -45.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -20.0, -48.0);    glVertex3f(-50.0, -20.0, -45.0);
    glVertex3f(-50.0, -18.0, -45.0);    glVertex3f(-50.0, -18.0, -48.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-43.0, -20.0, -48.0);    glVertex3f(-43.0, -20.0, -45.0);
    glVertex3f(-43.0, -18.0, -45.0);    glVertex3f(-43.0, -18.0, -48.0);
    glEnd();

    glColor3f(1.4, 0.4, 1.4);
    glBegin(GL_POLYGON);
    glVertex3f(-49.0, 10.1, -49.0);
    glVertex3f(-44.0, 10.1, -49.0);
    glVertex3f(-49.0, 10.1, -44.0);
    glVertex3f(-44.0, 10.1, -44.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-49.0, 5.1, -49.0);
    glVertex3f(-44.0, 5.1, -49.0);
    glVertex3f(-44.0, 10.1, -49.0);
    glVertex3f(-49.0, 10.1, -49.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-49.0, 5.1, -44.0);
    glVertex3f(-44.0, 5.1, -44.0);
    glVertex3f(-44.0, 10.1, -44.0);
    glVertex3f(-49.0, 10.1, -44.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-49.0, 5.1, -49.0);
    glVertex3f(-49.0, 5.1, -44.0);
    glVertex3f(-49.0, 10.1, -44.0);
    glVertex3f(-49.0, 10.1, -49.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-44.0, 5.1, -49.0);
    glVertex3f(-44.0, 5.1, -44.0);
    glVertex3f(-44.0, 10.1, -44.0);
    glVertex3f(-44.0, 10.1, -49.0);
    glEnd();

    //lemari
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-15.0, -20.0, -55.0);
    glVertex3f(0.0, -20.0, -55.0);
    glVertex3f(0.0, 10.0, -55.0);
    glVertex3f(-15.0, 10.0, -55.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-15.0, -20.0, -55.0);
    glVertex3f(-15.0, -20.0, -50.0);
    glVertex3f(-15.0, 10.0, -50.0);
    glVertex3f(-15.0, 10.0, -55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-7.0, -20.0, -55.0);
    glVertex3f(-7.0, -20.0, -50.0);
    glVertex3f(-7.0, 10.0, -50.0);
    glVertex3f(-7.0, 10.0, -55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -20.0, -55.0);
    glVertex3f(0.0, -20.0, -50.0);
    glVertex3f(0.0, 10.0, -50.0);
    glVertex3f(0.0, 10.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-15.0, 10.0, -50.0);
    glVertex3f(0.0, 10.0, -50.0);
    glVertex3f(0.0, 10.0, -55.0);
    glVertex3f(-15.0, 10.0, -55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-15.0, -15.9, -50.0);
    glVertex3f(0.0, -15.9, -50.0);
    glVertex3f(0.0, -15.9, -55.0);
    glVertex3f(-15.0, -15.9, -55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-15.0, -19.9, -50.0);
    glVertex3f(0.0, -19.9, -50.0);
    glVertex3f(0.0, -19.9, -55.0);
    glVertex3f(-15.0, -19.9, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-7.0, -10.0, -50.0);
    glVertex3f(0.0, -10.0, -50.0);
    glVertex3f(0.0, -10.0, -55.0);
    glVertex3f(-7.0, -10.0, -55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-7.0, -5.0, -50.0);
    glVertex3f(0.0, -5.0, -50.0);
    glVertex3f(0.0, -5.0, -55.0);
    glVertex3f(-7.0, -5.0, -55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-7.0, 1.0, -50.0);
    glVertex3f(0.0, 1.0, -50.0);
    glVertex3f(0.0, 1.0, -55.0);
    glVertex3f(-7.0, 1.0, -55.0);
    glEnd();


    glColor3f(0.1, 128.1, 0.1);                                             //Meja
    glBegin(GL_POLYGON);
    glVertex3f(5.0, -10.0, -10.0);    glVertex3f(20.0, -10.0, -10.0);
    glVertex3f(20.0, -10.0, 10.0);    glVertex3f(5.0, -10.0, 10.0);
    glEnd();

    //kaki kiri belakang
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(6.0, -20.0, -9.0);    glVertex3f(7.0, -20.0, -9.0);
    glVertex3f(7.0, -10.0, -9.0);    glVertex3f(6.0, -10.0, -9.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(6.0, -20.0, -8.0);    glVertex3f(7.0, -20.0, -8.0);
    glVertex3f(7.0, -10.0, -8.0);    glVertex3f(6.0, -10.0, -8.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(6.0, -20.0, -9.0);    glVertex3f(6.0, -20.0, -8.0);
    glVertex3f(6.0, -10.0, -8.0);    glVertex3f(6.0, -10.0, -9.0);
    glEnd();

    //kaki kiri depan
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(6.0, -20.0, 9.0);    glVertex3f(7.0, -20.0, 9.0);
    glVertex3f(7.0, -10.0, 9.0);    glVertex3f(6.0, -10.0, 9.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(6.0, -20.0, 8.0);    glVertex3f(7.0, -20.0, 8.0);
    glVertex3f(7.0, -10.0, 8.0);    glVertex3f(6.0, -10.0, 8.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(6.0, -20.0, 9.0);    glVertex3f(6.0, -20.0, 8.0);
    glVertex3f(6.0, -10.0, 8.0);    glVertex3f(6.0, -10.0, 9.0);
    glEnd();

    //kaki kanan depan
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(18.0, -20.0, 9.0);    glVertex3f(19.0, -20.0, 9.0);
    glVertex3f(19.0, -10.0, 9.0);    glVertex3f(18.0, -10.0, 9.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(18.0, -20.0, 8.0);    glVertex3f(19.0, -20.0, 8.0);
    glVertex3f(19.0, -10.0, 8.0);    glVertex3f(18.0, -10.0, 8.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(18.0, -20.0, 9.0);    glVertex3f(18.0, -20.0, 8.0);
    glVertex3f(18.0, -10.0, 8.0);    glVertex3f(18.0, -10.0, 9.0);
    glEnd();

    //kaki kanan belakang
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(18.0, -20.0, -9.0);    glVertex3f(19.0, -20.0, -9.0);
    glVertex3f(19.0, -10.0, -9.0);    glVertex3f(18.0, -10.0, -9.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(18.0, -20.0, -8.0);    glVertex3f(19.0, -20.0, -8.0);
    glVertex3f(19.0, -10.0, -8.0);    glVertex3f(18.0, -10.0, -8.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(18.0, -20.0, -9.0);    glVertex3f(18.0, -20.0, -8.0);
    glVertex3f(18.0, -10.0, -8.0);    glVertex3f(18.0, -10.0, -9.0);
    glEnd();

    //kursi

//kaki kanan depan
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, -20.0, 5.0);    glVertex3f(3.0, -20.0, 5.0);
    glVertex3f(3.0, -13.0, 5.0);    glVertex3f(2.0, -13.0, 5.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(2.0, -20.0, 4.0);    glVertex3f(3.0, -20.0, 4.0);
    glVertex3f(3.0, -13.0, 4.0);    glVertex3f(2.0, -13.0, 4.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(2.0, -20.0, 5.0);    glVertex3f(2.0, -20.0, 4.0);
    glVertex3f(2.0, -13.0, 4.0);    glVertex3f(2.0, -13.0, 5.0);
    glEnd();

    //kaki belakang kanan
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, -20.0, -5.0);    glVertex3f(3.0, -20.0, -5.0);
    glVertex3f(3.0, -13.0, -5.0);    glVertex3f(2.0, -13.0, -5.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(2.0, -20.0, -4.0);    glVertex3f(3.0, -20.0, -4.0);
    glVertex3f(3.0, -13.0, -4.0);    glVertex3f(2.0, -13.0, -4.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(2.0, -20.0, -5.0);    glVertex3f(2.0, -20.0, -4.0);
    glVertex3f(2.0, -13.0, -4.0);    glVertex3f(2.0, -13.0, -5.0);
    glEnd();

    //kaki belakang kiri
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -20.0, -5.0);    glVertex3f(-1.0, -20.0, -5.0);
    glVertex3f(-1.0, -13.0, -5.0);    glVertex3f(-2.0, -13.0, -5.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -20.0, -4.0);    glVertex3f(-1.0, -20.0, -4.0);
    glVertex3f(-1.0, -13.0, -4.0);    glVertex3f(-2.0, -13.0, -4.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -20.0, -5.0);    glVertex3f(-2.0, -20.0, -4.0);
    glVertex3f(-2.0, -13.0, -4.0);    glVertex3f(-2.0, -13.0, -5.0);
    glEnd();

    //kaki depan kiri
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -20.0, 5.0);    glVertex3f(-1.0, -20.0, 5.0);
    glVertex3f(-1.0, -13.0, 5.0);    glVertex3f(-2.0, -13.0, 5.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -20.0, 4.0);    glVertex3f(-1.0, -20.0, 4.0);
    glVertex3f(-1.0, -13.0, 4.0);    glVertex3f(-2.0, -13.0, 4.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -20.0, 5.0);    glVertex3f(-2.0, -20.0, 4.0);
    glVertex3f(-2.0, -13.0, 4.0);    glVertex3f(-2.0, -13.0, 5.0);
    glEnd();

    //sandaran depan
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -13.0, 5.0);    glVertex3f(-1.0, -13.0, 5.0);
    glVertex3f(-3.0, -5.0, 5.0);    glVertex3f(-4.0, -5.0, 5.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -13.0, 4.0);    glVertex3f(-1.0, -13.0, 4.0);
    glVertex3f(-3.0, -5.0, 4.0);    glVertex3f(-4.0, -5.0, 4.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -13.0, 5.0);    glVertex3f(-2.0, -13.0, 4.0);
    glVertex3f(-3.0, -5.0, 4.0);    glVertex3f(-4.0, -5.0, 5.0);
    glEnd();

    //sandaran belakanag
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -13.0, -5.0);    glVertex3f(-1.0, -13.0, -5.0);
    glVertex3f(-3.0, -5.0, -5.0);    glVertex3f(-4.0, -5.0, -5.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -13.0, -4.0);    glVertex3f(-1.0, -13.0, -4.0);
    glVertex3f(-3.0, -5.0, -4.0);    glVertex3f(-4.0, -5.0, -4.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -13.0, -5.0);    glVertex3f(-2.0, -13.0, -4.0);
    glVertex3f(-3.0, -5.0, -4.0);    glVertex3f(-4.0, -5.0, -5.0);
    glEnd();

    //sandaran
    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(-1.5, -12.0, -5.5); //kiri bawah
    glVertex3f(-1.5, -12.0, 5.5);   //kanan bawah
    glVertex3f(-3.0, -5.0, 5.5);
    glVertex3f(-3.0, -5.0, -5.5);
    glEnd();

    glColor3f(0.1, 128.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -13.0, 5.0);    glVertex3f(3.0, -13.0, 5.0);
    glVertex3f(3.0, -13.0, -5.0);    glVertex3f(-2.0, -13.0, -5.0);
    glEnd();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}


void mouse(int button, int state, int x, int y) {
    glClear(GL_COLOR_BUFFER_BIT);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;

    }

    else
        mouseDown = false;

    tampil();
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glLoadIdentity();
        gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(xrot, 1.0, 0.0, 0.0);
        glRotatef(yrot, 0.0, 1.0, 0.0);

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case'i':
    case'I':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case 'e':
    case 'E':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case 'u':
    case 'U':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case 'F':
    case 'f':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Alfriyanis Kolubo-672018152");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(5.0);
    glLineWidth(3.0f);
}
