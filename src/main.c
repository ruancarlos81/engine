#include "core/engine.h"
#include "platform/platform.h"

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
    Engine_BeginFrame();
    Engine_EndFrame();
  }

  Engine_Shutdown();
  return 0;
}
