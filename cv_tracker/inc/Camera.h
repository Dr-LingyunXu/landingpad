#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <string>
#include <iostream>



class Camera
{

public:
	Camera();
	~Camera();
    

    void setFocaLength( );
    double getFocalLength() { return focal_length; }
    double getDist( );
    void setA( double val ) { curr_a = val ; }
    void setB( double val ) { curr_b = val ; }
    void setC( double val ) { curr_c = val ; }
    double getA() { return curr_a; }
    double getB() { return curr_b; }
    double getC() { return curr_c; }
    void resetBlobs();
    void incBlobs();
    double blobTotal();
private:
    //double that keeps track of how many 
    //blobs that are being detected
    double tracked_blobs;
    double focal_length;
    
    //SMALL PAPER
    //const double known_obj_width = 5.5;
    //const double known_obj_dist  = 27.0;
 
    //LARGE PAPER
    //const double known_obj_width = 11.5;
    //const double known_obj_dist  = 30.5;   
    
    //LARGEST PAPER
    const double known_obj_width = 73.66;
    const double known_obj_dist  = 165.10;   
    double dist;
    
    //Original Pixel Widths

    //SMALL PAPER
    //const double orig_a = 141.00;
    //const double orig_b = 139.87;
    //const double orig_c = 142.68;
 
    //LARGE PAPER
    //const double orig_a = 273.827;
    //const double orig_b = 276.123;
    //const double orig_c = 270.017;
       
       
    //LARGEST PAPER
    const double orig_a = 311.827;
    const double orig_b = 313.677;
    const double orig_c = 319.006;
    
    //Observed Pixel Widths
    double curr_a;
    double curr_b;
    double curr_c;
    

};

#endif
