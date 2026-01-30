#include "core/engine.h"
#include "platform/platform.h"
#include "raylib.h"

int main(void)
{
  EngineConfig config = {
      .window_width = 1280,
      .window_height = 720,
      .title = "Engine 2.5D",
      .target_fps = 60};

  if (!Engine_Init(config))
    return -1;

  while (!Platform_ShouldClose())
  {
    if (IsKeyPressed(KEY_F5))
      Engine_SetMode(ENGINE_MODE_PLAY);

    if (IsKeyPressed(KEY_F6))
      Engine_SetMode(ENGINE_MODE_PAUSE);

    Engine_BeginFrame();

    DrawText(
        Engine_GetMode() == ENGINE_MODE_PLAY ? "PLAY" : Engine_GetMode() == ENGINE_MODE_PAUSE ? "PAUSE"
                                                                                              : "EDITOR",
        20, 20, 20, GREEN);

    Engine_EndFrame();
  }

  Engine_Shutdown();
  return 0;
}
