#pragma once
#include"stdc++.h"
using namespace std;
class Solution {
public:
	/*
	* @param source: A source string
	* @param target: A target string
	* @return: An integer as index
	*/
	int strStr2(const char* source, const char* target) {
		// write your code here
		if (source == nullptr || target == nullptr)
			return-1;
		int ssize = strlen(source);
		int tsize = strlen(target);
		if (ssize == 0 && tsize != 0)
			return -1;
		if (tsize == 0)
			return 0;
		vector<int>next(tsize);
		next[0] = -1;
		for (int i = 1; i<tsize; i++) {
			int j = next[i - 1];
			while (j >= 0 && target[i - 1] != target[j])
				j = next[j];
			if (j >= 0 && target[i - 1] == target[j])
				next[i] = j + 1;
			else next[i] = 0;
		}
		int index;
		for (index = 0; index<ssize; ++index) {
			int pos = 0;
			int iter = index;
			while (pos<tsize&&iter<ssize) {
				if (source[iter] == target[pos]) {
					++iter; ++pos;
				}
				else {
					if (pos == 0)++iter;
					else pos = next[pos - 1] + 1;
				}
			}
			if (pos == tsize && (iter - index) == tsize)
				return index;
		}
		return -1;
	}
};