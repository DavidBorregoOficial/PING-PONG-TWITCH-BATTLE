/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "raylib.h"
//indicacion de nivel minmo y maximo de volumenes en opciones
#define MAX_VOL     10 
#define MIN_VOL      0
#define MAX_VMUS     10
#define MIN_VMUS      0
#define MAX_VSOU     10
#define MIN_VSOU      0
typedef enum GameScreen { LOGO, LOGO2, TITLE, OPTIONS, FAKE, GAMEPLAY, GOODENDING, BADENDING } GameScreen;
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1280;
    int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "PING PONG TWITCH BATTLE by David <Falcon> Borrego Martinez");
    //Icono de aplicacion de juego
    Image icono = LoadImage("Resources/favicon.png");
    SetWindowIcon(icono);
    //Raylib animation
    int logoPositionX = screenWidth/2 - 128;
    int logoPositionY = screenHeight/2 - 128;

    int lettersCount = 0;
    int contadorraylib = 0;

    int topSideRecWidth = 16;
    int leftSideRecHeight = 16;

    int bottomSideRecWidth = 16;
    int rightSideRecHeight = 16;

    int estado = 0;                  // animacion estados
    float alpha3 = 1.0f;
    // Texturas
    Texture2D logo = LoadTexture("Resources/LOGO.png");
    Texture2D logobg = LoadTexture("Resources/logobackground.png");
    
    Texture2D title = LoadTexture("Resources/title.png");
    Texture2D titlebg = LoadTexture("Resources/titlebackground.png");
    Texture2D menuopt = LoadTexture("Resources/menu.png");
    
    Texture2D optbg = LoadTexture("Resources/optionsbackground.png");
    Texture2D tablabg = LoadTexture("Resources/tablabackground.png");
    Texture2D RTT = LoadTexture("Resources/Return2.png");
    Texture2D sumrest = LoadTexture("Resources/sumrest.png");
    
    Texture2D fakebg = LoadTexture("Resources/fakebackground.png");
    Texture2D fakebg2 = LoadTexture("Resources/fakebackground2.png");
    Texture2D fakebg3 = LoadTexture("Resources/fakebackground3.png");
    Texture2D fakebg4 = LoadTexture("Resources/fakebackground4.png");
    Texture2D fakebg5 = LoadTexture("Resources/fakebackground5.png");
    
    Texture2D you = LoadTexture("Resources/you.png");
    Texture2D enemy = LoadTexture("Resources/enemy.png");
    Texture2D ball = LoadTexture("Resources/ball.png");
    Texture2D sball = LoadTexture("Resources/sball.png");
    Texture2D backg = LoadTexture("Resources/fondo.png");
    Texture2D wall = LoadTexture("Resources/wall.png");
    
    Texture2D victorybg = LoadTexture("Resources/victorybackground.png");
    Texture2D endingG = LoadTexture("Resources/pog.png");
    Texture2D endingG2 = LoadTexture("Resources/pog2.png");
    
    Texture2D endingB = LoadTexture("Resources/lul.png");
    //Textos
    const char msg[25] = "LORD PRODUCTIONS PRESENTA";
    Font fuente = LoadFont("Resources/CurseoftheZombie.ttf");
    const char msg1[7] = "OPTIONS";
    Font opciones = LoadFont("Resources/DIMITRI_.TTF");    
    // Escena de inicio del juego
    GameScreen currentScene = LOGO;
    // Rectangulos para ping pong y otras escenas.
    Vector2 center = { 400 , 400 };
    Rectangle logoico = { 500, 160, 300, 300 };
    Rectangle logobackg = { 0, 0, screenWidth, screenHeight };
    
    Rectangle titleico = { 300, 60, 300, 169 };
    Rectangle titlebackg = { 0, 0, screenWidth, screenHeight };
    
    Rectangle play = { 200, 460, 90, 32 };
    Rectangle opt = { 200,520, 158, 32 };
    Rectangle quit = { 200,580, 90, 32 };
    Rectangle menu = { 190,455, 260, 160 };
    Rectangle menu2 = { 190,418, 290, 160 };
    
    Rectangle BackO = { 0, 0, screenWidth, screenHeight };
    Rectangle Tabla = {315, 100, 662, 518};
    Rectangle BTT = { 1090, 590, 120, 50};
    Rectangle VolMa1 = { 350, 130, 50, 50};
    Rectangle VolMa2 = { 890, 130, 50, 50};
    Rectangle VolMu1 = { 350, 330, 50, 50};
    Rectangle VolMu2 = { 890, 330, 50, 50};
    Rectangle VolSo1 = { 350, 530, 50, 50};
    Rectangle VolSo2 = { 890, 530, 50, 50};
    
    Rectangle BackF = { 0, 0, screenWidth, screenHeight };
    
    Rectangle rec = { 0, 300, 50, 200 };
    Rectangle rec2 = { screenWidth - 50, 200, 50, 200 };
    Rectangle fondo = { 0, 0, screenWidth, screenHeight };
    Rectangle wallie = { 620, 0, 50, screenHeight};
    
    Rectangle endg = { 1050, 482, 300, 169 };
    Rectangle endg2 = { 0, 482, 300, 169 };
    Rectangle youwin = { 605, 378, 50, 200 };
    
    Rectangle endb = { 0, 0, screenWidth, screenHeight };    
    
   //audio y musica
   InitAudioDevice();
   //audio
   Sound start = LoadSound("Resources/logostart.wav");
   Sound menusou = LoadSound("Resources/menuselect.wav");
   Sound souconf = LoadSound("Resources/audiovol.wav");
   Sound hittu = LoadSound("Resources/forsenhit.wav");
   Sound hitia = LoadSound("Resources/drhit.wav");
   Sound coin = LoadSound("Resources/coin.wav");   
   //musica
   Music logos = LoadMusicStream("Resources/logo.ogg");
   Music raysound = LoadMusicStream("Resources/rayaudio.ogg");
   Music music = LoadMusicStream("Resources/title.ogg");
   Music musconf = LoadMusicStream("Resources/musconf.ogg");
   Music masterconf = LoadMusicStream("Resources/masterconf.ogg");
   Music fakesong = LoadMusicStream("Resources/fake.ogg");
   Music pelea = LoadMusicStream("Resources/game.ogg");
   Music badend = LoadMusicStream("Resources/badend.ogg");
   Music goodend = LoadMusicStream("Resources/goodend.ogg");
    //valores de fade in y fade out, pelota de juego, contador de frames, Audio, Musica, Volumen Maestro
    int framesCounter = 30;
    
    float alpha = 1.0f;
    float alpha2 = 1.0f;
    float alpha4 = 1.0f;    //2 transicion
    float alpha5 = 1.0f;    //3 transicion
    float alpha6 = 1.0f;    //4 transicion
    
    float volumen = 1.0f;
    float volumus = 1.0f;
    float volusou = 1.0f;
    int volnum = 10;
    int musnum = 10;
    int sounum = 10;
    
    int LoadCounter = 0;
    int imageLoad = 0;
    
    int puntoplayer = 0;
    int pointia = 0;
    
    int Contadorfake = 0;  

    float rotation = 0;
    float radius = 30;
    
    int timer = 0;
    int smash = 0;
    int randValue = GetRandomValue(1, 3);
    
    Vector2 speed = { 10 , 10};    
    // variables para resetear variables de juego, pausa de juego y fade in y out
    bool gameover = true;
    bool pause = false;    
    bool fade = false;
    
    bool dark = true;
    bool primera = true;  //2 transicion
    bool segunda = true;  //3 transicion
    bool tercera = true;  //4 transicion
    
    bool gend = true;
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        // ajustes de audio, musica y volumen maestro
        SetMasterVolume(volumen);
        
        SetMusicVolume(logos,volumus);
        SetMusicVolume(music,volumus);
        
        SetMusicVolume(musconf,volumus);
        SetMusicVolume(masterconf,volumus);
        
        SetMusicVolume(fakesong,volumus);
        SetMusicVolume(pelea,volumus);
        SetMusicVolume(badend,volumus);
        SetMusicVolume(goodend,volumus);
        SetMusicVolume(raysound,volumus);
        
        SetSoundVolume(coin,volusou);
        SetSoundVolume(menusou,volusou);
        SetSoundVolume(start,volusou);
        
        SetSoundVolume(souconf,volusou);
        
        SetSoundVolume(hittu,volusou);
        SetSoundVolume(hitia,volusou);
        // ajustes de fade in fade out
        if(fade) alpha += 0.02f;
        else if(!fade) alpha -= 0.02f;       
          
        if(alpha >= 1.0f) alpha = 1.0f;
        else if (alpha <= 0.0f) alpha = 0.0f; 
        
        //fade de menu
        if(dark) alpha2 += 0.02f;
        if(!dark) alpha2 -= 0.02f;
        
        if(alpha2 >= 1.0f) alpha2 = 1.0f;
        else if (alpha2 <= 0.0f) alpha2 = 0.0f;
        //transiciones
        if(primera) alpha4 += 0.02f;
        if(!primera) alpha4 -= 0.02f;
        
        if(alpha4 >= 1.0f) alpha4 = 1.0f;
        else if (alpha4 <= 0.0f) alpha4 = 0.0f;

        if(segunda) alpha5 += 0.02f;
        if(!segunda) alpha5 -= 0.02f;
        
        if(alpha5 >= 1.0f) alpha5 = 1.0f;
        else if (alpha5 <= 0.0f) alpha5 = 0.0f;

        if(tercera) alpha6 += 0.02f;
        if(!tercera) alpha6 -= 0.02f;
        
        if(alpha6 >= 1.0f) alpha6 = 1.0f;
        else if (alpha6 <= 0.0f) alpha6 = 0.0f;          
        // Escenas
        switch(currentScene)
        {
            case LOGO:
            // reinicio de titulo de ventana
            SetWindowTitle("PING PONG TWITCH BATTLE by David <Falcon> Borrego Martinez");
            //------------------------------------------------------------------------------------
            //detener musicas inluidas de victoria/derrota
            UpdateMusicStream(logos);
            if(IsWindowReady()) PlayMusicStream(logos);
            contadorraylib++;
            if (contadorraylib == 540)
            {
                fade = !fade; 
            }            
            else if(alpha == 1.0f)
                {
                    fade = !fade;
                    currentScene++;
                    contadorraylib = 0;
                }
                
            break;
            
            case LOGO2:
            if (estado == 0)                 // Estado 0: puntito parpadeante
            {
                contadorraylib++;
                PlaySound(start);
                
                if (contadorraylib == 60)
                {
                    estado = 1;
                    contadorraylib = 0;      // Contador reseteado... sera usado para mas tarde
                }
            }
            else if (estado == 1)            // Estado 1: la el punto crece formando un palo horizontal
            {
                topSideRecWidth += 4;
                leftSideRecHeight += 4;

                if (topSideRecWidth == 256) estado = 2;
            }
            else if (estado == 2)            // Estado 2: las barras crecen para abajo formando el cuadro
            {
                bottomSideRecWidth += 4;
                rightSideRecHeight += 4;

                if (bottomSideRecWidth == 256) estado = 3;
            }
            else if (estado == 3)            // estado3: las letras de raylib aparecen
            {
                contadorraylib++;
                UpdateMusicStream(raysound);
                PlayMusicStream(raysound);

                if (contadorraylib/12)       // Cada 12 frames, una letra adicional
                {
                    lettersCount++;
                    contadorraylib = 0;
                }

                if (lettersCount >= 10)     // cuando todo aparezca, desaparece con el fade out
                {
                    alpha3 -= 0.02f;

                    if (alpha3 <= 0.0f)
                    {
                        alpha3 = 0.0f;
                        estado = 4;
                    }
                }
            }
            else if (estado == 4)
            {
                Contadorfake++;
                if (((Contadorfake/60)%2) == 1)
                {
                    fade = !fade;
                    Contadorfake = 0;
                    lettersCount = 0;                    
                }
                else if(alpha == 1.0f)
                {
                    fade = !fade;
                    currentScene = TITLE;
                }                
            }            
            break;
            
            case TITLE:
            SetWindowTitle("PING PONG TWITCH BATTLE by David <Falcon> Borrego Martinez");
            if(gameover) // Reset de variable final feliz
            {
                gend = true;
                pointia = 0;
                puntoplayer= 0;
                center.x = screenWidth/2;
                center.y = screenHeight/2;
                speed.x = 10;
                speed.y = 10;
                randValue = 0;
                smash = 0;
                radius = 30;
            }            
            StopMusicStream(raysound);
            UpdateMusicStream(music);
            if (IsWindowReady())
            {
                PlayMusicStream(music);
                StopSound(souconf);
                StopMusicStream(musconf);
                StopMusicStream(masterconf);
                framesCounter++;
            }
            if(CheckCollisionPointRec(GetMousePosition(), play))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        PlaySound(menusou);
                        fade = !fade;
                    }
                    else if(alpha == 1.0f)
                    {
                        fade = !fade;
                        currentScene = FAKE;
                    }                   
                }
            if(CheckCollisionPointRec(GetMousePosition(), opt))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        PlaySound(menusou);
                        fade = !fade;
                    }
                    else if(alpha == 1.0f)
                    {
                        fade = !fade;
                        currentScene = OPTIONS;
                    }                   
                }                
            break;
            
           case OPTIONS:
            SetWindowTitle("OPTIONS");
            if(IsWindowReady()) StopMusicStream(music);
            UpdateMusicStream(musconf);
            UpdateMusicStream(masterconf);
            if (volnum > MAX_VOL) volnum = MAX_VOL;
            else if (volnum < MIN_VOL) volnum = MIN_VOL;            //botones de volumen
            if(CheckCollisionPointRec(GetMousePosition(), VolMa1))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        volumen += 0.1f;
                        volnum++;
                        PlayMusicStream(masterconf);
                        StopMusicStream(musconf);
                        StopSound(souconf);
                        if(volumen > 1.0f) volumen = 1.0f;
                    }
                }
            if(CheckCollisionPointRec(GetMousePosition(), VolMa2))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        volumen -= 0.1f;
                        volnum--;
                        PlayMusicStream(masterconf);
                        StopSound(souconf);
                        StopMusicStream(musconf);
                        if(volumen < 0.0f) volumen = 0.0f;
                    }
                }
            if (musnum > MAX_VMUS) musnum = MAX_VMUS;
            else if (musnum < MIN_VMUS) musnum = MIN_VMUS;                
            if(CheckCollisionPointRec(GetMousePosition(), VolMu1))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        volumus += 0.1f;
                        musnum++;
                        PlayMusicStream(musconf);
                        StopMusicStream(masterconf);
                        StopSound(souconf);
                        if(volumus > 1.0f) volumus = 1.0f;
                    }
                }
            if(CheckCollisionPointRec(GetMousePosition(), VolMu2))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        volumus -= 0.1f;
                        musnum--;
                        PlayMusicStream(musconf);
                        StopMusicStream(masterconf);
                        StopSound(souconf);
                        if(volumus < 0.0f) volumus = 0.0f; 
                    }                
                }
            if (sounum > MAX_VSOU) sounum = MAX_VSOU;
            else if (sounum < MIN_VSOU) sounum = MIN_VSOU;                
            if(CheckCollisionPointRec(GetMousePosition(), VolSo1))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        volusou += 0.1f;
                        sounum++;
                        PlaySound(souconf);
                        StopMusicStream(musconf);
                        StopMusicStream(masterconf);
                        if(volusou > 1.0f) volusou = 1.0f;
                    }
                }
            if(CheckCollisionPointRec(GetMousePosition(), VolSo2))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        volusou -= 0.1f;
                        sounum--;
                        PlaySound(souconf);
                        StopMusicStream(musconf);
                        StopMusicStream(masterconf);
                        if(volusou < 0.0f) volusou = 0.0f;
                    }
                }                
            if(CheckCollisionPointRec(GetMousePosition(), BTT))
                {
                    if(IsMouseButtonReleased(0))
                    {
                        PlaySound(menusou);
                        fade = !fade;
                    }
                    else if(alpha == 1.0f)
                    {
                        fade = !fade;
                        currentScene = TITLE;
                    }                   
                }
            break;            
            
            case FAKE:
            // reinicio de titulo de ventana
            SetWindowTitle("LOADING");
            //------------------------------------------------------------------------------------
            //detener musicas incluidas de victoria/derrota
            if (IsWindowReady())
            {            
                StopMusicStream(music);
                UpdateMusicStream(fakesong);
                PlayMusicStream(fakesong);
                dark = true;
                primera = true;
                segunda = true;
                tercera = true;
                framesCounter++;
            }
            LoadCounter++;            
            Contadorfake++;
            if (((Contadorfake/60)%2) == 1)
            {
                imageLoad++;
            }            
            if (((Contadorfake/600)%10) == 1)
            {
                fade = !fade;
                Contadorfake = 0;
            }            
            else if(alpha == 1.0f)
                {
                    fade = !fade;
                    currentScene++;
                    imageLoad = 0;
                }  
            break;
            
            case GAMEPLAY:
            // cambio de titulo de ventana
            SetWindowTitle("FORSEN VS DR DISRESPECT");
            //--------------------------------------------
            if(IsWindowReady()) StopMusicStream(fakesong);
            UpdateMusicStream(pelea);
            if(IsWindowReady()) PlayMusicStream(pelea);
            if (IsKeyPressed(KEY_SPACE)) 
            {
                pause = !pause;
                PlaySound(coin);
                framesCounter = 30;
            }
             if (!pause)
            {      
            center.x += speed.x;
            center.y += speed.y;
            
            rotation += 5; // Rotacion de pelota
            
            if(center.x + radius >= screenWidth || center.x - radius <= 0) // Velocidad de pelota al impactar con las paredes
            {
                speed.x *= -1;
            }
            if(center.y + radius >= screenHeight || center.y - radius <= 0)
            {
                speed.y *= -1;
            }
            if(CheckCollisionCircleRec(center, radius, rec))
                {
                    if(center.x + radius >= rec.x || center.x - radius <= rec.x + rec.width)
                    {
                        speed.x *= -1;
                        PlaySound(hittu);
                        smash++;
                    }            
                }                
            if(CheckCollisionCircleRec(center, radius, rec2))
                {
                    if(center.x + radius >= rec2.x || center.x - radius <= rec2.x + rec2.width)
                    {
                        speed.x *= -1;
                        PlaySound(hitia);
                    }            
                }
            if(center.x >= screenWidth/2) // Bot
                {
                    if(speed.x >= 0)
                    {
                        if(center.y <= rec2.y + rec2.height/2) rec2.y -= 5.5;
                        else if(center.y >= rec2.y + rec2.height/2) rec2.y += 5.5;
                    }
                }
                
             if(rec.y <= 0) rec.y = 0;
             else if(rec.y + rec.height >= screenHeight) rec.y = screenHeight - rec.height;
            
             if(rec2.y <= 0) rec2.y = 0;
             else if(rec2.y + rec2.height >= screenHeight) rec2.y = screenHeight - rec2.height;
             if(IsKeyDown (KEY_UP)) rec.y -=10; // Controles
             if(IsKeyDown (KEY_DOWN)) rec.y +=10;
            }
            
            else
            {
                framesCounter++;
            }
            // power ups
            if (smash == 5) {
                randValue = GetRandomValue(1,3);
                smash = 0;
            }
            // velocidad
            if(randValue == 1 && IsKeyPressed(KEY_P)){
                speed.x = 15;
                speed.y = 15;
                smash = -100;
                randValue = -4;
            }
            // muro
            if(randValue == 2 && IsKeyPressed(KEY_P)){
                smash = -100;
                randValue = -3;
            } 
            //encoger pelota
            if(randValue == 3 && IsKeyPressed(KEY_P)){
                smash = -100;
                randValue = -2;
            }
            if(randValue == -2){
                radius = 15;
                timer++;
            }            
            else if (smash < -50) {
                timer++;
            }    
            //desaparecer los power ups
                if(timer == 180 && randValue == -4){
                speed.x = 10;
                speed.y = 10;
                timer = 0;
                smash = 0;
                randValue = 0;
                }
                if(timer == 180 && randValue == -3){
                timer = 0;
                smash = 0;
                randValue = 0;                
            }
                if(timer == 180 && randValue == -2){
                timer = 0;
                smash = 0;
                radius = 30;
                randValue = 0;  
            }            
        
            //suma de puntos entre el jugador y IA
            if(center.x + radius >= screenWidth)
                {
                    puntoplayer++;
                }
            if(center.x - radius <= 0)
                {
                    pointia++;
                }               
                
            else if(center.x + radius >= screenWidth && puntoplayer == 5) // Final bueno
                {
                    gend = gend;
                    fade = !fade;                    
                }
            if(gend && alpha == 1.0f)
                {
                    fade = !fade;
                    currentScene = GOODENDING;
                }                
            else if(center.x - radius <= 0 && pointia == 5)  // final malo
                {
                    gend = !gend;
                    fade = !fade;                    
                }                 
            if(!gend && alpha == 1.0f)
                {
                    fade = !fade; 
                    currentScene = BADENDING;
                }                
            break;

            case GOODENDING: // final bueno
            // cambio de titulo de ventana            
            SetWindowTitle("GG EZ");
            //------------------------------------------------------------
            if(IsWindowReady()) StopMusicStream(pelea);
            UpdateMusicStream(goodend);
            if(IsWindowReady()) PlayMusicStream(goodend);                        
            if(IsKeyPressed(KEY_ENTER))
                {
                    fade = !fade;
                }
            else if(alpha == 1.0f)
                {
                    fade = !fade;
                    StopMusicStream(goodend);
                    currentScene = TITLE;
                }                
            break;
       
            case BADENDING: // final malo
            // cambio de titulo de ventana
            SetWindowTitle("U SUCK");
            //-----------------------------------------------------------
            if(IsWindowReady()) StopMusicStream(pelea);
            UpdateMusicStream(badend);
            if(IsWindowReady()) PlayMusicStream(badend);             
            if(IsKeyPressed(KEY_ENTER))
                {
                    fade = !fade;
                }
            else if(alpha == 1.0f)
                {
                    fade = !fade;
                    StopMusicStream(badend);
                    currentScene = TITLE;                    
                }
            break;              
        }                  
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            switch(currentScene)
            {
                case LOGO:
                DrawRectangleRec(logobackg, WHITE);
                DrawTexture(logobg, logobackg.x, logobackg.y, WHITE);
                // Titulo + icono                
                DrawRectangleRec(logoico, WHITE);
                DrawTexture(logo, logoico.x, logoico.y, WHITE);
                DrawTextEx(fuente, msg, (Vector2){ 300, 500 }, 55, 0, WHITE);
                break;
                case LOGO2:
                if (estado == 0)
                {
                    if ((contadorraylib/15)%2) DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
                }
                else if (estado == 1)
                {
                    DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                    DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
                }
                else if (estado == 2)
                {
                    DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                    DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);

                    DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
                    DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
                }
                else if (estado == 3)
                {
                    DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha3));
                    DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha3));

                    DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha3));
                    DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha3));

                    DrawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224, Fade(RAYWHITE, alpha3));

                    DrawText(SubText("raylib", 0, lettersCount), screenWidth/2 - 44, screenHeight/2 + 48, 50, Fade(BLACK, alpha3));
                }
                break;
                
                case TITLE:
                DrawRectangleRec(titlebackg, WHITE);
                DrawTexture(titlebg, titlebackg.x, titlebackg.y, WHITE);                
                // Titulo + icono
                DrawRectangleRec(titleico, WHITE);
                DrawTexture(title, titleico.x, titleico.y, WHITE);
                // boton play
                DrawTexture(menuopt,menu.x,menu.y,WHITE);
                DrawRectangleRec(play, Fade(RED,0));                
                DrawText ("PLAY",200,460,35,WHITE);
                if(CheckCollisionPointRec(GetMousePosition(), play))
                {
                    DrawText ("PLAY",200,460,35,RED);
                }
                // boton option
                DrawText ("OPTIONS",200,520,35,WHITE);                
                if(CheckCollisionPointRec(GetMousePosition(), opt))
                {
                    DrawText ("OPTIONS",200,520,35,RED);
                }
                // boton salir
                DrawText ("QUIT",200,580,35,WHITE);                
                if(CheckCollisionPointRec(GetMousePosition(), quit))
                {
                    if(IsMouseButtonDown(0)) CloseWindow();
                    else DrawText ("QUIT",200,580,35,RED);
                }
                // parpadeo de press start
                DrawTexture(titlebg, menu2.x, menu2.y,Fade(WHITE, alpha2));
                if((framesCounter/10)%2) DrawText("PRESS ENTER TO PLAY", (screenWidth - MeasureText("PRESS ENTER TO PLAY", 45))/2, screenHeight/1.8 -1, 45, Fade(RED,alpha2));                
                // aparicion de menu
                if(IsKeyPressed(KEY_ENTER))
                    {
                        if (alpha2 == 1.0f)
                        {
                            dark = !dark;
                        }
                    }
                // desaparicion de menu(solo valido una vez aparecido el menu)
                else if(IsKeyPressed(KEY_BACKSPACE))
                    {
                        if (alpha2 == 0.0f)
                        {
                            dark = !dark;
                        }
                    }
                
                break;
                
                case OPTIONS:
                // Titulo
                DrawRectangleRec(BackO, WHITE);
                DrawTexture(optbg, BackO.x, BackO.y, WHITE);
                DrawTextEx(opciones, msg1, (Vector2){ 495, 10 }, 76, 0, BLACK); //color doble para un texto
                DrawTextEx(opciones, msg1, (Vector2){ 500, 10 }, 72, 0, RED);
                //Textura para tabla de volumenes
                DrawRectangleRec(Tabla, WHITE);
                DrawTexture(tablabg, Tabla.x, Tabla.y, WHITE);
                // Opciones de Volumen maestro                
                DrawRectangleRec(VolMa1, WHITE);
                DrawTexture(sumrest, VolMa1.x, VolMa1.y, WHITE);
                DrawRectangleRec(VolMa2, WHITE);
                DrawTexture(sumrest, VolMa2.x, VolMa2.y, WHITE);
                DrawText ("+",358,125,65,WHITE);                
                if(CheckCollisionPointRec(GetMousePosition(), VolMa1))
                {
                    DrawText ("+",358,125,65,RED);
                }
                DrawText ("-",900,125,65,WHITE);                
                if(CheckCollisionPointRec(GetMousePosition(), VolMa2))
                {
                    DrawText ("-",900,125,65,RED);
                }             
                DrawText(FormatText("%02i VOL MASTER", volnum), 450, 135, 50, RED);
                // Opciones de Volumen musica
                DrawRectangleRec(VolMu1, WHITE);
                DrawTexture(sumrest, VolMu1.x, VolMu1.y, WHITE);
                DrawRectangleRec(VolMu2, WHITE);
                DrawTexture(sumrest, VolMu2.x, VolMu2.y, WHITE);
                DrawText ("+",358,325,65,WHITE);
                if(CheckCollisionPointRec(GetMousePosition(), VolMu1))
                {
                    DrawText ("+",358,325,65,RED);
                }
                DrawText ("-",900,325,65,WHITE);                
                if(CheckCollisionPointRec(GetMousePosition(), VolMu2))
                {
                    DrawText ("-",900,325,65,RED);
                }
                DrawText(FormatText("%02i VOL MUSIC", musnum), 450, 335, 50, RED);
                // Opciones de Volumen sonido
                DrawRectangleRec(VolSo1, WHITE);
                DrawTexture(sumrest, VolSo1.x, VolSo1.y, WHITE);
                DrawRectangleRec(VolSo2, WHITE);
                DrawTexture(sumrest, VolSo2.x, VolSo2.y, WHITE);
                DrawText ("+",358,525,65,WHITE);                
                if(CheckCollisionPointRec(GetMousePosition(), VolSo1))
                {
                    DrawText ("+",358,525,65,RED);
                }
                DrawText ("-",900,525,65,WHITE);                
                if(CheckCollisionPointRec(GetMousePosition(), VolSo2))
                {
                    DrawText ("-",900,525,65,RED);
                }
                DrawText(FormatText("%02i VOL SOUND", sounum), 450, 535, 50, RED);
                // botonh de vuelta
                DrawRectangleRec(BTT, WHITE);
                DrawTexture(RTT, BTT.x, BTT.y, WHITE);                  
                DrawText ("BACK",1100,600,35,WHITE);                
                if(CheckCollisionPointRec(GetMousePosition(), BTT))
                {
                    DrawText ("BACK",1100,600,35,RED);
                }                              
                break;                
                
                case FAKE:
                // fondo CARGA
                DrawRectangleRec(BackF, WHITE);
                if(imageLoad > 240)
                {
                    tercera = !tercera;
                    DrawTexture(fakebg5, BackF.x, BackF.y, WHITE);
                }                
                if(imageLoad > 180)
                {
                    segunda = !segunda;
                    DrawTexture(fakebg4, BackF.x, BackF.y, Fade(WHITE, alpha6));
                }
                if(imageLoad > 120)
                {
                    primera = !primera;
                    DrawTexture(fakebg3, BackF.x, BackF.y, Fade(WHITE, alpha5));
                }                
                if(imageLoad > 60)
                {
                    dark = !dark;
                    DrawTexture(fakebg2, BackF.x, BackF.y, Fade(WHITE, alpha4));
                }                
                DrawTexture(fakebg, BackF.x, BackF.y, Fade(WHITE, alpha2));
                //cargando
                if((framesCounter/50)%2) DrawText("WAIT, LOADING", (screenWidth - MeasureText("WAIT, LOADING", 50))/2, screenHeight/1.25 -9, 50, RED);    
                break;
                
                case GAMEPLAY:
                // fondo partido
                DrawRectangleRec(fondo, WHITE);
                DrawTexture(backg, fondo.x, fondo.y, WHITE);
                // pelota kappa
                if (randValue == 0 || randValue == 1 || randValue == 2 || randValue == 3 || randValue == -3 || randValue == -4) {
                DrawTexturePro(ball, (Rectangle){ 0, 0, ball.width, ball.height }, (Rectangle){ center.x, center.y, ball.width, ball.height }, (Vector2){ ball.width/2, ball.height/2 }, rotation, WHITE);
                }
                // rectangulo forsen
                DrawRectangleRec(rec, BLUE);
                DrawTexture(you, rec.x, rec.y, WHITE);
                // rectangulo drdisrespect enemy
                DrawRectangleRec(rec2, BLACK);
                DrawTexture(enemy, rec2.x, rec2.y, WHITE);
                //PowerUp
                if (randValue == 1) {
                DrawText ("Press P to use ur SPEEDYKAPPA POWER", 620, 680,30,WHITE);
                }
                if (randValue == 2) {
                DrawText ("Press P to use to 'create a wall'", 620, 680,30,WHITE);
                }
                if (randValue == 3) {
                DrawText ("Press P to use ur MICROKAPPA POWER", 620, 680,30,WHITE);
                }                
                if (randValue == -3) {
                    DrawRectangleRec(wallie, WHITE);
                    DrawTexture(wall, wallie.x, wallie.y, WHITE);
                    if(CheckCollisionCircleRec(center, radius, wallie))
                        {
                            if(center.x + radius >= wallie.x || center.x - radius <= wallie.x + wallie.width)
                            {
                                speed.x *= -1;
                            }            
                        }                      
                }
                if (randValue == -2) {
                DrawTexturePro(sball, (Rectangle){ 0, 0, sball.width, sball.height }, (Rectangle){ center.x, center.y, sball.width, sball.height }, (Vector2){ sball.width/2, sball.height/2 }, rotation, WHITE);
                }                
                // puntuaciones
                DrawText ("who reach 5 points, will be the winner",10,10,20,WHITE);
                DrawText(FormatText("%i", puntoplayer), 500, 10, 80, WHITE);
                DrawText(FormatText("%i", pointia), 720, 10, 80, WHITE);
                
                // pausa
                DrawText ("press space to pause",10,700,20,WHITE);                
                if(pause)
                {
                    if((framesCounter/50)%2) DrawText("PAUSE", (screenWidth - MeasureText("PAUSE", 85))/2, screenHeight/2.25 -5, 75, RED);
                }        
                break;
                
                case GOODENDING:
                // Texto de victoria + icono + podio background
                DrawRectangleRec(titlebackg, WHITE);
                DrawTexture(victorybg, titlebackg.x, titlebackg.y, WHITE);                
                DrawText ("POGGERS, U WON VS DR.DISRESPECT",200,90,48,WHITE);
                DrawText ("PRESS ENTER TO GO BACK",480,260,20,WHITE);
                //tu personaje en el podio
                DrawRectangleRec(youwin, Fade(RED,0));
                DrawTexture(you, youwin.x, youwin.y, WHITE); 
                                
                // poggers 1 y 2 en el orden mencionado
                DrawRectangleRec(endg, Fade(RED,0));
                DrawTexture(endingG, endg.x, endg.y, WHITE);
                
                DrawRectangleRec(endg2, Fade(RED,0));
                DrawTexture(endingG2, endg2.x, endg2.y, WHITE);                 
                break;

                case BADENDING:
                // omegalul textura
                DrawRectangleRec(endb, WHITE);
                DrawTexture(endingB, endb.x, endb.y, WHITE);
                //texto de derrota
                DrawText ("U LOST VS HIM",480,250,48,WHITE);
                DrawText ("PRESS ENTER TO GO BACK",480,460,20,WHITE);              
                break;                
            }
            // carton negro para fade in fade out
            DrawRectangle (0,0, screenWidth, screenHeight, Fade(BLACK, alpha));
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    UnloadSound(coin);
    UnloadSound(start);
    UnloadSound(menusou);
    UnloadSound(souconf);
    UnloadSound(hittu);
    UnloadSound(hitia);
    UnloadMusicStream(logos);
    UnloadMusicStream(raysound);
    UnloadMusicStream(music);
    UnloadMusicStream(musconf);
    UnloadMusicStream(masterconf);
    UnloadMusicStream(fakesong);
    UnloadMusicStream(pelea);
    UnloadMusicStream(badend);
    UnloadMusicStream(goodend);
    CloseAudioDevice();    
    // texturas a descargar
    UnloadTexture(logo);
    UnloadTexture(logobg);
    UnloadTexture(title);
    UnloadTexture(titlebg);
    UnloadTexture(menuopt);
    UnloadTexture(optbg);
    UnloadTexture(tablabg);
    UnloadTexture(sumrest);
    UnloadTexture(RTT);
    UnloadTexture(fakebg);
    UnloadTexture(fakebg2);
    UnloadTexture(fakebg3);
    UnloadTexture(fakebg4);
    UnloadTexture(fakebg5);
    UnloadTexture(you);
    UnloadTexture(enemy);
    UnloadTexture(ball);
    UnloadTexture(sball);
    UnloadTexture(wall);
    UnloadTexture(backg);
    UnloadTexture(victorybg);
    UnloadTexture(endingG);
    UnloadTexture(endingG2);
    UnloadTexture(endingB);
    //Fuentes de texto
    UnloadFont(fuente);
    UnloadFont(opciones);
    //icono de juego
    UnloadImage(icono);    
    //--------------------------------------------------------------------------------------  
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}