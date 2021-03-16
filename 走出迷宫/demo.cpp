#include<iostream>
#include"MazeMap_Jerry.h"
#include"MazePerson_Jerry.h"
using namespace std;

int main()
{
	int map[8][10] = {
						{wall,wall,wall,wall,wall,wall,wall,wall,road,wall},
						{wall,wall,wall,wall,road,road,road,wall,road,wall},
						{wall,wall,wall,wall,road,wall,road,road,road,wall},
						{wall,road,road,road,road,wall,wall,wall,wall,wall},
						{wall,road,wall,wall,road,road,road,wall,wall,wall},
						{wall,road,wall,wall,wall,wall,road,wall,wall,wall},
						{wall,road,wall,wall,wall,wall,wall,wall,wall,wall},
						{wall,road,wall,wall,wall,wall,wall,wall,wall,wall}
	};

	MazeMap maze;
	//maze.set_defaultmap();//创建默认地图
	maze.set_wall('=');//设置墙壁字符
	maze.set_map(&map[0][0], 8, 10);//创建自定义地图
	maze.print_map();//打印地图

	MazePerson mazer;
	mazer.set_personpic('A');//设置人的字符
	mazer.set_position(1, 7);//设置当前位置
	mazer.set_speed(Fast);//设置速度
	mazer.start();//开始

	return 0;
}