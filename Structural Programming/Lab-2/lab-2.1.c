/*The coordinates of the center and the radius of the circle are entered from the keyboard. Determine through which quadrants passes the circle. Print a 4-bit binary number indicating whether the circle passes through the corresponding quadrant in the following order: first-second-third-fourth.

For example. for the circle (3,3,4) that passes through the first, second and fourth quadrants, 1101 should be printed, and for the circle (-2, -2,1) - 0010.

Distance between 2 points in the plane is calculated as follows:

d=$\sqrt{(x1-x2)^{2}+(y1-y2)^{2}}$ */

#include <stdio.h>
#include <math.h>
int main(){
      int I,II,III,IV;
      float x,y,r,d;
      scanf("%f %f %f",&x,&y,&r);
      d=sqrt((0-x)*(0-x)+(0-y)*(0-y));
      if(x>=0 && y>=0)
      {
          I=(x>=0 && y>=0);
          II=(r>x);
          III=(r>d);
          IV=(r>y);
      }
      if(x<=0 && y>=0)
      {
          II=(x<=0 && y>=0);
          x*=-1;
          I=(r>x);
          III=(r>y);
          IV=(r>d);
      }
      if(x<=0 && y<=0)
      {
          III=(x<=0 && y<=0);
          x*=-1;
          y*=-1;
          I=(r>d);
          II=(r>y);
          IV=(r>x);
      }
      if(x>=0 && y<=0)
      {
         IV=(x>=0 && y<=0);
         y*=-1;
         I=(r>y);
         II=(r>d);
         III=(r>x);
      }
      if(x==0 && y==0)
      {
          I=II=III=IV=1;
      }
       printf("%d%d%d%d",I,II,III,IV);
       return 0;

}