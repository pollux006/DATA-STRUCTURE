/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include "Image.h"
 
class StickerSheet{
    public:
    // constructor
    StickerSheet(const Image&, unsigned);

    ~StickerSheet();

    StickerSheet(const StickerSheet &);

    const StickerSheet& operator=(const StickerSheet&);

    unsigned getmax();
    // change the maximum number
    void changeMaxStickers(unsigned);

    int addSticker (Image&,unsigned,unsigned);
    bool translate(unsigned,unsigned,unsigned);
    void removeSticker(unsigned);

    Image* getSticker(unsigned);

    Image render() const;

    private:
    Image* picture_; // the base pic
    unsigned max_;
    Image* sticker_list;
    unsigned* xy_list;  // the list contains 3 values: status, x and y


};