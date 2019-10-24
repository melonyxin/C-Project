#include "Header.h"

int main()
{
	srand((unsigned)time(NULL));
	Load_IMAGE(); //����ͼƬ

	initgraph(WIDE, HIGH,NULL);
	setbkmode(TRANSPARENT);
	
	Ready();

	Start();

	closegraph();
}

/*****************************************************/
/*******************              ********************/
/********************    Data    *********************/
/*******************              ********************/
/*****************************************************/

/*--------------------������Դ��ʼ��-----------------*/
//����ͼƬ
void Load_IMAGE()
{
	//���ر���ͼƬ
	loadimage(&back, "res\\back.jpg");
	loadimage(&start, "res\\start.jpg");
	//�������ҷɵ�����
	loadimage(&aim_p[1][0][0][0], "res\\aimR1.jpg");
	loadimage(&aim_p[1][0][1][0], "res\\aimR2.jpg");
	loadimage(&aim_p[1][0][2][0], "res\\aimR3.jpg");
	loadimage(&aim_p[1][1][0][0], "res\\aimRB1.jpg");
	loadimage(&aim_p[1][1][1][0], "res\\aimRB2.jpg");
	loadimage(&aim_p[1][1][2][0], "res\\aimRB3.jpg");
	//��������ɵ�����
	loadimage(&aim_p[1][0][0][1], "res\\aimL1.jpg");
	loadimage(&aim_p[1][0][1][1], "res\\aimL2.jpg");
	loadimage(&aim_p[1][0][2][1], "res\\aimL3.jpg");
	loadimage(&aim_p[1][1][0][1], "res\\aimLB1.jpg");
	loadimage(&aim_p[1][1][1][1], "res\\aimLB2.jpg");
	loadimage(&aim_p[1][1][2][1], "res\\aimLB3.jpg");

	//�������ҷɵĴ�����
	loadimage(&aim_p[0][0][0][0], "res\\bigR1.jpg");
	loadimage(&aim_p[0][0][1][0], "res\\bigR2.jpg");
	loadimage(&aim_p[0][0][2][0], "res\\bigR3.jpg");
	loadimage(&aim_p[0][1][0][0], "res\\bigRB1.jpg");
	loadimage(&aim_p[0][1][1][0], "res\\bigRB2.jpg");
	loadimage(&aim_p[0][1][2][0], "res\\bigRB3.jpg");
	//��������ɵĴ�����
	loadimage(&aim_p[0][0][0][1], "res\\bigL1.jpg");
	loadimage(&aim_p[0][0][1][1], "res\\bigL2.jpg");
	loadimage(&aim_p[0][0][2][1], "res\\bigL3.jpg");
	loadimage(&aim_p[0][1][0][1], "res\\bigLB1.jpg");
	loadimage(&aim_p[0][1][1][1], "res\\bigLB2.jpg");
	loadimage(&aim_p[0][1][2][1], "res\\bigLB3.jpg");
	//���ذ�ť��ʽ
	loadimage(&button[0][0], "res\\but_1.jpg");
	loadimage(&button[0][1], "res\\butt_1.jpg");
	loadimage(&button[1][0], "res\\but_2.jpg");
	loadimage(&button[1][1], "res\\butt_2.jpg");
	loadimage(&button[2][0], "res\\but_3.jpg");
	loadimage(&button[2][1], "res\\butt_3.jpg");
	loadimage(&button[3][0], "res\\but_4.jpg");
	loadimage(&button[3][1], "res\\butt_4.jpg");
	loadimage(&button[4][0], "res\\but_5.jpg");
	loadimage(&button[4][1], "res\\butt_5.jpg");
	loadimage(&button[5][0], "res\\but_6.jpg");
	loadimage(&button[5][1], "res\\butt_6.jpg");
	loadimage(&button[6][0], "res\\but_7.jpg");
	loadimage(&button[6][1], "res\\butt_7.jpg");

	loadimage(&rect, "res\\rect.jpg");
	loadimage(&help, "res\\help.jpg");
	loadimage(&set, "res\\set.jpg");
	loadimage(&set_on, "res\\set_on.jpg");
	loadimage(&login, "res\\login.jpg");
	loadimage(&input, "res\\input.jpg");
	loadimage(&regi, "res\\register.jpg");
	loadimage(&click[0], "res\\click.jpg");
	loadimage(&click[1], "res\\clickB.jpg");

	hcur = (HCURSOR)LoadImage(NULL, "res\\meau.cur", IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
	hcur_game = (HCURSOR)LoadImage(NULL, "res\\game.ico", IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);//�������ͼ��
	
}

//��ʼ�������ֵ�ͷ���
void Get_Rank()
{
	FILE *fp;

	if ((fp = fopen("ranking.ini", "r")) == NULL)
	{
		if ((fp = fopen("ranking.ini", "w")) != NULL)
		{
			fprintf(fp, "[Ranking]\n\n");
			for (int i = 1; i <= 5; i++)
				fprintf(fp, "%d.**** 0\n", i);
			fclose(fp);
		}
		else {
			exit(0);
		}	
	}
	if ((fp = fopen("ranking.ini", "r")) != NULL)
	{
		int pig;
		fscanf(fp, "[Ranking]\n\n");
		for (int i = 0; i < 5; i++)
			fscanf(fp, "%d.%s %d\n", &pig, record[i].name, &record[i].score);
		fclose(fp);
	}
	else exit(0);
}

//�����ʼ����
void Ready()
{
	hwnd = GetHWnd();// ��ȡ��ͼ���ھ��
	Get_Rank();
	Creat_Rank();
	cleardevice();
	mciSendString("open res\\back.wma alias BackMusic", NULL, 0, NULL);
	mciSendString("open res\\game.wma alias GameMusic", NULL, 0, NULL);
	mciSendString("setaudio BackMusic volume to 300", NULL, 0, NULL);		//����������С
	mciSendString("play BackMusic repeat", NULL, 0, NULL);
	SetClassLong(hwnd, GCLP_HCURSOR, (long)hcur);
}

/*---------------------------------------------------*/

/*---------------��¼ע����漰��ع���--------------*/

//��¼����
int Login()
{
	MOUSEMSG Mouse = GetMouseMsg();
	USERMSG User = { "\0","\0" };
	char cipher[17] = "\0";

	settextcolor(BLACK);
	settextstyle(0, 0, NULL);
	int m = 0;
	int num_name = 0;
	int num_pass = 0;
	FlushMouseMsgBuffer();
	putimage(0, 0, &start);

	while (true)
	{
		if (MouseHit())
			Mouse = GetMouseMsg();
		BeginBatchDraw();


		putimage(510, 195, &login);

		m += Input_on(m % 2, Mouse, 293);

		switch (m % 2)
		{
		case 0:putimage(605, 235, &input); num_name += Input(User.name, num_name); break;
		case 1:putimage(605, 293, &input); num_pass += Input(User.passward, num_pass); break;
		}

		for (int i = 0; i < num_pass; i++)
			cipher[i] = '*';
		cipher[num_pass] = '\0';

		outtextxy(609, 240, User.name);
		outtextxy(609, 300, cipher);

		if (Button_On(5, 566, 358, 200, 50, Mouse))
		{
			switch (Login_In(User))
			{
			case 0:outtextxy(628, 505, "δ��ע��"); break;
			case 1:outtextxy(628, 505, "�������"); break;
			case 2:Get_Information(User.name); Creat_Record(); loading_login(); return 0;
			}
		}
		if (Button_On(6, 566, 420, 200, 50, Mouse))  return 1;

		EndBatchDraw();

	}
}

//��¼�ж�
int Login_In(USERMSG User)
{
	char pass[17] = "\0";

	FILE *fp;

	fp = fopen(User.name, "r");
	if (fp)
	{
		fscanf(fp, "name=%s\n");
		fscanf(fp, "passward=%s\n", pass);
		fclose(fp);
		if (strcmp(pass, User.passward))
			return 1;
		else
			return 2;
	}
	else {
		return 0;
	}
	fclose(fp);
	return 1;
}

//ע�����
void Register()
{
	MOUSEMSG Mouse = GetMouseMsg();
	USERMSG User = { "\0","\0" };
	settextcolor(BLACK);
	int m = 0;
	int num_name = 0;
	int num_pass = 0;
	FlushMouseMsgBuffer();
	putimage(0, 0, &start);

	while (true)
	{
		if (MouseHit())
			Mouse = GetMouseMsg();
		BeginBatchDraw();

		putimage(510, 195, &regi);

		m += Input_on(m % 2, Mouse, 325);

		switch (m % 2)
		{
		case 0:putimage(605, 235, &input); num_name += Input(User.name, num_name); break;
		case 1:putimage(605, 325, &input); num_pass += Input(User.passward, num_pass); break;
		}

		outtextxy(609, 240, User.name);
		outtextxy(609, 330, User.passward);

		if (Button_On(6, 566, 420, 200, 50, Mouse))
		{
			if (User.name[0] == '\0')
				outtextxy(628, 497, "�û�������Ϊ��");
			else if (User.passward[0] == '\0')
				outtextxy(628, 497, "���벻��Ϊ��");
			else if (Register_In(User))
				return;
			else
				outtextxy(628, 505, "�ѱ�ע��");
		}

		if (Button_On(4, 601, 517, 130, 50, Mouse))	break;

		EndBatchDraw();
	}
}

//ע���ж�
bool Register_In(USERMSG User)
{
	FILE *fp;

	fp = fopen(User.name, "r");
	if (fp)
	{
		fclose(fp);
		return false;
	}
	//	fclose(fp);	
	fp = fopen(User.name, "w");
	if (fp)
	{
		fprintf(fp, "name=%s\n", User.name);
		fprintf(fp, "passward=%s\n", User.passward);
		fprintf(fp, "\n");
		fprintf(fp, "game_time=0\n");
		fprintf(fp, "kill_number=0\n");
		fprintf(fp, "1.0\n");
		fprintf(fp, "2.0\n");
		fprintf(fp, "3.0\n");
		fprintf(fp, "4.0\n");
		fprintf(fp, "5.0\n");
		fclose(fp);
	}

	return true;
}

//��������빦��
int Input(char user[], int num)
{
	char ch = 0;
	if (_kbhit())
	{
		ch = _getch();
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
		{
			user[num] = ch;
			user[num + 1] = '\0';
			return 1;
		}
		else if (ch == VK_BACK && num >0)
		{
			user[num - 1] = '\0';
			return -1;
		}
	}


	return 0;
}

//������ȡ�����ж�
int Input_on(int m, MOUSEMSG Mouse, int y)
{
	if (Mouse.mkLButton)
	{
		switch (m)
		{
		case 0:if (Mouse.x > 605 && Mouse.x < 791 && Mouse.y>y && Mouse.y < y + 30)  return 1; break;
		case 1:if (Mouse.x > 605 && Mouse.x < 791 && Mouse.y>235 && Mouse.y < 265)  return 1; break;
		}
	}

	return 0;
}

//��¼���ȡ�û���Ϣ
void Get_Information(char name[])
{
	FILE *fp;

	fp = fopen(name, "r");
	if (fp)
	{
		fscanf(fp, "name=%s\n", user.name);
		fscanf(fp, "passward=%s\n", user.passward);
		fscanf(fp, "\n");
		fscanf(fp, "game_time=%d\n", &user.game_time);
		fscanf(fp, "kill_number=%d\n", &user.kill_number);
		fscanf(fp, "1.%d\n", &user.score[0]);
		fscanf(fp, "2.%d\n", &user.score[1]);
		fscanf(fp, "3.%d\n", &user.score[2]);
		fscanf(fp, "4.%d\n", &user.score[3]);
		fscanf(fp, "5.%d\n", &user.score[4]);
		fclose(fp);
	}
}

//���������û�����
void Creat_Record()
{
	char num[20];
	BeginBatchDraw();
	putimage(0, 0, &start);
	setcolor(BLACK);
	settextstyle(20, 10, NULL);
	outtextxy(300 - strlen(user.name) * 4, 64, user.name);
	setcolor(WHITE);
	snprintf(num, sizeof(num), "%dh %dm %ds", user.game_time / 3600, user.game_time / 60, user.game_time % 60);
	outtextxy(300 - strlen(num) * 4, 159, num);
	snprintf(num, sizeof(num), "%d", user.kill_number);
	outtextxy(300 - strlen(num) * 4, 250, num);
	for (int i = 0; i < 5; i++)
	{
		snprintf(num, sizeof(num), "%d.", i + 1);
		outtextxy(240, 345 + i * 50, num);
		snprintf(num, sizeof(num), "%d", user.score[i]);
		outtextxy(360 - strlen(num) * 8, 345 + i * 50, num);
	}
	getimage(&game, 0, 0, 1001, 601);
}

//�������а����
void Creat_Rank()
{
	char num[20];
	BeginBatchDraw();
	settextstyle(20, 10, NULL);
	setcolor(WHITE);
	for (int i = 0; i < 5; i++)
	{
		putimage(510, 146, &rect);
		snprintf(num, sizeof(num), "%d.", i + 1);
		outtextxy(550, 162, num);
		outtextxy(610, 162, record[i].name);
		snprintf(num, sizeof(num), "%d", record[i].score);
		outtextxy(770 - strlen(num) * 8, 162, num);
		getimage(&rank[i], 510, 146, 300, 50);
	}
}

/*---------------------------------------------------*/

/*--------------�˵����漰��Ҫ���ܽ���---------------*/

//���Ӹ�������
void Start()
{
	while (Login())    //��¼
	{
		loading_register();
		Register();
		Reback_login();
	}

	while (true)      //����������
	{
		switch (Menu())
		{
		case 0:Loading_game(); Game(); Reback_game(); break;
		case 1:Loading_rank(); Ranking(); Reback_rank(); break;
		case 2:Loading_set(help); Help(); Reback_set(help); break;
		case 3:Loading_set(set); Game_Set(); Reback_set(set); break;
		}
	}
}

//�˵�����
int Menu()
{
	MOUSEMSG Mouse = GetMouseMsg();
	FlushMouseMsgBuffer();
	while (true)
	{
		if (MouseHit())
			Mouse = GetMouseMsg();
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i<4; i++)
			if (Button_On(i, 560, 165 + i * 95, 200, 50, Mouse))   return i;
		EndBatchDraw();
	}
}

