/*
����
���ݳ�Ա���˵��ַ����˵ĳ����˵ĵ�ǰλ�á���ǰһ������λ�á��˵��ٶ�
��Ա���������캯�������ݷ�װ��������ͬ����ǰ���ĺ�����ת�亯������ʼ����
���캯����Ĭ�Ϲ��졢����������
���ݷ�װ�������˵��ַ����˵ĵ�ǰλ�á��˵ĵ�ǰ�����˵��ٶ�
��ͬ����ǰ���ĺ��������������ϡ��������������ص�ǰ����ǰ��
ת�亯������ת����ת
��ʼ����
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
	MazePerson();//���캯��
	MazePerson(int i_x, int i_y);//���캯�� �������Զ���λ�ã�Ĭ�Ϸ���
	MazePerson(int i_x, int i_y, objective_direction i_direction);//���캯�� �������Զ���λ�á�����
	void set_personpic(char p_pic);//�����˵��ַ�
	void set_position(int now_x, int now_y);//���õ�ǰλ��
	void set_direction(objective_direction i_direction);//���ó���
	void set_speed(int i_speed);//�����ٶ�
	void set_speed(long i_speed);
	void start();//��ʼ����

private:
	char person_pic;//�˵��ַ�
	objective_direction direction;//����
	int position_x;//λ�ú�����
	int position_y;//λ��������
	int pre_x;//ǰһ��λ�ú�����
	int pre_y;//ǰһ��λ��������
	int person_speed;//�ٶ�
	bool  person_condition;//״̬���Ƿ��߳��Թ�

	void save_pre_position();//����ǰһλ������
	
	void move_north();//������
	void move_south();//������
	void move_west();//������
	void move_east();//������
	void go_ahead();//��ǰ
	
	void turn_left();//��ת
	void turn_right();//��ת

	bool how_to_go();//���ǰ��

	void gotoxy(int x, int y);//�����������

	void print_person();//��ӡ���
};

#endif // !MazePerson_h