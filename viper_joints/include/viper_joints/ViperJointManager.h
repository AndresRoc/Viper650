#ifndef VIPER_JOINTS_VIPERJOINTMANAGER_H
#define VIPER_JOINTS_VIPERJOINTMANAGER_H

#include <string>
#include <vector>

#include <arm_components_name_manager/ArmComponentsNameManager.h>

#include <sensor_msgs/JointState.h>
#include <ros/ros.h>

/**
 * \author Jennifer Buehler
 * \date January 2016
 */
class ViperJointManager: public arm_components_name_manager::ArmComponentsNameManager
{
public:
    /**
     * Initializes joint names by reading from parameter server.
     * \namespace of the robot which is used in the YAML file
     */
    ViperJointManager(const std::string& robot_namespace="viper", bool readParams=true);
    ViperJointManager(const ViperJointManager& o);
    
    virtual bool hasDefaults()
    {
        return true;
    }


protected:

    virtual std::string getDefaultPalmLink() const;
    virtual std::vector<std::string> getDefaultArmJoints() const;
    virtual std::vector<std::string> getDefaultArmLinks() const;
    virtual std::vector<float> getDefaultArmJointsInitPose() const;
    virtual std::vector<float> getDefaultGripperJointsInitPose() const;
    virtual std::vector<std::string> getDefaultGripperJoints() const;
    virtual std::vector<std::string> getDefaultGripperLinks() const;
    virtual std::vector<float> getDefaultArmJointsMaxVel() const; 
    virtual std::vector<float> getDefaultArmJointsMaxForce() const; 
    virtual std::vector<float> getDefaultGripperJointsMaxVel() const; 
    virtual std::vector<float> getDefaultGripperJointsMaxForce() const; 
    
};

#endif  // VIPER_JOINTS_VIPERJOINTMANAGER_H
