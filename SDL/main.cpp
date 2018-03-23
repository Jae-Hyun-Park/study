//SDL과 표준입출력 포함
#include "include\SDL.h"
#include <iostream>

using namespace std;

//화면크기
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// 키 입력에 따른 로드할 이미지 수
const int MAX_IMAGE_COUNT = 5;

bool Init();
SDL_Surface* LoadSurface(string filePath);
void Close();

// 렌더링 할 창 (window)
SDL_Window* gwindow = NULL;

//window에 포함시킬 표면(surface)
SDL_Surface* gscreenSurface = NULL;

//이미지하나를 로드해서 사용할 표면
SDL_Surface* surfaces[MAX_IMAGE_COUNT] = { NULL, };
enum KeyPressState {
	KEY_PRESS_DEFAULT,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_RIGHT,
	KEY_PRESS_LEFT
};

KeyPressState gKeyPressState = KEY_PRESS_DEFAULT;

string filePath[MAX_IMAGE_COUNT] = {
	"Hi.bmp",
	"UP.bmp",
	"Down.bmp",
	"Right.bmp",
	"Left.bmp",
};
int main(int argc, char* args[]) {
	if (!Init()) {
		cout << "Failed to initialized!" << endl;
		return 0;
	}

	for (int i = 0; i < MAX_IMAGE_COUNT; ++i) {
		surfaces[i] = LoadSurface("./Media/" + filePath[i]);
	}

	bool quit = false; // 프로그램 종료상태시 true로 바뀌는 변수
	SDL_Event sdlEvent;
	SDL_Surface* currentSurface = surfaces[(int)KEY_PRESS_DEFAULT];
	while (!quit) {
		while (SDL_PollEvent(&sdlEvent) != 0) {
			if (sdlEvent.type == SDL_QUIT)
				quit = true;
			else if (sdlEvent.type == SDL_KEYDOWN) {
				switch (sdlEvent.key.keysym.sym) {
				case SDLK_UP:
					currentSurface = surfaces[(int)KEY_PRESS_UP];
					break;
				case SDLK_DOWN:
					currentSurface = surfaces[(int)KEY_PRESS_DOWN];
					break;
				case SDLK_LEFT:
					currentSurface = surfaces[(int)KEY_PRESS_LEFT];
					break;
				case SDLK_RIGHT:
					currentSurface = surfaces[(int)KEY_PRESS_RIGHT];
					break;
				default:
					currentSurface = surfaces[(int)KEY_PRESS_DEFAULT];
					break;
				}
			}
			else if (sdlEvent.type == SDL_KEYUP)
				currentSurface = surfaces[KEY_PRESS_DEFAULT];

		}

		//흰색으로 surface 채우기
		SDL_FillRect(gscreenSurface, NULL, SDL_MapRGB(gscreenSurface->format, 0xFF, 0x88, 0x88));
		if (currentSurface != NULL)
			SDL_BlitSurface(currentSurface, NULL, gscreenSurface, NULL);
		//surface 업데이트
		SDL_UpdateWindowSurface(gwindow);
	}
	Close();
	return 0;
}

bool Init() {
	bool success = true;
	//SDL 초기화
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {           // SDL 초기화 실패시
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {                                              // 초기화성공
  //윈도우 생성
		gwindow = SDL_CreateWindow(
			"SDL Tutorial",      // 타이틀
			SDL_WINDOWPOS_UNDEFINED, // x좌표
			SDL_WINDOWPOS_UNDEFINED, // y좌표
			SCREEN_WIDTH,            // 화면너비
			SCREEN_HEIGHT,            // 화면높이
			SDL_WINDOW_SHOWN         // 창보이기
		);
		if (gwindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Get window surface
			gscreenSurface = SDL_GetWindowSurface(gwindow);
		}
	}
	return success;
}

SDL_Surface* LoadSurface(string filePath) {

	SDL_Surface* surface = NULL;                         // 로드를 해서 바로 담을 Surface*
	SDL_Surface* optimizedSurface = NULL;                  // Screen과 동일 포맷으로 변환할 Surfcae
	surface = SDL_LoadBMP(filePath.c_str());              // surface에 로드

	if (surface == NULL)
		cout << "Unable to load image " << filePath.c_str() << "SDL_Error : " << SDL_GetError() << endl;
	else {                                              // 스크린 Surfcae의 포맷으로 변환 surface는 더이상 필요 없음.
		optimizedSurface = SDL_ConvertSurface(surface, gscreenSurface->format, NULL);
		if (optimizedSurface == NULL) // 변환실패
			cout << "Unable to optimize image " << filePath.c_str() << "SDL_Error : " << SDL_GetError() << endl;
		SDL_FreeSurface(surface);                     // 필요없는 surface*를 해제 
	}
	return optimizedSurface;
}

void Close() {

	for (int i = 0; i < MAX_IMAGE_COUNT; ++i)
		SDL_FreeSurface(surfaces[i]);
	//창 파괴
	SDL_DestroyWindow(gwindow);
	//SDL 하위시스템 끝내기
	SDL_Quit();
	return;
}
