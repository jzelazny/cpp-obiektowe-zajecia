#include "styledpolygon.h"
#include <QImage>
#include <cmath>

StyledPolygon::StyledPolygon(unsigned int contourColor, unsigned int fillColor) {
    m_contourColor=contourColor;
    m_fillColor=fillColor;
}

void StyledPolygon::draw(QImage &image) {
    Point max=maxPoint();
    for(int y=0; y<max.y; y++)
        for(int x=0; x<max.x; x++)
            if(contains({x,y}))
                image.setPixel(x,y,m_fillColor);

    for(int i=0; i<points-1; i++)
        drawLine(&arr[i],&arr[i+1],image);
    drawLine(&arr[points-1],&arr[0],image);
}

void StyledPolygon::drawLine(Point *p, Point *q, QImage &image) {
    float x, y;
    float a, b;
    Point *temp;

    a=(float)(p->y-q->y)/(p->x-q->x);
    b=p->y-a*p->x;

   if(fabs(a)<1) {
        if(p->x>q->x) {
            temp=p; p=q; q=temp;
        }
        for(x=p->x; x<=q->x; x++) {
            y=round(a*x+b);
            image.setPixel(x,y,m_contourColor);
        }
    }
    else {
        if(p->y>q->y) {
            temp=p; p=q; q=temp;
        }
        for(y=p->y; y<=q->y; y++) {
            x=round((y-b)/a);
            image.setPixel(x,y,m_contourColor);
        }
    }
}
