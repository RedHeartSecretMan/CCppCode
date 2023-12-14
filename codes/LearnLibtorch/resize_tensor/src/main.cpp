#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <torch/torch.h>

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

    // OpenCV resize
    std::cout << "OpenCV Data Type: " << img.type() << std::endl;
    cv::Mat resized_img;
    auto start_opencv = std::chrono::high_resolution_clock::now();
    cv::resize(img, resized_img, cv::Size(224, 224), 0, 0, cv::INTER_LINEAR);
    auto end_opencv = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_opencv = end_opencv - start_opencv;
    std::cout << "OpenCV Resize Time: " << elapsed_opencv.count() << " seconds." << std::endl;

    // Convert Mat to Tensor
    torch::Tensor img_tensor = torch::from_blob(img.data, {img.rows, img.cols, 3}, torch::kByte);
    img_tensor = img_tensor.permute({2, 0, 1});// Convert to CxHxW

    // LibTorch resize
    std::cout << "LibTorch Tensor Type: " << img_tensor.dtype() << std::endl;
    auto start_libtorch = std::chrono::high_resolution_clock::now();
    torch::Tensor resized_tensor = torch::nn::functional::interpolate(img_tensor.unsqueeze(0), torch::nn::functional::InterpolateFuncOptions().size(std::vector<int64_t>({224, 224})).mode(torch::kBilinear).align_corners(false));
    auto end_libtorch = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_libtorch = end_libtorch - start_libtorch;
    std::cout << "LibTorch Resize Time: " << elapsed_libtorch.count() << " seconds." << std::endl;

    return 0;
}
