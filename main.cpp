#include <iostream>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include "net.h"
#include "src/yoloface.h"
using namespace std;


//ham tao thu muc
void create_folder(string dir){
    if (access(dir.c_str(), F_OK) != -1) {
        std::cout << "Directory already exists" << std::endl;
    } else {
        // Sử dụng hàm mkdir() để tạo thư mục
        int result = mkdir(dir.c_str(), 0777);

        if (result == 0) {
            std::cout << "Directory created successfully" << std::endl;
        } else {
            std::cout << "Failed to create directory" << std::endl;
        }
    }
}

int main(){
    string path_save = "/home/maicg/Documents/Me/faceRecogCplus/pic";
     
    const char* modeltypes[] =
    {
        "yolov5n-0.5",
    };

    const int target_sizes[] =
    {
        320,
    };

    const float mean_vals[][3] =
    {
        {127.f, 127.f, 127.f},
    };

    const float norm_vals[][3] =
    {
        {1 / 255.f, 1 / 255.f, 1 / 255.f},
    };

    int modelid = 0;
    const char* modeltype = modeltypes[(int)modelid];
    int target_size = target_sizes[(int)modelid];
    bool use_gpu = 1;
    
    YoloFace yoloFace;
    yoloFace.load(modeltype, target_size, mean_vals[(int)modelid], norm_vals[(int)modelid], use_gpu);

    // flow main
    string path_img = "/home/maicg/Downloads/team.jpg";
    cv::Mat img = cv::imread(path_img);
    float area_base = img.cols*img.rows;
    cv::Mat img_rgb;
    cv::cvtColor( img, img_rgb, cv::COLOR_BGR2RGB);
    std::vector<Object> objects;
    yoloFace.detect(img_rgb, objects);
    yoloFace.draw(img, objects);
    cv::imshow("result", img);
	cv::waitKey(0);
    
    return 0;
}