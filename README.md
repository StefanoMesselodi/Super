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

SuPeR takes as input a color image and an integer number, which defines a set of tiles on the input image. SuPeR outputs a color image, which is the enhanced version of the input one.

Example: mainsuper <input_image> <n_tiles> <output_image>

# Further Development

SuPeR-B is a new version of SuPeR developed to enhance backlight images. The code of SuPeR-Bcan be derived from that of SuPeR as expalined in 

Lecca M. "A Retinex Inspired Bilateral Filter for Enhancing Images under Difficult Light Conditions." VISIGRAPP (4: VISAPP). Online Streaming, 2021

Lecca, M. (2023). "Enhancing Backlight and Spotlight Images by the Retinex-Inspired Bilateral Filter SuPeR-B". In: , et al. Computer Vision, Imaging and Computer Graphics Theory and Applications. VISIGRAPP 2021. Communications in Computer and Information Science, vol 1691. Springer, Cham. https://doi.org/10.1007/978-3-031-25477-2_15



