#pragma once

//
// The Errors struct
//
enum class Errors : int
{
	S_NO_ERROR,
	E_INVALID_INPUT_IMAGE,
	E_INVALID_OPERATION
};

// 
// The camera struct
//
struct Camera
{
	double cameraInterinsics[9];
	double distortionParams[5];
	double cameraRotation[9];
	double cameraTranslation[3];
};