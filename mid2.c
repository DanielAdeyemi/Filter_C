if (i == 0) // for the first row
{
    if (j == 0) // left corner
    {
        int bR = round(((float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed + (float)image[i + 1][j].rgbtRed + (float)image[i + 1][j + 1].rgbtRed) / 4);
        int bG = round(((float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen + (float)image[i + 1][j + 1].rgbtGreen) / 4);
        int bB = round(((float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue + (float)image[i + 1][j + 1].rgbtBlue) / 4);
    }
    else if (j == (width - 1)) // right corner
    {
        int bR = round((((float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i + 1][j - 1].rgbtRed + (float)image[i + 1][j].rgbtRed / 4);
        int bG = round(((float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i + 1][j - 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen / 4);
        int bB = round(((float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i + 1][j - 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue / 4);
    }
    else // rest of the first row
    {
        int bR = round(((float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed + (float)image[i + 1][j - 1].rgbtRed + (float)image[i + 1][j].rgbtRed + (float)image[i + 1][j + 1].rgbtRed) / 6);
        int bG = round(((float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen + (float)image[i + 1][j - 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen + (float)image[i + 1][j + 1].rgbtGreen) / 6);
        int bB = round(((float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue + (float)image[i + 1][j - 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue + (float)image[i + 1][j + 1].rgbtBlue) / 6);
    }
}
if (i == (height - 1)) // for the last row
{
    if (j == 0) //left bottom
    {
        int bR = round(((float)image[i - 1][j].rgbtRed + (float)image[i - 1][j + 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed / 4);
        int bG = round(((float)image[i - 1][j].rgbtGreen + (float)image[i - 1][j + 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen / 4);
        int bB = round(((float)image[i - 1][j].rgbtBlue + (float)image[i - 1][j + 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue / 4);
    }
    else if (j == (width - 1) // right bottom
    {
        int bR = round(((float)image[i - 1][j - 1].rgbtRed + (float)image[i - 1][j].rgbtRed + (float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed / 4);
        int bG = round(((float)image[i - 1][j - 1].rgbtGreen + (float)image[i - 1][j].rgbtGreen + (float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen / 4);
        int bB = round(((float)image[i - 1][j - 1].rgbtBlue + (float)image[i - 1][j].rgbtBlue + (float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue / 4);
    }
    else // rest of the last row
    {
        int bR = round(((float)image[i - 1][j - 1].rgbtRed + (float)image[i - 1][j].rgbtRed + (float)image[i - 1][j + 1].rgbtRed + (float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed / 6);
        int bG = round(((float)image[i - 1][j - 1].rgbtGreen + (float)image[i - 1][j].rgbtGreen + (float)image[i - 1][j + 1].rgbtGreen + (float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen / 6);
        int bB = round(((float)image[i - 1][j - 1].rgbtBlue + (float)image[i - 1][j].rgbtBlue + (float)image[i - 1][j + 1].rgbtBlue + (float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue / 6);
    }
}
if (i > 0 && i < (height - 1)) // for rest of the image
{
    if (j == 0) // first column except first pixel
    {
        int bR = round(((float)image[i - 1][j].rgbtRed + (float)image[i - 1][j + 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed + (float)image[i + 1][j].rgbtRed + (float)image[i + 1][j + 1].rgbtRed) / 6);
        int bG = round(((float)image[i - 1][j].rgbtGreen + (float)image[i - 1][j + 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen + (float)image[i + 1][j + 1].rgbtGreen) / 6);
        int bB = round(((float)image[i - 1][j].rgbtBlue + (float)image[i - 1][j + 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue + (float)image[i + 1][j + 1].rgbtBlue) / 6);
    }
    else if (j == (width - 1)) // last column except last pixel
    {
        int bR = round(((float)image[i - 1][j - 1].rgbtRed + (float)image[i - 1][j].rgbtRed + (float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i + 1][j - 1].rgbtRed + (float)image[i + 1][j].rgbtRed) / 6);
        int bG = round(((float)image[i - 1][j - 1].rgbtGreen + (float)image[i - 1][j].rgbtGreen + (float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i + 1][j - 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen) / 6);
        int bB = round(((float)image[i - 1][j - 1].rgbtBlue + (float)image[i - 1][j].rgbtBlue + (float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i + 1][j - 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue) / 6);
    }
    else // for the rest of the image
    {
        int bR = round(((float)image[i - 1][j - 1].rgbtRed + (float)image[i - 1][j].rgbtRed + (float)image[i - 1][j + 1].rgbtRed + (float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed + (float)image[i + 1][j - 1].rgbtRed + (float)image[i + 1][j].rgbtRed + (float)image[i + 1][j + 1].rgbtRed) / 9);
        int bG = round(((float)image[i - 1][j - 1].rgbtGreen + (float)image[i - 1][j].rgbtGreen + (float)image[i - 1][j + 1].rgbtGreen + (float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen + (float)image[i + 1][j - 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen + (float)image[i + 1][j + 1].rgbtGreen) / 9);
        int bB = round(((float)image[i - 1][j - 1].rgbtBlue + (float)image[i - 1][j].rgbtBlue + (float)image[i - 1][j + 1].rgbtBlue + (float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue + (float)image[i + 1][j - 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue + (float)image[i + 1][j + 1].rgbtBlue) / 9);
    }
}

image[i][j].rgbtRed = bR;
image[i][j].rgbtGreen = bG;
image[i][j].rgbtBlue = bB;