#include "engine.h"
#include "raylib.h"

static float g_delta_time = 0.0f;
static EngineMode g_mode = ENGINE_MODE_EDITOR;

bool Engine_Init(EngineConfig config)
{
  InitWindow(
      config.window_width,
      config.window_height,
      config.title);

  if (!IsWindowReady())
    return false;

  SetTargetFPS(config.target_fps);
  g_mode = ENGINE_MODE_EDITOR;

  return true;
}

void Engine_Shutdown(void)
{
  CloseWindow();
}

void Engine_BeginFrame(void)
{
  g_delta_time = GetFrameTime();

  if (g_mode == ENGINE_MODE_PAUSE)
    g_delta_time = 0.0f;

  BeginDrawing();
  ClearBackground(BLACK);
}

void Engine_EndFrame(void)
{
  EndDrawing();

  if (g_mode == ENGINE_MODE_STEP)
    g_mode = ENGINE_MODE_PAUSE;
}

float Engine_GetDeltaTime(void)
{
  return g_delta_time;
}

EngineMode Engine_GetMode(void)
{
  return g_mode;
}

void Engine_SetMode(EngineMode mode)
{
  g_mode = mode;
}