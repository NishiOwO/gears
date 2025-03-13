#include "engine.h"

#include <stdio.h>

#include <raylib.h>

int main(int argc, char** argv) {
	int st;

	printf("[Gears] Initializing Gears\n");

	printf("[Gears] Initializing engine\n");

	st = engine_init();
	if(st != 0) {
		fprintf(stderr, "[Gears] Engine initialization failure\n");
		return 1;
	}

	printf("[Gears] Initializing raylib\n");

	SetTraceLogLevel(100);
	InitWindow(640, 480, "Gears");
	if(!IsWindowReady()) {
		fprintf(stderr, "[Gears] Window creation failure\n");
		return 1;
	}
	SetExitKey(KEY_NULL);
	SetTargetFPS(60);

	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground((Color){0, 0, 0, 255});
		DrawRectangleV(GetMousePosition(), (Vector2){50, 50}, (Color){255, 0, 0, 255});
		/* todo */
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
