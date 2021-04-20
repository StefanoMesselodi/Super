#include <math.h>
#include <stdio.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <super.h>

// how to compile (under Ubuntu)
//
//g++ -O4 -I. -I/usr/local/include/opencv4 mainsuper.cpp -o mainsuper /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_imgcodecs.so

// Usage example:
//
// ./mainsuper test_01.jpeg 20 test_01_super.jpeg

int
main(int argc, char *argv[])
{
  if (argc != 4)
    {
      fprintf(stderr, "Usage: %s rgb_image partitions outfile\n", argv[0]);
      exit(0);
    }

  cv::Mat image = cv::imread(argv[1]);
  int n_grid = atoi(argv[2]);
  
  Super S;

  cv::Mat *Out = S.compute(image, n_grid);

  cv::imwrite(argv[3], *Out);

  delete Out;
}
