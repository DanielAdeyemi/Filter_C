#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int g = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtRed = g;
            image[i][j].rgbtBlue = g;
            image[i][j].rgbtGreen = g;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sR = round((float)(.393 * image[i][j].rgbtRed) + (float)(.769 * image[i][j].rgbtGreen) + (float)(.189 * image[i][j].rgbtBlue));
            int sG = round((float)(.349 * image[i][j].rgbtRed) + (float)(.686 * image[i][j].rgbtGreen) + (float)(.168 * image[i][j].rgbtBlue));
            int sB = round((float)(.272 * image[i][j].rgbtRed) + (float)(.534 * image[i][j].rgbtGreen) + (float)(.131 * image[i][j].rgbtBlue));

            if (sB > 255)
            {
                sB = 255;
            }
            if (sG > 255)
            {
                sG = 255;
            }
            if (sR > 255)
            {
                sR = 255;
            }

            image[i][j].rgbtGreen = sG;
            image[i][j].rgbtBlue = sB;
            image[i][j].rgbtRed = sR;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = temp;
            }
        }
        else
        {
            for (int k = 0; k < (width - 1) / 2; k++)
            {
                RGBTRIPLE temp = image[i][k];
                image[i][k] = image[i][width - k - 1];
                image[i][width - k - 1] = temp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; // make temp file to calculate new colors
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j]; // new file
            int bR = 0; 
            int bG = 0;
            int bB = 0;
        
            if (i == 0) // for the first row
            {
                if (j == 0) // left corner
                {
                    bR = round(((float)(image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)) / 4);
                    bG = round(((float)(image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 
                                        1].rgbtGreen)) / 4);
                    bB = round(((float)(image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)) /  
                               4);
                }
                else if (j == (width - 1)) // right corner
                {
                    bR = round(((float)(image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed)) / 4);
                    bG = round(((float)(image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 
                                        1][j].rgbtGreen)) / 4);
                    bB = round(((float)(image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue)) / 
                               4);
                }
                else // rest of the first row
                {
                    bR = round(((float)(image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i 
                                        + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)) / 6);
                    bG = round(((float)(image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + 
                                        image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)) / 6);
                    bB = round(((float)(image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + 
                                        image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)) / 6);

                }
            }
            if (i == (height - 1)) // for the last row
            {
                if (j == 0) //left bottom
                {
                    bR = round(((float)(image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed)) / 4);
                    bG = round(((float)(image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 
                                        1].rgbtGreen)) / 4);
                    bB = round(((float)(image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue)) / 
                               4);
                }
                else if (j == (width - 1)) // right bottom
                {
                    bR = round(((float)(image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed)) / 4);
                    bG = round(((float)(image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + 
                                        image[i][j].rgbtGreen)) / 4);
                    bB = round(((float)(image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue)) / 
                               4);
                }
                else // rest of the last row
                {
                    bR = round(((float)(image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + 
                                        image[i][j].rgbtRed + image[i][j + 1].rgbtRed)) / 6);
                    bG = round(((float)(image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 
                                        1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen)) / 6);
                    bB = round(((float)(image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 
                                        1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue)) / 6);
                }
            }
            if (i > 0 && i < (height - 1)) // for rest of the image
            {
                if (j == 0) // first column except first pixel
                {
                    bR = round(((float)(image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i 
                                        + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)) / 6);
                    bG = round(((float)(image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + 
                                        image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)) / 6);
                    bB = round(((float)(image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + 
                                        image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)) / 6);
                }
                else if (j == (width - 1)) // last column except last pixel
                {
                    bR = round(((float)(image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i 
                                        + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed)) / 6);
                    bG = round(((float)(image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + 
                                        image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen)) / 6);
                    bB = round(((float)(image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + 
                                        image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue)) / 6);
                }
                else // for the rest of the image
                {
                    bR = round(((float)(image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + 
                                        image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + 
                                        image[i + 1][j + 1].rgbtRed)) / 9);
                    bG = round(((float)(image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 
                                        1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + 
                                        image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)) / 9);
                    bB = round(((float)(image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j 
                                        - 1].rgbtBlue + 
                                        image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + 
                                        image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)) / 9);
                }
            }
            temp[i][j].rgbtRed = bR;
            temp[i][j].rgbtGreen = bG;
            temp[i][j].rgbtBlue = bB;
        }
    }
    for (int i = 0; i < height; i++) // assign temp pixel to original picture
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
