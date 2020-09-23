#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{

        Mat output;
        VideoCapture cap(CV_CAP_ANY);


        if( !cap.isOpened() )
        {
            cout << "Could not initialize capturing...\n";
            return 0;
        }


        while(1){
            cap >> output;

            imshow("webcam input", output);
            char c = (char)waitKey(10);
            if( c == 27 ) break;
          }
}
