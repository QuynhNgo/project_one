#include "voronoi.h"
#include <iostream>
using namespace std;
voronoi::voronoi(QWidget *parent) :
    QGLWidget(parent)
{
    resolution = 20;
    pixelSize = 600/resolution;
    color = false;
        point neWpoint;
        neWpoint.x = rand()%400-200;
        neWpoint.y = rand()%400-200;
        neWpoint.R = 1;
        neWpoint.B = 0;
        neWpoint.G=0;
        nodes.push_back(neWpoint);

        point neWpoint1;
        neWpoint1.x = rand()%400-200;
        neWpoint1.y = rand()%400-200;
        neWpoint1.R = 1;
        neWpoint1.B = 1;
        neWpoint1.G=0;
        nodes.push_back(neWpoint1);

        point neWpoint2;
        neWpoint2.x = rand()%400-200;
        neWpoint2.y = rand()%400-200;
        neWpoint2.R = 1;
        neWpoint2.B = 0;
        neWpoint2.G=1;
        nodes.push_back(neWpoint2);

        point neWpoint3;
        neWpoint3.x = rand()%400-200;
        neWpoint3.y = rand()%400-200;
        neWpoint3.R = 0;
        neWpoint3.B = 1;
        neWpoint3.G=1;
        nodes.push_back(neWpoint3);

}

void voronoi::initializeGL()
{
   glClearColor(1.0,1.0,1.0,1.0);
   glColor3f(1.0f,1.0f,0.0f);
}

void voronoi::paintGL()
{
   glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
   glEnable(GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(90,1,1,1000);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0,0,1,0,0,0,0,1,0);
   pixelSize = (double)600/(double)resolution;
   color = false;
   //cout << nodes.size() << endl;
   /*for(int i = 0; i<resolution; i++)
   {
       for(int j = 0; j<resolution;j++)
       {
           if(color)
           {
            glBegin(GL_POLYGON);
            glColor3f(1.0f,1.0f,1.0f);
            glVertex3f(-299+i*pixelSize,299-j*pixelSize,-299);
            glVertex3f(-299+(i+1)*pixelSize,299-j*pixelSize,-299);
            glVertex3f(-299+(i+1)*pixelSize,299-(j+1)*pixelSize,-299);
            glVertex3f(-299+i*pixelSize,299-(j+1)*pixelSize,-299);
            glEnd();
           }
           else
           {
             glBegin(GL_POLYGON);
             glColor3f(0.0f,0.0f,0.0f);
             glVertex3f(-299+i*pixelSize,299-j*pixelSize,-299);
             glVertex3f(-299+(i+1)*pixelSize,299-j*pixelSize,-299);
             glVertex3f(-299+(i+1)*pixelSize,299-(j+1)*pixelSize,-299);
             glVertex3f(-299+i*pixelSize,299-(j+1)*pixelSize,-299);
             glEnd();
           }
           color=!color;
       }
       if(resolution%2==0) color = !color;
   }*/
   for(int i = 0; i<resolution; i++)
       for(int j = 0; j<resolution; j++)
       {
           double disTanceX0 = -299 +(i+0.5)*pixelSize - nodes[0].x;
           double disTanceY0 = 299-(j+0.5)*pixelSize - nodes[0].y;
           double distanceX0Y0 = sqrt(disTanceX0*disTanceX0 + disTanceY0*disTanceY0);
           for(int k=0; k<nodes.size();k++)
           {
               double disTanceXk = -299 +(i+0.5)*pixelSize - nodes[k].x;
               double disTanceYk = 299-(j+0.5)*pixelSize - nodes[k].y;
               double distanceXkYk = sqrt(disTanceXk*disTanceXk + disTanceYk*disTanceYk);
               if(distanceX0Y0 > distanceXkYk) distanceX0Y0 = distanceXkYk;
           }
           for(int k = 0; k<nodes.size(); k++)
           {
               double disTanceXk = -299 +(i+0.5)*pixelSize - nodes[k].x;
               double disTanceYk = 299-(j+0.5)*pixelSize - nodes[k].y;
               double distanceXkYk = sqrt(disTanceXk*disTanceXk + disTanceYk*disTanceYk);
               if(distanceX0Y0 == distanceXkYk)
               {
                   glBegin(GL_POLYGON);
                   glColor3f(nodes[k].R,nodes[k].B,nodes[k].G);
                   glVertex3f(-299+i*pixelSize,299-j*pixelSize,-299);
                   glVertex3f(-299+(i+1)*pixelSize,299-j*pixelSize,-299);
                   glVertex3f(-299+(i+1)*pixelSize,299-(j+1)*pixelSize,-299);
                   glVertex3f(-299+i*pixelSize,299-(j+1)*pixelSize,-299);
                   glEnd();
                   break;

               }
           }

       }
   for(int i = 0; i<nodes.size(); i++)
   {
       glPushMatrix();
       glColor4f(0.0f,1.0f,0.0f,0.4f);
       glTranslatef(nodes[i].x, nodes[i].y,-299);
      // cout << nodes[i].x << " " << nodes[i].y << endl;
       glutSolidSphere(10,2,20);
       glPopMatrix();
   }

   glFlush();
}

void voronoi::resizeGL(int w, int h)
{
   glViewport(0,0,w,h);
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(90,(float)w/(float)h,1,1000);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0,0,1,0,0,0,0,1,0);
}
