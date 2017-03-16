// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CAMERAMOTION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CAMERAMOTION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CAMERAMOTION_EXPORTS
#define CAMERAMOTION_API __declspec(dllexport)
#else
#define CAMERAMOTION_API __declspec(dllimport)
#endif

#include "..\FeatureExtraction\FeatureExtraction.h"
#include "..\CalibrationUndistort\CalibrationUndistort.h"

//
// The Image Entry struct
//
struct ImageEntry
{
	const char* imagePath;
	Camera* imageCamera;
	Feature* imageFeatures;
};

//
// Sequential Type
//
enum class SequentialType
{
	Zigzag,
	Alternative
};

//
// Focal Length Type
//
enum class FocalLengthType
{
	Variable,
	Fixed,
	OneCameraModel
};

//
// CPU Percision Type
//
enum class CPUPercision
{
	VeryHigh,
	High,
	Normal
};

//
// Camera Motion settings
//
struct CameraMotionSettings
{
	bool useGPU;
	int minTracks;
	bool useSequentialCameraMotion;
	int sequentialFrames;
	SequentialType sequentialType;
	FocalLengthType focalLengthType;
	CPUPercision cpuPercision;
	int initialPair0;
	int initialPair1;
	double cameraDistance;
	bool useRT;
	double rtMaxProjectionError;
	double rtMinAngle;
	bool takeAllCameras;
	bool useFullBundleAdjustment;
	double focalLengthConstraint;
	double radialDistConstratint;
	bool estimateRadialDistortion;
	bool useParallelEpipolar;
	bool calc3DMatches;
	bool useRayDivergence;
	double maxReprojectionError;
	double rayAngleThreshold;
	int optimizationIterations;
	bool useConstraints;
	bool useDistanceOnlyConstraint;
	double rotationWeight;
	double translationWeight;
	int* constraintPairs;
};

//
// The Point view which is the keypoint in an image
//
struct PointView
{
	int image;
	int key;
};

//
// The 3D point estimated with its views
//
struct Point3D
{
	double x;
	double y;
	int numViews;
	PointView* views;
};

// 
// Camera Motion Output struct
//
struct CameraMotionOutput
{
	int numCamerasComputed;
	Camera* cameras;
	int numPoints;
	Point3D* points;
};

//
CAMERAMOTION_API int runCameraMotion(ImageEntry* imageEntries, CameraMotionSettings settings, CameraMotionOutput* output);
