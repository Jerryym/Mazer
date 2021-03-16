#include <iostream>
#include "MazeMap_Jerry.h"
using namespace std;


/*
��̬��Ա��ʼ��
*/
char MazeMap::maze_road = ' ';
int MazeMap::mazemap_row = 0;
int MazeMap::mazemap_col = 0;
int MazeMap::mazemap[Length][Width];

/*
 ���캯����MazeMap
 �������ܣ�Ĭ�ϳ�ʼ���Թ�
 �����б�
		��
 */
MazeMap::MazeMap():maze_wall('#')
{
	mazemap_row = 10;
	mazemap_col = 8;
}

/*
 ���캯����MazeMap
 �������ܣ���ʼ���Թ��ĳ��Ϳ�ǽ�ں�ͨ·Ĭ��
 �����б�
		row���Թ���ͼ���������
 		column���Թ���ͼ���������
 */
MazeMap::MazeMap(int * map, int row, int col):maze_wall('#')
{
	//��ʼ���Թ��ĳ��Ϳ�
	mazemap_row = row;
	mazemap_col = col;
	//���õ�ͼ��·
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; i < col; j++)
		{
			mazemap[i][j] = *map;
			map++;//ָ���һ
		}
	}
}

/*
 �������ƣ�set_wall
 �������ܣ�����ǽ���ַ�
 �����б�
		wall��ǽ���ַ�
 */
void MazeMap::set_wall(char wall)
{
	maze_wall = wall;
}

/*
 �������ƣ�set_road
 �������ܣ�����ͨ���ַ�
 �����б�
		wall��ͨ���ַ�
 */
void MazeMap::set_road(char road)
{
	maze_road = road;
}

/*
 �������ƣ�set_defaultmap
 �������ܣ�����Ĭ�ϵ�ͼ
 �����б�
		��
 */
void MazeMap::set_defaultmap()
{
	int map[6][6] = {
						{wall,wall,wall,wall,wall,wall},
						{wall,wall,wall,wall,road,road},
						{wall,wall,wall,wall,road,wall},
						{wall,road,road,road,road,wall},
						{wall,road,wall,wall,road,wall},
						{wall,road,wall,wall,wall,wall}
	};
	set_map(&map[0][0], 6, 6);
}

/*
 �������ƣ�set_map
 �������ܣ����õ�ͼ
 �����б�
		row���Թ���ͼ���������
 		column���Թ���ͼ���������
 */
void MazeMap::set_map(int * map, int row, int col)
{
	//��ʼ���Թ��ĳ��Ϳ�
	mazemap_row = row;
	mazemap_col = col;
	//���õ�ͼ��·
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mazemap[i][j] = *map;
			map++;//ָ���һ
		}
	}
}

/*
 �������ƣ�print_map
 �������ܣ���ӡ�����ͼ
 �����б�
		��
 */
void MazeMap::print_map() const
{
	for (int i = 0; i < mazemap_row; i++) 
	{
		for (int j = 0; j < mazemap_col; j++)
		{
			if (mazemap[i][j] == wall)
			{
				cout << maze_wall;
			}
			else
			{
				cout << maze_road;
			}
		}
		cout << endl;
	}
}

/*
 �������ƣ�get_road
 �������ܣ���ȡͨ���ַ�
 �����б�
		��
 */
char MazeMap::get_road()
{
	return maze_road;
}

/*
 �������ƣ�check_wall
 �������ܣ�ǽ�ڼ��
 �����б�
		temp_x����ǰλ�ú�����
		temp_y����ǰλ��������
 */
bool MazeMap::check_wall(int temp_x, int temp_y)
{
	if (mazemap[temp_y][temp_x] == wall)//����gotoxy()�����в���Ϊ���к��У�����������жԵ�
	{
		return true;
	}
	return false;
}

/*
 �������ƣ�check_exit
 �������ܣ����ڼ��
 �����б�
		temp_x����ǰλ�ú�����
		temp_y����ǰλ��������
 */
bool MazeMap::check_exit(int temp_x, int temp_y)
{
//����������߻����ұ�ʱ
	if (temp_x == 0 || temp_x == mazemap_col - 1)
	{
		if (mazemap[temp_y][temp_x] == road)//����gotoxy()�����в���Ϊ���к��У�����������жԵ�
		{
			return true;
		}
	}
//����������������±�ʱ
	if (temp_y == 0 || temp_y == mazemap_row - 1)
	{
		if (mazemap[temp_y][temp_x] == road)//����gotoxy()�����в���Ϊ���к��У�����������жԵ�
		{
			return true;
		}
	}
	return false;
}
