#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>

typedef struct EngineConfig
{
  int window_width;
  int window_height;
  const char *title;
  int target_fps;
} EngineConfig;

bool Engine_Init(EngineConfig config);
void Engine_Shutdown(void);

void Engine_BeginFrame(void);
void Engine_EndFrame(void);

float Engine_GetDeltaTime(void);

#endif