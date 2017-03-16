// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MATCHING_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MATCHING_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MATCHING_EXPORTS
#define MATCHING_API __declspec(dllexport)
#else
#define MATCHING_API __declspec(dllimport)
#endif

#include "..\FeatureExtraction\FeatureExtraction.h"

#ifdef __cplusplus
extern "C"
{
#endif

	//
	// The matching settings
	//
	struct MatchingSettings
	{
		bool useGPU;
		int maxMacthesCount;
		double maxMatchesDistance;
		bool useSequentialMatching;
		int matchingFrames;
		bool useOrsa;
		int orsaIterations;
	};

	// 
	// The match struct
	//
	struct Match
	{
		int trainIndex;
		int queryIndex;
	};

	//
	// Match two image features and store the output in matches list
	MATCHING_API int matchFeatures(const char* trainImagePath, Feature* trainImageFeatures, const char* queryImagePath, Feature* queryImageFeatures, Match* matchList, MatchingSettings settings);

#ifdef __cplusplus
}
#endif