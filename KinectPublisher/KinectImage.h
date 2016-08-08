#pragma once


class KinectImage
{
public:
	KinectImage();
	~KinectImage();

private:
	bool                    m_bNearMode;

	// Current Kinect
	INuiSensor*             m_pNuiSensor;

	// Direct2D
	ImageRenderer*          m_pDrawDepth;
	ID2D1Factory*           m_pD2DFactory;

	HANDLE                  m_pDepthStreamHandle;
	HANDLE                  m_hNextDepthFrameEvent;

	BYTE*                   m_depthRGBX;

};