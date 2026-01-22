// DECLARATIONS

#pragma once
#include <vector>
#include <iostream>

using namespace std;
using image = vector<vector<int>>;

void printImage(const image& img);

vector < vector<int> > applyKernel(const image& inputImg);

vector < vector<int> > minMaxNormalization(const image& preNormImg);