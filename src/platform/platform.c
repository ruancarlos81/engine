#include "platform.h"
#include "raylib.h"

bool Platform_ShouldClose(void)
{
  return WindowShouldClose();
}
