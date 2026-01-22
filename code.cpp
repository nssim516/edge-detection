// DEFINITIONS

#include "code.h"
#include <vector>
#include <iostream>
#include <algorithm> // for clamp: restricts a value to a specified range
#include <limits> 

using namespace std;
using image = vector< vector<int> >; // 2d vector for image

// printImage
void printImage(const image& img)
{
    // img.size(): how many rows in a vector
    // img[i].size(): how many columns in a vector
    for (int i = 0; i < img.size(); i++) // row looping
    {
        for (int j = 0; j < img[i].size(); j++) // column looping
        {
            cout << img[i][j];

            if (j < img[i].size()-1)
            {
                cout << '\t';
            }
        }
        cout << '\n';
    }
}

// applyKernel
vector < vector<int> > applyKernel(const image& inputImg)
{
    image kernel = {
        {-1, -1, -1},
        {-1, 8, -1},
        {-1, -1, -1}
    };

    size_t height = inputImg.size(); // number of rows must bt size_t not int
    size_t width = inputImg[0].size(); // number of columns
    vector < vector<int> > outputImg(height, vector<int>(width, 0)); // making them the same size
    int i = 0;
    int j = 0;
    int ki = 0; // kernal row
    int kj = 0; // kernal column

    // i = top edge, height = bottom edge, j = left edge, width = right edge
    // INVALID: OUTER EDGES
    for (int i = 0; i < height; ++i) 
    {
        for (int j = 0; j < width; ++j) 
        {
            if ((i == 0) || (i == height - 1) || (j == 0) || (j == width - 1))
            {
    
                outputImg[i][j] = 0;
            }

            //VALID: APPLE KERNEL
            else
            {
                int kernelSum = 0;
                for (int ki = -1; ki <= 1; ++ki)
                {
                    for (int kj = -1; kj <= 1; ++kj)
                    {
                        kernelSum += inputImg[i + ki][j + kj] * kernel[1 + ki][1 + kj];
                    }
                }
                outputImg[i][j] = kernelSum;
            }
        }
    }
    return outputImg;
}

// minMaxNormalization
vector < vector<int> > minMaxNormalization(const image& preNormImg)
{
    size_t height = preNormImg.size(); // number of rows
    size_t width = preNormImg[0].size(); // number of columns
    vector < vector<int> > postNormImg(height, vector<int>(width, 0)); // making them the same size

    int min = 255; // minimum value in the output image, will be replaced
    int max = 0; // maximum value in the output image, will be replaced
    int newMax = 255;
    int newMin = 0;

    // FINDING MINS AND MAXES
    for (size_t i = 0; i < height; ++i) 
    {
        for (size_t j = 0; j < width; ++j) 
        {
            int pixelVal = preNormImg[i][j];
            if (pixelVal < min)
            {
                min = pixelVal; // new min
            }

            if (pixelVal > max)
            {
                max = pixelVal; // new max
            }
        }
    }

    // if all pixel values are the same
    if (min == max)
    {
        for (size_t i = 0; i < height; ++i)
        {
            for (size_t j = 0; j < width; ++j)
            {
                postNormImg[i][j] = newMin;
            }
        }
        return postNormImg;
    }

    // NORMALIZATION
    for (size_t i = 0; i < height; ++i) 
    {
        for (size_t j = 0; j < width; ++j) 
        {
            int oldVal = preNormImg[i][j];
            int newVal = ((oldVal - min) * (newMax - newMin)) / (max - min) + newMin;
            postNormImg[i][j] = clamp(newVal, newMin, newMax);

            if (postNormImg[i][j] < 0)
            {
                postNormImg[i][j] = 0;
            }
            
            else if (postNormImg[i][j] > 255)
                {
                postNormImg[i][j] = 255;
                }
        }
    }
    return postNormImg;
}
/*
    // INPUT VALIDATION
    if ((x > 0) && (y > 0) && (pixel >= 0) && (pixel <= 255))
    {
        // valid image
    }
*/