//��������
void Help()
{
	MOUSEMSG Mouse = GetMouseMsg();
	FlushMouseMsgBuffer();
	while (true)
	{
		if (MouseHit())
			Mouse = GetMouseMsg();
		BeginBatchDraw();
		putimage(0, 0, &game);
		putimage(510, 146, &help);
		if (Button_On(4, 601, 517, 130, 50, Mouse))	break;
		EndBatchDraw();
	}
}

//��Ϸ���ý���
void Game_Set()
{
	MOUSEMSG Mouse = GetMouseMsg();
	FlushMouseMsgBuffer();
	while (true)
	{
		if (MouseHit())
			Mouse = GetMouseMsg();
		BeginBatchDraw();
		putimage(0, 0, &game);
		putimage(510, 146, &set);
		if (Button_On(4, 601, 517, 130, 50, Mouse))	break;
		Button_On(Mouse);
		EndBatchDraw();
	}
}

//���а����
void Ranking()
{
	MOUSEMSG Mouse = GetMouseMsg();
	FlushMouseMsgBuffer();
	while (true)
	{
		if (MouseHit())
			Mouse = GetMouseMsg();
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 5; i++)
		{
			putimage(510, 146 + i * 71, &rank[i]);
		}
		if (Button_On(4, 601, 517, 130, 50, Mouse))	break;
		EndBatchDraw();
	}
}

