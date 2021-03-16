#include <iostream>
#include "MazeMap_Jerry.h"
using namespace std;


/*
静态成员初始化
*/
char MazeMap::maze_road = ' ';
int MazeMap::mazemap_row = 0;
int MazeMap::mazemap_col = 0;
int MazeMap::mazemap[Length][Width];

/*
 构造函数：MazeMap
 函数功能：默认初始化迷宫
 参数列表：
		无
 */
MazeMap::MazeMap():maze_wall('#')
{
	mazemap_row = 10;
	mazemap_col = 8;
}

/*
 构造函数：MazeMap
 函数功能：初始化迷宫的长和宽，墙壁和通路默认
 参数列表：
		row：迷宫地图数组的行数
 		column：迷宫地图数组的列数
 */
MazeMap::MazeMap(int * map, int row, int col):maze_wall('#')
{
	//初始化迷宫的长和宽
	mazemap_row = row;
	mazemap_col = col;
	//设置地图线路
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; i < col; j++)
		{
			mazemap[i][j] = *map;
			map++;//指针加一
		}
	}
}

/*
 函数名称：set_wall
 函数功能：设置墙壁字符
 参数列表：
		wall：墙壁字符
 */
void MazeMap::set_wall(char wall)
{
	maze_wall = wall;
}

/*
 函数名称：set_road
 函数功能：设置通道字符
 参数列表：
		wall：通道字符
 */
void MazeMap::set_road(char road)
{
	maze_road = road;
}

/*
 函数名称：set_defaultmap
 函数功能：设置默认地图
 参数列表：
		无
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
 函数名称：set_map
 函数功能：设置地图
 参数列表：
		row：迷宫地图数组的行数
 		column：迷宫地图数组的列数
 */
void MazeMap::set_map(int * map, int row, int col)
{
	//初始化迷宫的长和宽
	mazemap_row = row;
	mazemap_col = col;
	//设置地图线路
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mazemap[i][j] = *map;
			map++;//指针加一
		}
	}
}

/*
 函数名称：print_map
 函数功能：打印输出地图
 参数列表：
		无
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
 函数名称：get_road
 函数功能：获取通道字符
 参数列表：
		无
 */
char MazeMap::get_road()
{
	return maze_road;
}

/*
 函数名称：check_wall
 函数功能：墙壁检测
 参数列表：
		temp_x：当前位置横坐标
		temp_y：当前位置纵坐标
 */
bool MazeMap::check_wall(int temp_x, int temp_y)
{
	if (mazemap[temp_y][temp_x] == wall)//由于gotoxy()函数中参数为先列后行，因此数组行列对调
	{
		return true;
	}
	return false;
}

/*
 函数名称：check_exit
 函数功能：出口检测
 参数列表：
		temp_x：当前位置横坐标
		temp_y：当前位置纵坐标
 */
bool MazeMap::check_exit(int temp_x, int temp_y)
{
//出口在最左边或最右边时
	if (temp_x == 0 || temp_x == mazemap_col - 1)
	{
		if (mazemap[temp_y][temp_x] == road)//由于gotoxy()函数中参数为先列后行，因此数组行列对调
		{
			return true;
		}
	}
//出口在最上面或最下边时
	if (temp_y == 0 || temp_y == mazemap_row - 1)
	{
		if (mazemap[temp_y][temp_x] == road)//由于gotoxy()函数中参数为先列后行，因此数组行列对调
		{
			return true;
		}
	}
	return false;
}
