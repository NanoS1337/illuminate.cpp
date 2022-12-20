#include "illuminate.h"

int main()
{
  Canvas canvas = Canvas(720, 480);

  illuminate_fill(&canvas, 100, 100, 100, 100, Color(1.f, 1.f, 0.f));
  illuminate_fill(&canvas, 250, 250, 50, 100, Color(0.f, 0.f, 1.f));
  illuminate_fill(&canvas, 300, 75, 150, 150, Color(0.8f, 0.f, 0.f));

  save_as_image(&canvas, "result.ppm");
}
