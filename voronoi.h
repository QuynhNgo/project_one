#ifndef VORONOI_H
#define VORONOI_H

#include <QGLWidget>
#include <GL/glut.h>
#include "point.h"
using namespace std;

class voronoi : public QGLWidget
{
    Q_OBJECT
public:
    explicit voronoi(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    double pixelSize;
    int resolution;
    bool color;
    vector<point>  nodes;

signals:

public slots:

};

#endif // VORONOI_H