//ʵ�ְ�ť����
bool Button_On(int i, int x, int y, int wide, int high, MOUSEMSG Mouse)
{

	if (Mouse.x > x && Mouse.x < x + wide && Mouse.y>y && Mouse.y < y + high)
	{
		putimage(x, y, &button[i][1]);
	}
	else {
		putimage(x, y, &button[i][0]);
	}

	if (Mouse.mkLButton)
	{

		if (Mouse.x > x && Mouse.x < x + wide && Mouse.y>y && Mouse.y < y + high)
		{
			putimage(x, y, &button[i][0]);
			return true;
		}
	}

	return false;
}

//ʵ��ѡ�����
void Button_On(MOUSEMSG Mouse)
{
	for (int i = 0; i < 3; i++)
		putimage(675 + (1 - switch_set[i]) * 65, 226 + i * 35, &set_on);
	putimage(490 + 70 * N, 400, &set_on);

	if (Mouse.mkLButton)
	{
		if (Mouse.x > 675 + switch_set[0] * 65 && Mouse.x < 700 + switch_set[0] * 65 && Mouse.y > 226 && Mouse.y < 251)
		{
			switch_set[0] = 1 - switch_set[0];
			switch (switch_set[0])
			{
			case 0:mciSendString("stop BackMusic", NULL, 0, NULL); break;
			case 1:mciSendString("play BackMusic repeat", NULL, 0, NULL); break;
			}
		}

		for (int i = 1; i < 3; i++)
		{
			int x = 675 + switch_set[i] * 65;
			int y = 226 + i * 35;
			if (Mouse.x > x && Mouse.x < x + 25 && Mouse.y > y && Mouse.y < y + 25)
				switch_set[i] = 1 - switch_set[i];

		}
		for (int i = 1; i <= 3; i++)
		{
			int x = 490 + 70 * i;
			if (Mouse.x > x && Mouse.x < x + 25 && Mouse.y > 400 && Mouse.y < 425)
				N = i;
		}
	}
}

