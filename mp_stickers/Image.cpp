#include "Image.h"

using namespace cs225;


// lighten
void Image::lighten(){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.l = (pixel.l+0.1)>1 ? 1.0:(pixel.l+0.1); // if not larger than 1 then add 0.1

        }
    }

}


void Image::lighten(double amount){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.l = (pixel.l+amount)>1 ? 1.0:(pixel.l+amount);  // the same as above but just change it to amount

        }
    }
}


// darken
void Image::darken(){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.l = (pixel.l-0.1)<0 ? 0.0:(pixel.l-0.1); // if not less than 0 then -0.1

        }
    }

}


void Image::darken(double amount){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.l = (pixel.l-amount)<0 ? 0.0:(pixel.l-amount); // if not less than 0 then -amount

        }
    }

}

// saturate
void Image::saturate(){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.s = (pixel.s+0.1)>1 ? 1.0:(pixel.s+0.1); // if not larger than 1 then add 0.1

        }
    }
}



void Image::saturate(double amount){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.s = (pixel.s+amount)>1 ? 1.0:(pixel.s+amount); // if not larger than 1 then add amount

        }
    }
}



// desaturate

void Image::desaturate(){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.s = (pixel.s-0.1)<0 ? 0.0:(pixel.s-0.1); // if not larger than 1 then - 0.1

        }
    }
}

void Image::desaturate(double amount){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.s = (pixel.s-amount)<0 ? 0.0:(pixel.s-amount); // if not larger than 1 then - amount

        }
    }
}


// scale
void Image::scale(double factor){
    unsigned newx = (this->width())*factor;
    unsigned newy = (this->height())*factor;        // get the new height and width 
    Image *temp_image = new Image(*this);            // copy the image for a back up
    resize(newx,newy);
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            unsigned origin_x = (1.0*x)/factor;            // get the location in original to copy
            unsigned origin_y = (1.0*y)/factor;
            HSLAPixel & temp_pixel = temp_image->getPixel(origin_x,origin_y);       //copy
            pixel.l =temp_pixel.l;
            pixel.s =temp_pixel.s;
            pixel.h =temp_pixel.h;
            pixel.a =temp_pixel.a;

        }
    }
    delete temp_image;          // delete the created temp
}


// scale
void Image::scale(unsigned w,unsigned h){
    
    double x_factor = (w*1.0)/this->width();
    double y_factor = (h*1.0)/this->height();            // get the factor at row and col
    double factor = x_factor>y_factor ? y_factor:x_factor;
    scale(factor);
    // Image* tmp = new Image(*this);
    // resize(w,h);
    // if (factor<1){
    //     for (unsigned x = 0;x <this->width();x++) {
	//         for (unsigned y=0; y<this->height(); y++) {
    //             HSLAPixel & pixel_to = this->getPixel(x, y);
    //             pixel_to = HSLAPixel();
	//         }
	//     }
    // }
    // for (unsigned x = 0;x <tmp->width()*factor;x++) {
	//     for (unsigned y=0; y<tmp->height()*factor; y++) {
	// 	    unsigned original_x = (1.0*x)/factor;
	// 	    unsigned original_y = (1.0*y)/factor;		
	// 	    HSLAPixel & pixel_to = this->getPixel(x, y);
	// 	    HSLAPixel & pixel_from = tmp->getPixel(original_x, original_y);
	// 	    pixel_to = pixel_from;
	//     }
	// }
   
   
}

// the grayscale is just turn the saturation to 0

void Image::grayscale(){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.s = 0.0; // turn the saturation to 0 to turn to grayscale

        }
    }
}

// rotate the color by degrees
void Image::rotateColor(double degrees){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            pixel.h = pixel.h+degrees;
            pixel.h = (pixel.h>=360)? (pixel.h-360) : pixel.h;
            pixel.h =(pixel.h<0)? (pixel.h+360) : pixel.h;
        }
    }
}


// turn the image to blue and orange
void Image::illinify(){
    for (unsigned x = 0; x<this->width(); x++){
        for (unsigned y=0; y<this->height(); y++){
            HSLAPixel & pixel = this->getPixel(x, y);   // get the current pixel 
            if (pixel.h>=114 && pixel.h<=243){
                pixel.h = 216;
            }
            else{
                pixel.h = 11;
            }
        }
    }

}