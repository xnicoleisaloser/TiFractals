#include <tice.h>
#include <graphx.h>
#include <stdio.h>

#define MAXCOUNT 30 

// setting the left, top, xside and yside 
// for the screen and image to be displayed 
float left = -1.35; 
float top = -1.0125; 
float xside = 1.35; 
float yside = 1.0125; 
	
void fractal(float left, float top, float xside, float yside) 
{ 
    float xscale, yscale, zx, zy, cx, tempx, cy; 
    int x, y, i, j; 
    int maxx, maxy, count; 
  
    // getting maximum value of x-axis of screen 
    maxx = 320;
  
    // getting maximum value of y-axis of screen 
    maxy = 240;
  
    // setting up the xscale and yscale 
    xscale = xside / maxx; 
    yscale = yside / maxy; 
  
    // calling fillscreen function 
    // where required image will be seen 
    gfx_FillScreen(255);
  
    // scanning every point in that rectangular area. 
    // Each point represents a Complex number (x + yi). 
    // Iterate that complex number 
    for (y = 0; y <= maxy - 1; y++) { 
        for (x = 0; x <= maxx - 1; x++) 
        { 
            // c_real 
            cx = x * xscale + left; 
  
            // c_imaginary 
            cy = y * yscale + top; 
  
            // z_real 
            zx = 0; 
  
            // z_imaginary 
            zy = 0; 
            count = 0; 
  
            // Calculate whether c(c_real + c_imaginary) belongs 
            // to the Mandelbrot set or not and draw a pixel 
            // at coordinates (x, y) accordingly 
            // If you reach the Maximum number of iterations 
            // and If the distance from the origin is 
            // greater than 2 exit the loop 
            while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT)) 
            { 
                // Calculate Mandelbrot function 
                // z = z*z + c where z is a complex number 
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real 
                tempx = zx * zx - zy * zy + cx; 
  
                // 2*z_real*z_imaginary + c_imaginary 
                zy = 2 * zx * zy + cy; 
  
                // Updating z_real = tempx 
                zx = tempx; 
  
                // Increment count 
                count = count + 1; 
            } 
  
            // To display the created fractal 
			gfx_SetColor(count);
            gfx_SetPixel(x, y);
        } 
    } 
} 


// Driver code 
int main() 
{ 
	/* Initialize graphics drawing */
    gfx_Begin();
	gfx_FillScreen(255);
	

  
    // Function calling 
    fractal(left, top, xside, yside); 
  
    /* Waits for a key */
    while (!os_GetCSC());

	gfx_End();

    return 0;
} 
