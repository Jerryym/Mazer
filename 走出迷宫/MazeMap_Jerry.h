/*
迷宫类
数据成员：墙壁字符、通道字符、迷宫数组（迷宫的尺寸：长 宽）
成员函数：构造函数、数据封装函数、迷宫绘制函数、迷宫边界检查函数
构造函数：默认构造，带参数构造
数据封装函数：set_wall、set_road、设置默认地图、设置自定义地图
迷宫绘制函数：输出打印函数、获取通道字符
迷宫边界检查函数：墙壁检查、出口检查函数
*/

/*
运用到的知识点
1、static：在内存中是以固定地址存放的，在整个程序运行期间都有效
2、类中静态数据成员需在类外初始化
3、常成员函数
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
//构造函数
	MazeMap();//设置默认地图
	MazeMap(int *map,int row,int col);//用户设置自定义地图
//数据封装函数
	void set_wall(char wall);//设置墙壁字符
	void set_road(char road);//设置通道字符
	void set_defaultmap();//设置默认地图
	void set_map(int *map, int row, int col);//设置自定义地图
//迷宫绘制函数
	void print_map()const;//打印输出地图（常成员函数）
	static char get_road();//获取通道字符
//迷宫边界检查函数
	static bool check_wall(int temp_x, int temp_y);//墙壁检测
	static bool check_exit(int temp_x, int temp_y);//出口检测

private:
	char maze_wall;//墙壁字符
	static char maze_road;//通道字符
	static int mazemap_row;//迷宫长
	static int mazemap_col;//迷宫宽
	static int mazemap[Length][Width];//迷宫数组
};

#endif // !MazeMap_h
