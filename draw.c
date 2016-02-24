#include <stdio.h>
#include <stdlib.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"


//Insert your line algorithm here

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x, y, A, B, d;
  
  if (x1 < x0) {
    
    int temp_x = x0;
    
    int temp_y = y0;
    
    x0 = x1; 
    y0 = y1;
    
    x1 = temp_x;
    y1 = temp_y;
    
  }
  
  int dx = x1 - x0;
  int dy = y1 - y0;
  
  
  
  if ((!dx && dy >= 0) || dy >= dx) { 
    
    x = x0; y = y0;
    A = y1 - y0;
    B = x0 - x1;
    d = A + 2 * B;
    
    while (y <= y1) {
      plot(s,c,x,y);
      if (d < 0) {
	x++;
	d += 2 * A;
      }
      y++;
      d += 2 * B;
    }
  }
  
  else if ( !dx || dy <= -1 * dx) { 
    x = x0; y = y0;
    A = y1 - y0;
    B = x0 - x1;
    d = A - 2 * B;
    
    while (y >= y1) {
      plot(s,c,x,y);
      if (d > 0) {
	x++;
	d += 2 * A;
      }
      y--;
      d -= 2 * B;
    }
    
  }
  
  
  
  else if (dy >= 0 && dy < dx) {
    x = x0; y = y0;
    A = y1 - y0;
    B = x0 - x1;
    d = 2 * A + B;
    
    while (x <= x1) {
      plot(s,c,x,y);
      if (d > 0) {
	y++;
	d += 2 * B;
      }
      
      x++;
      d += 2 * A;
      
    }
    
  }
  
  
  
  else{
    
    x = x0; y = y0;
    A = y1 - y0;
    B = x0 - x1;
    d = 2 * A - B;
    
    while (x <= x1) {
      plot(s,c,x,y);
      if (d < 0) {
	y--;
	d -= 2 * B;
      }
      x++;
      d += 2 * A;
    }
    
  }

}
