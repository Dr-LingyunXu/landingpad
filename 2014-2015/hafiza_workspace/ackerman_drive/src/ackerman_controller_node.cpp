#include "ackerman_drive/ackerman_controller.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "ackerman_controller");

    ros::NodeHandle n;


    ackerman_drive::ackerman_drive drive(n);

    ros::spin();

    return 0;
}

