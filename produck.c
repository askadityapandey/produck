#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

// Function to initialize SDL Mixer
int initSDL() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 0;
    }

    return 1;
}

// Function to play the duck sound
void playDuckSound() {
    Mix_Music *duckSound = Mix_LoadMUS("duck.mp3");
    if (!duckSound) {
        fprintf(stderr, "Failed to load duck.mp3! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    if (Mix_PlayMusic(duckSound, 1) == -1) {
        fprintf(stderr, "Failed to play duck sound! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

int main() {
    // Initialize SDL
    if (!initSDL()) {
        return 1;
    }

    while(1) {
        if(getchar()) {  // Check if a key is pressed
            playDuckSound(); // Play the duck sound
        }
    }

    return 0;
}