/*---------------------------------------------------*/

/*--------------------�� Ϸ �� ��--------------------*/
//��ʼ��Ϸ
void Game()
{
	int time;
	int score = 0;
	AIM aim[NUM];
	int a = 0;
	double c;
	MOUSEMSG mouse = GetMouseMsg();
	FlushMouseMsgBuffer();

	Load_Mouse_Music(); //����ͼƬ������
	int t = GetTickCount();

	while (true)
	{
		time = Clock(t);

		if(MouseHit())
			mouse = GetMouseMsg();
		if (mouse.mkLButton)
		{
			if(switch_set[2])
				PlaySound("res\\pat.wav", NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP);
			c = 1;
			score += Judge_In(mouse.x, mouse.y, aim, &a);
		}


		Draw_All(time, score, record[0].score, aim, a, &c, mouse.x, mouse.y);

		Aim_Move(aim,a);
	
		Add_Aim(aim, &a);

		if (time <= 0)
		{
			break;
		}
	}
	Game_Over(score);
	
}

//��Ϸ��ʼ�������ֺ����
void Load_Mouse_Music()
{
	//�������ͼ����Դ
	SetClassLong(hwnd, GCLP_HCURSOR, (long)hcur_game);// ���ô�����������ʽ�����еڶ��������������ʽ����

													  //�������֣���������
	mciSendString("stop BackMusic", NULL, 0, NULL);
	mciSendString("setaudio BackMusic volume to 300", NULL, 0, NULL);
	if (switch_set[1])
		mciSendString("play GameMusic repeat", NULL, 0, NULL);
	settextcolor(RGB(251, 23, 125));
	settextstyle(40, 20, NULL, 0, 0, 0, false, false, false);
}

