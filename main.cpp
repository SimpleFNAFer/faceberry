#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv-functions.h"

using namespace cv;
using namespace std;

int main() {
    int choice;
    cout << "Select 1 to Recognise Faces\n";
    cout << "Select 2 to Add a new Face\n";
    cout << "Option: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            FaceRecognition();
            break;
        case 2:
            addFace();
            eigenFaceTrainer();
            break;
        default:
            return 0;
    }

    return 0;
}

void previous () {
    VideoCapture cam;
    //VideoCapture cam(0);
    cam.open("/home/nasy/repos/faceberry/example.mp4");
    if (!cam.isOpened()) {
        cout << "Couldn't open camera 0";
    }

    Mat vid_img;
    Mat vid_img_grey;
    vector<Rect> results;
    Scalar_<double> color_outline{0, 0, 255};
    CascadeClassifier faces("/home/student/faces_default.xml");

    while (true) {
        cam >> vid_img;
        if (vid_img.empty()) {
            break;
        }
        cvtColor(vid_img, vid_img_grey, COLOR_BGR2GRAY);
        faces.detectMultiScale(vid_img_grey, results, 3, 4);
        for (Rect r : results) {
            rectangle(vid_img, r, color_outline, 3, LINE_8, 0);
        }
        namedWindow("Cam0", 0);
        resizeWindow("Cam0", 1080, 720);
        imshow("Cam0", vid_img);
        waitKey(10);
    }
}
