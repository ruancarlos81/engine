#include "engine.h"
#include "raylib.h"

static float g_delta_time = 0.0f;

bool Engine_Init(EngineConfig config)
{
  InitWindow(
      config.window_width,
      config.window_height,
      config.title);

  if (!IsWindowReady())
    return false;

  SetTargetFPS(config.target_fps);
  return true;
}

void Engine_Shutdown(void)
{
  CloseWindow();
}

void Engine_BeginFrame(void)
{
  g_delta_time = GetFrameTime();
  BeginDrawing();
  ClearBackground(BLACK);
}

void Engine_EndFrame(void)
{
  EndDrawing();
}

float Engine_GetDeltaTime(void)
{
  return g_delta_time;
}