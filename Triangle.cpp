// copyright Bryan Tait
#include "Triangle.h"

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for ( int index = 0; index < triangle.size(); index++ ) 
  {
    target.draw(triangle[index], states);
  }
}

Triangle::Triangle(double l, sf::Vector2f cen) 
{
  center = cen;
  length = l;
  height = (sqrt(3) / 2.0) * l;
  sf::VertexArray temp(sf::LineStrip, 4);

  temp[0].position = sf::Vector2f(center.x,
  center.y + (height * 2/3));  // bottom point
  temp[1].position = sf::Vector2f(center.x - l/2,
  center.y - (height/3));  // top left
  temp[2].position = sf::Vector2f(center.x + l/2,
  center.y - (height/3));  // top right
  temp[3] = temp[0];  // back to bottom point

  temp[0].color = sf::Color::Red;
  temp[1].color = sf::Color::White;
  temp[2].color = sf::Color::Green;
  triangle.push_back(temp);
}

void Triangle::makeTri(double l, double h, sf::Vector2f newcenter) {
height = (sqrt(3) / 2.0) * l;
sf::VertexArray temp(sf::LineStrip, 4);

temp[0].position = sf::Vector2f(newcenter.x,
newcenter.y + (height * 2/3));  // bottom point
temp[1].position = sf::Vector2f(newcenter.x - l/2,
newcenter.y - (height/3));  // top left
temp[2].position = sf::Vector2f(newcenter.x + l/2,
newcenter.y - (height/3));  // top right
temp[3] = temp[0];  // back to bottom point

temp[0].color = sf::Color::Red;
temp[1].color = sf::Color::White;
temp[2].color = sf::Color::Green;
triangle.push_back(temp);
}
