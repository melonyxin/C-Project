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

void Load_IMAGE();                       //加载图片资源
void Start();							 //连接各个模块
int Clock(int t);						 //得到剩余时间
void Add_Aim(AIM aim[], int *a);		 //增加蚊子，给蚊子赋初始数据
void Paint_Aim(AIM p);					 //将蚊子绘制出来
void Aim_Move(AIM aim[],int a);			 //实现各个蚊子动作位置的更新
int Judge_In(int x,int y, AIM aim[], int *a);   //判断是否击中蚊子
int Damage(AIM aim[], int *a, int i);			//杀死指定蚊子
void Draw_All(int time, int score, int max,AIM aim[],int a,double *c,int x,int y);   //游戏中，绘制出背景、蚊子，时间、得分及其它相关数据
void Load_Mouse_Music();				 //加载鼠标样式和游戏时的音乐
void Game_Over(int score);				 //游戏结束时，储存游戏数据
void Get_Rank();						 //从文件获取排行榜数据
bool Button_On(int i, int x, int y, int wide, int high,MOUSEMSG Mouse);              //实现按钮功能
void Game();							 //主游戏模块
void Loading_game();					 //加载界面的动画效果
void Reback_game();						 //返回主界面的动画效果
void Loading_rank();                     //加载排行榜动画效果
void Reback_rank();						 //返回动画效果
void Loading_set(IMAGE ima);			 //加载动画效果
void Reback_set(IMAGE ima);				 //返回动画效果
void Ranking();							 //排行榜模块
void  Help();							 //帮助模块
int Menu();								 //主界面菜单模块
int Login();							 //登录界面
int Input(char user[], int num);	     //输入功能实现
int Input_on(int m, MOUSEMSG Mouse,int y);  //输入框聚焦实现
bool Register_In(USERMSG User);			 //判断注册是否成功
int Login_In(USERMSG User);				 //判断登录是否成功
void Register();						 //注册界面
void Get_Information(char name[]);		 //得到用户游戏信息
void Creat_Record();					 //将用户数据显示在界面上
void Creat_Rank();						 //将数据显示在排行榜上
void loading_login();					 //登录界面的动画效果
void loading_register();				 //注册界面的动画效果
void Reback_login();					 //返回的动画效果
void sort(int score, int num[]);		 //个人记录的排序
void sort(char name[], int score, RECORD num[]);  //排行榜的排序
void Save_Record();						 //保存用户游戏信息
void Save_Rank();						 //保存排行榜信息
void Ready();							 //程序打开后的初始化
void  Game_Set();						 //游戏设置模块
void Button_On(MOUSEMSG Mouse);			 //单选框的实现

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