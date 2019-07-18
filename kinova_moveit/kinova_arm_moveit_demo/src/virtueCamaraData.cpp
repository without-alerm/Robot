#include <moveit/move_group_interface/move_group_interface.h>   // replace the old version "move_group.h"
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <kinova_driver/kinova_ros_types.h>
#include <actionlib/client/simple_action_client.h>
#include <kinova_msgs/SetFingersPositionAction.h>
#include <iostream>
#include <vector>
#include <tf2_ros/transform_listener.h>

int int main(int argc, char *argv[])
{
  ros::init(argc, argv, "virtueCamaraData");
  ros::NodeHandle n;
  ros::Publisher data_pub = n.advertise<kinova_arm_moveit_demo::targetsVector>("data_pub",1000);
  ros::Rate loop_data(10);
  int count = 0;
    kinova_arm_moveit_demo::targetsVector virtuedata;
    virtuedata[0].tag = 1;
    virtuedata[0].x = -0.0686;
    virtuedata[0].y = 0.424334;
    virtuedata[0].z = 0.000997;
    virtuedata[0].qx = 5;
    virtuedata[0].qy = 5;
    virtuedata[0].qz = 1;
    virtuedata[0].qw = 0;
    virtuedata[0].px = 155;
    virtuedata[0].py = 155;

  while (ros::ok())
  {
    ROS_INFO("data published");
    data_pub.publish(virtuedata);
    ros::spinOnce();
    loop_data.sleep();
  }

  return 0;
}