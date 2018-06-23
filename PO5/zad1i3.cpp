#include "polygon.h"
#include <algorithm>
#include <cmath>
#include <QImage>

Polygon::Polygon() {
    arr=new Point[4];
    reserved=4;
    points=0;
}

Polygon::Polygon(int size) {
    reserved=size + size%4>0 ? 4-size%4 : 0;
    arr=new Point[reserved];
    points=0;
}

Polygon::Polygon(Polygon &p) {
    reserved=p.reserved;
    points=p.points;

    arr=new Point[reserved];
    std::copy(p.arr,p.arr+reserved,this->arr);
}

void Polygon::addPoint(Point p) {
    if(points==reserved) {
        reserved+=4;
        Point *narr=new Point[reserved];
        std::copy(arr,arr+points,narr);
        delete [] arr;
        arr = narr;
    }

    arr[points]=p;
    points++;
}

Polygon::Point &Polygon::point(int index) {
    return arr[index];
}

void Polygon::draw(std::string path) {
    const Point max=maxPoint();

    QImage image(max.x+10,max.y+10,QImage::Format_RGB32);
    image.fill(0xFFFFFF);

    draw(image);

    image.save(QString::fromStdString(path));
}

void Polygon::draw(QImage &image) {
    for(int i=0; i<points-1; i++)
        drawLine(&arr[i],&arr[i+1],image);
    drawLine(&arr[points-1],&arr[0],image);
}

void Polygon::drawLine(Point *p, Point *q, QImage &image) {
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
            image.setPixel(x,y,0);
        }
    }
    else {
        if(p->y>q->y) {
            temp=p; p=q; q=temp;
        }
        for(y=p->y; y<=q->y; y++) {
            x=round((y-b)/a);
            image.setPixel(x,y,0);
        }
    }
}

const Polygon::Point Polygon::maxPoint() {
    Point max={0,0};

    for(int i=0; i<points; i++) {
        if(arr[i].x>max.x) max.x=arr[i].x;
        if(arr[i].y>max.y) max.y=arr[i].y;
    }

    return max;
}

bool Polygon::contains(Point checked) {
    Point *p, *q;
    float a, b;

    int cross=0;

    for(int i=0; i<points; i++) {
        p=&arr[i];
        q=&arr[(i+1)%points];

        if((p->y > checked.y &&  checked.y >= q->y)
        || (q->y > checked.y &&  checked.y >= p->y)) {
            a=(float)(p->y-q->y)/(p->x-q->x);
            b=p->y-a*p->x;
            if(a*checked.x+b<checked.y)
                cross++;
        }
    }
    return cross%2;
}

