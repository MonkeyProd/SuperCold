#include "debug.hpp"

sf::RectangleShape debugRectangle(sf::FloatRect rect) {
  sf::RectangleShape debugRect;
  debugRect.setSize({rect.width, rect.height});
  debugRect.setPosition({rect.left, rect.top});
  debugRect.setFillColor(sf::Color::Transparent);
  debugRect.setOutlineColor(sf::Color::White);
  debugRect.setOutlineThickness(1.0f);
  return debugRect;
}