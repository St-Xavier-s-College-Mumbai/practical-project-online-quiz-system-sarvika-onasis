#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

int qn = 0;
int score = 0;

struct Question 
{
    char question[100];
    char options[4][50];
    int answer;
};

struct Question questions0[MAX_QUESTIONS] = 
{    
    {"How many faces does a Dodecahedron have?", {"10", "11", "12", "13"}, 3},
    {"What is acrophobia a fear of?", {"Heights", "Bicycles", "Exercise", "Spiders"}, 1},
    {"Who was the Ancient Greek God of the Sun?", {"Artemis", "Zeus", "Ares", "Helios"}, 4},    
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 3},
    {"Where is the Chernobyl nuclear plant located?", {"Russia", "Ukraine", "Germany", "USA"}, 2},
    
    {"What is the only flag without four sides?", {"Nepal", "China", "Iceland", "Yemen"}, 1},
    {"How many hearts does an octopus have?", {"1", "7", "3", "9"}, 3},
    {"Which planet has the most moons?", {"Jupiter", "Neptune", "Uranus", "Saturn"}, 4},
    {"Where is the strongest human muscle located?", {"Thighs", "Jaws", "Arms", "Neck"}, 2},
    {"What is a group of crows called?", {"A Crow-d", "A Pride", "A Murder", "A Feather"}, 3}
};

typedef struct Button{
    Rectangle rect;
    Color colour;
}Button;

static void UpdateDrawFrame(void);
Button button_0 = {0};

Button button_1 = {0};
Button button_2 = {0};
Button button_3 = {0};
Button button_4 = {0};

int trans()
{
    float posY = -450;
    float timeBtwTransition = 50;
    while (!WindowShouldClose())
    {        
        BeginDrawing();
        if(timeBtwTransition>0)
        {
            DrawRectangle(0,posY,800,450,CLITERAL(Color){ 200, 200, 200, timeBtwTransition+20});
        }

            if(timeBtwTransition<=0&&qn<MAX_QUESTIONS)
            {
                ClearBackground(RAYWHITE);
                UpdateDrawFrame();
                
                DrawRectangleRec(button_1.rect, button_1.colour);
                DrawRectangleRec(button_2.rect, button_2.colour);
                DrawRectangleRec(button_3.rect, button_3.colour);
                DrawRectangleRec(button_4.rect, button_4.colour);
                
                DrawRectangle(18, 13, 764, 147, DARKGRAY);
                DrawRectangle(20, 15, 760, 120, LIGHTGRAY);
                DrawRectangle(20, 137, 760, 20, GRAY);
                
                DrawText(TextFormat("Q. %d", qn+1), 30, 25, 20, CLITERAL(Color){150, 0, 0, 255});
                DrawText(TextFormat("Q. %d", qn+1), 28, 23, 20, RED);
                
                DrawText(questions0[qn].question, 45, 50, 30, CLITERAL(Color){150, 0, 0, 255});
                DrawText(questions0[qn].question, 43, 48, 30, RED);
                
                DrawText(questions0[qn].options[0], 197, 212, 35, DARKGRAY);
                DrawText(questions0[qn].options[1], 427, 212, 35, DARKGRAY);
                DrawText(questions0[qn].options[2], 197, 312, 35, DARKGRAY);
                DrawText(questions0[qn].options[3], 427, 312, 35, DARKGRAY);
                
                DrawText(questions0[qn].options[0], 195, 210, 35, WHITE);
                DrawText(questions0[qn].options[1], 425, 210, 35, WHITE);
                DrawText(questions0[qn].options[2], 195, 310, 35, WHITE);
                DrawText(questions0[qn].options[3], 425, 310, 35, WHITE);
                
                //DrawText(TextFormat("Score: %d", score), 5, 5, 20, RED);
                //DrawText(TextFormat("Ans: %d", questions0[qn].answer), 5, 25, 20, RED);
                
                //DrawText(TextFormat("Score: %d", score), 5, 5, 20, RED);
            }
            else if(timeBtwTransition<=0 && qn>=MAX_QUESTIONS)
            {
                DrawText("Quiz Complete!", 202, 73, 60, CLITERAL(Color){150, 0, 0, 255});
                DrawText("Quiz Complete!", 200, 75, 60, RED);
                DrawText(TextFormat("Score: %d/%d", score, MAX_QUESTIONS), 302, 248, 30, CLITERAL(Color){150, 0, 0, 255});
                DrawText(TextFormat("Score: %d/%d", score, MAX_QUESTIONS), 300, 250, 30, RED);
            }
           
            if(timeBtwTransition>=0)
            {
                ClearBackground(RAYWHITE);
            }
            
            timeBtwTransition-=1;
            posY+=15;
            
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void initButton(Button *button, Rectangle rect, Color colour)
{
    button->rect = rect;
    button->colour = colour;
}

bool is_mouse_over_button(Button button)
{
    return CheckCollisionPointRec(GetMousePosition(), button.rect);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    char greeting[] = "Welcome to our Quiz!";

    InitWindow(screenWidth, screenHeight, "Online Quiz System");
    SetTargetFPS(100);
    
    initButton(&button_0, (Rectangle){250,210, 300, 100}, BLUE);
    
    initButton(&button_1, (Rectangle){185, 200, 200, 75}, BLUE);
    initButton(&button_2, (Rectangle){415, 200, 200, 75}, BLUE);
    initButton(&button_3, (Rectangle){185, 300, 200, 75}, BLUE);
    initButton(&button_4, (Rectangle){415, 300, 200, 75}, BLUE);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawText(greeting, 240, 50, 30, RED);
            DrawText("by Sarvika and Onasis", 290, 75, 20, LIGHTGRAY);
            
            //DrawRectangle(250,210,300,100,DARKBLUE);
            //DrawRectangle(250,200,300,100,BLUE);
            DrawText("START", 331, 241, 40, DARKGRAY);
            DrawText("START", 329, 239, 40, LIGHTGRAY);
            
        EndDrawing();
        
        DrawRectangle(255,220,300,100,LIGHTGRAY);
        DrawRectangleRec(button_0.rect, button_0.colour);
        
        UpdateDrawFrame();
        
    }
    CloseWindow();

    return 0;
}

int check=0;

static void UpdateDrawFrame(void)
{
    if(is_mouse_over_button(button_0)&&check==0)
    {
        button_0.colour = DARKBLUE; 
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            check=1;
            trans();
        }
    }
    else
    {
        button_0.colour = BLUE;
    }
    
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && is_mouse_over_button(button_1))
    {
        ansSelect(1);
    }    
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && is_mouse_over_button(button_2))
    {
        ansSelect(2);
    }    
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && is_mouse_over_button(button_3))
    {
        ansSelect(3);
    }    
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && is_mouse_over_button(button_4))
    {
        ansSelect(4);
    }
    
    if(is_mouse_over_button(button_1))
    {
        button_1.colour = DARKBLUE; 
    }
    else
    {
        button_1.colour = BLUE;
    }
    
    if(is_mouse_over_button(button_2))
    {
        button_2.colour = DARKBLUE; 
    }
    else
    {
        button_2.colour = BLUE;
    }
    
    if(is_mouse_over_button(button_3))
    {
        button_3.colour = DARKBLUE; 
    }
    else
    {
        button_3.colour = BLUE;
    }
    
    if(is_mouse_over_button(button_4))
    {
        button_4.colour = DARKBLUE; 
    }
    else
    {
        button_4.colour = BLUE;
    }
}

void ansSelect(int ans)
{
    if(ans==questions0[qn].answer)
    {
        score++;
    }
    
    qn++;
    trans();
}