//��������ʱ��
int Clock(int t)
{
	int tim = 30 - (GetTickCount() - t) / 1000;
	return tim;
}

//�������ӣ���ʼ��������
void Add_Aim(AIM aim[],int *a)
{
	if (*a < NUM)
	{
		int m = rand() % (500-NUM*N*N);
		if (m == 1)
		{
			do {
				aim[*a].x = rand() % 900;
				aim[*a].y = rand() % 500;
			} while (aim[*a].x <= 300 || aim[*a].y <= 150);
			aim[*a].distance = aim[*a].x;
			aim[*a].speed = rand() / (double)(RAND_MAX) / 5;
			aim[*a].dir = rand() % 2;
			aim[*a].mode = rand() / (double)(RAND_MAX)+1;
			aim[*a].style = rand() % 2;
			(*a)++;
		}
	}
}

//�������ӵ��ƶ�������
void Aim_Move(AIM aim[],int a)
{
	for (int i = 0; i < a; i++)
	{
		if (aim[i].x > 900)
		{
			aim[i].dir = 1;
		}
		else if (aim[i].x < 300)
		{
			aim[i].dir = 0;
		}

		if (aim[i].dir == 0)
		{
			aim[i].distance += aim[i].speed;
			aim[i].x = (int)aim[i].distance;
		}
		else {
			aim[i].distance -= aim[i].speed;
			aim[i].x = (int)aim[i].distance;
		}

		if (aim[i].mode > 2.20)
		{
			aim[i].mode = 0.80;
		}
		else if (aim[i].mode < 2 && aim[i].mode > 1)
		{
			aim[i].mode = aim[i].mode + 0.01;
		}
		else {
			aim[i].mode = aim[i].mode + 0.003;
		}
		aim[i].speed = rand() / (double)(RAND_MAX) / 5;
	}
	
}

