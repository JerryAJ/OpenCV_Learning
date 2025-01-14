#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;

void createAlphaMat(Mat& mat) {
	for (int i = 0; i < mat.rows; ++i) 
	{
		for (int j = 0; j < mat.cols; ++j)
		{
			Vec4b& rgba = mat.at<Vec4b>(i, j);
			rgba[0] = UCHAR_MAX;
			rgba[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols) * UCHAR_MAX);
			rgba[2] = saturate_cast<uchar>((float(mat.rows - i)) / ((float)mat.rows) * UCHAR_MAX);
			rgba[3] = saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));
		}
	}
}

int main() {
	// 创建带Alpha通道的Mat
	Mat mat(480, 640, CV_8UC4);
	createAlphaMat(mat);

	std::vector<int> compression_params;
	// 此句代码的OpenCV2版本：
	// compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	// 此句代码的OpenCV3版本：
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	try
	{
		imwrite("透明Alpha值图.png", mat, compression_params);
		imshow("生成的PNG图", mat);
		fprintf(stdout, "PNG图片文件的alpha数据保存完毕~\n可以在工程目录下查看有imwrite函数生成的图片\n");
		waitKey(0);
	}
	catch (std::runtime_error& ex)
	{
		fprintf(stderr, "图像转换成PNG格式发生错误：%s\n", ex.what());
		return 1;
	}

	return 0;
}