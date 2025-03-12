#include "engine.h"

#include <stdio.h>

#include <raylib.h>

int main(int argc, char** argv){
	int st;

	printf("Initializing Gears\n");

    InitWindow(1024, 768, "Gears");
    if(!IsWindowReady()){
		fprintf(stderr, "Window creation failure\n");
		return 1;
	}
	SetExitKey(KEY_NULL);
	SetTargetFPS(60);

	st = engine_init();
	if(st != 0){
		fprintf(stderr, "Engine initialization failure\n");
		return 1;
	}

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground((Color){0, 0, 0, 255});
		/* todo */
		EndDrawing();
	}

	CloseWindow();

	return 0;
}