//��Ϸ�����������
void Draw_All(int time,int score,int max,AIM aim[],int a,double *c,int x,int y)      
{
	char score_max[10];
	char score_text[10];
	char time_text[3];

	snprintf(time_text, sizeof(time_text), "%d", time);
	snprintf(score_text, sizeof(score_text), "%d", score);
	snprintf(score_max, sizeof(score_max), "%d", max);

	BeginBatchDraw();
	putimage(0, 0, &back);

	for (int i = 0; i < a; i++)
	{
		Paint_Aim(aim[i]);
	}

	if (*c > 0)
	{
		putimage(x-10, y-22, &click[1], SRCAND);
		putimage(x-10, y-22, &click[0], SRCINVERT);
		*c -= 0.05;
	}

	outtextxy(120, 22, time_text);
	outtextxy(120, 87, score_text);
	outtextxy(80, 370, score_max);
	EndBatchDraw();
}

//���ӻ������
void Paint_Aim(AIM p)       //��������
{
	putimage(p.x, p.y, &aim_p[p.style][1][(int)p.mode][p.dir], SRCAND);
	putimage(p.x, p.y, &aim_p[p.style][0][(int)p.mode][p.dir], SRCINVERT);
}

//�ж��Ƿ��������
int Judge_In(int x,int y,AIM aim[],int *a)      //�ж��Ƿ��������
{
	for (int i = 0; i < *a; i++)
	{
			int dx = x - aim[i].x - (1 - aim[i].style) * 5;
			int dy = y - aim[i].y - 19- (1 - aim[i].style) * 3;
			if (sqrt(dx*dx + dy * dy) <= (21 + (1 - aim[i].style) * 6))
			{
				return Damage(aim, a, i);
			}
	}

	return 0;
}

//�������������
int Damage(AIM aim[],int *a,int i)         //�������������
{
	int score;
	AIM t;
	t.x = 0;
	t.y = 0;
	t.style = 0;
	t.mode = 0;
	t.dir = 0;
	t.speed = 0;

	score = aim[i].style + 1;
	aim[i] = aim[*a - 1];
	aim[*a-1] = t;
	(*a)--;
	user.kill_number++;

	return score;
}

//��Ϸ������Ϣ�������¼
void Game_Over(int score)
{
	char game_over[80];
	snprintf(game_over, sizeof(game_over), "Game Over !!!\nYour score is %d!! \nPlease click space to restart game!", score);
	MessageBox(GetHWnd(), game_over, "Game Over", MB_OK);
	if (score > user.score[4])
	{
		if (score > record[4].score)
		{
			sort(user.name, score, record);
			Creat_Rank();
			Save_Rank();
		}
		sort(score, user.score);
	}
	user.game_time += 30;
	Creat_Record();
	Save_Record();

	mciSendString("stop GameMusic", NULL, 0, NULL);
	if(switch_set[0])
		mciSendString("play BackMusic repeat", NULL, 0, NULL);
	SetClassLong(hwnd, GCLP_HCURSOR, (long)hcur);
}

