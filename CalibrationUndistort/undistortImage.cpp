#include "stdafx.h"
#include "CalibrationUndistort.h"

#include <opencv2\opencv.hpp>
#include <vector>

CALIBRATIONUNDISTORT_API Errors undistortImage(const char * imagePath, const char * outputImage, Camera cameraSettings)
{
	// Read the input image
	cv::Mat inputImage = cv::imread(imagePath);
	if (inputImage.rows == 0 || inputImage.cols == 0)
		return Errors::E_INVALID_INPUT_IMAGE;

	// Prepare the input matrices
	cv::Mat cameraMatrix(3, 3, CV_64FC1, cameraSettings.cameraInterinsics);
	cv::Mat distCoeffs(1, 5, CV_64FC1, cameraSettings.distortionParams);

	// undistort the image
	cv::Mat undistortedImage;
	cv::undistort(inputImage, undistortedImage, cameraMatrix, distCoeffs);
	if (inputImage.rows == 0 || inputImage.cols == 0)
		return Errors::E_INVALID_OPERATION;

	// save the output image
	std::vector<int> compressionParameters;	
	compressionParameters.push_back(CV_IMWRITE_JPEG_QUALITY);
	compressionParameters.push_back(100);
	if (!cv::imwrite(outputImage, undistortedImage, compressionParameters))
		return Errors::E_INVALID_OPERATION;

	return Errors::S_NO_ERROR;
}