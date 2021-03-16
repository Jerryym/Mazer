#pragma once
#ifndef Define_h
#define Define_h

const int Fast = 1;//设置速度为快
const int Mid = 2;//设置速度为中
const int Slow = 3;//设置速度为慢

const int wall = 0;//设置墙壁为0
const int road = 1;//设置通道为1

enum objective_direction//客观位置，北 南 西 东
{
	north,south,west,east
};

#endif // !Define_h
