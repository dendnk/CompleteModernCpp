#pragma once

inline int global;

class Test
{
	inline static int Data = 50; // inline - add ability to init variable inside header

	constexpr static int PathSize = 255;

	int x = 5;
};

void InlineVariablesMain();
