#include "StickerSheet.h"

using namespace cs225;
// cosntructor

StickerSheet::StickerSheet(const Image& picture,unsigned max){
    picture_ = new Image(picture);
    max_ =max;
    xy_list = new unsigned[3*max_]{};
    sticker_list = new Image[max];
    
}

//destructor
StickerSheet::~StickerSheet(){
    delete picture_;
    delete[] xy_list;
    delete[] sticker_list;
}


StickerSheet::StickerSheet(const StickerSheet& other){
    max_ = other.max_;
    picture_= new Image(*(other.picture_));
    xy_list = new unsigned[3*max_]{};
    sticker_list = new Image[max_];
    for (unsigned i=0;i<max_;i++){
        sticker_list[i] = other.sticker_list[i];
        xy_list[i] = other.xy_list[i];
    }
}

int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y){
    for (unsigned i=0; i<max_; i++){
        if (xy_list[i*3]== 0){         // go to a place in the list where no image data 
            sticker_list[i] = sticker;
            xy_list[i*3] = 1;
            xy_list[i*3+1] = x;
            xy_list[i*3+2] = y;
            return i;
        }
    }
    return -1;

}


void StickerSheet::changeMaxStickers(unsigned max){
    if (max == max_){return;}
    unsigned m = max>max_ ? max_:max;
    Image* new_sticker_list = new Image[max];
    unsigned* new_xy_list = new unsigned[max*3]{};
    for (unsigned i=0;i<m;i++){
        new_sticker_list[i] = sticker_list[i];
        new_xy_list[i*3]= xy_list[i*3];
        new_xy_list[i*3+1]= xy_list[i*3+1];
        new_xy_list[i*3+2]= xy_list[i*3+2];
    }
    max_ =max;
    delete[] sticker_list;
    delete[] xy_list;
    sticker_list = new_sticker_list;
    xy_list = new_xy_list;
}


Image* StickerSheet::getSticker(unsigned index){
    if (index<max_ && index>=0 && xy_list[3*index]!=0){
        return &(sticker_list[index]);
    }
    else{
        return NULL;
    }
}

const StickerSheet& StickerSheet::operator=(const StickerSheet& other){
    max_ = other.max_;
    Image* temp = new Image(*(other.picture_));
    delete picture_;
    picture_= temp;
    delete[] xy_list;
    delete[] sticker_list;
    xy_list = new unsigned[3*max_]{};
    sticker_list = new Image[max_];
    for (unsigned i=0;i<max_;i++){
        sticker_list[i] = other.sticker_list[i];
        xy_list[i] = other.xy_list[i];
    }
    return *this;
}


void StickerSheet::removeSticker(unsigned index){
    if (index>=max_){
        return;
    }

    for (unsigned i =index;i<max_;i++){
        if ((i+1)!=max_){
            sticker_list[i]=sticker_list[i+1];
            xy_list[i*3+1] = xy_list[i*3+4];
            xy_list[i*3+2] = xy_list[i*3+5];
            xy_list[i*3] = xy_list[i*3+3];
        }
    }
    sticker_list[max_-1] = Image();
    xy_list[max_*3-1] = 0;
    xy_list[max_*3-2] = 0;
    xy_list[max_*3-3] = 0;
}



Image StickerSheet::render() const{
    unsigned new_width = picture_->width();
    unsigned new_height = picture_->height();    // save the width and height
    Image result = Image(*picture_);
    for (unsigned i = 0; i < max_; i++)
    {   
        if(xy_list[i*3]!=0){
            unsigned off_x = xy_list[i*3+1];
            unsigned off_y = xy_list[i*3+2];
            if ((off_x+sticker_list[i].width())>new_width) {
                new_width = off_x+sticker_list[i].width();
            }
            if ((off_y+sticker_list[i].height())>new_height) {
                new_height = off_y+sticker_list[i].height();
            }
        }
       
    }
    result.resize(new_width,new_height);
    for (unsigned i = 0; i < max_; i++)
    {   
        if(xy_list[i*3]!=0){
            unsigned off_x = xy_list[i*3+1];
            unsigned off_y = xy_list[i*3+2];
            for (unsigned j=0; j<sticker_list[i].width();j++){
                for (unsigned k=0; k<sticker_list[i].height();k++){
                    HSLAPixel & pixel = sticker_list[i].getPixel(j, k);   // get the current pixel 
                    HSLAPixel & pixel_to = result.getPixel(j+off_x, k+off_y);   // get the current pixel 
                    if (pixel.a!=0){
                        pixel_to = pixel;
                    }
                }
            }
        }
    }

 
    return result;
}


bool StickerSheet::translate(unsigned index, unsigned x,unsigned y){
    if(index<0||index>=max_){
        return false;
    }
    else if (xy_list[index*3]==0){
        return false;
    }
    else {
        xy_list[index*3+1] = x;
        xy_list[index*3+2] = y;
        return true;
    }
}







unsigned StickerSheet::getmax(){
    return max_;
}