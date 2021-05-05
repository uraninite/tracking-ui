#include <iostream>
#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\tracking.hpp"
using namespace std;

int main()
{
	//for tcp-ip camera
	string urll = "https://192.168.1.3:5555/video";
	
	//for video file
	//cv::VideoCapture video("G:\\lc\\target.MP4");
	
	//for camera 0
	//int urll = 0;
  
	string selection = "white";

	int Color_R = 255;
	int Color_G = 0;
	int Color_B = 0;

	int Golge_R = 0;
	int Golge_G = 0;
	int Golge_B = 0;
	depl:
	cv::VideoCapture video(urll);

	cin >> selection;

	//select ui color
	if (selection == "red")
	{
		Color_R = 255;
		Color_G = 0;
		Color_B = 0;
	}
	else if (selection == "green")
	{
		Color_R = 0;
		Color_G = 255;
		Color_B = 0;
	}
	else if (selection == "blue")
	{
		Color_R = 0;
		Color_G = 0;
		Color_B = 255;
	}
	else if (selection == "yellow")
	{
		Color_R = 255;
		Color_G = 255;
		Color_B = 0;
	}
	else if (selection == "white")
	{
		Color_R = 255;
		Color_G = 255;
		Color_B = 255;
	}

	//check video is opened
	if (!video.isOpened()) return -1;

	//save frames
	cv::Mat frame;

	//get video resolution

	//int frameWidth = 1280;
	//int frameHeigth = 720;
	int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
	int frameHeigth = video.get(cv::CAP_PROP_FRAME_HEIGHT);
	int HeightYuzde = frameHeigth / 100;
	int WidthYuzde = frameWidth / 100;

	//export as video
	cv::VideoWriter output("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeigth));
	cv::Ptr<cv::Tracker > tracker = cv::TrackerKCF::create();

	video.read(frame);
	cv::Rect trackingBox = cv::selectROI(frame, false);
	tracker->init(frame, trackingBox);

	int frameWidthBol2 = frameWidth / 2;
	int frameHeightBol2 = frameHeigth / 2;
	int WidthYuzde15 = WidthYuzde * 15;
	int HeightYuzde20 = HeightYuzde * 20;
	int mgs = 36;
	cv::Mat fkare;
	cv::Mat gray_image;
	//get screen output
	while (video.read(frame))
	{
		cv::cvtColor(frame, gray_image, cv::COLOR_RGB2GRAY);
		cv::cvtColor(gray_image, fkare, cv::COLOR_GRAY2RGB);

		//horizontal line
		cv::line(fkare, cv::Point(frameWidthBol2 - WidthYuzde15 + 1, HeightYuzde20 + 1), cv::Point(frameWidthBol2 - WidthYuzde *3 + 1, HeightYuzde20 + 1), cv::Scalar(Golge_B, Golge_G, Golge_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde15 + 1, HeightYuzde20 + 1), cv::Point(frameWidthBol2 + WidthYuzde *3 + 1, HeightYuzde20 + 1), cv::Scalar(Golge_B, Golge_G, Golge_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 - WidthYuzde15, HeightYuzde20), cv::Point(frameWidthBol2 - WidthYuzde *3, HeightYuzde20), cv::Scalar(Color_B, Color_G, Color_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde15, HeightYuzde20), cv::Point(frameWidthBol2 + WidthYuzde *3, HeightYuzde20), cv::Scalar(Color_B, Color_G, Color_R), 1, 8);

		//vertical line
		cv::line(fkare, cv::Point(frameWidthBol2 - WidthYuzde15 + 1, HeightYuzde20 + 1), cv::Point(frameWidthBol2 - WidthYuzde15 + 1, HeightYuzde *22 + 1), cv::Scalar(Golge_B, Golge_G, Golge_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde15 + 1, HeightYuzde20 + 1), cv::Point(frameWidthBol2 + WidthYuzde15 + 1, HeightYuzde *22 + 1), cv::Scalar(Golge_B, Golge_G, Golge_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 - WidthYuzde15, HeightYuzde20), cv::Point(frameWidthBol2 - WidthYuzde15, HeightYuzde *22), cv::Scalar(Color_B, Color_G, Color_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde15, HeightYuzde20), cv::Point(frameWidthBol2 + WidthYuzde15, HeightYuzde *22), cv::Scalar(Color_B, Color_G, Color_R), 1, 8);

		//crosshair vertical line
		cv::line(fkare, cv::Point(frameWidthBol2 + 1, frameHeightBol2 - HeightYuzde *8 + 1), cv::Point(frameWidthBol2 + 1, frameHeightBol2 - HeightYuzde *4 + 1), cv::Scalar(Golge_B, Golge_G, Golge_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + 1, frameHeightBol2 + HeightYuzde *8 + 1), cv::Point(frameWidthBol2 + 1, frameHeightBol2 + HeightYuzde *4 + 1), cv::Scalar(Golge_B, Golge_G, Golge_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2, frameHeightBol2 - HeightYuzde *8), cv::Point(frameWidthBol2, frameHeightBol2 - HeightYuzde *4), cv::Scalar(Color_B, Color_G, Color_R), 1.5, 8);
		cv::line(fkare, cv::Point(frameWidthBol2, frameHeightBol2 + HeightYuzde *8), cv::Point(frameWidthBol2, frameHeightBol2 + HeightYuzde *4), cv::Scalar(Color_B, Color_G, Color_R), 1.5, 8);

		//crosshair horizontal line
		cv::line(fkare, cv::Point(frameWidthBol2 - WidthYuzde *5 + 1, frameHeigth / 2 + 1), cv::Point(frameWidthBol2 - WidthYuzde *2 + 1, frameHeigth / 2 + 1), cv::Scalar(Golge_B, Golge_G, Golge_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde *5 + 1, frameHeigth / 2 + 1), cv::Point(frameWidthBol2 + WidthYuzde *2 + 1, frameHeigth / 2 + 1), cv::Scalar(Golge_B, Golge_G, Golge_R), 1, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 - WidthYuzde *5, frameHeightBol2), cv::Point(frameWidthBol2 - WidthYuzde *2, frameHeightBol2), cv::Scalar(Color_B, Color_G, Color_R), 1.5, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde *5, frameHeightBol2), cv::Point(frameWidthBol2 + WidthYuzde *2, frameHeightBol2), cv::Scalar(Color_B, Color_G, Color_R), 1.5, 8);

		//crosshair out lines horizontal
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde *1.5 + 1, frameHeightBol2 - HeightYuzde *8 + 1),
			cv::Point(frameWidthBol2 - WidthYuzde *1.5 + 1, frameHeightBol2 - HeightYuzde *8 + 1),
			cv::Scalar(Golge_B, Golge_G, Golge_R), 1.5, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde *1.5 + 1, frameHeightBol2 + HeightYuzde *8 + 1),
			cv::Point(frameWidthBol2 - WidthYuzde *1.5 + 1, frameHeightBol2 + HeightYuzde *8 + 1),
			cv::Scalar(Golge_B, Golge_G, Golge_R), 1.5, 8);

		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde *1.5, frameHeightBol2 - HeightYuzde *8),
			cv::Point(frameWidthBol2 - WidthYuzde *1.5, frameHeightBol2 - HeightYuzde *8),
			cv::Scalar(Color_B, Color_G, Color_R), 1.5, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde *1.5, frameHeightBol2 + HeightYuzde *8),
			cv::Point(frameWidthBol2 - WidthYuzde *1.5, frameHeightBol2 + HeightYuzde *8),
			cv::Scalar(Color_B, Color_G, Color_R), 1.5, 8);
		//crosshair out lines vertical
		cv::line(fkare, cv::Point(frameWidthBol2 - WidthYuzde *5 + 1, frameHeightBol2 + HeightYuzde *1.5 + 1),
			cv::Point(frameWidthBol2 - WidthYuzde *5 + 1, frameHeightBol2 - HeightYuzde *1.5 + 1),
			cv::Scalar(Golge_B, Golge_G, Golge_R), 1.5, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde *5 + 1, frameHeightBol2 - HeightYuzde *1.5 + 1),
			cv::Point(frameWidthBol2 + WidthYuzde *5 + 1, frameHeightBol2 + HeightYuzde *1.5 + 1),
			cv::Scalar(Golge_B, Golge_G, Golge_R), 1.5, 8);

		cv::line(fkare, cv::Point(frameWidthBol2 - WidthYuzde *5, frameHeightBol2 + HeightYuzde *1.5),
			cv::Point(frameWidthBol2 - WidthYuzde *5, frameHeightBol2 - HeightYuzde *1.5),
			cv::Scalar(Color_B, Color_G, Color_R), 1.5, 8);
		cv::line(fkare, cv::Point(frameWidthBol2 + WidthYuzde *5, frameHeightBol2 - HeightYuzde *1.5),
			cv::Point(frameWidthBol2 + WidthYuzde *5, frameHeightBol2 + HeightYuzde *1.5),
			cv::Scalar(Color_B, Color_G, Color_R), 1.5, 8);

		//text shadow
		cv::putText(fkare,	//target image
			"39",	//text
			cv::Point(frameWidthBol2 - 20 + 1, HeightYuzde20 + 10 + 1),	//top-left position 
			cv::FONT_HERSHEY_SIMPLEX,
			1,
			CV_RGB(Golge_R, Golge_G, Golge_B),	//font color
			0.5);

		cv::putText(fkare,	//target image
			"39",	//text
			cv::Point(frameWidthBol2 - 20, HeightYuzde20 + 10),	//top-left position 
			cv::FONT_HERSHEY_SIMPLEX,
			1,
			CV_RGB(Color_R, Color_G, Color_B),	//font color
			0.5);
    
    //draw rectangle
		if (tracker->update(fkare, trackingBox))
		{
			cv::rectangle(fkare, trackingBox, cv::Scalar(Color_B, Color_G, Color_R), 1, 8);
			cout << "F1";

		}

		//F1F0[72 x 86 from(95, 196)]
		//F0[72 x 86 from(95, 196)]

		cout << "F0" << trackingBox << endl;
		// display the frame
		cv::imshow("Video", fkare);

		// write video frame to output
		output.write(fkare);

		// for breaking the loop
		if (cv::waitKey(25) >= 0) break;

	}	// end while (video.read(frame))

	//release video capture and writer
	output.release();
	video.release();

	//close windows
	cv::destroyAllWindows();
	int x;
	std::cin >> x;
	goto depl;

}
