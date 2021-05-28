# SuPeR
Fast implementation of a Retinex inspired algorithm performing color image enhancement.

As Retinex, SuPeR reworks the image color channels independently and modifies the channel intensity of each pixel x based on the spatial color distribution in a neighborhood of x.
SuPeR increases the brightness and the contrast of the input image, while decreasing the entropy of the color distribution. Moreover, possible color casts due to the illumination under which the image has been acquired are lowered.


![superWF](https://user-images.githubusercontent.com/82895709/119674563-95794500-be3c-11eb-8108-26672b3178cb.png)


# Reference
Please cite the following paper when you use this code:

Lecca M. and Messelodi S.

SuPeR: Milano Retinex implementation exploiting a regular image grid

in JOURNAL OF THE OPTICAL SOCIETY OF AMERICA.A, OPTICS, IMAGE SCIENCE, AND VISION,
vol. 36, n. 8, 2019, pp. 1423 - 1432
DOI: 10.1364/JOSAA.36.001423xample:

# Compilation Rule

The code used the OpenCV library v. 4.2.0. To use the code of SuPeR, install this library on your PC and link it to the code of SuPeR to compile it.

The compilation command on Linux/Ubuntu OS looks like

g++ -O4 -I. -I/usr/local/include/opencv4 mainsuper.cpp -o mainsuper /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_imgcodecs.so

# Run SuPeR

SuPeR takes as input a color image and an integer number, which defines a set of tiles on the input image. It output a color image, which is the enhanced version of the input one.

Example: mainsuper <input_image> <n_tiles> <output_image>


