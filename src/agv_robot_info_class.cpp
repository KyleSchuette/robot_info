#include "robot_info/robot_info.h"
#include "hydraulic_system_monitor.cpp"

class AGVRobotInfo : public RobotInfo {
public:
  float maximum_payload;
  HydraulicSystemMonitor hydraulic_monitor;  // composition

  AGVRobotInfo() : maximum_payload(0.0f) {}

  void publish_data() override {
    robotinfo_msgs::RobotInfo10Fields msg;

    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number: " + serial_number;
    msg.data_field_03 = "ip_address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;
    msg.data_field_05 = "maximum_payload: " + std::to_string(maximum_payload) + " Kg";

    // Values from HydraulicSystemMonitor object
    msg.data_field_06 = "hydraulic_oil_temperature: " + hydraulic_monitor.getHydraulicOilTemperature();
    msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulic_monitor.getHydraulicOilTankFillLevel();
    msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulic_monitor.getHydraulicOilPressure();

    // Extra fields
    msg.data_field_09 = "";
    msg.data_field_10 = "";

    info_pub_.publish(msg);

    ROS_INFO_STREAM("[AGVRobotInfo] Published:\n"
                    << msg.data_field_01 << "\n"
                    << msg.data_field_02 << "\n"
                    << msg.data_field_03 << "\n"
                    << msg.data_field_04 << "\n"
                    << msg.data_field_05 << "\n"
                    << msg.data_field_06 << "\n"
                    << msg.data_field_07 << "\n"
                    << msg.data_field_08);
  }
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");

  AGVRobotInfo agv;
  agv.robot_description = "Cooper100";
  agv.serial_number = "567A359";
  agv.ip_address = "169.254.5.180";
  agv.firmware_version = "3.5.8";
  agv.maximum_payload = 100.0f;

  ros::Rate rate(1);
  while (ros::ok()) {
    agv.publish_data();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
