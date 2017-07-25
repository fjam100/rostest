#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>
#include<sensor_msgs/LaserScan.h>

void scanCallback(const sensor_msgs::LaserScan msg){
	ROS_INFO("Scna: [%f]", msg.angle_min);
}
int main(int argc, char ** argv){
	ros::init(argc, argv, "turtlebot_commands");
	ros::NodeHandle nh;

	ros::Publisher pub_vel=nh.advertise<geometry_msgs::Twist>\
	("/mobile_base/commands/velocity",10);
	ros::Rate rate(10);

	ros::Subscriber sub_scan=nh.subscribe("/scan", 1, scanCallback);
	
	while(ros::ok()){
		geometry_msgs::Twist vel_cmd;
		vel_cmd.linear.x=1;
		pub_vel.publish(vel_cmd);
		rate.sleep();
		ros::spinOnce();
	}

}
