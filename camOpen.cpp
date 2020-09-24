#include <iostream>
#include <opencv2/*.hpp>

using namespace cv;

int main(int argc, char** argv)
{

        Mat output;
        VideoCapture cap(CV_CAP_ANY);


        if( !cap.isOpened() )
        {
            std::cout << "Could not initialize capturing...\n"<<std::endl;
            return 0;
        }


        while(1){
            cap >> output;

            imshow("webcam input", output);
          }
}
