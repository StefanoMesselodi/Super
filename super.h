#ifndef _SUPER_H_
#define _SUPER_H_

class Super
{
  const double EPS = 0.000000001;
  int M;
  int rows;
  int cols;
  int DeltaR;
  int DeltaC;
  int Diag2;
  uchar **Bins;
  double aux[5][256];

public:
  Super()
  {
    M = 0;
    rows = 0;
    cols = 0;
    Diag2 = 0;
    DeltaR = 0;
    DeltaC = 0;
    Bins = NULL;
  }

  ~Super()
  {
    if (Bins != NULL)
      {
	delete Bins[0];
	delete Bins;
      }
  }

  cv::Mat *compute(cv::Mat &f, int n_grid)
  {
    cv::Size size = f.size();
    init(size.height, size.width, n_grid);

    cv::Mat *ret = new cv::Mat(f);
	 
    for (int ch = 0; ch < 3; ch++)
      {
	zeroBins();
    
	int R = -1;
	for(int r = 0; r < rows; r++)
	  {
	    uchar *Rptr = ret->ptr(r);
	    if (r%DeltaR == 0) R++;
	    int C = -1;
	    for(int c = 0, k = 0; c < cols; c++, k+=3)
	      {
		if (c%DeltaC == 0) C++;
		
		//if (I[k+ch] > Bins[R][C])
		//  Bins[R][C] = I[k+ch];
		if (Rptr[k+ch] > Bins[R][C])
		  Bins[R][C] = Rptr[k+ch];
	      }
	  }

	fillAux();
    
	double K = (1.0 + EPS) * Diag2;
	double num, den, Sdelta;
	
	for(int r = 0; r < rows; r++)
	  {
	    uchar *Rptr = ret->ptr(r);
	    for(int c = 0, j = 0; c < cols; c++, j+=3)
	      {
		num = 0.0;
		den = 0.0;
		
		for(int k = Rptr[j+ch] +1; k < 256; k++)
		  {
		    
		    if (aux[0][k] > 0)
		      {
			double dist = aux[0][k] * r * r - 2 * r * aux[1][k] + aux[2][k];
			dist += aux[0][k] * c * c - 2 * c * aux[3][k] + aux[4][k];
			
			Sdelta = aux[0][k] * K - dist;
			
			num += Sdelta / (double)k;
			den += Sdelta;
		      }
		  }
		
		double res = (den > 0.0) ? Rptr[j+ch] * num / den : 1.0;
		
		Rptr[j+ch] = (uchar) (255 * res);
	      }
	  }
      }
    return ret;
  }

private:

  void init(int H, int W, int bin_size)
  {
    bool alloc = true;
    if (bin_size == M)
      alloc = false;
    else if (M > 0)
      {
	delete Bins[0];
	delete Bins;
      }
    
    M = bin_size;
    rows = H;
    cols = W;
    Diag2 = rows * rows + cols * cols;
    DeltaR = rows / M;
    DeltaC = cols / M;
    if (rows % M > 0) DeltaR++;
    if (cols % M > 0) DeltaC++;
    if (alloc)
      {
	Bins = new uchar*[M];
	Bins[0] = new uchar[M*M];
	for (int i = 1; i < M; i++)
	  Bins[i] = Bins[i-1] + M;
      }
  }
  
  void zeroBins()
  {
    for (int k = 0; k < M*M; k++)
      Bins[0][k] = 0;
  }

  void fillAux()
  {
    for(int i = 0; i < 256; i++)
      {
	aux[0][i] = 0.0;
	aux[1][i] = 0.0;
	aux[2][i] = 0.0;
	aux[3][i] = 0.0;
	aux[4][i] = 0.0;
      }
    for(int i = 0; i < M; i++)
      for(int j = 0; j < M; j++)
	{
	  int v = Bins[i][j];
	  double x = DeltaR*(i+0.5);
	  double y = DeltaC*(j+0.5);
	  aux[0][v]++;
	  aux[1][v] += x;
	  aux[2][v] += x*x;
	  aux[3][v] += y;
	  aux[4][v] += y*y;
	}
  }

};


#endif
