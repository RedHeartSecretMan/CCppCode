#include <opencv2/opencv.hpp>

int main() {
    // 读取图像
    cv::Mat image = cv::imread("/Users/WangHao/Downloads/0000000_1690034799402.jpg", cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cout << "Could not read the image!" << std::endl;
        return 1;
    }

    // 显示图像
    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::imshow("Image", image);

    // 等待按键输入
    cv::waitKey(0);

    return 0;
}