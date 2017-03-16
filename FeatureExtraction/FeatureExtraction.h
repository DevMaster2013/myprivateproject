// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the FEATUREEXTRACTION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// FEATUREEXTRACTION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FEATUREEXTRACTION_EXPORTS
#define FEATUREEXTRACTION_API __declspec(dllexport)
#else
#define FEATUREEXTRACTION_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	//
	// The Feature Extraction settings
	//
	struct FeatureExtractionSettings
	{
		bool useGPU;
		int layersCount;
		double contrastThreshold;
		double edgesThreshold;
		double sigma;
		bool useASIFT;
		int tiltsCount;
	};

	//
	// The Feature struct
	//
	struct Feature
	{
		double x;
		double y;
		double size;
		double angle;
		unsigned char descriptor[256];
	};

	//
	// Extract the features of the image specified and store it in the output file
	// Using the settings specified
	//
	FEATUREEXTRACTION_API int extractFeatures(const char* imagePath, Feature* features, FeatureExtractionSettings settings);

#ifdef __cplusplus
}
#endif