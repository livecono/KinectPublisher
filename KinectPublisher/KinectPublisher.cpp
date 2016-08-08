// rosserial_hello_world.cpp : Example of sending command velocities from Windows using rosserial
//
#include "stdafx.h"
#include <string>
#include <stdio.h>
#include "ros.h"
#include <sensor_msgs/Image.h>

//#include <geometry_msgs/Twist.h>
#include <windows.h>

using std::string;

int _tmain(int argc, _TCHAR * argv[])
{
	ros::NodeHandle nh;
	char *ros_master = "192.168.1.3";

	printf("Connecting to server at %s\n", ros_master);
	nh.initNode(ros_master);

	printf("Advertising cmd_vel message\n");
	sensor_msgs::Image depthImage;
	ros::Publisher imagePub("image_raw", &depthImage);
	nh.advertise(imagePub);

	printf("Go robot go!\n");
	while (1)
	{
		depthImage.linear.x = 5.1;
		depthImage.linear.y = 0;
		depthImage.linear.z = 0;
		depthImage.angular.x = 0;
		depthImage.angular.y = 0;
		depthImage.angular.z = -1.8;
		imagePub.publish(&depthImage);

		nh.spinOnce();
		Sleep(100);
	}

	printf("All done!\n");
	return 0;
}