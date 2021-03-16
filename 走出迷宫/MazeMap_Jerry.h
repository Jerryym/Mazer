/*
�Թ���
���ݳ�Ա��ǽ���ַ���ͨ���ַ����Թ����飨�Թ��ĳߴ磺�� ��
��Ա���������캯�������ݷ�װ�������Թ����ƺ������Թ��߽��麯��
���캯����Ĭ�Ϲ��죬����������
���ݷ�װ������set_wall��set_road������Ĭ�ϵ�ͼ�������Զ����ͼ
�Թ����ƺ����������ӡ��������ȡͨ���ַ�
�Թ��߽��麯����ǽ�ڼ�顢���ڼ�麯��
*/

/*
���õ���֪ʶ��
1��static�����ڴ������Թ̶���ַ��ŵģ����������������ڼ䶼��Ч
2�����о�̬���ݳ�Ա���������ʼ��
3������Ա����
*/
#pragma once
#ifndef MazeMap_h
#define MazeMap_h

#define Length 80
#define Width 25

#include"define.h"

class MazeMap
{
public:
//���캯��
	MazeMap();//����Ĭ�ϵ�ͼ
	MazeMap(int *map,int row,int col);//�û������Զ����ͼ
//���ݷ�װ����
	void set_wall(char wall);//����ǽ���ַ�
	void set_road(char road);//����ͨ���ַ�
	void set_defaultmap();//����Ĭ�ϵ�ͼ
	void set_map(int *map, int row, int col);//�����Զ����ͼ
//�Թ����ƺ���
	void print_map()const;//��ӡ�����ͼ������Ա������
	static char get_road();//��ȡͨ���ַ�
//�Թ��߽��麯��
	static bool check_wall(int temp_x, int temp_y);//ǽ�ڼ��
	static bool check_exit(int temp_x, int temp_y);//���ڼ��

private:
	char maze_wall;//ǽ���ַ�
	static char maze_road;//ͨ���ַ�
	static int mazemap_row;//�Թ���
	static int mazemap_col;//�Թ���
	static int mazemap[Length][Width];//�Թ�����
};

#endif // !MazeMap_h
