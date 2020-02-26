#include "Image.h"
#include "StickerSheet.h"

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image bg; 
  bg.readFromFile("pic/bg.png");
  bg.scale(2);
  Image pen1;
  Image pen2;
  Image pen3;
  Image pen4;

  Image pen5;
  Image pen6;

  Image pen7;
  pen1.readFromFile("pic/1.png");
  pen2.readFromFile("pic/2.png");
  pen3.readFromFile("pic/3.png");
  pen4.readFromFile("pic/4.png");
  pen5.readFromFile("pic/5.png");
  pen6.readFromFile("pic/6.png");
  pen7.readFromFile("pic/7.png");
  
  StickerSheet sheet(bg, 8);


  sheet.addSticker(pen1, 300, 2100);
  sheet.addSticker(pen2, 700, 2300);
  sheet.addSticker(pen3, 1000, 2270);
  sheet.addSticker(pen4, 1750, 1290);
  sheet.addSticker(pen5, 800, 1200);
  sheet.addSticker(pen6, 550, 1250);
  sheet.addSticker(pen7, 400, 1200);

  sheet.render().writeToFile("myImage.png");






  return 0;
}
