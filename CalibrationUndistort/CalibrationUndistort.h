// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CALIBRATIONUNDISTORT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CALIBRATIONUNDISTORT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CALIBRATIONUNDISTORT_EXPORTS
#define CALIBRATIONUNDISTORT_API __declspec(dllexport)
#else
#define CALIBRATIONUNDISTORT_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	// 
	// The camera struct
	struct Camera
	{
		double cameraInterinsics[9];
		double distortionParams[5];
		double cameraRotation[9];
		double cameraTranslation[3];
	};

	//
	// Undistort the image with the interinsic data and distortion parameters
	// Outputs the undistorted image in the specified path
	//
	CALIBRATIONUNDISTORT_API int undistortImage(const char* imagePath, const char* outputImage, Camera cameraSettings);

#ifdef __cplusplus
}
#endif
