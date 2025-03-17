#include "iGraphics.h"
#include "bitmap_loader.h"
#include<time.h>
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://


void drawHomePage();
void drawStart();
void drawControls();
void drawCredits();
void drawHighScore();
void drawExit();
void gameover();
void firstPlayerObject();
void drawCurve();
void velocityVortex();

void StartButtonClickHandler();
void ControlsButtonClickHandler();
void CreditsButtonClickHandler();
void HighScoreButtonClickHandler();
void ExitButtonClickHandler();
void BackButtonClickHandler();
void HomeButtonClickHandler();
void curveButtonClickHandler();

int StartButtonClick = 0;
int ControlsButtonClick = 0;
int CreditsButtonClick = 0;
int HighScoreButtonClick = 0;
int ExitButtonClick = 0;
int CurvePageButtonClick = 0;

int HomePage = 0;
int StartPages = 0;
int ControlsPage = 0;
int CreditsPage = 0;
int intro = 1;
int HighScorePage = 0;
int CurvePage = 0;
int Exit = 0;
bool MusicOn = true;

//buttons related
int a3= 100, a4= 100, a5=100,a6 = 100;
int b3 = 30, b4 = 30, b5 = 30, b6 = 100;
int a1 = 100, a2 = 100;
int b1 = 30, b2 = 30;

//For FirstCar
int fc;

//For Bullet,Nitro;
int bullet = 0;
int bullets = 0;
int nitro = 0;


//Player Object Related

char player[12][200] = { "images\\CarHero.bmp", "images\\Armored_Vehicle.bmp", "images\\MonsterTruck.bmp", "images\\CarHeroL.bmp", 
"images\\Armored_VehicleL.bmp", "images\\MonsterTruckL.bmp", "images\\CarHeroB.bmp", "images\\Armored_VehicleB.bmp", "images\\MonsterTruckB.bmp","images\\CarHeroR.bmp", "images\\Armored_VehicleR.bmp",
"images\\MonsterTruckR.bmp" };
int playerIndex = 0;

//Life Object Related

int lives = 3;

//Power related

int power = 1;

// Player and collision objects positions

int playerX = 470, playerY = 0;

float x1 = 400, m = 601;
float x2 = 600, y2 = 601;
float x3 = 550, y3 = 601;
float p1 = 165, q1 = 601;
float p2 = 200, q2 = 601;
float p3 = 300, q3 = 601;
float p4 = playerX + 35, q4 = playerY + 154;

// Level Difficulty Systems

float decrement = 5.5;
int control_increment = 10;
int nitro_increment = 15;
float bullet_increment = 7;

int speed = 0;
int destroyed = 0;

