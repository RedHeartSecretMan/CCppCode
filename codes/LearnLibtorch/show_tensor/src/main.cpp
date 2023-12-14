#include <torch/torch.h>

#include <opencv2/opencv.hpp>

cv::Mat ConvertTensorToMat(torch::Tensor tensor) {
    // 确保 Tensor 是浮点型且在 CPU 上
    tensor = tensor.to(torch::kCPU).to(torch::kFloat32);

    // 调整大小和形状
    tensor = tensor.squeeze().detach();// 打断计算图
    tensor = tensor.permute({1, 2, 0});// 从 CHW 到 HWC

    // 将 Tensor 转换为 Mat
    cv::Mat mat(tensor.size(0), tensor.size(1), CV_32FC3,
                tensor.data_ptr<float>());

    return mat.clone();// 克隆 Mat 以确保内存安全
}

int main() {
    // 创建一个 Tensor
    torch::Tensor tensor = torch::rand({3, 240, 320});

    // 转换 Tensor 为 Mat
    cv::Mat mat = ConvertTensorToMat(tensor);

    // 显示图像
    cv::imshow("Tensor Image", mat);
    cv::waitKey(0);

    return 0;
}
