using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace PRC
{
    public enum Errors
    {
        S_NO_ERROR,
        E_INVALID_INPUT_IMAGE,
        E_INVALID_OPERATION
    }

    /// <summary>
    /// The Camera Struct
    /// </summary>
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct Camera
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 9)]
        public double[] cameraInterinsics;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 5)]
        public double[] distortionParams;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 9)]
        public double[] cameraRotation;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
        public double[] cameraTranslation;
    };

    /// <summary>
    /// Manage the interface between the client application and the DLLs
    /// </summary>
    public static class PRCDLLInterface
    {
        [DllImport("CalibrationUndistort.dll", EntryPoint = "undistortImage")]
        public static extern Errors undistortImage(string imagePath, string outputImage, Camera cameraSettings);
    }
}
