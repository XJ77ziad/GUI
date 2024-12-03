#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

typedef enum {MAIN,GAME,SETTINGS,CREDITS}screen;

int main() {
    InitWindow(800,1000,"GUESS ME");
    InitAudioDevice();

    screen x = MAIN;
    float volume_music = 0.5f;
    float volume_sfx = 0.5f;
    Music gamemusic = LoadMusicStream("D:\\ProjectGUI\\DOOM.mp3");
    Sound sfx = LoadSound("D:\\ProjectGUI\\CLICK.mp3");

    SetTargetFPS(144);


    PlayMusicStream(gamemusic);

    while (!WindowShouldClose()){
        UpdateMusicStream(gamemusic);
        ClearBackground(RAYWHITE);

        BeginDrawing();
        if (x == MAIN){
            if (GuiButton((Rectangle){350,600,100,50},"START")){
                PlaySound(sfx);
                x = GAME;
            }
            else if (GuiButton((Rectangle){350,675,100,50},"Settings")){
                PlaySound(sfx);
                x = SETTINGS;
            }
            else if (GuiButton((Rectangle){350,750,100,50},"Credits")){
                PlaySound(sfx);
                x = CREDITS;
            }
        }
        else if (x == GAME) {
            //to be edited
        }
        else if (x == SETTINGS){
            if (GuiButton((Rectangle){10,10,100,50},"Back")) {
                PlaySound(sfx);
                x = MAIN;
            }
            GuiLabel((Rectangle){250,260,600,200}, TextFormat("music volume :%.1f",volume_music));
            if (GuiSlider((Rectangle){250,400,300,25},"Volume",NULL,&volume_music,0.0,1.5)){
                SetMusicVolume(gamemusic,volume_music);
            }
            if (GuiSlider((Rectangle){250,600,300,25},"Volume",NULL,&volume_sfx,0.0,1.5)){
                SetSoundVolume(sfx,volume_sfx);
            }
        }
        else if (x == CREDITS){
            if (GuiButton((Rectangle){10,10,100,50},"Back")){
                PlaySound(sfx);
                x = MAIN;
            }
            DrawText("Credits",310,200,50,BLACK);
            DrawText("GUI:",10,300,30,PURPLE);
            DrawText("Saif Haytham",10,340,30,BLACK);
            DrawText("23-101282",400,340,30,BLACK);
            DrawText("Ziad Mohamed",10,380,30,BLACK);
            DrawText("23-101280",400,380,30,BLACK);

            DrawText("Code:",10,450,30,PURPLE);
            DrawText("3abood el ahbl",10,490,30,BLACK);
            DrawText("23-101279",400,490,30,BLACK);
            DrawText("Moatez Hindy",10,530,30,BLACK);
            DrawText("23-101290",400,530,30,BLACK);
            DrawText("Hassan Ahmed",10,570,30,BLACK);
            DrawText("Blank",400,570,30,BLACK);

            DrawText("Data Base:",10,640,30,PURPLE);
            DrawText("Ahmed Zaytoun",10,680,30,BLACK);
            DrawText("23-101329",400,680,30,BLACK);
        }
        EndDrawing();
    }
    UnloadMusicStream(gamemusic);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
