#pragma once

#include <stdint.h>
#include <string>

struct Color {
  float red, green, blue, alpha;

  Color() : red(1.f), green(1.f), blue(1.f), alpha(1.f) {}

  Color(float red, float green, float blue, float alpha = 1.f) : red(red), green(green), blue(blue), alpha(alpha) {}
};

class Canvas {
  public:
    uint16_t width;
    uint16_t height;
    Color *pixel_data;
    Canvas(uint16_t width, uint16_t height);
};

void save_as_image(Canvas *canvas, std::string file_name);

void illuminate_fill(Canvas *canvas, uint16_t x, uint16_t y, uint16_t width, uint16_t height, Color color);
