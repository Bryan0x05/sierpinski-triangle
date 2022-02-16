// copyright BryanTait
#include <iostream>
#include <sstream>
#include "Triangle.h"

void fTree(Triangle* obj, double R,double h, double l, float x, float y, double lfac, double hfac) 
{
if (R < 0)
    return;
if (lfac != 1  && hfac != 1) {
  sf::Vector2f newcenter;
  newcenter.x = x +  (l * lfac);
  newcenter.y = y + (h * hfac);
  l = l / 2;
  h = (sqrt(3)/2) * l;
  obj->makeTri(l, h, newcenter);
  x = newcenter.x;
  y = newcenter.y;
}

fTree(obj, R-1, h, l, x, y, lfac = -1.0/2, hfac = -2.0/3);  // top left
fTree(obj, R-1, h, l, x, y, lfac = 3.0/4, hfac = -1.0/6);  // top right
fTree(obj, R-1, h, l, x, y, lfac = -1.0/4, hfac = 5.0/6);  // bottom triangle
}

int main(int argc, char* argv[]) 
{
int x = 800, y = 800, once = 0, R; // window height and length, flag int, and recursion depth
double L;  // Length of the side of the base of equilateral triangle(double)
std::stringstream ss; // stringstream to parse commandline arguments
sf::Vector2f center; // stores x and y coordinate of the center of the window
center.x  = x / 2.0;
center.y = y / 2.0;

ss.str(argv[1]);  // triangle length
ss >> L;
// clearing EOF flag
ss.clear();
ss.str(argv[2]);  // recursion depth i.e. how many times you want to recurse
ss >> R;

Triangle Base(L, center); // makes the first triangle centered around the center
fTree(&Base, R, Base.getH(), Base.getL(), Base.getX(), Base.getY(), 1, 1); 
sf::RenderWindow window(sf::VideoMode(x, y), "Triangles Everywhere!");
while (window.isOpen()) {
sf::Event event;
while (window.pollEvent(event)) {
if (event.type == sf::Event::Closed)
  window.close();
}
if (once == 0) {
  window.clear();
  window.draw(Base);
  window.display();
}
once = 1;
}
return 0;
}

