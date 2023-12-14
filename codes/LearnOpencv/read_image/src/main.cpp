#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    // 检查是否提供了足够的参数
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return -1;
    }

    // 获取图像路径
    std::string image_path = argv[1];

    // 加载图像
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

    if (img.empty()) {
        std::cerr << "Error: Image not found." << std::endl;
        return -1;
    }

    // 显示图像
    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::imshow("Image", img);

    // 等待按键输入
    cv::waitKey(0);

    return 0;
}