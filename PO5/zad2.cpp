#include "image.h"
#include "styledpolygon.h"
#include <QImage>

Image::Image() {
    polygons=0;
}

void Image::addPolygon(StyledPolygon *p) {
    if(polygons<10)
        arr[polygons++]=p;
}

void Image::draw(std::string path) {
    Polygon::Point max={0,0}, localMax;

    for(int i=0; i<polygons; i++) {
        localMax=arr[i]->maxPoint();
        if(localMax.x > max.x) max.x=localMax.x;
        if(localMax.y > max.y) max.y=localMax.y;
    }

    QImage image(max.x+10,max.y+10,QImage::Format_RGB32);
    image.fill(0xFFFFFF);

    for(int i=0; i<polygons; i++) {
        arr[i]->draw(image);
    }

    image.save(QString::fromStdString(path));


}
