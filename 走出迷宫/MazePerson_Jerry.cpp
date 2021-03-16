#include<iostream>
#include<Windows.h>
#include"MazePerson_Jerry.h"
#include"MazeMap_Jerry.h"
using namespace std;

/*
 ���캯����MazePerson
 �������ܣ����캯������ʼ���˵ĺ����ꡢ�������ǰ������
 �����б�
		��
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
 ���캯����MazePerson
 �������ܣ����캯������ʼ���˵ĺ����ꡢ�������ǰ������
 �����б�
		i_x����ǰλ�ú�����
		i_y����ǰλ��������
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
 ���캯����MazePerson
 �������ܣ����캯������ʼ���˵ĺ����ꡢ�������ǰ������
 �����б�
		i_x����ǰλ�ú�����
		i_y����ǰλ��������
		i_direction����ǰ����
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
 �������ƣ�set_personpic
 �������ܣ������˵��ַ�
 �����б�
		p_pic���˵��ַ�
 */
void MazePerson::set_personpic(char p_pic)
{
	person_pic = p_pic;
}

/*
 �������ƣ�set_position
 �������ܣ����õ�ǰλ��
 �����б�
		now_x��������
		now_y��������
 */
void MazePerson::set_position(int now_x, int now_y)
{
	position_x = now_x;
	position_y = now_y;
}

/*
 �������ƣ�set_position
 �������ܣ����õ�ǰ����
 �����б�
		i_direction������
 */
void MazePerson::set_direction(objective_direction i_direction)
{
	direction = i_direction;
}

/*
 �������ƣ�set_speed
 �������ܣ����õ�ǰ�ٶ�
 �����б�
		i_speed���ٶ�
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
 �������ƣ�save_pre_position
 �������ܣ�����ǰһλ������
 �����б�
		��
 */
void MazePerson::save_pre_position()
{
	pre_x = position_x;
	pre_y = position_y;
}

/*
 �������ƣ�move_north��move_south��move_west��move_east
 �������ܣ���ͬ����ǰ���ĺ���
 �����б�
		��
 */
void MazePerson::move_north()
{
	//���浱ǰλ������
	save_pre_position();
	//���߲���
	position_x = position_x;
	position_y = position_y - 1;
}

void MazePerson::move_south()
{
	//���浱ǰλ������
	save_pre_position();
	//�����߲���
	position_x = position_x;
	position_y = position_y + 1;
}

void MazePerson::move_west()
{
	//���浱ǰλ������
	save_pre_position();
	//�����߲���
	position_x = position_x - 1;
	position_y = position_y;
}

void MazePerson::move_east()
{
	//���浱ǰλ������
	save_pre_position();
	//���߲���
	position_x = position_x + 1;
	position_y = position_y;
}

/*
 �������ƣ�go_ahead
 �������ܣ���ǰ
 �����б�
		��
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
	default:cout << "���������޷�ǰ��..." << endl;
		break;
	}
	//���ɶ���
	print_person();
	//����Ƿ񵽴����
	//���������ڣ�����ʾ
	if (MazeMap::check_exit(position_x, position_y))
	{
		gotoxy(0, 22);
		cout << "���������ڳ�������" << endl;
		person_condition = true;
	}
}

/*
 �������ƣ�turn_left��turn_right
 �������ܣ�ת�亯��
 �����б�
		��
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
	default:cout << "�������..." << endl;
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
	default:cout << "�������..." << endl;
		break;
	}
}

/*
 �������ƣ�how_to_go
 �������ܣ����ǰ��
 �����б�
		��
 */
bool MazePerson::how_to_go()
{
	//�жϵ�ǰλ���Ƿ�Ϸ������Ƿ���ͨ��
	if (MazeMap::check_wall(position_x, position_y))
	{
		gotoxy(0, 23);
		cout << "��⵽��ǰ�趨����ʼλ����ǽ�ڣ��������趨��" << endl;
		person_condition = false;
		return no;
	}
	//���ǰһ��λ�õ�����ֵ��һ��Ϊ1000�����ڵ�ǰλ�÷���
	if (pre_x == 1000 || pre_y == 1000)
	{
		gotoxy(position_x, position_y);
		cout << person_pic;
		Sleep(5000);
	}
	//�������ֹ���
	int right_x, right_y;//�Ҳ�����
	int forward_x, forward_y;//ǰ������
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
	if (MazeMap::check_wall(right_x, right_y))//�Ҳ���ǽ��
	{
		if (MazeMap::check_wall(forward_x, forward_y))//ǰ����ǽ��
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

void MazePerson::gotoxy(int x, int y)//���ֱ��������x��y��
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void MazePerson::print_person()
{
	//�ڵ�ǰλ���ϻ�����
	char maze_road = MazeMap::get_road();
	gotoxy(pre_x, pre_y);
	cout << maze_road;
	gotoxy(position_x, position_y);
	cout << person_pic;
	//Ϊ��������Ч��ʹ��ʱ���ӳ�
	Sleep(person_speed);
}
