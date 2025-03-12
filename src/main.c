#include "engine.h"

#include <stdio.h>

#include <raylib.h>
#include <tcl.h>

int main(int argc, char** argv){
	int st;

	printf("Initializing Gears\n");

	printf("Initializing raylib\n");
	
	InitWindow(1024, 768, "Gears");
	if(!IsWindowReady()){
		fprintf(stderr, "Window creation failure\n");
		return 1;
	}
	SetExitKey(KEY_NULL);
	SetTargetFPS(60);

	printf("Initializing Tcl/Tk\n");
	Tcl_FindExecutable(argv[0]);

	printf("Initializing engine\n");

	st = engine_init();
	if(st != 0){
		fprintf(stderr, "Engine initialization failure\n");
		return 1;
	}

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground((Color){0, 0, 0, 255});
		DrawRectangleV(GetMousePosition(), (Vector2){50, 50}, (Color){255, 0, 0, 255});
		/* todo */
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