void collision()
{
	if (((playerX + 66) >= x1) && (playerX <= (x1 + 66)) && ((playerY + 156) >= m && playerY <= (m + 156)) &&(playerIndex == 0 || playerIndex == 1) && StartPages == 1)
	{
		if (lives == 1)
		{
			StartPages = 0;
			HomePage = 2;
		}
		else
		{
			lives--;
			playerX = 470, playerY = 0;
			q1 = 601;
			p1 = 165 + rand() % 611;
			q2 = 601;
			p2 = 165 + rand() % 611;
			q3 = 601;
			p3 = 165 + rand() % 611;
			m = 601;
			x1 = 165 + rand() % 611;
			y2 = 601;
			x2 = 165 + rand() % 611;
			y3 = 601;
			x3 = 165 + rand() % 611;
			playerIndex = 0;
		}
	}
	else if (((playerX + 66) >= x2 && playerX <= (x2 + 66)) && ((playerY + 156) >= y2 && playerY <= (y2 + 156)) && (playerIndex == 0 || playerIndex == 1) && StartPages == 1)
	{
		if (lives == 1)
		{
			StartPages = 0;
			HomePage = 2;
		}
		else
		{
			lives--;
			playerX = 470, playerY = 0;
			q1 = 601;
			p1 = 165 + rand() % 611;
			q2 = 601;
			p2 = 165 + rand() % 611;
			q3 = 601;
			p3 = 165 + rand() % 611;
			m = 601;
			x1 = 165 + rand() % 611;
			y2 = 601;
			x2 = 165 + rand() % 611;
			y3 = 601;
			x3 = 165 + rand() % 611;
			playerIndex = 0;
		}
	}
	else if (((playerX + 66) >= x3 && playerX <= (x3 + 66)) && ((playerY + 156) >= y3 && playerY <= (y3 + 156)) && (playerIndex == 0 || playerIndex == 1) && StartPages == 1)
	{
		if (lives == 1)
		{
			StartPages = 0;
			HomePage = 2;
		}
		else
		{
			lives--;
			playerX = 470, playerY = 0;
			q1 = 601;
			p1 = 165 + rand() % 611;
			q2 = 601;
			p2 = 165 + rand() % 611;
			q3 = 601;
			p3 = 165 + rand() % 611;
			m = 601;
			x1 = 165 + rand() % 611;
			y2 = 601;
			x2 = 165 + rand() % 611;
			y3 = 601;
			x3 = 165 + rand() % 611;
			playerIndex = 0;
		}
	}
	else if (((playerX + 66) >= p1 && playerX <= (p1 + 66)) && ((playerY + 156) >= q1 && playerY <= (q1 + 156)) && StartPages == 1)
	{
		if (lives >= 3)
			lives = 3;
		else
		{
			lives++;
			q1 = 601;
			p1 = 165 + rand() % 611;
		}
	}
	else if (((playerX + 66) >= p2 && playerX <= (p2 + 66)) && ((playerY + 156) >= q2 && playerY <= (q2 + 156)) && power && StartPages == 1)
	{
		power = 0;
		playerIndex = 2;
		q2 = 601;
		p2 = 165 + rand() % 611;
		p3 = 1500;
		q3 = 1500;

	}
	else if (((playerX + 66) >= p3 && playerX <= (p3 + 66)) && ((playerY + 156) >= q3 && playerY <= (q3 + 156)) && power && StartPages == 1)
	{
		power = 0;
		playerIndex = 1;
		q3 = 601;
		p3 = 165 + rand() % 611;
		p2 = 1500;
		q2 = 1500;

	}
	else if (((playerX + 66) >= x1 && playerX <= (x1 + 66)) && ((playerY + 156) >= m && playerY <= (m + 156)) && (playerIndex == 2) && StartPages == 1)
	{
		m = 601;
		x1 = 165 + rand() % 611;
		destroyed = 1;
	}
	else if (((playerX + 66) >= x2 && playerX <= (x2 + 66)) && ((playerY + 156) >= y2 && playerY <= (y2 + 156)) && (playerIndex == 2) && StartPages == 1)
	{
		y2 = 601;
		x2 = 165 + rand() % 611;
		destroyed = 1;
	}
	else if (((playerX + 66) >= x3 && playerX <= (x3 + 66)) && ((playerY + 156) >= y3 && playerY <= (y3 + 156)) && (playerIndex == 2) && StartPages == 1)
	{
		y3 = 601;
		x3 = 165 + rand() % 611;
		destroyed = 1;
	}
	else if (((p4) >= x1 && p4 <= (x1 + 66)) && ((q4) >= m && q4 <= (m + 156)) && (playerIndex == 1) && StartPages == 1)
	{
		m = 601;
		x1 = 165 + rand() % 611;
		bullet = 0;
		destroyed = 1;
	}
	else if (((p4) >= x2 && p4 <= (x2 + 66)) && ((q4) >= y2 && q4 <= (y2 + 156)) && (playerIndex == 1) && StartPages == 1)
	{
		y2 = 601;
		x2 = 165 + rand() % 611;
		bullet = 0;
		destroyed = 1;
	}
	else if (((p4) >= x3 && p4 <= (x3 + 66)) && ((q4) >= y3 && q4 <= (y3 + 156)) && (playerIndex == 1) && StartPages == 1)
	{
		y3 = 601;
		x3 = 165 + rand() % 611;
		bullet = 0;
		destroyed=1;
	}
	else if (((playerX) >= 788 && playerX <= (951)) && ((playerY) >= 550 && playerY <= (600)) && CurvePage == 1)
	{
		StartButtonClickHandler();
		playerX = 500;
		playerY = 0;
	}
	else if (((playerX) >= 197 && playerX <= (1000)) && ((playerY) >= 0 && playerY <= (155)) && CurvePage == 1)
	{
		if (lives == 1)
		{
			CurvePage = 0;
			HomePage = 2;
		}
		else
		{
			lives--;
			playerX = 30, playerY = 0;
			
		}
	}
	else if (((playerX) >= 0 && playerX <= (788)) && ((playerY) >= 400 && playerY <= (600)) && CurvePage == 1)
	{
		if (lives == 1)
		{
			CurvePage = 0;
			HomePage = 2;
		}
		else
		{
			lives--;
			playerX = 30, playerY = 0;

		}
	}
}

