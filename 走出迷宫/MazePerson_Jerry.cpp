#include<iostream>
#include<Windows.h>
#include"MazePerson_Jerry.h"
#include"MazeMap_Jerry.h"
using namespace std;

/*
 构造函数：MazePerson
 函数功能：构造函数，初始化人的横坐标、纵坐标和前进方向
 参数列表：
		无
 */
MazePerson::MazePerson() :person_pic('-')
{
	position_x = 1;
	position_y = 5;
	pre_x = 1000;
	pre_y = 1000;
	direction = north;
	person_speed = 10000;
	person_condition = false;
}

/*
 构造函数：MazePerson
 函数功能：构造函数，初始化人的横坐标、纵坐标和前进方向
 参数列表：
		i_x：当前位置横坐标
		i_y：当前位置纵坐标
 */
MazePerson::MazePerson(int i_x, int i_y) :person_pic('-')
{
	position_x = i_x;
	position_y = i_y;
	pre_x = 1000;
	pre_y = 1000;
	direction = north;
	person_condition = false;
}

/*
 构造函数：MazePerson
 函数功能：构造函数，初始化人的横坐标、纵坐标和前进方向
 参数列表：
		i_x：当前位置横坐标
		i_y：当前位置纵坐标
		i_direction：当前朝向
 */
MazePerson::MazePerson(int i_x, int i_y, objective_direction i_direction) :person_pic('-')
{
	position_x = i_x;
	position_y = i_y;
	pre_x = 1000;
	pre_y = 1000;
	direction = i_direction;
	person_condition = false;
}

/*
 函数名称：set_personpic
 函数功能：设置人的字符
 参数列表：
		p_pic：人的字符
 */
void MazePerson::set_personpic(char p_pic)
{
	person_pic = p_pic;
}

/*
 函数名称：set_position
 函数功能：设置当前位置
 参数列表：
		now_x：横坐标
		now_y：纵坐标
 */
void MazePerson::set_position(int now_x, int now_y)
{
	position_x = now_x;
	position_y = now_y;
}

/*
 函数名称：set_position
 函数功能：设置当前朝向
 参数列表：
		i_direction：朝向
 */
void MazePerson::set_direction(objective_direction i_direction)
{
	direction = i_direction;
}

/*
 函数名称：set_speed
 函数功能：设置当前速度
 参数列表：
		i_speed：速度
 */
void MazePerson::set_speed(int i_speed)
{
	person_speed = i_speed * 500;
}

void MazePerson::set_speed(long i_speed)
{
	person_speed = i_speed;
}

void MazePerson::start()
{
	while (!person_condition)
	{
		gotoxy(0, 15);
		how_to_go();
	}
}

/*
 函数名称：save_pre_position
 函数功能：保存前一位置坐标
 参数列表：
		无
 */
void MazePerson::save_pre_position()
{
	pre_x = position_x;
	pre_y = position_y;
}

/*
 函数名称：move_north、move_south、move_west、move_east
 函数功能：向不同方向前进的函数
 参数列表：
		无
 */
void MazePerson::move_north()
{
	//保存当前位置坐标
	save_pre_position();
	//向北走操作
	position_x = position_x;
	position_y = position_y - 1;
}

void MazePerson::move_south()
{
	//保存当前位置坐标
	save_pre_position();
	//向南走操作
	position_x = position_x;
	position_y = position_y + 1;
}

void MazePerson::move_west()
{
	//保存当前位置坐标
	save_pre_position();
	//向西走操作
	position_x = position_x - 1;
	position_y = position_y;
}

void MazePerson::move_east()
{
	//保存当前位置坐标
	save_pre_position();
	//向东走操作
	position_x = position_x + 1;
	position_y = position_y;
}

/*
 函数名称：go_ahead
 函数功能：向前
 参数列表：
		无
 */
void MazePerson::go_ahead()
{
	switch (direction)
	{
	case north:move_north();
		break;
	case south:move_south();
		break;
	case west:move_west();
		break;
	case east:move_east();
		break;
	default:cout << "方向不明，无法前进..." << endl;
		break;
	}
	//生成动画
	print_person();
	//检测是否到达出口
	//如果到达出口，则提示
	if (MazeMap::check_exit(position_x, position_y))
	{
		gotoxy(0, 22);
		cout << "哈哈，终于出来啦！" << endl;
		person_condition = true;
	}
}

/*
 函数名称：turn_left、turn_right
 函数功能：转弯函数
 参数列表：
		无
 */
void MazePerson::turn_left()
{
	switch (direction)
	{
	case north:direction = west;
		break;
	case south:direction = east;
		break;
	case west:direction = south;
		break;
	case east:direction = north;
		break;
	default:cout << "方向错误..." << endl;
		break;
	}
}

void MazePerson::turn_right()
{
	switch (direction)
	{
	case north:direction = east;
		break;
	case south:direction = west;
		break;
	case west:direction = north;
		break;
	case east:direction = south;
		break;
	default:cout << "方向错误..." << endl;
		break;
	}
}

/*
 函数名称：how_to_go
 函数功能：如何前进
 参数列表：
		无
 */
bool MazePerson::how_to_go()
{
	//判断当前位置是否合法，即是否是通道
	if (MazeMap::check_wall(position_x, position_y))
	{
		gotoxy(0, 23);
		cout << "检测到当前设定的起始位置是墙壁，请重新设定。" << endl;
		person_condition = false;
		return no;
	}
	//如果前一个位置的坐标值有一个为1000，则在当前位置放人
	if (pre_x == 1000 || pre_y == 1000)
	{
		gotoxy(position_x, position_y);
		cout << person_pic;
		Sleep(5000);
	}
	//运用右手规则
	int right_x, right_y;//右侧坐标
	int forward_x, forward_y;//前方坐标
	switch (direction)
	{
	case north:
		right_x = position_x + 1; right_y = position_y;
		forward_x = position_x; forward_y = position_y - 1;
		break;
	case south:
		right_x = position_x - 1; right_y = position_y;
		forward_x = position_x; forward_y = position_y + 1;
		break;
	case west:
		right_x = position_x; right_y = position_y - 1;
		forward_x = position_x - 1; forward_y = position_y;
		break;
	case east:
		right_x = position_x; right_y = position_y + 1;
		forward_x = position_x + 1; forward_y = position_y;
		break;
	}
	if (MazeMap::check_wall(right_x, right_y))//右侧是墙壁
	{
		if (MazeMap::check_wall(forward_x, forward_y))//前方是墙壁
		{
			turn_left();
			return no;
		}
		else
		{
			go_ahead();
			return yes;
		}
	}
	else
	{
		Sleep(3000);
		turn_right();
		go_ahead();
		return yes;
	}
}

void MazePerson::gotoxy(int x, int y)//光标直接跳到第x列y行
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void MazePerson::print_person()
{
	//在当前位置上绘制人
	char maze_road = MazeMap::get_road();
	gotoxy(pre_x, pre_y);
	cout << maze_road;
	gotoxy(position_x, position_y);
	cout << person_pic;
	//为制作动画效果使用时间延迟
	Sleep(person_speed);
}
