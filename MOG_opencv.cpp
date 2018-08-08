#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <Windows.h>  
#include <opencv2/opencv.hpp> 

using namespace cv;  
using namespace std;

bool pause = false;//是否暂停
int frameNum = 0;

int main()
{
    uchar key = false;//用来设置暂停

    VideoCapture video("test2.avi"); 
    //Mat frame,mask,thresholdImage,output;
    Mat frame,mask;
    video>>frame;
    //bgSubtractor(history,nmixtures,backgroundRatio,noiseSigma)  
    BackgroundSubtractorMOG bgSubtractor(5,2,0.75,false);

    while(true){
        video>>frame;
        ++frameNum;
        //bgSubtractor(当前帧，二值图，学习率);
        bgSubtractor(frame,mask,0.01);
        imshow("frame",frame);
        imshow("mask",mask);
        waitKey(20);

        //按键P切换暂停和播放
        key = cvWaitKey(1);
        if(key == 'p') pause = true;
        while(pause)
            if(cvWaitKey(0)=='p')
                pause = false;  
    }

    return 0;
}
