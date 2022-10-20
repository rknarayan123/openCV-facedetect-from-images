#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

 //importing images

void main()
{
	string path = "Resources/test.png"; //to set a path
	Mat img = imread(path);              //read the image from the path string line 13;
	                                     // Mat a datatype introduced by cv to handle all the images.....used during image operations
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) { cout << "empty" << endl; }
	vector<Rect>faces;                   // to detect the faces and store them we need bounding boxes(rectangle)
	faceCascade.detectMultiScale(img, faces, 1.1, 10); //detect faces;
	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}
	imshow("image", img);                //to show image
	waitKey(0);                          //used to display the image as a timer...0 is infinity




}
