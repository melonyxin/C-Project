#define _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include <conio.h>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>

#define WIDE 1001
#define HIGH 601
#define NUM 50

#pragma comment(lib, "winmm.lib")

struct AIM {
	int x;
	int y;
	double distance;
	double speed;
	double mode;
	int dir;
	int style;
};

struct USERMSG {
	char name[11];
	char passward[17];
};

struct RECORD {
	char name[11];
	int score;
};

struct USERS {
	char name[11];
	char passward[17];
	int game_time;
	int kill_number;
	int score[5];
};

void Load_IMAGE();                       //����ͼƬ��Դ
void Start();							 //���Ӹ���ģ��
int Clock(int t);						 //�õ�ʣ��ʱ��
void Add_Aim(AIM aim[], int *a);		 //�������ӣ������Ӹ���ʼ����
void Paint_Aim(AIM p);					 //�����ӻ��Ƴ���
void Aim_Move(AIM aim[],int a);			 //ʵ�ָ������Ӷ���λ�õĸ���
int Judge_In(int x,int y, AIM aim[], int *a);   //�ж��Ƿ��������
int Damage(AIM aim[], int *a, int i);			//ɱ��ָ������
void Draw_All(int time, int score, int max,AIM aim[],int a,double *c,int x,int y);   //��Ϸ�У����Ƴ����������ӣ�ʱ�䡢�÷ּ������������
void Load_Mouse_Music();				 //���������ʽ����Ϸʱ������
void Game_Over(int score);				 //��Ϸ����ʱ��������Ϸ����
void Get_Rank();						 //���ļ���ȡ���а�����
bool Button_On(int i, int x, int y, int wide, int high,MOUSEMSG Mouse);              //ʵ�ְ�ť����
void Game();							 //����Ϸģ��
void Loading_game();					 //���ؽ���Ķ���Ч��
void Reback_game();						 //����������Ķ���Ч��
void Loading_rank();                     //�������а񶯻�Ч��
void Reback_rank();						 //���ض���Ч��
void Loading_set(IMAGE ima);			 //���ض���Ч��
void Reback_set(IMAGE ima);				 //���ض���Ч��
void Ranking();							 //���а�ģ��
void  Help();							 //����ģ��
int Menu();								 //������˵�ģ��
int Login();							 //��¼����
int Input(char user[], int num);	     //���빦��ʵ��
int Input_on(int m, MOUSEMSG Mouse,int y);  //�����۽�ʵ��
bool Register_In(USERMSG User);			 //�ж�ע���Ƿ�ɹ�
int Login_In(USERMSG User);				 //�жϵ�¼�Ƿ�ɹ�
void Register();						 //ע�����
void Get_Information(char name[]);		 //�õ��û���Ϸ��Ϣ
void Creat_Record();					 //���û�������ʾ�ڽ�����
void Creat_Rank();						 //��������ʾ�����а���
void loading_login();					 //��¼����Ķ���Ч��
void loading_register();				 //ע�����Ķ���Ч��
void Reback_login();					 //���صĶ���Ч��
void sort(int score, int num[]);		 //���˼�¼������
void sort(char name[], int score, RECORD num[]);  //���а������
void Save_Record();						 //�����û���Ϸ��Ϣ
void Save_Rank();						 //�������а���Ϣ
void Ready();							 //����򿪺�ĳ�ʼ��
void  Game_Set();						 //��Ϸ����ģ��
void Button_On(MOUSEMSG Mouse);			 //��ѡ���ʵ��

IMAGE back, start,game;
IMAGE aim_p[2][2][3][2];
IMAGE button[7][2];
IMAGE rect, help, set, set_on;
IMAGE login, input,regi;
HCURSOR hcur;
HCURSOR hcur_game;
HWND hwnd;
USERS user;
RECORD record[5];
IMAGE rank[5];
IMAGE click[2];

int N = 1;
int switch_set[3] = { 1,1,1 };