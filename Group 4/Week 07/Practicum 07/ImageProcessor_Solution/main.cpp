#include <iostream>

#include "Image.h"

int main() {

    Image birdImage("bird.ppm");

    birdImage.createImage("birdProcessed.ppm");

    return 0;
}
