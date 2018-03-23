//SDL과 표준입출력 포함
#include "include\SDL.h"
#include <stdio.h>

//화면크기
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	// 렌더링 할 창 (window)
	SDL_Window* window = NULL;

	//window에 포함시킬 표면(surface)
	SDL_Surface* screenSurface = NULL;

	//SDL 초기화
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	else {
		//윈도우 생성
		window = SDL_CreateWindow(
			"SDL Tutorial",      // 타이틀
			SDL_WINDOWPOS_UNDEFINED, // x좌표
			SDL_WINDOWPOS_UNDEFINED, // y좌표
			SCREEN_WIDTH,            // 화면너비
			SCREEN_HEIGHT,            // 화면높이
			SDL_WINDOW_SHOWN         // 창보이기
		);
		if (window == NULL) 
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//흰색으로 surface 채우기
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//surface 업데이트
			SDL_UpdateWindowSurface(window);

			//2초 wait
			SDL_Delay(2000);
		}
	}
	
	//창 파괴
	SDL_DestroyWindow(window);

	//SDL 하위시스템 끝내기
	SDL_Quit();

	return 0;
}
