// File guard
#ifndef BryanTait_PS5_Triangles 
#define BryanTait_PS5_Triangles 

#include <math.h>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Triangle: public sf::Drawable {
 private:
double length;  // length of base triangle
double height;  // height of triangle
std::vector<sf::VertexArray> triangle;
sf::Vector2f center;  // x&y center of window
 public:
Triangle(double l, sf::Vector2f cen);
void makeTri(double l, double h, sf::Vector2f);
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
double getL() {return length;}
double getH() {return height;}
float getX() {return center.x;}
float getY() {return center.y;}
};

#endif  // BryanTait_PS5_Triangles 