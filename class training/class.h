#pragma once
#include "lib\framework.hpp"

enum SceneName
{
	Title,
	Game,
	Result

};

class title
{
public:

	void upDate();
	void draw();
	SceneName Shift();

private:

};

class result
{
public:

	void upDate();
	void draw();
	SceneName Shift();

private:

};

class game
{
public:

	void upDate();
	void draw();
	SceneName Shift();

private:

};
