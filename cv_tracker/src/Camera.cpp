#include "../inc/Camera.h"


Camera::Camera()
{
    setFocaLength( );
    Camera::resetBlobs();
}

Camera::~Camera()
{
}

void Camera::setFocaLength( )
{
    double avg_pix = ( orig_a + orig_b + orig_c ) / 3.0;
    focal_length = avg_pix * ( known_obj_dist / known_obj_width );
}

double Camera::getDist( )
{
    double avg_val = 1.0;
    if( blobTotal() >= 3 )
        avg_val = 3.0;
    else
        avg_val = 1.0;
    double avg_pix = ( curr_a + curr_b + curr_c ) / avg_val;
    dist = known_obj_width * ( focal_length / avg_pix );
    return dist;
}


void Camera::resetBlobs( )
{
    tracked_blobs = 0;
}

void Camera::incBlobs( )
{
    tracked_blobs += 1;
}

double Camera::blobTotal()
{
    return tracked_blobs;
}