//���˼�¼�Ƚ�
void sort(int score, int num[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (score > num[i])
			break;
	}
	for (int j = 4; j>i; j--)
	{
		num[j] = num[j - 1];
	}
	num[i] = score;
}

//���а��¼�Ƚ�
void sort(char name[], int score, RECORD num[])
{

	int i;
	for (i = 0; i < 5; i++)
	{
		if (score > num[i].score)
			break;
	}
	for (int j = 4; j>i; j--)
	{
		num[j] = num[j - 1];
	}
	num[i].score = score;
	strcpy(num[i].name, name);
}

//�������а��¼
void Save_Record()
{
	FILE *fp;
	fp = fopen(user.name, "w");
	if (fp)
	{
		fprintf(fp, "name=%s\n", user.name);
		fprintf(fp, "passward=%s\n", user.passward);
		fprintf(fp, "\n");
		fprintf(fp, "game_time=%d\n", user.game_time);
		fprintf(fp, "kill_number=%d\n", user.kill_number);
		fprintf(fp, "1.%d\n", user.score[0]);
		fprintf(fp, "2.%d\n", user.score[1]);
		fprintf(fp, "3.%d\n", user.score[2]);
		fprintf(fp, "4.%d\n", user.score[3]);
		fprintf(fp, "5.%d\n", user.score[4]);
		fclose(fp);
	}
}

//������˼�¼
void Save_Rank()
{
	FILE *fp;
	fp = fopen("ranking.ini", "w");
	if (fp)
	{
		fprintf(fp, "[Ranking]\n\n");
		for (int i = 0; i<5; i++)
			fprintf(fp, "%d.%s %d\n", i + 1, record[i].name, record[i].score);

		fclose(fp);
	}
}

/*---------------------------------------------------*/

/*--------------------��������Ч��-------------------*/

//������Ϸ���ض���
void Loading_game()
{
	for (int x = 560; x < 860; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 4; i++)
		{
			putimage(x, 165 + i * 95, 860 - x,50 ,&button[i][0],0,0);
		}
		EndBatchDraw();
	}

	/*for (int y = 0; y <= 601; y++)          //����ת��
	{
		BeginBatchDraw();
		putimage(0, y-601, &back);
		putimage(0, y, &start);
		EndBatchDraw();
	}*/
	for (int x = 0; x >= -501; x--)           //�м�ֿ�
	{
		BeginBatchDraw();
		putimage(0, 0 ,&back);
		putimage(x, 0, 501, 601, &start, 0, 0);
		putimage(501 - x, 0, 500, 601, &start, 501, 0);
		EndBatchDraw();
	}


}

//����������ļ��ض���
void Reback_game()
{
	for (int x = -501; x <= 0; x++)           //�м�ֿ�
	{
		BeginBatchDraw();
		putimage(0, 0, &back);
		putimage(x, 0, 501, 601, &start, 0, 0);
		putimage(501 - x, 0, 500, 601, &game, 501, 0);
		EndBatchDraw();
	}
	for (int x = 860; x >= 560; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 4; i++)
		{
			putimage(x, 165 + i * 95, 860 - x, 50, &button[i][0], 0, 0);
		}
		EndBatchDraw();
	}
}

//�������а񶯻�
void Loading_rank()
{
	for (int x = 560; x < 860; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 4; i++)
		{
			putimage(x, 165 + i * 95, 860 - x, 50, &button[i][0], 0, 0);
		}
		EndBatchDraw();
	}
	for (int y = 601; y >= 146; y--)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 5; i++)
		{
			putimage(510, y + i * 71, &rank[i]);
		}
		putimage(601, y + 371, &button[4][0]);
		EndBatchDraw();
	}
}

//���ض���
void Reback_rank()
{
	for (int y = 146; y <= 601; y++)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 5; i++)
		{
			putimage(510, y + i * 71, &rank[i]);
		}
		putimage(601, y + 371, &button[4][0]);
		EndBatchDraw();
	}
	for (int x = 860; x >= 560; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 4; i++)
		{
			putimage(x, 165 + i * 95, 860 - x, 50, &button[i][0], 0, 0);
		}
		EndBatchDraw();
	}
}

