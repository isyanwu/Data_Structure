
#include "opencv2/opencv.hpp"
#include "opencv2/video/background_segm.hpp"
 
using namespace cv;
using namespace std;
int main()
{
	VideoCapture video("../video.avi");
	int frameNum = 1;
	Mat frame, mask, thresholdImage, output;
	if (!video.isOpened())
		cout << "fail to open!" << endl;
	//cout<<video.isOpened();
	double totalFrameNumber = video.get(CAP_PROP_FRAME_COUNT);
	video >> frame;
	Ptr<BackgroundSubtractorMOG2> bgsubtractor = createBackgroundSubtractorMOG2();
	bgsubtractor->setVarThreshold(20);
	
	while (true){
		if (totalFrameNumber == frameNum)
			break;
		video >> frame;
		++frameNum;
		//bgSubtractor(frame, mask, 0.001);
		bgsubtractor->apply(frame, mask, 0.01);
		imshow("mask", mask);
		waitKey(10);
	}
	
	return 0;
}
