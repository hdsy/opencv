#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <string>

using namespace cv;

const std::string imgpath = "F:\\Code\\Self\\opencv_demo\\x64\\Debug\\opencv.log.jpg";
const std::string imgpath1 = "F:\\Code\\Self\\opencv_demo\\x64\\Debug\\anaconda.log.jpg";

int TestImageMerge()
{
	int i, j;

	Mat img = imread(imgpath, IMREAD_ANYCOLOR);
	Mat img1 = imread(imgpath1, IMREAD_ANYCOLOR);
	//Mat img1 = imread(imgpath1, CV_LOAD_IMAGE_GRAYSCALE);

	if ((!img.data) || (!img1.data))
	{
		std::cout << "load error on " <<  imgpath << " or" << imgpath1 << std::endl;
		return -1;
	}

	imshow("origin img", img);

	Mat img2;

	//img2.create(img.dims, img.size(), img.type());
	img2 = img.clone();


	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			if ((j%50 == 0) || (i%50 == 0))
			{
				//std::cout << (int)img1.at<unsigned char >(i, j) << ",";
				img.at<unsigned char >(i, j) ^= 50;
			}
			//img2.at<unsigned char >(i, j) ^= img1.at<unsigned char >(i, j);


		}
	}
	std::cout << "img...." << img.type() << "( " << i << "." << img.rows << "," << j << "." << img.cols << ")" << std::endl;


	imshow("rect img", img);

	imshow("origin img1", img1);


	for (i = 0; i < img1.rows; i++)
	{
		for (j = 0; j < img1.cols; j++)
		{
			if ((j % 50 == 0) || (i % 50 == 0))
			{
				//std::cout << (int)img1.at<unsigned char >(i, j) << ",";
				img1.at<unsigned char >(i, j) ^= 50;
			}
			//img2.at<unsigned char >(i, j) ^= img1.at<unsigned char >(i, j);


		}
	}
	imshow("rect img1", img1);

	std::vector<Mat> img1Vec;

	split(img1, img1Vec);

	imshow("img1 B", img1Vec[0]);
	imshow("img1 G", img1Vec[1]);
	imshow("img1 R", img1Vec[2]);

	std::vector<Mat> imgVec;

	split(img, imgVec);

	imshow("img B", imgVec[0]);
	imshow("img G", imgVec[1]);
	imshow("img R", imgVec[2]);


	for(int z=0;z<3;z++)
	


	std::cout << "---------------------------------" << std::endl;

	

	for (i = 0; i < img1.rows; i++)
	{
		for (j = 0; j < img1.cols; j++)
		{
			/*if((i % 100 == 0 ) || (j %100 == 0))
			{
				std::cout << (int) img1.at<unsigned char >(i, j) << ",";
				img2.at<unsigned char >(i, j) = 0;
			}*/
			//img2.at<Vec3b >(i, j) += img1.at<Vec3b>(i, j);
			Vec3b & img2Vec = img2.at<Vec3b >(i, j);
			Vec3b & img1Vec = img1.at<Vec3b>(i, j);

			for (int aa = 0; aa < img2Vec.cols;aa++)
				img2Vec[aa] ^= img1Vec[aa];
		
		}
	}

	
	std::cout << "img1...." << img1.type() << "( " << i << "." << img1.rows << "," << j << "."<<img1.cols << ")" << std::endl;

	std::cout << "---------------------------------" << std::endl;

	//	img2.at<int>(i, j) += img1.at<int>(i, j);
	

	imshow("img_merge", img2);
}

int TestMatrix()
{
	// 2行3列的float类型，单通道矩阵
	Mat m = Mat(2, 3, CV_32FC(1));
	// Size(col,row) 这个要注意的差异
	Mat m2 = Mat(Size(3, 2), CV_32FC(1));

	Mat m3 = Mat::zeros(2, 3, CV_32FC1);

	Mat m4 = Mat::ones(2, 3, CV_32FC1);

	Mat m5 = (Mat_<int>(2, 3) << 1, 2, 3, 4, 5, 6);

	Mat m6;
	m6.create(2, 3, CV_32FC1);  // m6.create(Size(3,2), CV_32FC1);

	std::cout << "rc: " << m5.rows << " cc: " << m5.cols << std::endl;

	std::cout << "size: " << m5.size() << std::endl;
	std::cout << "chn: " << m5.channels() << std::endl;
	std::cout << "area: " << m5.total() << std::endl;
	std::cout << "dim: " << m5.dims << std::endl;

	for (int r = 0; r < m5.rows; r++)
		for (int c = 0; c < m5.cols; c++)
			std::cout << " " << m5.at<int>(r, c) << " ";
			
	std::cout << std::endl;

	//imshow("m5", m5);

	return 0;
}

int main(int argc, char ** argv)
{
	TestMatrix();

	TestImageMerge();


	waitKey(0);

	return 0;
}