//For background Rendering

int totalImagCount = 30;
int increment = 20;
char backgroundImagePath[200][250] = { "images\\background\\01.bmp", "images\\background\\02.bmp", "images\\background\\03.bmp", "images\\background\\04.bmp",
"images\\background\\05.bmp", "images\\background\\06.bmp", "images\\background\\07.bmp", "images\\background\\08.bmp", "images\\background\\09.bmp", 
"images\\background\\10.bmp", "images\\background\\11.bmp", "images\\background\\12.bmp", "images\\background\\13.bmp", "images\\background\\14.bmp", 
"images\\background\\15.bmp", "images\\background\\16.bmp", "images\\background\\17.bmp", "images\\background\\18.bmp", "images\\background\\19.bmp", 
"images\\background\\20.bmp", "images\\background\\21.bmp", "images\\background\\22.bmp", "images\\background\\23.bmp", "images\\background\\24.bmp", 
"images\\background\\25.bmp", "images\\background\\26.bmp", "images\\background\\27.bmp", "images\\background\\28.bmp", "images\\background\\29.bmp", 
"images\\background\\30.bmp" };

int imgPosition[100];
int backgroundY = 0;
int backgroundImagePathIndex = 0;

void inatializeImagPosition()
{
	int i, j;
	for (i = 0, j = 0; i < totalImagCount; i++)
	{
		imgPosition[i] = j;
		j = j + increment;
	}
}

void moveBackground()
{
	for (int i = 0; i < totalImagCount; i++)
	{
		imgPosition[i] = imgPosition[i] - increment;
	}
	for (int i = 0; i < totalImagCount; i++)
	{
		if (imgPosition[i] < 0)
		{
			imgPosition[i] = 600 - increment;
		}
	}
}

void renddering()
{
	if (StartPages==1)
	for (int i = 0; i < totalImagCount; i++)
	{
		iShowBMP2(0, imgPosition[i], backgroundImagePath[i], 0);
	}
	/*if (CurvePage == 1)
	for (int i = 0; i < totalImagCount; i++)
	{
		iShowBMP2(0, imgPosition[i], backgroundImagePath[i], 0);
	}*/

}

//For timer,level and score
int level = 1;
int second = 0;
int pd = 0;
int score = 0;
char sec[10000];
int minute = 0;
int hour = 0;
char hr[10000];
int totalSecond = 0;
char point[10000];
char lvl[10000];

void changeTimer()
{
	if (StartPages == 1 || CurvePage==1)
	{
		totalSecond = (second++) + (60 * minute) + (60 * 60 * hour);
		if (StartPages == 1)
		score = score + second + destroyed + speed;
		destroyed = 0;
		speed = 0;
		if (second % 60 == 0)
		{
			level++;
			decrement = decrement + 0.5;
			control_increment = control_increment + 1;
			nitro_increment = nitro_increment + 1;
			bullet_increment = bullet_increment + 0.5;
		}
		if (playerIndex == 1 || playerIndex == 2)
		{
			pd++;
			if (pd % 10 == 0)
				playerIndex = 0,pd=0;
		}
		if (playerIndex == 0)
		{
			pd++;
			if (pd % 20 == 0)
				power = 1, pd = 0;
		}
		if (second == 90)
		{
			playerX = 30;
			playerY = 0;
			curveButtonClickHandler();

		}
	}
}

