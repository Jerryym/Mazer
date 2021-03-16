/*
人类
数据成员：人的字符、人的朝向、人的当前位置、人前一个所处位置、人的速度
成员函数：构造函数、数据封装函数、向不同方向前进的函数、转弯函数、开始函数
构造函数：默认构造、带参数构造
数据封装函数：人的字符，人的当前位置、人的当前朝向、人的速度
向不同方向前进的函数：朝北、朝南、朝西、朝东、沿当前方向前进
转弯函数：左转、右转
开始函数
*/
#pragma once
#ifndef MazePerson_h
#define MazePerson_h

#include"define.h"

const bool yes = true;
const bool no = false;

class MazePerson
{
public:
	MazePerson();//构造函数
	MazePerson(int i_x, int i_y);//构造函数 ，设置自定义位置，默认方向
	MazePerson(int i_x, int i_y, objective_direction i_direction);//构造函数 ，设置自定义位置、方向
	void set_personpic(char p_pic);//设置人的字符
	void set_position(int now_x, int now_y);//设置当前位置
	void set_direction(objective_direction i_direction);//设置朝向
	void set_speed(int i_speed);//设置速度
	void set_speed(long i_speed);
	void start();//开始函数

private:
	char person_pic;//人的字符
	objective_direction direction;//朝向
	int position_x;//位置横坐标
	int position_y;//位置纵坐标
	int pre_x;//前一个位置横坐标
	int pre_y;//前一个位置纵坐标
	int person_speed;//速度
	bool  person_condition;//状态，是否走出迷宫

	void save_pre_position();//保存前一位置坐标
	
	void move_north();//朝北走
	void move_south();//朝南走
	void move_west();//朝西走
	void move_east();//朝东走
	void go_ahead();//向前
	
	void turn_left();//左转
	void turn_right();//右转

	bool how_to_go();//如何前进

	void gotoxy(int x, int y);//动画输出控制

	void print_person();//打印输出
};

#endif // !MazePerson_h