//������Ϸ���ö���
void Loading_set(IMAGE ima)
{
	for (int x = 560; x < 860; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 4; i++)
		{
			putimage(x, 165 + i * 95, 860 - x, 50, &button[i][0], 0, 0);
		}
		EndBatchDraw();
	}
	for (int x = 300; x > 0; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		putimage(460, 146, 300-x, 328, &ima, x, 0);
		putimage(460, 517, 221-x, 50, &button[4][0], x-91, 0);
		EndBatchDraw();
	}
	for (int x = 460; x < 510; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		putimage(x, 146, &ima);
		putimage(x+91, 517,&button[4][0]);
		EndBatchDraw();
	}
}         

//���ض���
void Reback_set(IMAGE ima)
{
	for (int x = 510; x >  460; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		putimage(x, 146, &ima);
		putimage(x + 91, 517, &button[4][0]);
		EndBatchDraw();
	}
	for (int x = 0; x < 300; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		putimage(460, 146, 300 - x, 328, &ima, x, 0);
		putimage(460, 517, 221 - x, 50, &button[4][0], x - 91, 0);
		EndBatchDraw();
	}
	for (int x = 860; x >= 560; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 4; i++)
		{
			putimage(x, 165 + i * 95, 860 - x, 50, &button[i][0], 0, 0);
		}
		EndBatchDraw();
	}
}

//��¼�������ض���
void loading_login()
{
	for (int x = 510; x > 460; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		putimage(x, 195, &login);
		putimage(x + 56, 358, &button[5][0]);
		putimage(x + 56, 420, &button[6][0]);
		EndBatchDraw();
	}
	for (int x = 0; x < 300; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		putimage(460, 195, 300 - x, 300, &login, x, 0);
		putimage(460, 358, 291 - x, 50, &button[5][0], x - 56, 0);
		putimage(460, 420, 291 - x, 50, &button[6][0], x - 56, 0);
		EndBatchDraw();
	}
	for (int x = 860; x >= 560; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &game);
		for (int i = 0; i < 4; i++)
		{
			putimage(x, 165 + i * 95, 860 - x, 50, &button[i][0], 0, 0);
		}
		EndBatchDraw();
	}
}

//����ע����涯��
void loading_register()
{
	for (int x = 510; x > 460; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &start);
		putimage(x, 195, &login);
		putimage(x + 56, 358, &button[5][0]);
		putimage(x + 56, 420, &button[6][0]);
		EndBatchDraw();
	}
	for (int x = 0; x < 300; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &start);
		putimage(460, 195, 300 - x, 300, &login, x, 0);
		putimage(460, 358, 291 - x, 50, &button[5][0], x - 56, 0);
		putimage(460, 420, 291 - x, 50, &button[6][0], x - 56, 0);
		EndBatchDraw();
	}
	for (int x = 860; x >= 510; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &start);
		putimage(x, 195, 860 - x, 300, &regi, 0, 0);
		putimage(x + 56, 420, 804 - x, 50, &button[6][0], 0, 0);
		EndBatchDraw();
	}
}

//���ص�¼���涯��
void Reback_login()
{
	for (int x = 510; x < 860; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &start);
		putimage(x, 195, 860 - x, 300, &regi, 0, 0);
		putimage(x + 56, 420, 804 - x, 50, &button[6][0], 0, 0);
		EndBatchDraw();
	}
	for (int x = 300; x > 0; x--)
	{
		BeginBatchDraw();
		putimage(0, 0, &start);
		putimage(460, 195, 300 - x, 300, &login, x, 0);
		putimage(460, 358, 291 - x, 50, &button[5][0], x - 56, 0);
		putimage(460, 420, 291 - x, 50, &button[6][0], x - 56, 0);
		EndBatchDraw();
	}
	for (int x = 460; x < 510; x++)
	{
		BeginBatchDraw();
		putimage(0, 0, &start);
		putimage(x, 195, &login);
		putimage(x + 56, 358, &button[5][0]);
		putimage(x + 56, 420, &button[6][0]);
		EndBatchDraw();
	}
}

/*---------------------------------------------------*/