void drawTimer()
{
	if (StartPages == 1)
	{
		iSetColor(255, 204, 203);
		iFilledRectangle(840, 510, 160, 60);

		iSetColor(255, 0, 0);
		sprintf_s(sec, "%d", second);
		iText(940, 525, sec, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(850, 525, "Timer", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 204, 203);
		iFilledRectangle(0, 510, 150, 40);

		iSetColor(255, 0, 0);
		sprintf_s(lvl, "%d", level);
		iText(110, 525, lvl, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(10, 525, "Level", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 204, 203);
		iFilledRectangle(840, 450, 120, 60);
		iSetColor(0, 0, 0);
		iText(865, 485, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(point, "%d", score);
		iText(875, 456, point, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (CurvePage == 1)
	{
		iSetColor(255, 204, 203);
		iFilledRectangle(540, 510, 160, 60);

		iSetColor(255, 0, 0);
		sprintf_s(sec, "%d", second);
		iText(640, 525, sec, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(550, 525, "Timer", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 204, 203);
		iFilledRectangle(0, 510, 150, 40);

		iSetColor(255, 0, 0);
		sprintf_s(lvl, "%d", level);
		iText(110, 525, lvl, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(10, 525, "Level", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 204, 203);
		iFilledRectangle(540, 450, 120, 60);
		iSetColor(0, 0, 0);
		iText(565, 485, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(point, "%d", score);
		iText(575, 456, point, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

//For saving scores and showing high scores

void newHighscore();
void readScore();
int len = 0;
char str1[100];
bool newscore = true;

struct hscore{
	char name[30];
	int score = 0;
}high_score[5];

void readScore()
{
	FILE *fp;
	fp = fopen("Score.txt", "r");
	char showName[5][30], showScore[5][5];
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s %d\n", high_score[i].name, &high_score[i].score);
	}
	for (int i = 0; i < 5; i++)
	{
		sprintf(showName[i], "%s", high_score[i].name);
		sprintf(showScore[i], "%d", high_score[i].score);
		iSetColor(0, 0, 0);
		iText(400, 450 - 50 * i, showName[i], GLUT_BITMAP_HELVETICA_18);
		iText(500, 450 - 50 * i, showScore[i], GLUT_BITMAP_HELVETICA_18);
	}
	fclose(fp);
}

void newHighscore()//Mistake newHighscore()
{
	FILE *fp;
	fp = fopen("Score.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s %d\n", high_score[i].name, &high_score[i].score);
	}
	int t;
	char n[30];
	if (newscore)
	{
		for (int i = 0; i < 5; i++)
		{
			if (high_score[i].score < score)
			{
				high_score[4].score = score;
				strcpy(high_score[4].name, str1);
				for (int j = 0; j < 5; j++)
				{
					for (int k = 5; k>j; k--){
						if (high_score[k].score > high_score[k - 1].score)
						{
							int t = high_score[k - 1].score;
							high_score[k - 1].score = high_score[k].score;
							high_score[k].score = t;

							char n[50];
							strcpy(n, high_score[k - 1].name);
							strcpy(high_score[k - 1].name, high_score[k].name);
							strcpy(high_score[k].name, n);
						}
					}
				}

				FILE* fp = fopen("Score.txt", "w");
				for (int i = 0; i < 5; i++)
				{
					fprintf(fp, "%s %d\n", high_score[i].name, high_score[i].score);
				}
				fclose(fp);

				newscore = false;
				break;
			}
		}
	}
}

void showChar()
{
	iSetColor(204, 229, 255);
	iFilledRectangle(492, 362, 160, 30);
	iFilledRectangle(400, 406, 160, 30);
	iRectangle(495, 362, 160, 30);
	iSetColor(255, 0, 0);
	iText(400, 412, "Enter your Name : ", GLUT_BITMAP_HELVETICA_18);
	iText(500, 372, str1, GLUT_BITMAP_HELVETICA_18);
}
void takeinput(unsigned key)
{
	if (key == '\r')
	{
		HomePage = 1;
		newHighscore();
	}

	else if (key == '\b')
	{
		if (len <= 0)
			len = 0;
		else
			len--;

		str1[len] = '\0';
	}
	else{
		str1[len] = key;
		len++;

		if (len > 15)
			len = 15;

		str1[len] = '\0';
	}
}

void iDraw()
{
	iClear();
	if (intro == 1)
	{
		velocityVortex();
	}
	else if (HomePage == 1)
	{
		drawHomePage();
	}
	else if (StartPages == 1)
	{
		drawStart();
	}
	else if (ControlsPage == 1)
	{
		drawControls();
	}
	else if(CreditsPage == 1)
	{
		drawCredits();
	}
	else if (HighScorePage == 1)
	{
		drawHighScore();
	}
	else if (Exit == 1)
	{
		drawExit();
	}
	else if (HomePage == 2)
	{
		gameover();
		showChar();
	}
	else if (CurvePage == 1)
	{
		drawCurve();
	}
	
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	if (HomePage == 1 && (mx >= 100 && mx <= 299) && (my >= 493 && my <= 550))
	{
		a1 = 110;
		b1 = 40;
	}
	else if (HomePage == 1 && (mx >= 100 && mx <= 299) && (my >= 392 && my <= 450))
	{
		a2 = 110;
		b2 = 40;
	}
	else if (HomePage == 1 && (mx >= 100 && mx <= 299) && (my >= 190 && my <= 251))
	{
		a4 = 110;
		b4 = 40;
	}
	else if (HomePage == 1 && (mx >= 100 && mx <= 299) && (my >= 291 && my <= 350))
	{
		a3 = 110;
		b3 = 40;
	}
	else if (HomePage == 1 && (mx >= 100 && mx <= 299) && (my >= 89 && my <= 153))
	{
		a5 = 110;
		b5 = 40;
	}
	else if ((CreditsPage == 1 || ControlsPage == 1 || HighScorePage == 1 || HomePage == 2) && (mx >= 430 && mx <= 634) && (my >= 70 && my <= 132))
	{
		a6 = 110;
		b6 = 40;
	}
	else
	{
		a1 = 100, a2 = 100;
		a3 = 100, a4 = 100, a5 = 100, a6 = 100;
		b1 = 30, b2 = 30;
		b3 = 30, b4 = 30, b5 = 30, b6 = 30;
	}
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("mx = %d my = %d \n", mx, my);
		if (intro == 1 && (mx >= 551&& mx <= 768) && (my >= 100&& my <= 119))
		{
			HomeButtonClickHandler();
		}
		else if (HomePage == 1 && (mx >= 100 && mx <= 299) && (my >= 493 && my <= 550))
		{
			PlaySound("audio\\ButtonSound.wav", NULL, SND_ASYNC);
			StartButtonClickHandler();
		}
		else if (HomePage == 1 && (mx >= 100&& mx <= 299) && (my >= 392&& my <= 450))
		{
			PlaySound("audio\\ButtonSound.wav", NULL, SND_ASYNC);
			ControlsButtonClickHandler();
		}
		else if (HomePage == 1 && (mx >= 100&& mx <= 299) && (my >= 190&& my <= 251))
		{
			PlaySound("audio\\ButtonSound.wav", NULL, SND_ASYNC);
			CreditsButtonClickHandler();
		}
		else if (HomePage == 1 && (mx >= 100&& mx <= 299) && (my >= 291&& my <= 350))
		{
			PlaySound("audio\\ButtonSound.wav", NULL, SND_ASYNC);
			HighScoreButtonClickHandler();
		}
		else if (HomePage == 1 && (mx >= 100&& mx <= 299) && (my >= 89&& my <= 153))
		{
			PlaySound("audio\\ButtonSound.wav", NULL, SND_ASYNC);
			ExitButtonClickHandler();
		}
		else if ((CreditsPage == 1 || ControlsPage == 1 || HighScorePage == 1 || HomePage==2) && (mx >= 430 && mx <= 634) && (my >= 70 && my <= 132))
		{
			PlaySound("audio\\ButtonSound.wav", NULL, SND_ASYNC);
			BackButtonClickHandler();
		}
		
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	/*if (key == '\r')
	{
		
	}*/
	if (HomePage == 2)
	{
		takeinput(key);
	}
	if (key == 27)
	{
		if ((StartPages == 1 || CreditsPage == 1 || ControlsPage == 1 || HighScorePage == 1 || HomePage == 2))
		{
			PlaySound("audio\\ButtonSound.wav", NULL, SND_ASYNC);
			BackButtonClickHandler();
		}
	}
	if (key == 70 || key == 102)
	{
		if (playerIndex == 1)
		{
			bullet = 1;
			bullets++;
			p4 = playerX + 35;
			q4 = playerY + 154;
		}
	}

	if (key == 'x' || key == 'X')
	{
		if (StartPages == 1 || CurvePage == 1)
		{	playerY = playerY + nitro_increment;
			nitro = 1;
			speed = 2;
		}
		if (playerY > 453)
		{
			playerY = 0;
		}
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		if (CurvePage == 1)
		{
			if (playerIndex == 0 || playerIndex == 3 || playerIndex == 6 || playerIndex == 9)
				playerIndex = 9;
			else if (playerIndex == 1 || playerIndex == 4 || playerIndex == 7 || playerIndex == 10)
				playerIndex = 10;
			else if (playerIndex == 2 || playerIndex == 5 || playerIndex == 8 || playerIndex == 11)
				playerIndex = 11;
		}
		if (StartPages == 1)
		{
			if (playerIndex == 0 || playerIndex == 3 || playerIndex == 6 || playerIndex == 9)
				playerIndex = 0;
			else if (playerIndex == 1 || playerIndex == 4 || playerIndex == 7 || playerIndex == 10)
				playerIndex = 1;
			else if (playerIndex == 2 || playerIndex == 5 || playerIndex == 8 || playerIndex == 11)
				playerIndex = 2;
		}
		playerX = playerX + control_increment;
		if (playerX > 770 && StartPages==1)
		{
			playerX = 770;
		}
		nitro = 0;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (CurvePage == 1)
		{
			if (playerIndex == 0 || playerIndex == 3 || playerIndex == 6 || playerIndex == 9)
				playerIndex = 3;
			else if (playerIndex == 1 || playerIndex == 4 || playerIndex == 7 || playerIndex == 10)
				playerIndex = 4;
			else if (playerIndex == 2 || playerIndex == 5 || playerIndex == 8 || playerIndex == 11)
				playerIndex = 5;
		}
		if (StartPages == 1)
		{
			if (playerIndex == 0 || playerIndex == 3 || playerIndex == 6 || playerIndex == 9)
				playerIndex = 0;
			else if (playerIndex == 1 || playerIndex == 4 || playerIndex == 7 || playerIndex == 10)
				playerIndex = 1;
			else if (playerIndex == 2 || playerIndex == 5 || playerIndex == 8 || playerIndex == 11)
				playerIndex = 2;
		}
		playerX = playerX - control_increment;
		if (playerX < 164 && StartPages == 1)
		{
			playerX = 164;
		}
		nitro = 0;
	}
	if (key == GLUT_KEY_UP)
	{
		if (CurvePage == 1)
		{
			if (playerIndex == 0 || playerIndex == 3 || playerIndex == 6 || playerIndex == 9)
				playerIndex = 0;
			else if (playerIndex == 1 || playerIndex == 4 || playerIndex == 7 || playerIndex == 10)
				playerIndex = 1;
			else if (playerIndex == 2 || playerIndex == 5 || playerIndex == 8 || playerIndex == 11)
				playerIndex = 2;
		}
		if (StartPages == 1)
		{
			if (playerIndex == 0 || playerIndex == 3 || playerIndex == 6 || playerIndex == 9)
				playerIndex = 0;
			else if (playerIndex == 1 || playerIndex == 4 || playerIndex == 7 || playerIndex == 10)
				playerIndex = 1;
			else if (playerIndex == 2 || playerIndex == 5 || playerIndex == 8 || playerIndex == 11)
				playerIndex = 2;
		}
		nitro = 0;
		speed = 1;
		playerY = playerY + control_increment;
		if (playerY > 453 && StartPages == 1)
		{
			playerY = 0;
		}
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (CurvePage == 1)
		{
			if (playerIndex == 0 || playerIndex == 3 || playerIndex == 6 || playerIndex == 9)
				playerIndex = 6;
			else if (playerIndex == 1 || playerIndex == 4 || playerIndex == 7 || playerIndex == 10)
				playerIndex = 7;
			else if (playerIndex == 2 || playerIndex == 5 || playerIndex == 8 || playerIndex == 11)
				playerIndex = 8;
		}
		if (StartPages == 1)
		{
			if (playerIndex == 0 || playerIndex == 3 || playerIndex == 6 || playerIndex == 9)
				playerIndex = 0;
			else if (playerIndex == 1 || playerIndex == 4 || playerIndex == 7 || playerIndex == 10)
				playerIndex = 1;
			else if (playerIndex == 2 || playerIndex == 5 || playerIndex == 8 || playerIndex == 11)
				playerIndex = 2;
		}
		nitro = 0;
		playerY = playerY - control_increment;
		if (playerY < 0)
		{
			playerY = 0;
		}
	}
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
	if (key == GLUT_KEY_F1)
	{
		if (MusicOn)
		{
			MusicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			MusicOn = true;
			PlaySound("audio\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
	
}

void velocityVortex()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\hp.bmp",0);
	iShowBMP2(700, 300, "images\\logo1.bmp", 0);
	iSetColor(224, 224, 224);
	iText(550, 100, "<Tap To Main Menu>", GLUT_BITMAP_TIMES_ROMAN_24);
	glLineWidth(50);
}
void drawHomePage()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\homepage.bmp",0);
	iShowBMP2(700, 350, "images\\logo2.bmp", 0);
	iSetColor(137, 207, 244);
	iFilledEllipse(200, 520, a1, b1);
	iFilledEllipse(200, 420, a2, b2);
	iFilledEllipse(200, 320, a3, b3);
	iFilledEllipse(200, 220, a4, b4);
	iFilledEllipse(200, 120, a5, b5);
	iSetColor(100, 100, 100);
	iEllipse(200, 520, a1, b1);
	iEllipse(200, 420, a2, b2);
	iEllipse(200, 320, a3, b3);
	iEllipse(200, 220, a4, b4);
	iEllipse(200, 120, a5, b5);
	iSetColor(0, 0, 0);
	iText(170, 513, "Start", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(160, 410, "Controls", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(150, 315, "High Score", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(165, 215, "Credits", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(170, 115, "Exit", GLUT_BITMAP_TIMES_ROMAN_24);
	glLineWidth(5);
}
void drawStart()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1000, 600);
	renddering();

	
	iShowBMP2(playerX, playerY, player[playerIndex], 0);
	iShowBMP2(x1, m, "images\\v1.bmp", 0);
	iShowBMP2(x2, y2, "images\\v2.bmp", 0);
	iShowBMP2(x3, y3, "images\\v3.bmp", 0);
	iShowBMP2(p1, q1, "images\\p1.bmp", 0);
	/*if (playerIndex != 0)
	{
		
	}*/
	if (power)
	{
		iShowBMP2(p2, q2, "images\\p2.bmp", 0);
		iShowBMP2(p3, q3, "images\\p3.bmp", 0);
		q2 = q2 - decrement;
		if (q2 <= -10)
		{
			q2 = 601;
			p2 = 165 + rand() % 611;
		}//collision();

		q3 = q3 - decrement;
		if (q3 <= -10)
		{
			q3 = 601;
			p3 = 165 + rand() % 611;
		}//collision();
	}
	if (nitro)
	{
		iShowBMP2(playerX+48, playerY-70, "images\\nitro.bmp", 0);
	}
	if (lives == 3)
	{
		iShowBMP2(875, 10, "images\\Life.bmp", 0);
		iShowBMP2(875, 100, "images\\Life.bmp", 0);
		iShowBMP2(875, 190, "images\\Life.bmp", 0);
	}
	else if (lives == 2)
	{
		iShowBMP2(875, 10, "images\\Life.bmp", 0);
		iShowBMP2(875, 100, "images\\Life.bmp", 0);
	}
	else if (lives == 1)
	{
		iShowBMP2(875, 10, "images\\Life.bmp", 0);
	}

	m = m - decrement;
	if (m <= -10)
	{
		m = 601;
		x1 = 165 + rand() % 611;
	}collision();

	y2 = y2 - decrement;
	if (y2 <= -10)
	{
		y2 = 601;
		x2 = 165 + rand() % 611;
	}//collision();

	y3 = y3 - decrement;
	if (y3 <= -10)
	{
		y3 = 601;
		x3 = 165 + rand() % 611;
	}//collision();

	q1 = q1 - decrement;
	if (q1 <= -10)
	{
		q1 = 601;
		p1 = 165 + rand() % 611;
	}//collision();

	if (bullet)
	{
		
		
		/*iShowBMP2(p4, q4, "images\\bullet.bmp", 0);

		q4 = q4 + bullet_increment;
		if (q4 == 600)
		{
			bullet = 0;
		}*/
		for (int i = 0; i < bullets; i++)
		{
			iShowBMP2(p4, q4 + i * 50, "images\\bullet.bmp", 0);
			q4 = q4 + 5;
		}
		
	}

	drawTimer();
	
}
void drawCurve()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\CurveRoad.bmp", 0);
	iShowBMP2(playerX, playerY, player[playerIndex], 0);
	if (nitro)
	{
		iShowBMP2(playerX + 48, playerY - 70, "images\\nitro.bmp", 0);
	}
	if (lives == 3)
	{
		iShowBMP2(875, 10, "images\\Life.bmp", 0);
		iShowBMP2(875, 100, "images\\Life.bmp", 0);
		iShowBMP2(875, 190, "images\\Life.bmp", 0);
	}
	else if (lives == 2)
	{
		iShowBMP2(875, 10, "images\\Life.bmp", 0);
		iShowBMP2(875, 100, "images\\Life.bmp", 0);
	}
	else if (lives == 1)
	{
		iShowBMP2(875, 10, "images\\Life.bmp", 0);
	}
	drawTimer();
	collision();
}
void drawControls()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\ControlsPage.bmp", 0);
	iSetColor(137, 207, 244);
	iFilledEllipse(533, 100, a6, b6);
	iSetColor(100, 100, 100);
	iEllipse(533, 100, a6, b6);
	iSetColor(0, 0, 0);
	iText(490, 90, "Go Back", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawCredits()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\CreditsPage.bmp", 0);
	iSetColor(137, 207, 244);
	iFilledEllipse(533, 100, a6, b6);
	iSetColor(100, 100, 100);
	iEllipse(533, 100, a6, b6);
	iSetColor(0, 0, 0);
	iText(490, 90, "Go Back", GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawHighScore()
{
	//iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\HighScorePage.bmp", 0);
	iSetColor(204, 229, 255);
	iFilledRectangle(375, 240, 175, 300);
	iSetColor(137, 207, 244);
	iFilledEllipse(533, 100, a6, b6);
	iSetColor(100, 100, 100);
	iEllipse(533, 100, a6, b6);
	iSetColor(0, 0, 0);
	iText(400, 512, "Name", GLUT_BITMAP_HELVETICA_18);
	iText(490, 512, "Score", GLUT_BITMAP_HELVETICA_18);
	iText(490, 90, "Go Back", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(200, 200, 200);
	iLine(375, 495, 550, 495);
	iLine(467, 239, 467, 540);
	iSetColor(255, 255, 255);
	//iText(375, 625, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(925, 625, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);

	readScore();
	HomePage = 2;
}
void drawExit()
{
	exit(1);
}
void HomeButtonClickHandler()
{
	intro = 0;
	HomePage = 1;
	StartPages = 0;
	ControlsPage = 0;
	CreditsPage = 0;
	HighScorePage = 0;
	Exit = 0;
}

void StartButtonClickHandler()
{
	intro = 0;
	HomePage = 0;
	StartPages = 1;
	ControlsPage = 0;
	CreditsPage = 0;
	HighScorePage = 0;
	Exit = 0;
}
void CreditsButtonClickHandler()
{
	HomePage = 0;
	StartPages = 0;
	ControlsPage = 0;
	CreditsPage = 1;
	HighScorePage = 0;
	Exit = 0;
}
void ControlsButtonClickHandler()
{
	HomePage = 0;
	StartPages = 0;
	ControlsPage = 1;
}
void HighScoreButtonClickHandler()
{
	HomePage = 0;
	StartPages = 0;
	ControlsPage = 0;
	CreditsPage = 0;
	HighScorePage = 1;
	CreditsPage = 0;
	Exit = 0;

}
void ExitButtonClickHandler()
{
	HomePage = 0;
	StartPages = 0;
	ControlsPage = 0;
	CreditsPage = 0;
	HighScorePage = 0;
	Exit = 1;
}
void BackButtonClickHandler()
{
	HomePage = 1;
	StartPages = 0;
	ControlsPage = 0;
	CreditsPage = 0;
	HighScorePage = 0;
	Exit = 0;
	intro = 0;
}

void curveButtonClickHandler()
{
	HomePage = 0;
	StartPages = 0;
	ControlsPage = 0;
	CreditsPage = 0;
	HighScorePage = 0;
	Exit = 0;
	intro = 0;
	CurvePage = 1;
}

void gameover()
{
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\GameOver.bmp", 0);
	iSetColor(137, 207, 244);
	iFilledEllipse(533, 100, a6, b6);
	iSetColor(100, 100, 100);
	iEllipse(533, 100, a6, b6);
	iSetColor(0, 0, 0);
	iText(490, 90, "Go Back", GLUT_BITMAP_TIMES_ROMAN_24);
	HomePage = 2;
}


int main()
{
	///srand((unsigned)time(NULL));
	srand(time(0));
	if (MusicOn)
		PlaySound("audio\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
	
	
	inatializeImagPosition();
	iSetTimer(10, moveBackground);
	iSetTimer(1000, changeTimer);
	
	iInitialize(1000, 600, "Velocity Vortex");
	///updated see the documentations
	iStart();
	return 0;
}