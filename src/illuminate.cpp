#include "illuminate.h"
#include <iostream>
#include <fstream>
#include <cmath>

Canvas::Canvas(uint16_t width, uint16_t height)
{
  this->width = width;
  this->height = height;
  pixel_data = new Color[width * height];
}

void save_as_image(Canvas *canvas, std::string file_name)
{
  std::ofstream file;
  file.open(file_name);

  file << "P3\n" << canvas->width << " " << canvas->height << "\n255\n";

  for (uint16_t y = 0; y<canvas->height; ++y)
  {
    for (uint16_t x = 0; x<canvas->width; ++x)
    {
      Color color = canvas->pixel_data[y*canvas->width+x];
      int red = static_cast<int>(color.red * 255) * color.alpha;
      int green = static_cast<int>(color.green * 255) * color.alpha;
      int blue = static_cast<int>(color.blue * 255) * color.alpha;
      file << red << "  " << green << "  " << blue << "\n";
    }
  }
}

void illuminate_fill_rect(Canvas *canvas, uint16_t x, uint16_t y, uint16_t width, uint16_t height, Color color)
{
  for(uint16_t i = x; i<x+width; ++i)
  {
    for(uint16_t j = y; j<y+height; ++j)
    {
			color_pixel(canvas, i, j, color);
    }
  }
}

void illuminate_fill_circle(Canvas *canvas, uint16_t x, uint16_t y, uint16_t size, Color color)
{
	for(uint16_t i = x; i<x+size; ++i)
	{
		for(uint16_t j = y; j<y+size; ++j)
		{
			float distance = sqrt(pow(i - (x + size / 2), 2) + pow(j - (y + size / 2), 2));

			if (distance <= size / 2)
			{
				color_pixel(canvas, i, j, color);
			}
		}
	}
}

void color_pixel(Canvas *canvas, uint16_t x, uint16_t y, Color color)
{
	canvas->pixel_data[y*canvas->width+x] = color;
}
