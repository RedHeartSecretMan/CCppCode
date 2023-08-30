#include <opencv2/opencv.hpp>

int main() {
    // 读取图像
    cv::Mat image = cv::imread("/Users/WangHao/Desktop/TODO/Data/车牌识别/测试数据/夜间极差/0000000_1690034443852.jpg", cv::IMREAD_COLOR);

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