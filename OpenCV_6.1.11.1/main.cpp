#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	const auto image = imread("..\\_images\\1.jpg");

	namedWindow("�����˲�->ԭͼ");
	namedWindow("�����˲�->Ч��ͼ");

	// ��ʾԭͼ
	imshow("�����˲�->ԭͼ", image);

	// ���з����˲�����
	Mat out;
	boxFilter(image, out, -1, Size(5, 5));

	// ��ʾЧ��ͼ
	imshow("�����˲�->Ч��ͼ", out);

	waitKey(0);
	return 0;
}